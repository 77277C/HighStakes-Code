#include "autons.hpp"
#include "subsystems/ladybrown.hpp"




/**
 * Call this function to set the PID constants to no mogo constants
 * DO NOT MODIFY THIS FUNCTION. IT EXTRACTS THE CONSTANTS FROM main.cpp
 */
void no_mogo_pid_constants() {
   // Set the lateral pid constants of the original PID controller settings
   // the original PID controllers settings is tuned for no mogo
   chassis.lateralPID.kP = lateral_controller.kP;
   chassis.lateralPID.kI = lateral_controller.kI;
   chassis.lateralPID.kD = lateral_controller.kD;

   // Set the angular consants
   chassis.angularPID.kP = angular_controller.kP;
   chassis.angularPID.kI = angular_controller.kI;
   chassis.angularPID.kD = angular_controller.kD;
}


/**
 * Call this function to set PID constants to empty mogo constants
 */
void empty_mogo_pid_constants() {
   // Set the lateral constants (modify when tuning)
   chassis.lateralPID.kP = 1;
   chassis.lateralPID.kI = 1;
   chassis.lateralPID.kD = 1;

   // Set the angular constants (modify when tuning)
   chassis.angularPID.kP = 1;
   chassis.angularPID.kI = 1;
   chassis.angularPID.kD = 1;
}

