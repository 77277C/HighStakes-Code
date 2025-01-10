#pragma once

#include "pros/adi.hpp"


class Doinker {
public:
    /**
     * @brief Construct the doinker subsystem object
     *
     * @param piston The piston object to use
     */
    explicit Doinker(pros::adi::Pneumatics& piston)
        : piston(piston) {

    }

    /**
     * @brief Set the pneumatics to a specified boolean state
     * @param state The state to set the solenoid to
     */
    void set_state(const bool state) {
        piston.set_value(state);
    }

    /**
     * @brief Set to toggle the pneumatic state
     */
    void toggle() {
        piston.toggle();
    }

private:
    // Save the pneumatics as a private field
    pros::adi::Pneumatics& piston;
};

