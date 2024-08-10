#include "qlib/odometry.hpp"
#include "qlib/constants.h"


void AbstractOdometry::update_from_values(int vertical, int horizontal, int heading, int vertical_offset, int horizontal_offset) {
    // because in the first iteration, there is no previous value so we use the current value instead
    double delta_vertical = vertical - previous_vertical.value_or(vertical);
    double delta_horizontal = horizontal - previous_horizontal.value_or(horizontal);
    double delta_heading = heading - previous_heading.value_or(heading);

    previous_vertical = vertical;
    previous_horizontal = horizontal;
    previous_heading = heading;

    // Get the local x and y displacement in the cartesian system
    double local_x, local_y;
    if (delta_heading == 0) { // prevent dividing by 0
        local_x = horizontal;
        local_y = vertical;
    }
    else {
        local_x = 2 * std::sin(delta_heading / 2) * (delta_horizontal / delta_heading + horizontal_offset);
        local_y = 2 * std::sin(delta_heading / 2) * (delta_vertical / delta_heading + vertical_offset);
    }

    // Convert the local cartesian coordinates to polar coordinates
    double local_polar_radius = std::sqrt(local_x * local_x + local_y * local_y);
    double local_polar_angle = std::atan2(local_y, local_x);

    // Rotate the displacement vector by -heading
    double average_heading = heading + delta_heading / 2;
    double global_angle = local_polar_angle - average_heading;

    // Convert polar displacement back to cartesian and update our position
    current_pose.x += local_polar_radius * std::cos(global_angle);
    current_pose.y += local_polar_radius * std::sin(global_angle);
    current_pose.theta = current_pose.theta + delta_heading;
}


Pose AbstractOdometry::get_pose() const {
    return current_pose;
}


void AbstractOdometry::set_pose(Pose pose) {
    current_pose = pose;
}


void AbstractOdometry::log_coordinates(rd::Console &console) const {
    while (true) {
        Pose pose = this->get_pose();
        console.printf("(%f, %f, %f)\n", pose.x, pose.y, rad_to_deg(pose.theta));
    }
}


VerticalTrackerImuOdometry::VerticalTrackerImuOdometry(const TrackingWheel &vertical_tracking_wheel,
                                                       const pros::Imu &imu)
        : vertical_tracking_wheel(vertical_tracking_wheel), imu(imu) {}


void VerticalTrackerImuOdometry::initialize() {
    // Reset the sensors
    vertical_tracking_wheel.reset();
    imu.reset(true);

    // Start the odometry loop
    pros::Task([=] {
        while (true) {
            update();
            pros::delay(DELAY_TIME);
        }
    });
}

void VerticalTrackerImuOdometry::update() {
    double vertical = vertical_tracking_wheel.get_distance_traveled();
    // The inertial sensor returns degrees but C++ funcs use radians
    double imu_heading = deg_to_rad(imu.get_rotation());
    update_from_values(vertical, 0, imu_heading, vertical_tracking_wheel.get_offset(), 0);
}
