#include "autons.hpp"
#include "subsystems/ladybrown.hpp"


void red_left_after_mogo() {
   intake.move_percentage(100);
   chassis.moveToPoint(-14, 33, 5000, {
      .maxSpeed = 90,
      .earlyExitRange = 4
   });

   chassis.moveToPose(-3.5, 55, 0, 5000, {
      .lead = 0.6,
      .maxSpeed = 60,   
      .earlyExitRange = 1
   });

   chassis.waitUntilDone();
   pros::delay(100);

   chassis.moveToPoint(-18, 52, 3000, {
       .maxSpeed = 80,
       .earlyExitRange = 1
   });
   chassis.waitUntilDone();

   pros::delay(500);

    chassis.moveToPoint(-10, 35, 3000, {
        .forwards = false,
       .maxSpeed = 80,
       .earlyExitRange = 0.5
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-43, 7, 3500, {
      .maxSpeed = 100,
   });

   chassis.waitUntil(20);
   intake_raise.set_state(true);
   chassis.cancelMotion();
   
   chassis.moveToPoint(-43, 7, 3500, {
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   intake_raise.set_state(false);
   
   pros::delay(300);
   
   chassis.moveToPoint(-41, 10, 3500, {
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-26, 0, 1000);
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
   clamp.set_state(true);
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
   chassis.setPose(-55.4, 17.5, 180);
   // score on alliance stake
   chassis.moveToPoint(-54, 10.5, 1500);
   chassis.waitUntilDone();
   chassis.turnToPoint(-70, 0, 2000);
   chassis.waitUntilDone();
   pros::delay(100);
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   pros::delay(500);
   chassis.moveToPoint(-25, 34, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(3);
   chassis.cancelMotion();
   chassis.moveToPose(-25, 21.5, 245, 4000, {
   
      .forwards = false,

      .maxSpeed = 100,
      .minSpeed = 60,
      .earlyExitRange = 4.5
   });
   chassis.waitUntil(5);
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.moveToPoint(-22, 22.5, 1500, {
      .forwards = false,
      .maxSpeed = 90,
      .minSpeed = 60
   });
   chassis.waitUntil(2);
   clamp.set_state(true);
   chassis.waitUntilDone();
   pros::delay(200);
   


   // Do code for the solo awp and grabbing the first mogo
   red_left_after_mogo();
}

void blue_right_after_mogo() {
   intake.move_percentage(100);
   chassis.moveToPoint(12, 33, 5000, {
      .maxSpeed = 90,
      .earlyExitRange = 4
   });

   chassis.moveToPose(1, 55, 0, 5000, {
      .lead = 0.6,
      .maxSpeed = 60,
      .earlyExitRange = 1
   });

   chassis.waitUntilDone();
   pros::delay(100);

   chassis.moveToPoint(16, 50, 3000, {
       .maxSpeed = 80,
       .earlyExitRange = 3
   });
   chassis.waitUntilDone();

   pros::delay(500);

    chassis.moveToPoint(10, 35, 3000, {
        .forwards = false,
       .maxSpeed = 80,
       .earlyExitRange = 0.5
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(43, 7, 3500, {
      .maxSpeed = 100,
   });

   chassis.waitUntil(20);
   intake_raise.set_state(true);
   chassis.cancelMotion();
   
   chassis.moveToPoint(43, 7, 3500, {
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   intake_raise.set_state(false);
   
   pros::delay(300);
   
   chassis.moveToPoint(41, 10, 3500, {
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(26, 0, 1000);
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
   clamp.set_state(true);
   chassis.waitUntilDone();

   chassis.setPose(23.5, 22.5, chassis.getPose().theta);

   blue_right_after_mogo();
}

void blue_right_alliance_stake() {
   chassis.setPose(53.4, 16, 180);
   // score on alliance stake
   chassis.moveToPoint(55, 9.5, 1500);
   chassis.waitUntilDone();
   chassis.turnToPoint(70, 0, 2000);
   chassis.waitUntilDone();
   pros::delay(100);
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   pros::delay(500);
   chassis.moveToPoint(25, 34, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(3);
   chassis.cancelMotion();
   chassis.moveToPose(25, 23, 115, 4000, {
   
      .forwards = false,

      .maxSpeed = 100,
      .minSpeed = 60,
      .earlyExitRange = 4.5
   });
   chassis.waitUntil(5);
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.moveToPoint(22, 24, 1500, {
      .forwards = false,
      .maxSpeed = 70,
      .minSpeed = 60
   });
   chassis.waitUntil(2);
   clamp.set_state(true);
   chassis.waitUntilDone();
   pros::delay(200);
   

   blue_right_after_mogo();
}

void red_right_after_mogo() {

}

void red_rush() {
   chassis.setPose(-62, -35, 90);

   chassis.moveToPoint(-12.5, -35.5, 3000);
   chassis.waitUntilDone();

   chassis.turnToPoint(3, -47, 1000);
   chassis.waitUntilDone();

   ladybrown.set_current_target(310);
   pros::delay(1300);

   chassis.turnToPoint(-10, -48, 1000);
   chassis.waitUntilDone();

   chassis.moveToPose(-19, -23, 120, 2500, {
      .forwards = false,
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-24, -22, 1500, {
      .forwards = false,
      .maxSpeed = 70,
      .minSpeed = 60
   });
   chassis.waitUntilDone();

   clamp.set_state(true);
   pros::delay(500);

   chassis.moveToPoint(-23, -47, 3000);
}

void red_right_alliance_stake() {}

void blue_left_after_mogo() {
   chassis.moveToPoint(23.5, -36.5, 3000, {
      .maxSpeed = 40
   });
   chassis.waitUntil(8.5);
   intake.move_percentage(100);
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

   doinker.set_state(true);
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
   doinker.set_state(false);

   chassis.moveToPoint(23.5, -9, 4000, {
      .forwards = false,
      .maxSpeed = 40
   });
   chassis.waitUntil(15);
   intake.move_percentage(0);
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

   clamp.set_state(true);
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
   clamp.set_state(true);

   blue_left_after_mogo();
}

void skills() {
   chassis.setPose(-56, 0, 270);
   chassis.moveToPoint(-50, 0, 2000, {.forwards = false});
   chassis.waitUntilDone();

   
   pros::delay(500);
   chassis.moveToPoint(-56, 0, 2000);
   chassis.waitUntilDone();

   
   
   pros::delay(700);
   chassis.moveToPoint(-50, 0, 2000, {.forwards = false});
   chassis.waitUntilDone();

   chassis.moveToPose(-50, 20, 180, 2000, {.forwards = false, .earlyExitRange = 10});
   chassis.moveToPoint(-50, 25, 2000, {.forwards = false, .maxSpeed = 40, .earlyExitRange = 2});
   chassis.waitUntilDone();
   pros::delay(100);
   clamp.set_state(true);
   pros::delay(200);

   intake.move_percentage(100);
   chassis.moveToPoint(-24, 23, 2000,{.minSpeed = 30, .earlyExitRange = 2});
   
   chassis.moveToPoint(-24, 48.5, 3000, {.minSpeed = 30, .earlyExitRange = 2});

   chassis.moveToPoint(26, 47, 3000, {.minSpeed = 30, .earlyExitRange = 3});

   chassis.moveToPoint(0, 47, 3000, { .forwards = false, .minSpeed = 30, .earlyExitRange = 1});

   
   chassis.moveToPoint(-1, 58, 3000);
   chassis.waitUntilDone();
   
   pros::delay(700);

   chassis.moveToPoint(0, 47, 3000, {.forwards = false, .earlyExitRange = 3});

   chassis.moveToPoint(-58, 47, 5000, {.earlyExitRange = 5});

   chassis.moveToPoint(-44, 60, 3000, {.earlyExitRange = 2});
   
   chassis.moveToPose(-65, 65, 135, 3000, {.forwards = false, .earlyExitRange = 2});
   clamp.set_state(false);

   chassis.moveToPoint(-70, 70, 200);
   chassis.waitUntilDone();

   chassis.moveToPose(-47, 0, 180, 6000, {.earlyExitRange = 2});

   chassis.turnToHeading(0, 3000);
   chassis.waitUntilDone();

   chassis.moveToPoint(-46, -24, 2500, {.forwards = false, .earlyExitRange = 1});
   clamp.set_state(true);
   pros::delay(200);

   chassis.moveToPoint(-23, -24, 3000, {.earlyExitRange =2});

   chassis.moveToPoint(-23, -47, 3000, {.earlyExitRange =2});
   chassis.moveToPoint(23, -47, 3000, {.earlyExitRange =2});

   chassis.moveToPoint(0, -47, 3000, {.forwards = false, .earlyExitRange =2});




   


}
void pid_tuning(){
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.moveToPoint(0, 10, 5000);
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    controller.print(0, 0, "%.2f", chassis.getPose().y);
}
std::vector<rd::Selector::routine_t> autons = {
   {"Red right", red_rush},
   {"PID", pid_tuning},
   {"Blue Right Alliance Stake", blue_right_alliance_stake},
   {"Red left", red_left},
   {"Solo AWP Red left", solo_awp_red_left},
   {"Blue right", blue_right},
   
   
   {"Red Red Alliance Stake", red_right_alliance_stake},
   {"Blue left", blue_left},
   {"Blue Left Alliance Stake", blue_left_alliance},
   {"Skills", skills},
};