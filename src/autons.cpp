#include "autons.hpp"
#include "subsystems/ladybrown.hpp"


void red_left_after_mogo() {
   intake.move_percentage(100);
   chassis.moveToPoint(-22, 33, 5000, {
      .maxSpeed = 90,
      .earlyExitRange = 4
   });

   chassis.moveToPose(-13, 52, 0, 5000, {
      .lead = 0.6,
      .maxSpeed = 60,   
      .earlyExitRange = 1
   });

   chassis.waitUntilDone();
   pros::delay(100);

   chassis.moveToPose(-23, 24, 30, 3000, {
       .forwards = false,
       .maxSpeed = 80,
       .earlyExitRange = 1
   });
   chassis.waitUntilDone();

   pros::delay(500);

    chassis.moveToPoint(-24, 48, 3000, {
       .maxSpeed = 100,
       .earlyExitRange = 0.5
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-45, 2, 3500, {
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

   chassis.moveToPoint(-29, 0, 800);
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
   chassis.setPose(-61.5, 9.5, 215);
   // score on alliance stake
   pros::delay(100);
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   pros::delay(500);
   chassis.moveToPoint(-25, 34, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(3);
   chassis.cancelMotion();
   chassis.moveToPose(-25, 21, 245, 4000, {
   
      .forwards = false,

      .maxSpeed = 100,
      .minSpeed = 60,
      .earlyExitRange = 4.5
   });
   chassis.waitUntil(5);
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.moveToPoint(-24, 21.5, 1500, {
      .forwards = false,
      .maxSpeed = 90,
      .minSpeed = 60,
      .earlyExitRange = 3
   });
   chassis.waitUntilDone();
   pros::delay(200);
   clamp.set_state(true);


   // Do code for the solo awp and grabbing the first mogo
   red_left_after_mogo();
}

void blue_right_after_mogo() {
   intake.move_percentage(100);
   chassis.moveToPoint(25, 30, 5000, {
      .maxSpeed = 90,
      .earlyExitRange = 4
   });
   intake.move_percentage(100);
   chassis.moveToPose(13, 52, 0, 5000, {
      .lead = 0.55,
      .maxSpeed = 60,   
      .earlyExitRange = 1
   });
   chassis.waitUntil(18);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(100);

   chassis.moveToPose(23, 24, 330, 3000, {
       .forwards = false,
       .maxSpeed = 80,
       .earlyExitRange = 1
   });
   
   intake.move_percentage(100);
   chassis.waitUntilDone();

   pros::delay(500);

    chassis.moveToPoint(28, 48, 3000, {
       .maxSpeed = 100,
       .earlyExitRange = 0.5
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(46, 5, 3500, {
      .maxSpeed = 100,
   });

   chassis.waitUntil(20);
   intake_raise.set_state(true);
   chassis.cancelMotion();
   
   chassis.moveToPoint(46, 5, 3500, {
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

   chassis.moveToPoint(28, 0, 800);
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
   chassis.setPose(61.5, 9.5, 145);
   // score on alliance stake
   pros::delay(100);
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   pros::delay(500);
   chassis.moveToPoint(30, 34, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(3);
   chassis.cancelMotion();
   chassis.moveToPose(28, 21, 115, 4000, {
   
      .forwards = false,

      .maxSpeed = 100,
      .minSpeed = 60,
      .earlyExitRange = 4.5
   });
   chassis.waitUntil(5);
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.moveToPoint(26.5, 21.5, 1500, {
      .forwards = false,
      .maxSpeed = 90,
      .minSpeed = 60,
      .earlyExitRange = 3
   });
   chassis.waitUntilDone();
   pros::delay(600);
   clamp.set_state(true);
   

   blue_right_after_mogo();
}

void red_right_after_mogo() {

}

void red_rush() {
   chassis.setPose(-55, -35, 90);

   chassis.moveToPoint(-10.25, -35.75, 3000);
   chassis.waitUntilDone();

   chassis.turnToPoint(2, -47, 1000);
   chassis.waitUntilDone();

   ladybrown.set_current_target(312);
   pros::delay(3000);

   chassis.turnToPoint(-17, -48, 1000);
   chassis.waitUntilDone();
   ladybrown.cycle_target();
   pros::delay(200);
   
   intake.move_percentage(100);
   chassis.moveToPoint(-24, -50, 1000);
   chassis.waitUntil(8);
   intake.move_percentage(100);
   
   chassis.waitUntilDone();
   pros::delay(200);
   intake.move_percentage(0);
   chassis.moveToPose(-24, -27, 180, 2500, {
      .forwards = false,
   });
   chassis.waitUntilDone();

   clamp.set_state(true);
   intake.move_percentage(100);
   pros::delay(500);
   intake.move_percentage(100);
   chassis.moveToPoint(-24, -49, 3000);
   chassis.waitUntilDone();
   pros::delay(3000);

   
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
      chassis.setPose(55, -35, 270);

   chassis.moveToPoint(10.25, -35.75, 3000);
   chassis.waitUntilDone();

   chassis.turnToPoint(-4, -47, 1000);
   chassis.waitUntilDone();

   ladybrown.set_current_target(315);
   pros::delay(2000);

   chassis.turnToPoint(17, -48, 1000);
   chassis.waitUntilDone();
   ladybrown.cycle_target();
   pros::delay(200);
   
   intake.move_percentage(100);
   chassis.moveToPoint(24, -50, 1000);
   chassis.waitUntil(8);
   intake.move_percentage(100);
   
   chassis.waitUntilDone();
   pros::delay(50);
   intake.move_percentage(0);
   chassis.moveToPose(24, -27, 180, 2500, {
      .forwards = false,
   });
   chassis.waitUntilDone();

   clamp.set_state(true);
   intake.move_percentage(100);
   pros::delay(500);
   intake.move_percentage(100);
   chassis.moveToPoint(24, -49, 3000);
   chassis.waitUntilDone();
   pros::delay(3000);
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
   chassis.setPose(-58, 0, 90);
   intake.move_percentage(100);
   pros::delay(500);
   intake.move_percentage(0);
   chassis.moveToPoint(-41, 0, 2000, {.earlyExitRange = 0.5});


   chassis.moveToPoint(-41.5, 28, 2000, {.forwards = false,.earlyExitRange = 2});
   chassis.moveToPoint(-41.5, 28, 2000, {.forwards = false,.maxSpeed = 70});
   chassis.waitUntilDone();
   pros::delay(100);
   clamp.set_state(true);
   pros::delay(200);

   intake.move_percentage(100);
   chassis.moveToPoint(-24, 23, 2000,{.minSpeed = 30, .earlyExitRange = 2});
   
   intake.move_percentage(95);
   chassis.moveToPoint(28, 48, 3000, {.minSpeed = 30, .earlyExitRange = 1});
   chassis.waitUntil(45);
   intake.move_percentage(95);
   ladybrown.cycle_target();
   chassis.waitUntilDone();

   pros::delay(2000);
   intake.move_percentage(100);

   chassis.moveToPoint(4, 44, 3000, { .forwards = false, .minSpeed = 30, .earlyExitRange = 1});
   
   chassis.waitUntilDone();
   intake.move_percentage(0);
   ladybrown.cycle_target();
   chassis.moveToPose(8.5, 60, 0, 3000);
   chassis.waitUntil(4);
   intake.move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(7.5, 65, 2000);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(200);
   ladybrown.cycle_target();
   chassis.moveToPoint(7, 64, 300, {.forwards = false});
   intake.move_percentage(100);
   chassis.moveToPoint(7, 65, 300, {.earlyExitRange = 0.5});



   chassis.moveToPoint(6, 47, 3000, {.forwards = false, .earlyExitRange = 3});
   chassis.waitUntil(10);
   ladybrown.cycle_target();
   intake.move_percentage(100);




   chassis.moveToPoint(-51, 47, 5000, {.earlyExitRange = 5});
   intake.move_percentage(100);
   chassis.waitUntil(5);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(1000);

   chassis.moveToPoint(-42, 60, 3000, {.earlyExitRange = 2});
   intake.move_percentage(100);
   chassis.waitUntil(5);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(1000);

   chassis.moveToPoint(-60, 65, 1500, {.forwards = false});
   chassis.waitUntilDone();
   intake.move_percentage(-100);
   pros::delay(200);
   clamp.set_state(false);
   // side 2
   chassis.moveToPose(-41, 0, 180, 6000, {.earlyExitRange = 2});

   chassis.moveToPoint(-41, -28, 2500, {.forwards = false, .earlyExitRange = 1});
   chassis.waitUntilDone();
   clamp.set_state(true);
   pros::delay(1000);

   intake.move_percentage(100);
   chassis.moveToPoint(-24, -23, 2000,{.minSpeed = 30, .earlyExitRange = 2});
   
   intake.move_percentage(100);
   chassis.moveToPoint(28, -48, 3000, {.minSpeed = 30, .earlyExitRange = 1});
   chassis.waitUntil(45);
   intake.move_percentage(100);
   ladybrown.cycle_target();
   chassis.waitUntilDone();

   pros::delay(3000);
   intake.move_percentage(100);

   chassis.moveToPoint(4, -44, 3000, { .forwards = false, .minSpeed = 30, .earlyExitRange = 1});
   
   chassis.waitUntilDone();
   intake.move_percentage(0);
   ladybrown.cycle_target();
   chassis.moveToPose(8.5, -60, 180, 3000);
   chassis.waitUntil(4);
   intake.move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(7.5, -65, 2000);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(200);
   ladybrown.cycle_target();
   chassis.moveToPoint(7, -64, 300, {.forwards = false});
   intake.move_percentage(100);
   chassis.moveToPoint(7, -65, 300, {.earlyExitRange = 0.5});



   chassis.moveToPoint(6, -47, 3000, {.forwards = false, .earlyExitRange = 3});
   ladybrown.cycle_target();
   intake.move_percentage(100);




   chassis.moveToPoint(-51, -47, 5000, {.earlyExitRange = 5});
   intake.move_percentage(100);
   chassis.waitUntil(5);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(500);

   chassis.moveToPoint(-42, -60, 3000, {.earlyExitRange = 2});
   intake.move_percentage(100);
   chassis.waitUntil(5);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(500);

   chassis.moveToPoint(-60, -65, 1500, {.forwards = false});
   chassis.waitUntilDone();
   intake.move_percentage(-100);
   pros::delay(200);
   clamp.set_state(false);




   


}
void pid_tuning(){
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    controller.print(0, 0, "%.2f", chassis.getPose().y);
    pros::delay(100);
    chassis.moveToPoint(0, 24, 5000);
    chassis.waitUntilDone();
    pros::delay(850);
    controller.print(0, 0, "%.2f", chassis.getPose().y);
}
void pid_tuning2(){
    chassis.setPose(-18, 41, 90);
    // turn to face heading 90 with a very long timeout
    
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    controller.print(0, 0, "%.2f", chassis.getPose().y);
    chassis.moveToPoint(24.8, 40.6, 3000,{.earlyExitRange = 1});
    chassis.waitUntilDone();

    chassis.moveToPose(24, -35, 270, 4000);
    chassis.waitUntilDone();

    chassis.moveToPoint(-26, -35, 4000, {.earlyExitRange = 1});

    chassis.moveToPose(-18, 41, 90, 4000);
    chassis.waitUntilDone();
    controller.print(0, 0, "%.2f", chassis.getPose().y);
}
std::vector<rd::Selector::routine_t> autons = {
   {"Red right", red_rush},
   {"Skills", skills},
   {"PID", pid_tuning},
   {"Blue Right Alliance Stake", blue_right_alliance_stake},
   {"Red left", red_left},
   {"Solo AWP Red left", solo_awp_red_left},
   {"Blue right", blue_right},
   
   
   {"Red Red Alliance Stake", red_right_alliance_stake},
   {"Blue left", blue_left},
   {"Blue Left Alliance Stake", blue_left_alliance},
   
};