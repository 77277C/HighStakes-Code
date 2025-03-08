#pragma once
#include "lemlib/api.hpp"


class PilonsDriveCurve : public lemlib::DriveCurve {
    public:
        explicit PilonsDriveCurve(double t, double scale);
        float curve(float input) override;
    private:
        const double t;
        const double scale;
};


void arcade(lemlib::Chassis& chassis, double left, double right);
