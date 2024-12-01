#include "autons.hpp"


void red_left_after_mogo() {
   chassis.turnToPoint(-23.5, 41, 5000, {
      .minSpeed = 127
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-23.5, 41, 5000);
   chassis.waitUntil(2);
   chassis.cancelMotion();

   pros::delay(500);

   chassis.moveToPoint(-23.5, 41, 5000, {
      .maxSpeed = 50
   });
   intake -> move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(-22.5, 36.5, 5000, {
      .forwards = false,
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-12.5, 39, 5000, {
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   pros::delay(1000);

   chassis.moveToPoint(-23, 46, 5000, {
      .forwards = false,
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-12, 47, 5000, {
      .maxSpeed = 40
   });
   chassis.waitUntilDone();

   pros::delay(1000);

   chassis.moveToPose(-23, 25, 90, 5000, {
      .lead = 0.8,
      .maxSpeed = 60
   });
   chassis.waitUntilDone();

   intake -> move_percentage(0);
}

void red_left() {
   chassis.setPose(-55, 43.5, 270);
   chassis.moveToPose(-23.5, 25, 310, 5000, {
      .forwards = false,
      .lead = 0.5
   });
   chassis.waitUntil(15);
   chassis.cancelMotion();
   chassis.moveToPose(-24, 24.5, 310, 5000, {
      .forwards = false,
      .maxSpeed = 30
   });
   chassis.waitUntil(15);
   clamp -> set_state(true);
   chassis.waitUntilDone();

   chassis.setPose(-23.5, 23.5, chassis.getPose().theta + 5);

   red_left_after_mogo();
}

void solo_awp_red_left() {
   // Do code for the solo awp and grabbing the first mogo
   red_left_after_mogo();
}

void blue_right_after_mogo() {
   intake -> move_percentage(100);
   chassis.moveToPose(6, 62, 0, 5000, {
      .lead = 0.8,
      .earlyExitRange = 1
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(30, 44, 5000);
   chassis.waitUntilDone();

   intake -> move_percentage(0);

   chassis.moveToPose(23, 0, 225, 4200, {
      .lead = 0.8,
      .maxSpeed = 60
   });
   chassis.waitUntilDone();
}

void blue_right() {
   chassis.setPose(55, 43.5, 90);
   chassis.moveToPose(23.5, 25, 50, 5000, {
      .forwards = false,
      .lead = 0.5
   });
   chassis.waitUntil(15);
   chassis.cancelMotion();

   chassis.moveToPose(24, 24.5, 50, 5000, {
      .forwards = false,
      .maxSpeed = 60
   });
   chassis.waitUntil(15);
   clamp -> set_state(true);
   chassis.waitUntilDone();

   chassis.setPose(23.5, 23.5, chassis.getPose().theta);

   blue_right_after_mogo();
}

void blue_right_alliance_stake() {
   chassis.setPose(58.5, 11.5, 135);
   // score on alliance stake
   pros::delay(1000);

   chassis.moveToPose(24, 23.5, 135, 5000, {
      .forwards = false,
      .earlyExitRange = 3
   });
   chassis.waitUntilDone();

   chassis.moveToPose(24, 23.5, 135, 5000, {
      .forwards = false,
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   blue_right_after_mogo();
}

void red_right_after_mogo() {

}

void red_right() {
   chassis.setPose(-58.5, -35, 270);
   chassis.moveToPose(-35, -30, 225, 3000, {
      .forwards = false,
      .lead = 0.6
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-23, -21, 3000, {
      .forwards = false,
      .maxSpeed = 30
   });
   chassis.waitUntil(15);
   clamp -> set_state(true);
   chassis.waitUntilDone();

   chassis.moveToPoint(-25.5, -42, 3000, {
      .maxSpeed = 40
   });
   chassis.waitUntil(5);
   intake -> move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(-23.5, -13, 4000, {
      .maxSpeed = 60
   });
   chassis.waitUntilDone();
   pros::delay(1000);
   intake -> move_percentage(0);

   chassis.moveToPoint(-23.5, -8, 4000, {
      .maxSpeed = 40
   });
   chassis.waitUntilDone();
}

void red_right_alliance_stake() {}

void blue_left_after_mogo() {
   chassis.moveToPoint(23.5, -36.5, 3000, {
      .maxSpeed = 40
   });
   chassis.waitUntil(8.5);
   intake -> move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(30.5, -40, 4000, {
      .forwards = false,
      .maxSpeed = 60
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(15, -45, 3000, {
      .maxSpeed = 40
   });
   chassis.waitUntilDone();
   pros::delay(200);

   doinker -> set_state(true);
   pros::delay(400);

   chassis.moveToPoint(40, -43, 4000, {
      .forwards = false,
      .maxSpeed = 60
   });
   chassis.waitUntil(22);
   chassis.cancelMotion();

   chassis.turnToPoint(50, -62, 4000, {
      .maxSpeed = 90
   });
   chassis.waitUntilDone();
   doinker -> set_state(false);

   chassis.moveToPoint(23.5, -9, 4000, {
      .forwards = false,
      .maxSpeed = 40
   });
   chassis.waitUntil(15);
   intake -> move_percentage(0);
   chassis.waitUntilDone();
}

void blue_left() {
   chassis.setPose(53.6, -32, 90);

   chassis.moveToPose(26, -25, 135, 3000, {
      .forwards = false,
      .earlyExitRange = 3
   });
   chassis.moveToPoint(26, -25, 1000, {
      .forwards = false,
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   clamp -> set_state(true);
   pros::delay(50);

   blue_left_after_mogo();
}

void blue_left_alliance() {
   chassis.setPose(58.5, -11.5, 45);
   // score on alliance stake
   pros::delay(1000);

   chassis.moveToPose(27.3, -21.35, 55, 3000, {
      .forwards = false,
      .lead = 0.2,
      .maxSpeed = 70
   });
   chassis.waitUntilDone();
   clamp -> set_state(true);

   blue_left_after_mogo();
}

void skills() {
   chassis.setPose(-58.5, -35, 270);
   chassis.moveToPose(-35, -30, 225, 3000, {
      .forwards = false,
      .lead = 0.6
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-23, -21, 3000, {
      .forwards = false,
      .maxSpeed = 30
   });
   chassis.waitUntil(15);
   clamp -> set_state(true);
   chassis.waitUntilDone();

   chassis.moveToPoint(-25, -23, 3000, {
      .maxSpeed = 50
   });
   chassis.waitUntil(3);
   intake -> move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(-24, -47, 3000, {
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-60, -48, 5000, {
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-42, -62, 3000, {
      .maxSpeed = 50
   });
   chassis.waitUntilDone();

   chassis.moveToPose(-67, -68, 45, 6000, {
      .forwards = false,
      .lead = 0.5,
      .maxSpeed = 60
   });
   chassis.waitUntilDone();
   clamp -> set_state(false);
   intake -> move_percentage(0);

   chassis.moveToPoint(-74, -74, 500, {
      .forwards = false
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-45, -45, 3000);
   chassis.waitUntilDone();

   chassis.moveToPose(-47, 18.6, 3000, 0, {
      .forwards = false,
      .maxSpeed = 60
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-22.6, 22.6, 3000);
   chassis.waitUntil(3);
   intake -> move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(-22.3, 42.8, 4000, {
      .maxSpeed = 70
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-47, 47, 4000, {
      .maxSpeed = 70
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-60, 47, 4000, {
      .maxSpeed = 70
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-47, 58.5, 4000, {
      .maxSpeed = 70
   });
   chassis.waitUntilDone();

}

std::vector<rd::Selector::routine_t> autons = {
   {"Red left", red_left},
   {"Solo AWP Red left", solo_awp_red_left},
   {"Blue right", blue_right},
   {"Blue Right Alliance Stake", blue_right_alliance_stake},
   {"Red right", red_right},
   {"Red Red Alliance Stake", red_right_alliance_stake},
   {"Blue left", blue_left},
   {"Blue Left Alliance Stake", blue_left_alliance},
   {"Skills", skills},
};