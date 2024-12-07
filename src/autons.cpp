#include "autons.hpp"


void red_left_after_mogo() {
    intake -> move_percentage(100);
   chassis.moveToPose(0, 56, 0, 5000, {
      .lead = 0.7,
      .maxSpeed = 110,
      .earlyExitRange = 5
   });

   chassis.moveToPose(0, 56, 0, 5000, {
      .lead = 0.7,
      .maxSpeed = 70,
      .earlyExitRange = 1
   });

   pros::delay(1000);

   chassis.moveToPoint(-15, 50, 5000, {
       .maxSpeed = 80,
   });
   chassis.waitUntilDone();

   pros::delay(400);

    chassis.moveToPoint(-10, 44, 5000, {
        .forwards = false,
       .maxSpeed = 80
   });
   chassis.waitUntilDone();

   chassis.moveToPose(-20, 11, 180, 3500, {
      .maxSpeed = 60
   });
   chassis.waitUntil(25);
   intake -> move_percentage(0);
   chassis.waitUntilDone();
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

   chassis.setPose(-23.5, 22.5, chassis.getPose().theta);
    chassis.turnToHeading(360, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-23.5, 28, 2000, {.maxSpeed = 80});
    chassis.waitUntilDone();
    chassis.setPose(-16.5, 30, chassis.getPose().theta);
   red_left_after_mogo();
}

void solo_awp_red_left() {
   chassis.setPose(-53.5, 17, 270);
   // score on alliance stake
   chassis.moveToPoint(-51.5, 17, 1000, {.earlyExitRange = 0.5});
   wall_stakes->set_state(true);
   pros::delay(200);
   chassis.turnToHeading(223, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-59.5, 8.8, 2000, {.maxSpeed = 80});
   chassis.waitUntilDone();
   wall_stakes->set_state(false);
   pros::delay(500);
   chassis.moveToPoint(-48, 22, 2000, {.forwards = false});
   chassis.waitUntilDone();
   chassis.moveToPose(-19, 24, 245, 4000, {
   
      .forwards = false,
      .maxSpeed = 100,
      .earlyExitRange = 3
   });

   chassis.waitUntilDone();
    clamp->set_state(true);
    pros::delay(100);
    
    chassis.moveToPose(-17, 29, 285, 1500, {
      .forwards = false,
      .maxSpeed = 50
   });
   
   chassis.waitUntilDone();
   chassis.setPose(-12, 30, chassis.getPose().theta);

   // Do code for the solo awp and grabbing the first mogo
   red_left_after_mogo();
}

void blue_right_after_mogo() {
   intake -> move_percentage(100);
   chassis.moveToPose(0, 57, 0, 5000, {
      .lead = 0.7,
      .maxSpeed = 110,
      .earlyExitRange = 5
   });

   chassis.moveToPose(0, 57, 0, 2000, {
      .lead = 0.7,
      .maxSpeed = 70,
      .earlyExitRange = 1
   });

   pros::delay(1000);

   chassis.moveToPoint(15, 50.5, 3000, {
       .maxSpeed = 80,
       .earlyExitRange = 2
   });
   chassis.waitUntilDone();

   pros::delay(500);

    chassis.moveToPoint(10, 44, 3000, {
        .forwards = false,
       .maxSpeed = 80,
       .earlyExitRange = 0.5
   });
   chassis.waitUntilDone();

   chassis.moveToPose(20, 8, 180, 3500, {
      .maxSpeed = 60
   });
   chassis.waitUntil(10);
   intake -> move_percentage(0);
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

   chassis.setPose(23.5, 22.5, chassis.getPose().theta);

   blue_right_after_mogo();
}

void blue_right_alliance_stake() {
   chassis.setPose(53.5, 17, 90);
   // score on alliance stake
   chassis.moveToPoint(51.5, 17, 1000, {.earlyExitRange = 0.5});
   wall_stakes->set_state(true);
   pros::delay(200);
   chassis.turnToHeading(137, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(60, 10.4, 2000, {.maxSpeed = 80});
   chassis.waitUntilDone();
   wall_stakes->set_state(false);
   pros::delay(500);
   chassis.moveToPoint(48, 22, 2000, {.forwards = false});
   chassis.waitUntilDone();
   chassis.moveToPose(18, 26, 105, 4000, {
   
      .forwards = false,
      .maxSpeed = 100,
      .earlyExitRange = 3
   });

   chassis.waitUntilDone();
    clamp->set_state(true);
    pros::delay(100);
    
    chassis.moveToPose(17, 29, 75, 1500, {
      .forwards = false,
      .maxSpeed = 50
   });
   
   chassis.waitUntilDone();
   chassis.setPose(15, 29, chassis.getPose().theta);

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
   chassis.setPose(-56, 0, 270);
   chassis.moveToPoint(-50, 0, 2000, {.forwards = false});
   chassis.waitUntilDone();

   wall_stakes->set_state(true);
   pros::delay(500);
   chassis.moveToPoint(-56, 0, 2000);
   chassis.waitUntilDone();

   
   wall_stakes->set_state(false);
   pros::delay(700);
   chassis.moveToPoint(-50, 0, 2000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPose(-50, 20, 180, 2000, {.forwards = false, .earlyExitRange = 10});
   chassis.moveToPoint(-50, 25, 2000, {.forwards = false, .maxSpeed = 40, .earlyExitRange = 2});
   chassis.waitUntilDone();
   pros::delay(100);
   clamp->set_state(true);
   pros::delay(200);

   intake->move_percentage(100);
   chassis.moveToPoint(-24, 23, 2000,{.minSpeed = 30, .earlyExitRange = 2});
   
   chassis.moveToPoint(-24, 48.5, 3000, {.minSpeed = 30, .earlyExitRange = 2});

   chassis.moveToPoint(26, 47, 3000, {.minSpeed = 30, .earlyExitRange = 3});

   chassis.moveToPoint(0, 47, 3000, { .forwards = false, .minSpeed = 30, .earlyExitRange = 1});

   intake->redirect_next_ring();
   wall_stakes->set_state(true);
   chassis.moveToPoint(-1, 58, 3000);
   chassis.waitUntilDone();
   wall_stakes->set_state(false);
   pros::delay(700);

   chassis.moveToPoint(0, 47, 3000, {.forwards = false, .earlyExitRange = 3});

   chassis.moveToPoint(-58, 47, 5000, {.earlyExitRange = 5});

   chassis.moveToPoint(-44, 60, 3000, {.earlyExitRange = 2});
   
   chassis.moveToPose(-65, 65, 135, 3000, {.forwards = false, .earlyExitRange = 2});
   clamp->set_state(false);

   chassis.moveToPoint(-70, 70, 200);
   chassis.waitUntilDone();

   chassis.moveToPose(-47, 0, 180, 6000, {.earlyExitRange = 2});

   chassis.turnToHeading(0, 3000);
   chassis.waitUntilDone();

   chassis.moveToPoint(-46, -24, 2500, {.forwards = false, .earlyExitRange = 1});
   clamp->set_state(true);
   pros::delay(200);

   chassis.moveToPoint(-23, -24, 3000, {.earlyExitRange =2});

   chassis.moveToPoint(-23, -47, 3000, {.earlyExitRange =2});
   intake->redirect_next_ring();
   chassis.moveToPoint(23, -47, 3000, {.earlyExitRange =2});

   chassis.moveToPoint(0, -47, 3000, {.forwards = false, .earlyExitRange =2});




   


}
void pid_tuning(){
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.moveToPoint(0, 10, 10000);
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