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

    chassis.moveToPoint(-12.5, 39, 5000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    pros::delay(1000);

    chassis.moveToPoint(-23, 46, 5000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-12, 47, 5000, {.maxSpeed = 40});
    chassis.waitUntilDone();

    pros::delay(1000);


    chassis.moveToPose(-23, 25, 90, 5000, {.lead = 0.8, .maxSpeed = 60});
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

    chassis.moveToPoint(12.5, 39, 5000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    pros::delay(800);

    chassis.moveToPoint(24, 48, 5000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(13.5, 51, 5000, {.maxSpeed = 40});
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
    pros::delay(2000);
    
    intake.move(125);
    intake.brake();

    chassis.moveToPoint(23.5, -9, 2500, {.maxSpeed = 40});
    chassis.waitUntilDone();
}

void auton5(){
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();
}
void auton6(){
    chassis.setPose(-58.5, -35, 270);
    chassis.moveToPose(-35, -30,225, 3000, {.forwards = false, .lead = 0.6} );
    chassis.waitUntilDone();

    chassis.moveToPoint(-23, -21, 3000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntil(15);
    clamp.extend();
    chassis.waitUntilDone();

    chassis.moveToPoint(-25, -23, 3000,{.maxSpeed = 50});
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntilDone();

    chassis.moveToPoint(-24, -47, 3000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-60, -48, 5000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-42, -62, 3000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPose(-67, -68, 45,6000, {.forwards = false,.lead = 0.5, .maxSpeed = 60});
    chassis.waitUntilDone();
    clamp.retract();
    intake.brake();

    chassis.moveToPoint(-74, -74, 500, {.forwards = false});
    chassis.waitUntilDone();

    chassis.moveToPoint(-45, -45, 3000);
    chassis.waitUntilDone();

    chassis.moveToPose(-47, 18.6, 3000, 0, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();

    chassis.moveToPoint(-22.6, 22.6, 3000);
    chassis.waitUntil(3);
    intake.move(127);
    chassis.waitUntilDone();

    chassis.moveToPoint(-22.3, 42.8, 4000, {.maxSpeed = 70});
    chassis.waitUntilDone();

    chassis.moveToPoint(-47, 47, 4000, {.maxSpeed = 70});
    chassis.waitUntilDone();

    chassis.moveToPoint(-60, 47, 4000, {.maxSpeed = 70});
    chassis.waitUntilDone();

    chassis.moveToPoint(-47, 58.5, 4000, {.maxSpeed = 70});
    chassis.waitUntilDone();

}


std::vector<rd::Selector::routine_t> autons = {
    {"4 ring Red", auton1},
    {"4 ring Blue", auton2},
    {"2 ring Red", auton3},
    {"2 ring Blue", auton4},
    {"angular tune", auton5},
    {"SKILLS", auton6},
};
