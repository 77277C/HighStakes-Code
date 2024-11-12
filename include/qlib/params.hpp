#pragma once
#include <algorithm>
#include <cmath>


struct TurnParams {
    bool forwards = true;
    bool async = true;
};


struct MoveToPoseParams {
    bool forwards = true;
    bool async = true;
    double min_voltage = 0;
    double max_voltage = 127;
    double dlead = 0.6;
};
