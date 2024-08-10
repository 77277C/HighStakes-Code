#pragma once
#include <cmath>


#define DEFINE_UNIT(name, conversion) \
inline double operator"" _##name(long double x) { return (x) * (conversion); } \
inline double operator"" _##name(unsigned long long x) { return (x) * (conversion); }


// The units for length convert to INCHES
DEFINE_UNIT(in, 1.0) // No conversion needed

// The units for angles convert to RADIANS
DEFINE_UNIT(rad, 1.0)          // No conversion needed
DEFINE_UNIT(deg, M_PI / 180.0) // Multiply by PI/180 to convert degrees to radians
