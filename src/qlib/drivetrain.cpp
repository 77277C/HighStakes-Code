#include "qlib/drivetrain.hpp"
#include "qlib/constants.h"


// Initialize the drivetrain with he given motors
Drivetrain::Drivetrain(pros::AbstractMotor& left_motors, pros::AbstractMotor& right_motors) :
    left_motors(left_motors),
    right_motors(right_motors) {}


void Drivetrain::tank(double left, double right) const {
    left_motors.move(left);
    right_motors.move(right);
}


void Drivetrain::arcade(double vertical, double horizontal) const {
    double left = vertical + horizontal;
    double right = vertical - horizontal;

    left_motors.move(left);
    right_motors.move(right);
}

