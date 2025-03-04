#include "devices.hpp"


pros::adi::Pneumatics clamp_piston('A', false);
pros::adi::Pneumatics intake_piston('B', false);
pros::adi::Pneumatics doinker_piston('C', false);

pros::MotorGroup left_motors({-13, -12, -9}, pros::MotorGears::blue);
pros::MotorGroup right_motors({8, 15, 4}, pros::MotorGears::blue);

pros::MotorGroup intake_hooks({19}, pros::MotorGears::blue);
pros::MotorGroup intake_front({18}, pros::MotorGears::blue);

pros::Imu imu(17);
pros::Optical intake_optical(10);

pros::Rotation ladybrown_rotation(10);
pros::MotorGroup ladybrown_motor({-14});

pros::Rotation vert_tracking_wheel_rotation(-16);
