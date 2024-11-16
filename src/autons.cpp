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

    chassis.moveToPoint(-11, 47, 5000, {.maxSpeed = 40});
    chassis.waitUntilDone();

    pros::delay(1000);


    chassis.moveToPose(-23, 0, 135, 5000, {.lead = 0.8, .maxSpeed = 60});
    chassis.waitUntilDone();

    intake.brake();
    
}


void auton2() {
    chassis.setPose(55, 43.5, 90);
    chassis.moveToPose(23.5, 25, 50, 5000, {.forwards = false, .lead = 0.5});
    chassis.waitUntil(15);
    chassis.cancelMotion();
    chassis.moveToPose(24, 24.5, 50, 5000, {.forwards = false, .maxSpeed=30});    
    chassis.waitUntil(15);
    clamp.extend();
    chassis.waitUntilDone();

    chassis.setPose(23.5, 23.5, chassis.getPose().theta + 5);

    chassis.turnToPoint(23.5, 41, 5000, {.minSpeed = 127});
    chassis.waitUntilDone();
    
    chassis.moveToPoint(23.5, 41, 5000);
    chassis.waitUntil(2);
    chassis.cancelMotion();

    pros::delay(500);

    chassis.moveToPoint(23.5, 41, 5000, {.maxSpeed = 50});
    intake.move(127);
    chassis.waitUntilDone();
    
    chassis.moveToPoint(22.5, 36.5, 5000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(11.5, 39, 5000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    pros::delay(800);

    chassis.moveToPoint(24, 48, 5000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(11.5, 51, 5000, {.maxSpeed = 40});
    chassis.waitUntilDone();

    pros::delay(800);


    chassis.moveToPose(23, 0, 225, 4200, {.lead = 0.8, .maxSpeed = 60});
    chassis.waitUntilDone();

    intake.brake();
}
void auton3(){
    chassis.setPose(-58.5, -35, 270);
    chassis.moveToPose(-35, -30,225, 3000, {.forwards = false, .lead = 0.6} );
    chassis.waitUntilDone();

    chassis.moveToPoint(-23, -21, 3000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntil(15);
    clamp.extend();
    chassis.waitUntilDone();

    chassis.moveToPoint(-25.5, -42,3000, {.maxSpeed = 40});
    chassis.waitUntil(5);
    intake.move(127);
    chassis.waitUntilDone();

    chassis.moveToPoint(-23.5, -13, 4000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    pros::delay(1000);
    intake.move(125);
    intake.brake();

    chassis.moveToPoint(-23.5, -8, 4000, {.maxSpeed = 40});
    chassis.waitUntilDone();
}
void auton4(){
    chassis.setPose(58.5, -35, 90);
    chassis.moveToPose(35, -30,135, 3000, {.forwards = false, .lead = 0.6} );
    chassis.waitUntilDone();

    chassis.moveToPoint(23, -21, 3000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntil(15);
    clamp.extend();
    chassis.waitUntilDone();

    chassis.moveToPoint(25.5, -38.5,3000, {.maxSpeed = 40});
    chassis.waitUntil(8.5);
    intake.move(127);
    chassis.waitUntilDone();

    chassis.moveToPoint(23.5, -15, 4000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    pros::delay(1000);

    chassis.moveToPoint(23.5, -20, 4000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    pros::delay(1500);
    chassis.moveToPoint(23.5, -15, 4000, {.maxSpeed = 80});
    chassis.waitUntilDone();
    
    intake.move(125);
    intake.brake();

    chassis.moveToPoint(23.5, -9, 2500, {.maxSpeed = 40});
    chassis.waitUntilDone();
}


std::vector<rd::Selector::routine_t> autons = {
    {"4 ring Red", auton1},
    {"4 ring Blue", auton2},
    {"2 ring Red", auton3},
    {"2 ring Blue", auton4}
};
