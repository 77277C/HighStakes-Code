#pragma once

#include "pros/motor_group.hpp"
#include "pros/distance.hpp"
#include "command/subsystem.h"
#include "command/runCommand.h"

#ifndef DELAY_TIME
#define DELAY_TIME 10
#endif



class Intake : public Subsystem {
public:
    /**
     * @brief Construct the intake subsystem object
     *
     * @param motor The motor object to use
     * @param redirect_distance The distance sensor object to use
     */
    explicit Intake(pros::MotorGroup& motor, pros::Distance& redirect_distance)
        : motor(motor), redirect_distance(redirect_distance) {

    }

    /**
     * @brief This function moves the intake from a percentage -100% - 100%
     * @param percentage The percentage to use [-100, 100]
     */
    void move_percentage(const int percentage) {
        // Do not allow manual control if active redirecting
        if (!actively_redirecting) {
            this->motor.move(percentage * 1.27);
        }
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
     * @brief Queue the next ring to be redirected
     */
    void redirect_next_ring() {
        // if the next ring is already queued for redirection
        if (this->redirect_task == nullptr) {
            return;
        }

        this->redirect_task = new pros::Task([this]() {
            // Wait until a ring is detected
            while (this->redirect_distance.get_distance() > 75) {
                pros::delay(DELAY_TIME);
            }

            // Manual control needs to be disabled at this point
            actively_redirecting = true;

            // Move the intake in reverse for a second
            this->motor.move(-127);
            pros::delay(1000);
            this->motor.move(0);

            // Cleanup the task
            actively_redirecting = false;
            this->redirect_task = nullptr;
        });
    }

    /**
     * @brief Simple command to the queue the next ring to be redirected
     *
     * @return Command pointer to a RunCommand that queues the redirect
     */
    RunCommand* redirect_next_ring_command() {
        return new RunCommand(
            [this]() {
                this->redirect_next_ring();
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
    pros::Distance& redirect_distance;
    pros::Task* redirect_task = nullptr;
    bool actively_redirecting = false;
};

