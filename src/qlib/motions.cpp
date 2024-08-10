#include "qlib/motions.hpp"


bool is_close(double error) {
    return std::fabs(error) < 7.5;
}


template <typename T> double sgn(T val) {
    return (T(0) < val) - (val < T(0));
}


Motions::Motions(Drivetrain& drivetrain, PIDController& linear_controller,
                 PIDController& angular_controller, AbstractOdometry& odometry) :
      drivetrain(drivetrain),
      linear_controller(linear_controller),
      angular_controller(angular_controller),
      odometry(odometry),
      is_in_motion(false) {}


bool Motions::start_motion() {
    if (in_motion()) {
        return false;
    }

    is_in_motion = true;
    motion_tracker = std::make_unique<MotionTracker>(odometry);
    return true;
}


bool Motions::in_motion() const {
    return is_in_motion;
}


void Motions::end_motion() {
    is_in_motion = false;
    motion_tracker = nullptr;

    linear_controller.reset();
    angular_controller.reset();

    drivetrain.tank(0, 0);
}


void Motions::wait_until_done() const {
    do pros::delay(DELAY_TIME);
    while (in_motion());
}


void Motions::wait_until(double until, MotionType type) const {
    do pros::delay(DELAY_TIME);
    while (in_motion() && (
            type == MotionType::LINEAR ?
            motion_tracker->get_distance() :
            motion_tracker->get_angle()) < until
    );
}


void Motions::turn_to_heading(double heading, MovementParams params) {
    // If there is already a motion running, ignore this motion
    if (!start_motion()) { return; }
    if (params.async) {
        params.async = false;
        pros::Task([&]() {
            turn_to_heading(heading, params);
        });
        pros::delay(DELAY_TIME);
        return;
    }

    // If the forward field is false, reverse the angle
    if (!params.forwards) {
        heading = std::fmod(heading + 180, 360);
    }

    while (!angular_controller.check_exit_conditions(DELAY_TIME) && in_motion()) {
        // Calculate the closest angle between our target angle and our current angle
        double error = rad_to_deg(odometry.get_pose().theta - heading);

        // Update the angular controller
        double voltage = angular_controller.compute(error);

        // Move the drivetrain
        drivetrain.tank(voltage, -voltage);

        // Tell the motion tracker to update the distance traveled
        motion_tracker->update();
        pros::delay(DELAY_TIME);
    }

    // Reset PID controller and stop the drivetrain
    angular_controller.reset();
    end_motion();
}


void Motions::swing_to_heading(double heading, SwingType swing_type, MovementParams params) {
    // If there is already a motion running, ignore this motion
    if (!start_motion()) { return; }
    if (params.async) {
        params.async = false;
        pros::Task([&]() {
            swing_to_heading(heading, swing_type, params);
        });
        pros::delay(DELAY_TIME);
        return;
    }

    // If the forward field is false, reverse the angle
    if (!params.forwards) {
        heading = std::fmod(heading + 180, 360);
    }

    while (!angular_controller.check_exit_conditions(DELAY_TIME)  && in_motion()) {
        // Calculate the closest angle between our target angle and our current angle
        double error = rad_to_deg(odometry.get_pose().theta - heading);

        // Update the angular PID and slew controller with our new errors
        double voltage = angular_controller.compute(error);

        // Move the side of the drivetrain that is specified by the swing type
        if (swing_type == SwingType::LEFT) {
            drivetrain.tank(voltage, 0);
        }
        else {
            drivetrain.tank(0, -voltage);
        }

        // Tell the motion tracker to update the distance traveled
        motion_tracker->update();
        pros::delay(DELAY_TIME);
    }

    // Reset PID controller and stop the drivetrain
    angular_controller.reset();
    end_motion();
}


void Motions::move_to_point(double x, double y, LinearMovementParams params) {
    if (!start_motion()) { return; }
    if (params.async) {
        params.async = false;
        pros::Task([&]() {
            move_to_point(x, y, params);
        });
        pros::delay(DELAY_TIME);
        return;
    }

    Pose target(x, y, 0_rad);
}

