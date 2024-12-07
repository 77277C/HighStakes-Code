#pragma once

#include "pros/motor_group.hpp"
#include "pros/distance.hpp"
#include "command/subsystem.h"
#include "command/runCommand.h"
#include "console.hpp"

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
        // dont start a new task if one already exists
        if (this->redirect_task == nullptr) {
            this->redirect_task = new pros::Task([this]() {
                // Wait until a ring is detected
                while (this->redirect_distance.get() > 75) {
                    pros::delay(DELAY_TIME);
                }

                console.println("1");

                // Wait until the ring has passed the senor
                while (this->redirect_distance.get() < 75) {
                    pros::delay(50);
                    console.println(std::to_string(redirect_distance.get_distance()));
                }

                console.println("2");
        
                // Manual control needs to be disabled at this point
                actively_redirecting = true;
    
                // Move the intake in reverse for a second
                this->motor.move(-127);
                pros::delay(1000);
                this->motor.move(0);
    
                // Cleanup the task
                pros::Task* task_to_delete = this->redirect_task;
                this->redirect_task = nullptr;
                delete task_to_delete; // Free task memory safely
            });
        }
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
     * @brief Wait until a ring has been redirected
     * @param timeout the amount of time to exit after
     *
     * @return true if redirected, false if timeouted
     */
    bool wait_until_redirect(int timeout) {
        int start_time = pros::millis();
        while (this->redirect_task != nullptr) {
            pros::delay(DELAY_TIME);
            if (start_time + timeout > pros::millis()) {
                return false;
            }        
        }
        return true;
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

