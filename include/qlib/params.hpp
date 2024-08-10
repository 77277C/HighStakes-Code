#pragma once
#include <algorithm>
#include <cmath>


struct MovementParams {
    bool forwards = true;
    bool async = true;
};


struct LinearMovementParams : public MovementParams {
    double min_voltage = 0;
    double max_voltage = 127;
};
