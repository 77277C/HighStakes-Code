#pragma once
#include "main.h"
#include "subsystems/clamp.hpp"
#include "subsystems/doinker.hpp"
#include "subsystems/intake.hpp"
#include "devices.hpp"

extern std::vector<rd::Selector::routine_t> autons;
extern void skills();
extern void pid_tuning();
