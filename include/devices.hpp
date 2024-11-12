#include "pros/motor_group.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "robodash/api.h"
#include "qlib/drivetrain.hpp"
#include "qlib/controller.hpp"
#include "qlib/tracking_wheel.hpp"

extern pros::adi::Pneumatics clamp;
extern pros::adi::Pneumatics hang;
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::MotorGroup intake;
extern Drivetrain drivetrain;
extern pros::Imu imu;
extern MotorTrackingWheel vertical_tracking_wheel;

