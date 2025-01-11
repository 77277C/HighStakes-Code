#include "devices.hpp"


pros::adi::Pneumatics clamp_piston('A', false);
pros::adi::Pneumatics intake_piston('B', false);
pros::adi::Pneumatics doinker_piston('C', false);

pros::MotorGroup left_motors({-13, -5, -6}, pros::MotorGears::blue);
pros::MotorGroup right_motors({1, 15, 3}, pros::MotorGears::blue);

pros::MotorGroup intake_motor({-7});


pros::Imu imu(16);
pros::Optical intake_optical(10);

pros::Rotation ladybrown_rotation(10);
pros::MotorGroup ladybrown_motor({-8});
