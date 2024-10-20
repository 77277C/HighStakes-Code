#include "devices.hpp"


pros::adi::Pneumatics clamp('A', false);

pros::MotorGroup left_motors({-3, -4});
pros::MotorGroup right_motors({1, 2});

pros::MotorGroup intake({-6, 7});

Drivetrain drivetrain (
        left_motors,
        right_motors
);


MotorTrackingWheel vertical_tracking_wheel (
        left_motors,              // motors
        450,                      // rpm
        -6,                        // offset
        2.50                      // wheel diameter
);

pros::Imu imu(9);

