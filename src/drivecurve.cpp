#include "drivecurve.hpp"


PilonsDriveCurve::PilonsDriveCurve(double t, double scale)
    : t(t), scale(scale) {}


float PilonsDriveCurve::curve(float input) {
    return (
            std::pow(M_E, -(this->t/10)) +
            std::pow(M_E, (std::abs(input) - 127) / 10) *
            (1 - std::pow(M_E, -(this->t/10)))
        ) * input * this->scale;
}


void arcade(lemlib::Chassis& chassis, double throttle, double turn) {
    throttle = chassis.throttleCurve->curve(throttle);
    turn = chassis.steerCurve->curve(turn);

    double left = throttle + turn;
    double right = throttle - turn;
    chassis.tank(left, right, true);
}

