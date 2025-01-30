#pragma once

#include "pros/rotation.hpp"
#include "pros/optical.hpp"
#include "pros/motor_group.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"

extern pros::adi::Pneumatics clamp_piston;
extern pros::adi::Pneumatics doinker_piston;
extern pros::adi::Pneumatics intake_piston;
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::MotorGroup intake_hooks;
extern pros::Optical intake_optical;
extern pros::Imu imu;
extern pros::Rotation ladybrown_rotation;
extern pros::MotorGroup ladybrown_motor;
extern pros::Rotation vert_tracking_wheel_rotation;
extern pros::MotorGroup intake_front;
