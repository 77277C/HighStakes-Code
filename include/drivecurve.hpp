#pragma once
#include "lemlib/api.hpp"


class DoubleBandedExpoDriveCurve : public lemlib::ExpoDriveCurve {
    private:
        const float maxband = 127;
    public:
        DoubleBandedExpoDriveCurve(float deadband, float maxband, float minOutput, float curve);
        float curve(float input) override;
};
