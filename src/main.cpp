#include "main.h"


lemlib::Drivetrain drivetrain(
        &left_motors,
        &right_motors,
        12.5,
        lemlib::Omniwheel::NEW_275,
        450,
        2
);


// All sensors all nullptr because we will use our custom odometry
lemlib::OdomSensors sensors(
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        &imu
);


lemlib::ControllerSettings lateral_controller(
        60, // proportional gain (kP)
        0, // integral gain (kI)
        30, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in inches
        100, // small error range timeout, in milliseconds
        3, // large error range, in inches
        500, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
);


lemlib::ControllerSettings angular_controller(
        6, // proportional gain (kP)
        0, // integral gain (kI)
        46, // derivative gain (kD)
        3, // anti windup
        1, // small error range, in degrees
        100, // small error range timeout, in milliseconds
        3, // large error range, in degrees
        500, // large error range timeout, in milliseconds
        0 // maximum acceleration (slew)
);


DoubleBandedExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                          120, // joystick maxband out of 127
                                          10, // minimum output where drivetrain will move out of 127
                                          1.019 // expo curve gain
);


lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                   10, // minimum output where drivetrain will move out of 127
                                   1.019 // expo curve gain
);

lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttle_curve, &steer_curve);


rd::Selector selector(autons);


CommandController controller(pros::E_CONTROLLER_MASTER);

Intake* intake;
Clamp* clamp;
Doinker* doinker;


/**
 * @brief This function runs the update scheduler at each frame with a consistent schedule
 *
 * @warning This function or alternative similar to it must be running to ensure the \refitem CommandScheduler is run
 */
[[noreturn]] void update_loop() {
    // Loop forever
    while (true) {
        // Store the start time
        auto start_time = pros::millis();

        // Run the command scheduler
        // This might be an expensive(Time wise) computation
        CommandScheduler::run();

        // Use delay until if this computation ends up being expensive, keeping loop time in check
        pros::c::task_delay_until(&start_time, DELAY_TIME);
    }
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // Calibrate the inertial sensor
    chassis.calibrate();

    // Start the command scheduler task
    pros::Task command_scheduler_task(update_loop);

    intake = new Intake(intake_motor);
    CommandScheduler::registerSubsystem(intake, intake->move_percentage_command(0));
    controller.getTrigger(pros::E_CONTROLLER_DIGITAL_R1)->whileTrue(intake->move_percentage_command(100));
    controller.getTrigger(pros::E_CONTROLLER_DIGITAL_R2)->whileTrue(intake->move_percentage_command(-100));

    clamp = new Clamp(clamp_piston);
    CommandScheduler::registerSubsystem(clamp, clamp->set_state_command(false));
    controller.getTrigger(pros::E_CONTROLLER_DIGITAL_L2)->toggleOnTrue(clamp->set_state_command(true));

    doinker = new Doinker(doinker_piston);
    CommandScheduler::registerSubsystem(doinker, doinker->set_state_command(false));
    controller.getTrigger(pros::E_CONTROLLER_DIGITAL_L1)->whileTrue(doinker->set_state_command(true));

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
    selector.run_auton();
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
    while (true) {
        int left_y = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int right_x = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(left_y, right_x, false, 0.6);

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            selector.run_auton();
        }

        pros::delay(DELAY_TIME);  // delay to save resources
    }
}

