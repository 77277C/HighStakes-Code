#include "devices.hpp"


pros::adi::Pneumatics clamp_piston('A', false);
pros::adi::Pneumatics doinker_piston('B', false);
pros::adi::Pneumatics wall_stakes_piston('C', false);

pros::MotorGroup left_motors({-5, -4, -6}, pros::MotorGears::blue);
pros::MotorGroup right_motors({1, 2, 3}, pros::MotorGears::blue);

pros::MotorGroup intake_motor({-7});


pros::Imu imu(9);
pros::Optical intake_optical(10);

pros::Rotation ladybrown_rotation(11);
pros::MotorGroup ladybrown_motor({-8});
