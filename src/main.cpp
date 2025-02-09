#include "main.h"


lemlib::Drivetrain drivetrain(
        &left_motors,
        &right_motors,
        12.5,
        lemlib::Omniwheel::NEW_275,
        450,
        2
);


lemlib::TrackingWheel vertical_tracking_wheel(
        &vert_tracking_wheel_rotation,
        2.085,
        0
);


lemlib::OdomSensors sensors(
        &vertical_tracking_wheel,
        nullptr,
        nullptr,
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
        10 // maximum acceleration (slew)
);


lemlib::ControllerSettings angular_controller(
        5, // proportional gain (kP)
        0, // integral gain (kI)
        35, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in degrees
        100, // small error range timeout, in milliseconds
        3, // large error range, in degrees
        500, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
);



DoubleBandedExpoDriveCurve throttle_curve(10, // joystick deadband out of 127
                                          120, // joystick maxband out of 127
                                          10, // minimum output where drivetrain will move out of 127
                                          1.019 // expo curve gain
);


lemlib::ExpoDriveCurve steer_curve(10, // joystick deadband out of 127
                                   10, // minimum output where drivetrain will move out of 127
                                   1.03 // expo curve gain
);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve, &steer_curve);


rd::Selector selector(autons);


pros::Controller controller(pros::E_CONTROLLER_MASTER);
Intake intake(intake_hooks, intake_front, intake_optical);
Clamp clamp(clamp_piston);
Doinker doinker(doinker_piston);
Doinker intake_raise(intake_piston);
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
    //intake.start_color_sort_task(RingColor::BLUE);

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
        int left_y = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int right_x = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(left_y, right_x, false, 0.5);

        // Run the commands
        // This might be an expensive(Time wise) computation
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intake.move_percentage(100, IntakeMotors::FRONT);
            intake.move_percentage(0, IntakeMotors::HOOKS);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            intake.move_percentage(100);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake.move_percentage(-100);
        }
        else {
            intake.move_percentage(0);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
            ladybrown.cycle_target();
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            ladybrown.cycle_bottom_target();
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            doinker.set_state(true);
        }
        else {
            doinker.set_state(false);
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
            intake_raise.toggle();
        }
        if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
            clamp.toggle();
        }

        // Use delay until if this computation ends up being expensive, keeping loop time in check
        pros::Task::delay_until(&start_time, DELAY_TIME);
    }
}

