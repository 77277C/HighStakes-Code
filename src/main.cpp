#include "main.h"


lemlib::Drivetrain drivetrain(
        &left_motors,
        &right_motors,
        12.5,
        lemlib::Omniwheel::NEW_325,
        450,
        2
);


lemlib::TrackingWheel vertical_tracking_wheel(
        &vert_tracking_wheel_rotation,
        2.085,
        0
);


lemlib::TrackingWheel horizontal_tracking_wheel(
        &horz_tracking_wheel_rotation,
        2.085,
        0
);


lemlib::OdomSensors sensors(
        &vertical_tracking_wheel,
        nullptr,
        &horizontal_tracking_wheel,
        nullptr,
        &imu
);


lemlib::ControllerSettings lateral_controller(
        10, // proportional gain (kP)
        0, // integral gain (kI)
        45, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in inches
        100, // small error range timeout, in milliseconds
        3, // large error range, in inches
        500, // large error range timeout, in milliseconds
        35 // maximum acceleration (slew)
);


lemlib::ControllerSettings angular_controller(
        4.4, // proportional gain (kP)
        0, // integral gain (kI)
        35, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in degrees
        100, // small error range timeout, in milliseconds
        3, // large error range, in degrees
        500, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
);


PilonsDriveCurve throttle_curve(1, 1);
PilonsDriveCurve steer_curve(1, 0.85);


lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve, &steer_curve);


rd::Selector selector(autons);


pros::Controller controller(pros::E_CONTROLLER_MASTER);
Intake intake(intake_hooks, intake_front, intake_optical, RingColor::BLUE);
Clamp clamp(clamp_piston);
Doinker left_doinker(left_doinker_piston);
Doinker right_doinker(right_doinker_piston);
LadyBrown ladybrown(ladybrown_motor, ladybrown_rotation);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // Calibrate the inertial sensor
    chassis.calibrate();

    // Start the color sorting task
    intake.start_color_sort_task();

    // Start the ladybrown PID task
    ladybrown.start_pid_task();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    selector.run_auton();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled viSa
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
[[ noreturn ]] void opcontrol() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    while (true) {
        // Store the start time
        auto start_time = pros::millis();

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            autonomous();
        }

        // Operate the drivetrain
        int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        throttle = throttle_curve.curve(throttle);
        turn = steer_curve.curve(turn);
        chassis.tank(throttle + turn, throttle - turn, true);


        // Run the commands
        // This might be an expensive(Time wise) computation
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
            intake.resume();
        }

        // Intake
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            intake.move_percentage(100, DELAY_TIME);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
            intake.move_percentage(-100, DELAY_TIME);
        }
        else {
            intake.move_percentage(0, DELAY_TIME);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            intake.queue_ring(true);
        }

        // Intake Colorsort
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            intake.swap_color();
            intake.print_color(controller);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
            intake.toggle_color_sort();
        }


        // Ladybrown
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
            ladybrown.cycle_target();
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
            ladybrown.cycle_bottom_target();
        }

        // Doinker
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            right_doinker.toggle();
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
            left_doinker.toggle();
        }

        // Clamp
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
            clamp.toggle();
        }

        // Use delay until if this computation ends up being expensive, keeping loop time in check
        pros::Task::delay_until(&start_time, DELAY_TIME);
    }
}

