#pragma once

#include "pros/adi.hpp"
#include "command/subsystem.h"
#include "command/runCommand.h"


class Doinker : public Subsystem {
public:
    explicit Doinker(pros::adi::Pneumatics& piston)
        : piston(piston) {

    }

    void set_state(const bool state) {
        piston.set_value(state);
    }

    RunCommand* set_state_command(const bool state) {
        return new RunCommand(
            [this, state] {
                this->set_state(state);
            },
            {this}
        );
    }

    void toggle() {
        piston.toggle();
    }

    RunCommand* toggle_command() {
        return new RunCommand(
            [this] () {
                this->toggle();
            },
            {this}
        );
    }

    void periodic() override {

    }

private:
    pros::adi::Pneumatics& piston;
};

