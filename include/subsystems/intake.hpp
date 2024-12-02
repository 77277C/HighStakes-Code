#pragma once

#include "pros/motor_group.hpp"
#include "command/subsystem.h"
#include "command/runCommand.h"




class Intake : public Subsystem {
public:
    /**
     * @brief Construct the intake subsystem object
     *
     * @param motor The motor object to use
     */
    explicit Intake(pros::MotorGroup& motor)
        : motor(motor) {

    }

    /**
     * @brief This function moves the intake from a percentage -100% - 100%
     * @param percentage The percentage to use [-100, 100]
     */
    void move_percentage(const int percentage) {
        this->motor.move(percentage * 1.27);
    }

    /**
     * @brief Simple command to move the intake
     *
     * @param percentage Percentage Desired for this command
     * @return Command pointer to a RunCommand that moves the intake
     */
    RunCommand* move_percentage_command(const int percentage) {
        return new RunCommand(
            [this, percentage] () {
                this->move_percentage(percentage);
            },
            {this}
        );
    }

    /**
     * @brief This method runs every loop, for the intake, do nothing
     */
    void periodic() override {

    }

    ~Intake() override = default;

private:
    // Save the device as a private field
    pros::MotorGroup& motor;
};

