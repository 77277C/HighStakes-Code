#pragma once

#include "intake.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "lemlib/pid.hpp"


class LadyBrown {
public:
    static constexpr int AWAY = 70;
    static constexpr int LOAD = 90;
    static constexpr int READY_TO_SCORE = 170;
    static constexpr int SCORE = 200;
    static constexpr int UTIL = 300;

    explicit LadyBrown(pros::MotorGroup& motor, pros::Rotation& rotation)
        : motor(motor), rotation(rotation) {
    }

    void cycle_target() {
        if (this->current_target == AWAY) this->set_current_target(LOAD);
        else if (this->current_target == LOAD) this->set_current_target(READY_TO_SCORE);
        else if (this->current_target == READY_TO_SCORE) this->set_current_target(SCORE);
        else {
            this->set_current_target(AWAY);
        }
    }

    void set_current_target(double target) {
        if (target != this->current_target) {
            this->current_target = target;
            pid.reset();
        }
    }

    void start_pid_task() {
        this->pid_task = new pros::Task([&]() {
            while (true) {
                double error = this->current_target - rotation.get_angle() / 100.0;
                double output = this->pid.update(error);
                this->motor.move(output);

                pros::delay(DELAY_TIME);
            }
        });
    }

private:
    // Save the devices as a private field
    pros::MotorGroup& motor;
    pros::Rotation& rotation;
    lemlib::PID pid = lemlib::PID(1, 0, 0);
    double current_target = AWAY;
    pros::Task* pid_task;
};