#pragma once

#include "pros/motor_group.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"

extern pros::adi::Pneumatics clamp_piston;
extern pros::adi::Pneumatics doinker_piston;
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::MotorGroup intake_motor;
extern pros::Imu imu;
