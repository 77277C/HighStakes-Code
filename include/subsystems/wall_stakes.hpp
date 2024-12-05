#pragma once

#include "pros/adi.hpp"
#include "command/subsystem.h"
#include "command/runCommand.h"


class WallStakes : public Subsystem {
public:
    /**
     * @brief Construct the clamp subsystem object
     *
     * @param piston The piston object to use
     */
    explicit WallStakes(pros::adi::Pneumatics& piston)
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
     * @brief Simple command to set the pneumatics
     *
     * @param state state The state to set the solenoid to
     * @return Command pointer to a RunCommand that sets the solenoid
     */
    RunCommand* set_state_command(const bool state) {
        return new RunCommand(
            [this, state] {
                this->set_state(state);
            },
            {this}
        );
    }

    /**
     * @brief Set to toggle the pneumatic state
     */
    void toggle() {
        piston.toggle();
    }

    /**
     * @brief Simple command to set the pneumatics
     *
     * @param state state The state to set the solenoid to
     * @return Command pointer to a RunCommand that sets the solenoid
     */
    RunCommand* toggle_command() {
        return new RunCommand(
            [this] () {
                this->toggle();
            },
            {this}
        );
    }

    /**
    * @brief This method runs every loop, for the intake, do nothing
    */
    void periodic() override {

    }

private:
    // Save the pneumatics as a private field
    pros::adi::Pneumatics& piston;
};

