#include "main.h"


PIDController linear_pid_controller (
        10,   // kP
        0,    // kI
        5,    // kD
        0,    // Integral Start
        1,    // Small error range
        500,  // Small error time,
        3,    // Big error range
        1000  // Big error time,
);


PIDController angular_pid_controller (
        10,   // kP
        0,    // kI
        5,    // kD
        0,    // Integral Start
        1,    // Small error range
        500,  // Small error time,
        3,    // Big error range
        1000  // Big error time
);

VerticalTrackerImuOdometry odometry(vertical_tracking_wheel, imu);


Motions motions(
        drivetrain,
        linear_pid_controller,
        angular_pid_controller,
        odometry
);


rd::Selector selector({});


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    odometry.initialize();
    pros::Task([&]() { odometry.log_coordinates(); });
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
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    while (true) {
        int left_y = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int right_x = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            clamp.toggle();
        }
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            intake.move(127);
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intake.move(-127)
        }


        drivetrain.arcade(left_y, right_x);
        pros::delay(DELAY_TIME);  // delay to save resources
    }
}

