#include "autons.hpp"


void auton1() {
    chassis.setPose(-55, 43.5, 270);
    chassis.moveToPose(-23.5, 25, 310, 5000, {.forwards = false, .lead = 0.5});
    chassis.waitUntil(15);
    chassis.cancelMotion();
    chassis.moveToPose(-24, 24.5, 310, 5000, {.forwards = false, .maxSpeed=30});    
    chassis.waitUntil(15);
    clamp.extend();
    chassis.waitUntilDone();

    chassis.setPose(-23.5, 23.5, chassis.getPose().theta + 5);

    chassis.turnToPoint(-23.5, 41, 5000, {.minSpeed = 127});
    chassis.waitUntilDone();
    
    chassis.moveToPoint(-23.5, 41, 5000);
    chassis.waitUntil(2);
    chassis.cancelMotion();

    pros::delay(500);

    chassis.moveToPoint(-23.5, 41, 5000, {.maxSpeed = 50});
    intake.move(127);
    chassis.waitUntilDone();
    
    chassis.moveToPoint(-22.5, 36.5, 5000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-11.5, 39, 5000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    pros::delay(1000);

    chassis.moveToPoint(-23, 46, 5000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-11.25, 47, 5000, {.maxSpeed = 40});
    chassis.waitUntilDone();

    pros::delay(1000);


    chassis.moveToPose(-23, 0, 135, 5000, {.lead = 0.8, .maxSpeed = 60});
    chassis.waitUntilDone();

    intake.brake();
    
}


void auton2() {
    
}


std::vector<rd::Selector::routine_t> autons = {
    {"Auton 1", auton1},
    {"Auton 2", auton2}
};
