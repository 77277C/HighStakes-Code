#pragma once
#include <vector>
#include <functional>
#include <cmath>
#include "pose.hpp"
#include "drivetrain.hpp"


class PIDController {
public:
    PIDController(double p, double i, double d, double start_i, double small_error, double small_error_time ,
        double big_error, double big_error_time);

    double compute(double error);
    void reset();
    void reset_timers();
    void set_constants(double p, double i, double d, double start_i = 0);
    void set_exit_conditions(double small_error, double small_error_time,
                             double big_error, double big_error_time);
    bool check_exit_conditions(double refresh_rate);

protected:
    double p;
    double i;
    double d;
    double start_i;

    double error;
    double previous_error;
    double integral;

    double small_error = 0;
    double small_error_time = 0;
    double big_error = 0;
    double big_error_time = 0;

    double inside_small_timer;
    double inside_big_timer;
};


class SlewController {
public:
    int rate;
    bool enable_deceleration;

    SlewController(double rate, bool enable_deceleration);
    double compute(double target);
    void reset();

protected:
    double previous;
};
