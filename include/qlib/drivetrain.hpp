#pragma once
#include "pros/abstract_motor.hpp"
#include "robodash/api.h"


/**
 * Drivetrain class
 *
 * This class is used to control the drivetrain of the robot.
 */
class Drivetrain {
public:
    pros::AbstractMotor& left_motors;
    pros::AbstractMotor& right_motors;

    /**
     * Constructor
     *
     * @param left_motors The left motors of the drivetrain
     * @param right_motors The right motors of the drivetrain
     */
    Drivetrain(pros::AbstractMotor& left_motors, pros::AbstractMotor& right_motors);

    /**
     * Use the drivetrain with the tank control scheme
     *
     * @param left The speed of the left side of the drivetrain
     * @param right The speed of the right side of the drivetrain
     */
    void tank(double left, double right) const;

    /**
     * Use the drivetrain with the arcade control scheme
     *
     * @param vertical The vertical speed of the drivetrain
     * @param horizontal The horizontal speed of the drivetrain
     */
    void arcade(double vertical, double horizontal) const;

};
