#include "devices.hpp"


pros::adi::Pneumatics clamp_piston('A', false);
pros::adi::Pneumatics left_doinker_piston('C', false);
pros::adi::Pneumatics right_doinker_piston('B', false);

pros::MotorGroup left_motors({17, -12, -9}, pros::MotorGears::blue);
pros::MotorGroup right_motors({-8, 15, 11}, pros::MotorGears::blue);

pros::MotorGroup intake_hooks({19}, pros::MotorGears::blue);
pros::MotorGroup intake_front({18}, pros::MotorGears::blue);

pros::Imu imu(7);
pros::Optical intake_optical(5 );

pros::Rotation ladybrown_rotation(10);
pros::MotorGroup ladybrown_motor({-14});

pros::Rotation vert_tracking_wheel_rotation(-16);
pros::Rotation horz_tracking_wheel_rotation(13);

pros::Distance left_distance_sensor(4);
pros::Distance right_distance_sensor(3);
