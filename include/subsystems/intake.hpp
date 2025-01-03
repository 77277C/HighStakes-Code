#pragma once

#include "pros/motor_group.hpp"

#ifndef DELAY_TIME
#define DELAY_TIME 10
#endif


enum class RingColor {
    RED,
    BLUE
};


class Intake {
public:
    /**
     * @brief Construct the intake subsystem object
     *
     * @param motor The motor object to use
     * @param optical the optical sensor object to use
     */
    explicit Intake(pros::MotorGroup& motor, pros::Optical& optical)
        : motor(motor), optical(optical) {
        this->optical.set_led_pwm(100);
        this->optical.disable_gesture();
        this->optical.set_integration_time(10);
    }

    /**
     * @brief start the task for color sorting
     *
     * @param color The alliance color
     */
    void start_color_sort_task(const RingColor color) {
        this->color_sort_task = new pros::Task([&]() {
            while (true) {
                if (this->color_sort_on) {
                    pros::c::optical_rgb_s_t rgb = this->optical.get_rgb();
                    if ((color == RingColor::BLUE && rgb.red >= 200) ||
                        (color == RingColor::RED && rgb.blue >= 200)) {
                        // Ensure that no opcontrol commands happen during this time
                        mutex.take(TIMEOUT_MAX);
                        this->pause(100);
                        mutex.give();
                    }
                }
                pros::delay(DELAY_TIME);
            }
        });
    }

    /**
     * @brief Turn color sorting on or off
     */
    void toggle_color_sort() {
        this->color_sort_on = !this->color_sort_on;
    }

    /**
     * @brief Pause the intake for a certain time
     *
     * @param delay the amount of time in ms to pause the intake for
     */
    void pause(const int delay) {
        int old_voltage = this->motor.get_voltage();
        this->motor.move_voltage(0);
        pros::delay(delay);
        this->motor.move_voltage(old_voltage);
    }

    /**
     * @brief This function moves the intake from a percentage -100% - 100%
     * @param percentage The percentage to use [-100, 100]
     */
    void move_percentage(const int percentage) {
        // Do not interfere with colorsorting
        mutex.take(TIMEOUT_MAX);
        this->motor.move(percentage * 1.27);
        mutex.give();
    }

private:
    // Save the device as a private field
    pros::MotorGroup& motor;
    pros::Optical& optical;
    pros::Task* color_sort_task = nullptr;
    bool color_sort_on = true;
    pros::Mutex mutex;
};

