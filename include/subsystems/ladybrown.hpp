#pragma once

#include "intake.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/pid.hpp"


class LadyBrown {
public:
    // Define the constants that hold the values of different ladybrown positions
    // Cycle positions
    static constexpr int AWAY = 65;
    static constexpr int LOAD = 85;
    static constexpr int READY_TO_SCORE = 170;
    static constexpr int SCORE = 235;
    // Util positions
    static constexpr int BOTTOM = 290;

    // Feedforward constant
    static constexpr int FEEDFORWARD_K = 10;

    /**
     * @brief Construct the ladybrown subsystem object
     *
     * @param motor The motor object to use
     * @param rotation The rotation sensor object to use
     */
    explicit LadyBrown(pros::MotorGroup& motor, pros::Rotation& rotation)
        : motor(motor), rotation(rotation) {
    }

    /**
     * @brief Cycle between the cycle positions, if not on one, reset to AWAY
     */
    void cycle_target() {
        if (this->current_target == AWAY) this->set_current_target(LOAD);
        else if (this->current_target == LOAD) this->set_current_target(READY_TO_SCORE);
        else if (this->current_target == READY_TO_SCORE) this->set_current_target(SCORE);
        else {
            this->set_current_target(AWAY);
        }
    }

    /**
     * @brief Set the PID Target
     * @param target The target
     */
    void set_current_target(double target) {
        if (target != this->current_target) {
            this->current_target = target;
            pid.reset();
        }
    }

    /**
     * @brief Start the task that will run the PID with feedforward loop
     */
    void start_pid_task() {
        this->pid_task = new pros::Task([&]() {
            while (true) {
                if (this->pid_control_on) {
                    double current_angle = rotation.get_angle() / 100.0;
                    double error = this->current_target - current_angle;

                    double output = this->pid.update(error);
                    double feedforward_output = FEEDFORWARD_K * std::sin((180.0 - current_angle));
                    if (output < 0) {
                        feedforward_output = 0;
                    }
                    this->motor.move(output + feedforward_output);
                }

                pros::delay(DELAY_TIME);
            }
        });
    }

    /**
     * @brief Toggle whether the PID task is on
     */
    void toggle_pid_control() {
        this->pid_control_on = !this->pid_control_on;
        // If the pid was turned on make the positions the away position
        if (this->pid_control_on) {
            this->set_current_target(AWAY);
        }
    }

    /**
     * @return Whether the PID task is on or off
     */
    bool get_pid_control_status() {
        return this->pid_control_on;
    }

    /**
     * @brief This function moves the ladybrown from a percentage -100% - 100%
     * @param percentage The percentage to use [-100, 100]
     */
    void move_percentage(const int percentage) {
        this->motor.move(percentage * 1.27);
    }

private:
    // Save the devices as a private field
    pros::MotorGroup& motor;
    pros::Rotation& rotation;
    lemlib::PID pid = lemlib::PID(2.5, 0, 0);
    double current_target = AWAY;
    pros::Task* pid_task = nullptr;
    bool pid_control_on = true;
};