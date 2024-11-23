#include "drivecurve.hpp"


// Call the parent classes constructor and also assign the maxband variable
DoubleBandedExpoDriveCurve::DoubleBandedExpoDriveCurve(
    float deadband, float maxband, float minOutput, float curve
) : lemlib::ExpoDriveCurve(deadband, minOutput, curve), maxband(maxband) {}


float DoubleBandedExpoDriveCurve::curve(float input) {
    // if the input is over the maxband value return the max power
    if (input > maxband) {
        return 127;
    }
    // otherwise let the parent class's method do its algorithim
    return lemlib::ExpoDriveCurve::curve(input);
}
