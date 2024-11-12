#pragma once
#include <vector>
#include <functional>
#include <cmath>
#include "pose.hpp"
#include "drivetrain.hpp"
#include "console.hpp"


class PIDController {
public:
    PIDController(double p, double i, double d, double start_i);

    double compute(double error);
    void reset();
    void set_constants(double p, double i, double d, double start_i = 0);

protected:
    double p;
    double i;
    double d;
    double start_i;

    double error;
    double previous_error;
    double integral;
};


class SlewController {
public:
    int rate;
    bool enable_deceleration;

    SlewController(double rate, bool enable_deceleration);
    double compute(double target);
    void reset();

    double previous;
};
