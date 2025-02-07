#pragma once

#include "pros/adi.hpp"


class Clamp {
public:
    /**
     * @brief Construct the clamp subsystem object
     *
     * @param piston The piston object to use
     */
    explicit Clamp(pros::adi::Pneumatics& piston)
        : piston(piston) {

    }

    /**
     * @brief Set the pneumatics to a specified boolean state
     * @param state The state to set the solenoid to
     */
    void set_state(const bool state) {
        piston.set_value(state);
        this->check_status();
    }

    /**
     * @brief Set to toggle the pneumatic state
     */
    void toggle() {
        piston.toggle();
        this->check_status();
    }

    /**
     * @brief Rumble the controller if the piston was extended
     */
    void check_status() {
        static pros::Controller controller(pros::E_CONTROLLER_MASTER);
        if (piston.is_extended()) {
            controller.rumble(".");
        }
    }


private:
    // Save the pneumatics as a private field
    pros::adi::Pneumatics& piston;
};

