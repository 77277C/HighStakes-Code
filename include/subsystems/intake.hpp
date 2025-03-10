#pragma once

#include "pros/motor_group.hpp"
#include "lemlib/timer.hpp"
#include <atomic>

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
     * @param color the alliance color
     */
    explicit Intake(pros::MotorGroup& hooks, pros::MotorGroup& front, pros::Optical& optical, RingColor color)
        : hooks(hooks), front(front), optical(optical) {
        this->optical.set_led_pwm(100);
        this->optical.disable_gesture();
        this->optical.set_integration_time(10);
        this->set_color(color);
    }

    /**
     * @brief Set the alliance color
     * @param color The new color
     */
    void set_color(RingColor color) {
        this->color = color;
    }

    /**
     * @brief Swap the alliance color
     */
    void swap_color() {
        if (this->color == RingColor::BLUE) {
            this->color = RingColor::RED;
        }
        else {
            this->color = RingColor::BLUE;
        }
    }

    /**
     * @brief print the alliance color to the given controller
     * @param controller the given controller
     */
    void print_color(pros::Controller& controller) {
        if (this->color == RingColor::BLUE) {
            controller.print(0, 0, "blue");
        }
        else {
            controller.print(0, 0, "red");
        }
    }

    /**
     * @brief start the task for color sorting
     */
    void start_color_sort_task() {
        this->color_sort_task = new pros::Task([&]() {
            while (true) {
                if (this->color_sort_on) {
                    double hue = optical.get_hue();
                    double proximity = optical.get_proximity();
                    if (
                        proximity > 200 &&
                        ((color == RingColor::BLUE && hue > 200 && hue < 260) ||
                        (color == RingColor::RED && (hue > 330 || hue < 30)))
                    ) {
                        pros::delay(100);
                        this->mutex.take();

                        lemlib::Timer timeout(1000);
                        double initial_position = hooks.get_position();
                        while (initial_position - hooks.get_position() < 100 && !timeout.isDone()) {
                            this->front.move(-127);
                            this->hooks.move(-127);
                        }
                        this->front.move(0);
                        this->hooks.move(0);
                        this->mutex.give();
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
     * @brief Stop the next ring when it reaches the optical sensor
     * @param shouldPause whether to pause the intake until a new press or not
     *                    should be false in auton and true in opcontrol
     * @return The created task
     */
    pros::Task* queue_ring(bool shouldPause) {
        return new pros::Task([&]() {
            while (true) {
                double hue = optical.get_hue();
                double proximity = optical.get_proximity();
                if (
                        proximity > 200 &&
                        ((color == RingColor::BLUE && hue > 200 && hue < 260) ||
                        (color == RingColor::RED && (hue > 330 || hue < 30)))
                    ) {
                    // Attempt to stop the intake for a second before aborting
                    this->move_percentage(0, 1000);

                    if (shouldPause) {
                        // Intake is paused, needs new button press to restart
                        this->pause();
                    }
                    break;
                }

                pros::delay(DELAY_TIME);
            }
        });
    }

    /**
     * Make the next input require a new press
     */
    void pause() {
        this->paused.store(true);
    }

    /**
     * Unpause the intake
     */
    void resume() {
        this->paused.store(false);
    }

    /**
     * @brief This function moves the intake from a percentage -100% - 100%
     *        Ignore all inputs if intake is paused
     * @param percentage The percentage to use [-100, 100]
     * @param timeout The timeout to wait before bailing the move command
     *                This should be TIMEOUT_MAX in autons but should be DELAY_TIME
     *                in opcontrol because move commands are repeatedly fired
     */
    void move_percentage(const int percentage, const int timeout) {
        if (this->paused.load()) {
            return;
        }
        mutex.take(timeout);
        this->front.move(percentage * 1.27);
        this->hooks.move(percentage * 1.27);
        mutex.give();
    }

private:
    // Save the device as a private field
    pros::MotorGroup& hooks;
    pros::MotorGroup& front;
    pros::Optical& optical;
    pros::Task* color_sort_task = nullptr;
    bool color_sort_on = false;
    std::atomic<bool> paused = false;
    pros::Mutex mutex;
    RingColor color;
};

