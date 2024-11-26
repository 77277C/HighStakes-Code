#include "autons.hpp"


void red_left_after_mogo() {
    chassis.turnToPoint(-23.5, 41, 5000, {.minSpeed = 127});
    chassis.waitUntilDone();

    chassis.moveToPoint(-23.5, 41, 5000);
    chassis.waitUntil(2);
    chassis.cancelMotion();

    pros::delay(500);

    chassis.moveToPoint(-23.5, 41, 5000, {.maxSpeed = 50});
    intake->move_percentage(100);
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

    intake->move_percentage(0);
}


void red_left() {
    chassis.setPose(-55, 43.5, 270);
    chassis.moveToPose(-23.5, 25, 310, 5000, {.forwards = false, .lead = 0.5});
    chassis.waitUntil(15);
    chassis.cancelMotion();
    chassis.moveToPose(-24, 24.5, 310, 5000, {.forwards = false, .maxSpeed=30});    
    chassis.waitUntil(15);
    clamp->set_state(true);
    chassis.waitUntilDone();

    chassis.setPose(-23.5, 23.5, chassis.getPose().theta + 5);

    red_left_after_mogo();
}


void solo_awp_red_left() {
    // Do code for the solo awp and grabbing the first mogo
    red_left_after_mogo();
}


void blue_right_after_mogo() {
    chassis.turnToPoint(23.5, 41, 5000, {.minSpeed = 127});
    chassis.waitUntilDone();

    chassis.moveToPoint(23.5, 41, 5000);
    chassis.waitUntil(2);
    chassis.cancelMotion();

    pros::delay(500);

    chassis.moveToPoint(23.5, 41, 5000, {.maxSpeed = 50});
    intake->move_percentage(100);
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

    intake->move_percentage(100);
}


void blue_right() {
    chassis.setPose(55, 43.5, 90);
    chassis.moveToPose(23.5, 25, 50, 5000, {.forwards = false, .lead = 0.5});
    chassis.waitUntil(15);
    chassis.cancelMotion();
    chassis.moveToPose(24, 24.5, 50, 5000, {.forwards = false, .maxSpeed=30});    
    chassis.waitUntil(15);
    clamp->set_state(true);
    chassis.waitUntilDone();

    chassis.setPose(23.5, 23.5, chassis.getPose().theta + 5);

    blue_right_after_mogo();
}


void solo_awp_blue_right() {
    // Do code for solo AWP  and grabbing the first mogo
    blue_right_after_mogo();
}


void red_right(){
    chassis.setPose(-58.5, -35, 270);
    chassis.moveToPose(-35, -30,225, 3000, {.forwards = false, .lead = 0.6} );
    chassis.waitUntilDone();

    chassis.moveToPoint(-23, -21, 3000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntil(15);
    clamp->set_state(true);
    chassis.waitUntilDone();

    chassis.moveToPoint(-25.5, -42,3000, {.maxSpeed = 40});
    chassis.waitUntil(5);
    intake->move_percentage(100);
    chassis.waitUntilDone();

    chassis.moveToPoint(-23.5, -13, 4000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    pros::delay(1000);
    intake->move_percentage(0);

    chassis.moveToPoint(-23.5, -8, 4000, {.maxSpeed = 40});
    chassis.waitUntilDone();
}


void solo_awp_red_right() {}


void blue_left(){
    chassis.setPose(58.5, -35, 90);
    chassis.moveToPose(35, -30,135, 3000, {.forwards = false, .lead = 0.6} );
    chassis.waitUntilDone();

    chassis.moveToPoint(23, -21, 3000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntil(15);
    clamp->set_state(true);
    chassis.waitUntilDone();

    chassis.moveToPoint(25.5, -38.5,3000, {.maxSpeed = 40});
    chassis.waitUntil(8.5);
    intake->move_percentage(100);
    chassis.waitUntilDone();

    chassis.moveToPoint(23.5, -15, 4000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    pros::delay(2000);

    intake->move_percentage(0);

    chassis.moveToPoint(23.5, -9, 2500, {.maxSpeed = 40});
    chassis.waitUntilDone();
}


void solo_awp_blue_left() {}


void skills(){
    chassis.setPose(-58.5, -35, 270);
    chassis.moveToPose(-35, -30,225, 3000, {.forwards = false, .lead = 0.6} );
    chassis.waitUntilDone();

    chassis.moveToPoint(-23, -21, 3000, {.forwards = false, .maxSpeed = 30});
    chassis.waitUntil(15);
    clamp->set_state(true);
    chassis.waitUntilDone();

    chassis.moveToPoint(-25, -23, 3000,{.maxSpeed = 50});
    chassis.waitUntil(3);
    intake->move_percentage(100);
    chassis.waitUntilDone();

    chassis.moveToPoint(-24, -47, 3000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-60, -48, 5000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPoint(-42, -62, 3000, {.maxSpeed = 50});
    chassis.waitUntilDone();

    chassis.moveToPose(-67, -68, 45,6000, {.forwards = false,.lead = 0.5, .maxSpeed = 60});
    chassis.waitUntilDone();
    clamp->set_state(false);
    intake->move_percentage(0);

    chassis.moveToPoint(-74, -74, 500, {.forwards = false});
    chassis.waitUntilDone();

    chassis.moveToPoint(-45, -45, 3000);
    chassis.waitUntilDone();

    chassis.moveToPose(-47, 18.6, 3000, 0, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();

    chassis.moveToPoint(-22.6, 22.6, 3000);
    chassis.waitUntil(3);
    intake->move_percentage(100);
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
    {"Red left", red_left},
    {"Solo AWP Red left", solo_awp_red_left},
    {"Blue right", blue_right},
    {"Solo AWP Blue right", solo_awp_blue_right},
    {"Red right", red_right},
    {"Solo AWP Red right", solo_awp_red_right},
    {"Blue left", blue_left},
    {"Solo AWP Blue left", solo_awp_blue_left},
    {"Skills", skills},
};