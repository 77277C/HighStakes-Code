#include "qlib/motion_tracker.hpp"


// Constructor initializes the MotionTracker with an Odometry instance
MotionTracker::MotionTracker(const AbstractOdometry& odometry)
    : odometry(odometry), initial_pose(odometry.get_pose()), previous_pose(initial_pose),
      theta(0_rad), distance(0_in) {}

// Get the accumulated distance traveled by the robot
double MotionTracker::get_distance() const {
    return distance;
}

// Get the total angle turned by the robot (in radians)
double MotionTracker::get_angle() const {
    return theta;
}

// Update the motion tracker based on the current pose
void MotionTracker::update() {
    // Get the current pose from the Odometry
    Pose current_pose = odometry.get_pose();

    // Compute the distance traveled since the last update
    distance += previous_pose.distance_to(current_pose);

    // Compute the absolute angular error (angle turned) from the initial pose
    theta = std::fabs(current_pose.theta - initial_pose.theta);

    // Update the previous pose for the next iteration
    previous_pose = current_pose;
}
