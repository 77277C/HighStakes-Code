#include "drivecurve.hpp"


DoubleBandedExpoDriveCurve::DoubleBandedExpoDriveCurve(
    float deadband, float maxband, float minOutput, float curve
) : lemlib::ExpoDriveCurve(deadband, minOutput, curve), maxband(maxband) {}


float DoubleBandedExpoDriveCurve::curve(float input) {
    if (input > maxband) {
        return 127;
    }
    return lemlib::ExpoDriveCurve::curve(input);
}
