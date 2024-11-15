#include "autons.hpp"


void auton1() {
    // lemlib docs: lemlib.readthedocs.io
    // See path.jerryio.com to see coordinates

    // Set where the robot starts from
    chassis.setPose(-34, -28, 80);

    // This will turn to the point and move in a straight line to it
    chassis.moveToPoint(0, 10, 4000);

    // This will take a curved path and end at the specified heading
    // Higher dlead means curvier
    // https://www.desmos.com/calculator/sptjw5szex see for path
    chassis.moveToPose(0, 10, 90, 4000);

    // Turn in place
    chassis.turnToHeading(90, 2000);

    // Swing turn
    chassis.swingToHeading(90, lemlib::DriveSide::LEFT, 2000);

    // Run intake at max speed for 3 seconds
    intake.move(127);
    pros::delay(3000);
    intake.brake();

    // clamp extend
    clamp.extend();

    // retract clamp
    clamp.retract();
}


void auton2() {

}


std::vector<rd::Selector::routine_t> autons = {
    {"Auton 1", auton1},
    {"Auton 2", auton2}
};
