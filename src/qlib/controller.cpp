#include "qlib/controller.hpp"

// Constructor initializes pid gains and exit conditions
PIDController::PIDController(double p, double i, double d, double start_i)
        : p(p),
          i(i),
          d(d),
          start_i(start_i){}

// Compute the control output based on the error
double PIDController::compute(double error) {
    this->error = error;
    double derivative = error - previous_error;

    // Integral term accumulates when error is above start_i threshold
    if (error >= start_i) {
        integral += error;
    }
    // Reset integral term if error changes sign (prevents windup)
    if ((error > 0 && previous_error < 0) || (error < 0 && previous_error > 0)) {
        integral = 0;
    }

    previous_error = error;
    // Combine proportional, integral, and derivative terms
    return error * p + derivative * d + integral * i;
}

// Reset PIDController controller state (error, integral, and timers)
void PIDController::reset() {
    previous_error = 0;
    integral = 0;
}


// Set new PID gains for the PIDController controller
void PIDController::set_constants(double p, double i, double d, double start_i) {
    this->p = p;
    this->i = i;
    this->d = d;
    this->start_i = start_i;
}


// Constructor initializes the slew rate (maximum allowable change per iteration)
SlewController::SlewController(double rate, bool enable_deceleration) : rate(rate), enable_deceleration(enable_deceleration) {}

// Compute the output value with rate-limited change
double SlewController::compute(double target) {
    // rate of 0 means slew is disabled
    if (rate <= 0.001) {
        return target;
    }

    // Calculate the change from the previous value
    double change = target - previous;

    // Limit the change to the specified rate
    if (change > rate) {
        change = rate;
    }
    // Disabled slew rate if decelerating since that would interfere with settling
    else if (change < -rate && enable_deceleration) {
        change = -rate;
    }

    // Update the previous value and return the adjusted output
    previous += change;
    return previous;
}

// Reset the internal state (previous target value)
void SlewController::reset() {
    previous = 0;
}