/*
void red_left_after_mogo() {
   intake.move_percentage(100);
   chassis.moveToPoint(-22, 33, 5000, {
      .maxSpeed = 90,
      .earlyExitRange = 4
   });

   chassis.moveToPose(-16, 50, 0, 5000, {
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

    chassis.moveToPoint(-30, 49, 3000, {
       .maxSpeed = 100,
       .earlyExitRange = 0.5
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-56, 2, 3500, {
      .maxSpeed = 100,
   });

   chassis.waitUntil(20);
   intake_raise.set_state(true);
   chassis.cancelMotion();
   
   chassis.moveToPoint(-56, 7, 3500, {
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   intake_raise.set_state(false);
   
   pros::delay(1000);
   
   chassis.moveToPoint(-56, 15, 3500, {
      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   pros::delay(1000);
   chassis.moveToPoint(-29, 0, 800);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   intake.move_percentage(100);
   pros::delay(2000);
}

void red_left() {
   chassis.setPose(-51, 36, 310);
   chassis.moveToPoint(-23.5, 14,5000, {
      .forwards = false
   });
   chassis.waitUntil(15);
   chassis.cancelMotion();
   chassis.moveToPoint(-23.5, 14,5000, {
      .forwards = false
   });
   chassis.waitUntilDone();
   clamp.set_state(true);


   chassis.setPose(-35, 27.5, chassis.getPose().theta);
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
   chassis.moveToPose(-25, 23.5, 245, 4000, {
   
      .forwards = false,

      .maxSpeed = 100,
      .minSpeed = 60,
      .earlyExitRange = 4.5
   });
   chassis.waitUntil(5);
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.moveToPoint(-24, 23.5, 1500, {
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
      .minSpeed = 80,
      .earlyExitRange = 4
   });
   intake.move_percentage(100);
   chassis.moveToPose(14.5, 58, 0, 5000, {
      .lead = 0.55,
      .maxSpeed = 100,
      .minSpeed = 80,   
      .earlyExitRange = 1
   });
   chassis.waitUntil(18);
   intake.move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPose(20, 32, 335, 2000, {
       .forwards = false,
       .maxSpeed = 100,
       .minSpeed = 80,
       .earlyExitRange = 5
   });
   
   intake.move_percentage(100);

    chassis.moveToPoint(30.5, 46, 3000, {
       .minSpeed = 80,
       .earlyExitRange = 0.5,
   });

   chassis.waitUntilDone();
   //chassis.moveToPoint(68, 67, 2500);
   //chassis.waitUntilDone();
   intake.move_percentage(100);
   

   //chassis.moveToPoint(50, 50, 3000, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});

   chassis.moveToPoint(55, 5, 3500, {
      .minSpeed = 110,
   });

   chassis.waitUntil(20);
   intake_raise.set_state(true);
   chassis.cancelMotion();
   
   chassis.moveToPoint(57, 7.5, 3500, {
      .maxSpeed = 60,
   });
   chassis.waitUntilDone();

   intake_raise.set_state(false);
   
   pros::delay(300);
   
   chassis.moveToPoint(57, 7.5, 3500, {
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntilDone();
   intake.move_percentage(100);
   chassis.moveToPoint(74, 69, 3500);
   chassis.waitUntilDone();
   intake.move_percentage(100);
   pros::delay(400);
   chassis.moveToPoint(50, 50, 3500, {.forwards = false});
   intake.move_percentage(100);
   
   chassis.moveToPoint(63, -44, 5000);
   chassis.waitUntilDone();
   pros::delay(2000);
}

void blue_right() {
   chassis.setPose(51, 36, 50);
   chassis.moveToPoint(23.5, 14,5000, {
      .forwards = false
   });
   chassis.waitUntil(15);
   chassis.cancelMotion();
   chassis.moveToPoint(23.5, 14,5000, {
      .forwards = false
   });
   chassis.waitUntilDone();
   clamp.set_state(true);


   chassis.setPose(34, 27.5, chassis.getPose().theta);  

   blue_right_after_mogo();
}

void blue_right_alliance_stake() {
   chassis.setPose(58, 12, 145);
   // score on alliance stake
   pros::delay(100);

   chassis.moveToPoint(61, 9, 700);
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   chassis.waitUntilDone();

   pros::delay(300);
   chassis.moveToPoint(30, 34, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(3);
   chassis.cancelMotion();
   chassis.moveToPose(28, 22, 115, 4000, {
   
      .forwards = false,

      .maxSpeed = 100,
      .minSpeed = 65,
      .earlyExitRange = 4.5
   });
   chassis.waitUntil(5);
   ladybrown.set_current_target(LadyBrown::AWAY);
    
   chassis.moveToPoint(26.5, 22.5, 1500, {
      .forwards = false,
      .maxSpeed = 90,
      .minSpeed = 65,
      .earlyExitRange = 3
   });
   chassis.waitUntilDone();
   pros::delay(300);
   clamp.set_state(true);
   

   blue_right_after_mogo();
}
void blue_safe(){
   chassis.setPose(54.5, 16.5, 130);
   // score on alliance stake
   pros::delay(100);
   chassis.moveToPoint(56.5, 10, 2000);
   chassis.waitUntilDone();
   pros::delay(200);
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   pros::delay(1300);
   chassis.moveToPoint(30, 27, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(5);
   
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.waitUntil(25);
   chassis.cancelMotion();
   

   chassis.moveToPoint(24, 30, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();
   clamp.set_state(true);
   intake.move_percentage(100);
   // Do code for the solo awp and grabbing the first mogo
   chassis.moveToPoint(22, 54, 5000, {
   
      .maxSpeed = 80,
   });

   chassis.waitUntilDone();

   chassis.moveToPoint(30, 50, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();

   chassis.moveToPoint(9, 54, 5000, {
   
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();
   pros::delay(1000);

   chassis.moveToPoint(30, 50, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();
   chassis.moveToPoint(45, 0, 5000, {
   
      .maxSpeed = 75,
   });
   chassis.waitUntil(10);

   intake_raise.set_state(true);
   chassis.waitUntilDone();
   intake_raise.set_state(false);

   chassis.moveToPoint(28, 22, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(15, 15, 5000, {
   
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();

   ladybrown.cycle_target();
   ladybrown.cycle_target();
   pros::delay(2000);
}
void red_safe() {
   chassis.setPose(-54.5, 16.5, 225);
   // score on alliance stake
   pros::delay(100);
   chassis.moveToPoint(-58, 13, 2000);
   chassis.waitUntilDone();
   ladybrown.set_current_target(LadyBrown::BOTTOM);
   pros::delay(1000);
   chassis.moveToPoint(-30, 30, 5000, {
   
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntil(5);
   
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.waitUntilDone();
    
   chassis.waitUntil(25);
   chassis.cancelMotion();
   

   chassis.moveToPoint(-26, 34, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();
   clamp.set_state(true);
   intake.move_percentage(100);
   // Do code for the solo awp and grabbing the first mogo
   chassis.moveToPoint(-30, 54, 5000, {
   
      .maxSpeed = 80,
   });

   chassis.waitUntilDone();

   chassis.moveToPoint(-30, 50, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();

   chassis.moveToPoint(-12, 55, 5000, {
   
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();
   pros::delay(1000);

   chassis.moveToPoint(-30, 50, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();
   chassis.moveToPoint(-45, 0, 5000, {
   
      .maxSpeed = 50,
   });
   chassis.waitUntil(10);

   intake_raise.set_state(true);
   chassis.waitUntilDone();
   intake_raise.set_state(false);

   chassis.moveToPoint(-28, 22, 5000, {
   
      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   chassis.moveToPoint(-15, 15, 5000, {
   
      .maxSpeed = 50,
   });

   chassis.waitUntilDone();

   ladybrown.cycle_target();
   ladybrown.cycle_target();
   pros::delay(2000);

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
void score_alliance(){
   //chassis.setPose(65, 0, 90);
   chassis.moveToPoint(51, 0, 2000, {.forwards = false, .maxSpeed = 36, .earlyExitRange = 4});

   ladybrown.cycle_bottom_target();
   ladybrown.cycle_bottom_target();
   chassis.moveToPoint(65, 55, 3000);
   intake_raise.set_state(true);
   ladybrown.cycle_target();
   chassis.waitUntilDone();
}
void skills() {
   chassis.setPose(-58, 0, 90);
   intake.move_percentage(100);
   intake.move_percentage(0, IntakeMotors::FRONT);
   pros::delay(500);
   intake.move_percentage(0);
   chassis.moveToPoint(-43, 0, 2000, {.earlyExitRange = 0.5});


   chassis.moveToPoint(-43, 28, 2000, {.forwards = false,.earlyExitRange = 2});
   chassis.moveToPoint(-43, 28, 2000, {.forwards = false,.maxSpeed = 70});
   chassis.waitUntilDone();
   pros::delay(100);
   clamp.set_state(true);
   pros::delay(200);

   intake.move_percentage(100);
   chassis.moveToPoint(-24, 23, 1500,{.minSpeed = 70, .earlyExitRange = 2});
   
   intake.move_percentage(100);
   chassis.moveToPoint(24, 46, 3000, {.minSpeed = 70});
   chassis.waitUntil(45);
   intake.move_percentage(100);
   ladybrown.cycle_target();
   chassis.waitUntilDone();

   pros::delay(700);
   intake.move_percentage(100);

   chassis.moveToPoint(4, 44, 3000, { .forwards = false, .minSpeed = 70, .earlyExitRange = 1});
   
   chassis.waitUntilDone();
   intake.move_percentage(100);
   chassis.moveToPose(7.5, 60, 0, 2500, {.earlyExitRange = 0.5});
   chassis.waitUntil(6);

   intake.move_percentage(0, IntakeMotors::HOOKS);

   chassis.moveToPoint(6.5, 65, 700);
   intake.move_percentage(100, IntakeMotors::FRONT);
   chassis.waitUntilDone();
   
   // score
   ladybrown.cycle_target();
   ladybrown.cycle_target();
   pros::delay(500);

   chassis.moveToPoint(6, 47, 3000, {.forwards = false, .earlyExitRange = 3});
   chassis.waitUntil(10);
   ladybrown.cycle_target();
   intake.move_percentage(100);




   chassis.moveToPoint(-51, 47, 5000, {.earlyExitRange = 5});
   intake.move_percentage(100);
   chassis.waitUntil(5);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(800);

   chassis.moveToPoint(-42, 60, 3000, {.earlyExitRange = 2});
   intake.move_percentage(100);
   chassis.waitUntil(5);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(800);

   chassis.moveToPoint(-60, 65, 1500, {.forwards = false});
   chassis.waitUntilDone();
   intake.move_percentage(-100);
   pros::delay(300);
   clamp.set_state(false);
   // SIDE 2
   //goes under



   chassis.moveToPoint(6, -3, 4000, {.minSpeed = 70});
   intake.move_percentage(100, IntakeMotors::FRONT);
   chassis.waitUntilDone();
   pros::delay(500);

   chassis.moveToPoint(-37, -24,  2500, {.forwards = false,  .earlyExitRange = 8});
   chassis.moveToPoint(-50, -33, 800, {.forwards = false, .maxSpeed = 50});
   chassis.waitUntilDone();
   clamp.set_state(true);
   
   pros::delay(200);
   intake.move_percentage(100);
   pros::delay(400);

   chassis.moveToPose(6.5, -59, 180, 3000, {.lead = 0.6});
   chassis.waitUntil(15);
   ladybrown.cycle_target();

   intake.move_percentage(100);
   chassis.moveToPoint(5.5, -68, 2000);
   intake.move_percentage(100, IntakeMotors::FRONT);
   pros::delay(500);
   
   intake.move_percentage(0, IntakeMotors::HOOKS);
   ladybrown.set_current_target(235);
   pros::delay(1500);



   chassis.moveToPoint(5, -47, 3000, {.forwards = false, .earlyExitRange = 3});
   ladybrown.cycle_target();
   intake.move_percentage(100);
   intake.move_percentage(100, IntakeMotors::FRONT);




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
   chassis.moveToPoint(-54, -58, 1000);
   chassis.waitUntil(4);
   chassis.cancelMotion();

   // PART THREE

   chassis.moveToPose(28, -24, 0, 15000, {.lead = 0.67, .minSpeed = 80, .earlyExitRange = 1});
   chassis.waitUntil(40);
   intake.move_percentage(100, IntakeMotors::FRONT);
   chassis.waitUntil(40);
   intake.move_percentage(20);
   intake.move_percentage(100, IntakeMotors::FRONT);
   chassis.waitUntilDone();

   chassis.moveToPoint(35, -12, 5000, {.forwards = false, .minSpeed = 70});
   chassis.waitUntilDone();

   chassis.moveToPoint(52, -4, 3000, {.forwards = false, .maxSpeed = 40});
   chassis.waitUntilDone();
   clamp.set_state(true);
   pros::delay(500);

   chassis.moveToPoint(49, -55, 4000);
   intake.move_percentage(100);
   chassis.waitUntilDone();

   chassis.moveToPoint(49, -47, 4000, {.forwards = false, .earlyExitRange = 1});

   chassis.moveToPoint(60, -47, 4000);
   intake.move_percentage(100);
   chassis.waitUntilDone();
   pros::delay(300);

   chassis.moveToPoint(62, -60, 4000, {.forwards = false});
   chassis.waitUntilDone();

   clamp.set_state(false);
   intake.move_percentage(-100);
   pros::delay(200);
   

   chassis.moveToPose(25, 22.5,330, 5000);
   intake.move_percentage(100); 
   chassis.waitUntil(20);
   ladybrown.cycle_target();
   chassis.waitUntilDone();

   pros::delay(500);
   chassis.turnToPoint(42, 0, 2000, {.earlyExitRange = 2});

   chassis.moveToPose(60, -4, 90, 3500, {.earlyExitRange = 1});

   chassis.moveToPoint(68, -4, 1000);

   chassis.waitUntilDone();

   score_alliance();

   chassis.moveToPoint(20, 20, 4000, {.forwards = false, .minSpeed = 75, .earlyExitRange = 5});
   chassis.waitUntil(10);
   ladybrown.set_current_target(235);
   chassis.moveToPoint(0, 0, 2000, {.forwards = false, .maxSpeed = 40});

   chassis.waitUntilDone();
   ladybrown.set_current_target(70);









   


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

*/
std::vector<rd::Selector::routine_t> autons = {
   /*
   {"Red Safe", red_safe},
   {"Blue Safe", blue_safe},
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
   */
};