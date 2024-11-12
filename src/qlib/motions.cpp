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
    return true;
}


bool Motions::in_motion() const {
    return is_in_motion;
}


void Motions::end_motion() {
    is_in_motion = false;

    linear_controller.reset();
    angular_controller.reset();

    drivetrain.tank(0, 0);
}


void Motions::turn_to_heading(double heading, TurnParams params) {
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

    double error;
    do {
        // Calculate the closest angle between our target angle and our current angle
        error = rad_to_deg(odometry.get_pose().theta - heading);

        // Update the angular controller
        double voltage = angular_controller.compute(error);

        // Move the drivetrain
        drivetrain.tank(voltage, -voltage);

        pros::delay(DELAY_TIME);
    } while (error > 5 && in_motion());

    // Reset PID controller and stop the drivetrain
    angular_controller.reset();
    end_motion();
}


void Motions::swing_to_heading(double heading, SwingType swing_type, TurnParams params) {
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

    double error;
    do {
        // Calculate the closest angle between our target angle and our current angle
        error = rad_to_deg(odometry.get_pose().theta - heading);

        // Update the angular PID and slew controller with our new errors
        double voltage = angular_controller.compute(error);

        // Move the side of the drivetrain that is specified by the swing type
        if (swing_type == SwingType::LEFT) {
            drivetrain.tank(voltage, 0);
        }
        else {
            drivetrain.tank(0, -voltage);
        }

        pros::delay(DELAY_TIME);
    } while (error > 5 && in_motion());

    // Reset PID controller and stop the drivetrain
    angular_controller.reset();
    end_motion();
}


void Motions::move_to_pose(Pose target, MoveToPoseParams params) {
    if (!start_motion()) { return; }

    if (params.async) {
        params.async = false;
        pros::Task([&]() {
            move_to_pose(target, params);
        });
        pros::delay(DELAY_TIME);
        return;
    }


    target.theta = std::fmod(2 * M_PI - target.theta, 2 * M_PI);

    double linear_error;
    double angular_error;
    do {
        Pose current_pose = odometry.get_pose();
        double distance_to_target = current_pose.distance_to(target);

        Pose carrot_point(
                target.x - distance_to_target * std::cos(target.theta) * params.dlead,
                target.y - distance_to_target * std::sin(target.theta) * params.dlead
        );

        linear_error = current_pose.distance_to(carrot_point);
        angular_error = current_pose.angle_to(carrot_point);

        double linear_voltage = linear_controller.compute(linear_error);
        double angular_voltage = angular_controller.compute(angular_error);
        drivetrain.arcade(linear_voltage, angular_voltage);

        pros::delay(DELAY_TIME);
    } while ((linear_error > 0.5 || angular_error > 5) && in_motion());

    linear_controller.reset();
    angular_controller.reset();
    end_motion();
}

