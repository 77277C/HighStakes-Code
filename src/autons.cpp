#include "autons.hpp"
#include "subsystems/ladybrown.hpp"




/**
 * Call this function to set the PID constants to no mogo constants
 * DO NOT MODIFY THIS FUNCTION. IT EXTRACTS THE CONSTANTS FROM main.cpp
 */
void no_mogo_pid_constants() {
   // Set the lateral pid constants of the original PID controller settings
   // the original PID controllers settings is tuned for no mogohey
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


void red_left_after_mogo() {
   intake.move_percentage(100, TIMEOUT_MAX);
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
   chassis.cancelMotion();

   chassis.moveToPoint(-56, 7, 3500, {
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();



   pros::delay(1000);

   chassis.moveToPoint(-56, 15, 3500, {
      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();

   pros::delay(1000);
   chassis.moveToPoint(-29, 0, 800);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   intake.move_percentage(100, TIMEOUT_MAX);
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
   ladybrown.set_current_target(330);
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
   ladybrown.set_current_target(71.5);
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
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(25, 30, 5000, {
      .maxSpeed = 90,
      .minSpeed = 80,
      .earlyExitRange = 4
   });
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPose(14.5, 58, 0, 5000, {
      .lead = 0.55,
      .maxSpeed = 100,
      .minSpeed = 80,
      .earlyExitRange = 1
   });
   chassis.waitUntil(18);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();

   chassis.moveToPose(20, 32, 335, 2000, {
       .forwards = false,
       .maxSpeed = 100,
       .minSpeed = 80,
       .earlyExitRange = 5
   });

   intake.move_percentage(100, TIMEOUT_MAX);

    chassis.moveToPoint(30.5, 46, 3000, {
       .minSpeed = 80,
       .earlyExitRange = 0.5,
   });

   chassis.waitUntilDone();
   //chassis.moveToPoint(68, 67, 2500);
   //chassis.waitUntilDone();
   intake.move_percentage(100, TIMEOUT_MAX);


   //chassis.moveToPoint(50, 50, 3000, {.forwards = false, .minSpeed = 70, .earlyExitRange = 3});

   chassis.moveToPoint(55, 5, 3500, {
      .minSpeed = 110,
   });

   chassis.waitUntil(20);

   chassis.cancelMotion();

   chassis.moveToPoint(57, 7.5, 3500, {
      .maxSpeed = 60,
   });
   chassis.waitUntilDone();


   pros::delay(300);

   chassis.moveToPoint(57, 7.5, 3500, {
      .forwards = false,
      .maxSpeed = 100,
   });
   chassis.waitUntilDone();
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(74, 69, 3500);
   chassis.waitUntilDone();
   intake.move_percentage(100, TIMEOUT_MAX);
   pros::delay(400);
   chassis.moveToPoint(50, 50, 3500, {.forwards = false});
   intake.move_percentage(100, TIMEOUT_MAX);

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
   ladybrown.set_current_target(330);
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
   ladybrown.set_current_target(71.5);

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
   chassis.moveToPoint(56, 12, 2000, {.earlyExitRange = 4});
   chassis.waitUntilDone();
   pros::delay(200);
   ladybrown.set_current_target(330);
   pros::delay(1300);
   chassis.moveToPoint(30, 27, 5000, {

      .forwards = false,
      .maxSpeed = 70,
   });
   chassis.waitUntil(5);

   ladybrown.set_current_target(71.5);
   chassis.waitUntilDone();

   chassis.waitUntil(25);
   chassis.cancelMotion();


   chassis.moveToPoint(24, 30, 5000, {

      .forwards = false,
      .maxSpeed = 50,
   });
   chassis.waitUntilDone();
   clamp.set_state(true);
   intake.move_percentage(100, TIMEOUT_MAX);
   // Do code for the solo awp and grabbing the first mogo
   chassis.moveToPoint(22, 47.5, 5000, {

      .maxSpeed = 60,
   });

   chassis.waitUntilDone();

   pros::delay(700);

   chassis.moveToPoint(22, 39, 5000, {
      .forwards = false,
      .maxSpeed = 60,
   });
   chassis.moveToPoint(12, 44, 5000, {

      .maxSpeed = 50,
   });

   chassis.waitUntilDone();
   pros::delay(1500);

   chassis.moveToPoint(25, 44, 5000, {
      .forwards = false, 
      .maxSpeed = 70,
   });

   chassis.moveToPoint(15, 12, 2000, {.maxSpeed = 60});

   ladybrown.cycle_target();
   ladybrown.cycle_target();
   pros::delay(2000);
}
void red_safe() {
   chassis.setPose(-54.5, 16.5, 230);
   // score on alliance stake
   pros::delay(100);
   chassis.moveToPoint(-56, 12, 2000, {.earlyExitRange = 1});
   chassis.waitUntilDone();
   pros::delay(200);
   ladybrown.set_current_target(330);
   pros::delay(1300);
   chassis.moveToPoint(-30, 24, 5000, {

      .forwards = false,
      .maxSpeed = 60,
   });
   chassis.waitUntil(5);

   ladybrown.set_current_target(71.5);
   chassis.waitUntilDone();

   chassis.waitUntil(25);
   chassis.cancelMotion();


   chassis.moveToPoint(-24, 27, 5000, {

      .forwards = false,
      .maxSpeed = 40,
   });
   chassis.waitUntilDone();
   clamp.set_state(true);
   pros::delay(300);
   intake.move_percentage(100, TIMEOUT_MAX);
   // Do code for the solo awp and grabbing the first mogo
   chassis.moveToPoint(-22, 46.5, 5000, {

      .maxSpeed = 60,
   });

   chassis.waitUntilDone();

   pros::delay(700);

   chassis.moveToPoint(-22, 39, 5000, {
      .forwards = false,
      .maxSpeed = 60,
   });
   chassis.moveToPoint(-12, 42, 5000, {

      .maxSpeed = 50,
   });

   chassis.waitUntilDone();
   pros::delay(1500);

   chassis.moveToPoint(-25, 44, 5000, {
      .forwards = false, 
      .maxSpeed = 70,
   });

   chassis.moveToPoint(-15, 12, 2000, {.maxSpeed = 60});

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

   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(-24, -50, 1000);
   chassis.waitUntil(8);
   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.waitUntilDone();
   pros::delay(200);
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.moveToPose(-24, -27, 180, 2500, {
      .forwards = false,
   });
   chassis.waitUntilDone();

   clamp.set_state(true);
   intake.move_percentage(100, TIMEOUT_MAX);
   pros::delay(500);
   intake.move_percentage(100, TIMEOUT_MAX);
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
   intake.move_percentage(100, TIMEOUT_MAX);
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

   left_doinker.set_state(true);
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
   left_doinker.set_state(false);

   chassis.moveToPoint(23.5, -9, 4000, {
      .forwards = false,
      .maxSpeed = 40
   });
   chassis.waitUntil(15);
   intake.move_percentage(0, TIMEOUT_MAX);
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

   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(24, -50, 1000);
   chassis.waitUntil(8);
   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.waitUntilDone();
   pros::delay(50);
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.moveToPose(24, -27, 180, 2500, {
      .forwards = false,
   });
   chassis.waitUntilDone();

   clamp.set_state(true);
   intake.move_percentage(100, TIMEOUT_MAX);
   pros::delay(500);
   intake.move_percentage(100, TIMEOUT_MAX);
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

   ladybrown.cycle_target();
   chassis.waitUntilDone();
}
void skills() {

   intake.set_color(RingColor::RED);
   chassis.setPose(-57, 0, 90);
   intake.move_percentage(100, TIMEOUT_MAX);
   pros::delay(500);
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.moveToPoint(-39, 0, 2000, {.earlyExitRange = 0.5});


   chassis.moveToPoint(-38.5, 24.5, 2000, {.forwards = false,.maxSpeed = 60, .minSpeed = 50, .earlyExitRange = 12});
   chassis.moveToPoint(-38.5, 29, 2000, {.forwards = false,.maxSpeed = 45, .minSpeed = 40});
   chassis.waitUntilDone();
   pros::delay(100);
   clamp.set_state(true);
   pros::delay(250);

   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(-24, 26, 1500,{.minSpeed = 70, .earlyExitRange = 2});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(27.5, 49, 3000, {.maxSpeed = 75, .minSpeed = 70});
   chassis.waitUntil(45);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();

   pros::delay(800);
   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.moveToPoint(4, 44, 3000, { .forwards = false, .minSpeed = 70, .earlyExitRange = 1});
   chassis.waitUntil(21.5);
   ladybrown.cycle_target();
   

   chassis.waitUntilDone();
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPose(8, 60, 0, 2500, {.earlyExitRange = 0.5});
   chassis.waitUntil(2);

   intake.move_percentage(-30, TIMEOUT_MAX);
   pros::delay(100);
   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.moveToPoint(7, 68, 790);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   
   // score
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.tank(20,20,true);
   pros::delay(100);
   ladybrown.set_current_target(245);
   pros::delay(1000);
   chassis.tank(0,0,true);

   chassis.moveToPoint(6, 49, 3000, {.forwards = false, .earlyExitRange = 3});
   
   chassis.waitUntil(10);
   ladybrown.cycle_target();
   intake.move_percentage(100, TIMEOUT_MAX);



   chassis.moveToPoint(-23, 54, 5000, {.maxSpeed = 80,.minSpeed = 60, .earlyExitRange = 5});

   chassis.moveToPoint(-52, 54, 5000, {.maxSpeed = 50, .earlyExitRange = 5});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntil(5);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   pros::delay(800);

   chassis.moveToPoint(-40, 67, 3000, {.maxSpeed = 80, .earlyExitRange = 2});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntil(5);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   pros::delay(700);


   chassis.moveToPoint(-59, 71, 1100, {.forwards = false});
   clamp.set_state(false);
   chassis.waitUntilDone();

   // SIDE 2
   //goes under


   pros::delay(200);
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.moveToPoint(12,-2, 4000, {.maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 10});
   intake.move_percentage(50, TIMEOUT_MAX);
   chassis.moveToPoint(12,-2, 4000, {.maxSpeed = 80, .minSpeed = 60});
   
   intake.queue_ring(false);  
   
   chassis.waitUntilDone();
   intake.move_percentage(100, TIMEOUT_MAX);
   pros::delay(750);
   intake.move_percentage(0, TIMEOUT_MAX);

   chassis.moveToPoint(-25, -11.5,  2500, {.forwards = false,.maxSpeed = 80, .earlyExitRange = 8});
   chassis.moveToPoint(-53, -20, 1650, {.forwards = false, .maxSpeed = 40});
   chassis.waitUntilDone();
   clamp.set_state(true);
   
   pros::delay(350);

   

   chassis.moveToPoint(-14, -23, 1500, {.maxSpeed = 80, .minSpeed = 50, .earlyExitRange = 2});

   chassis.waitUntil(5);
   intake.move_percentage(100, TIMEOUT_MAX);

   
   chassis.moveToPoint(2, -40, 2000, {.maxSpeed = 80, .minSpeed = 50, .earlyExitRange = 1});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntil(25);
   ladybrown.cycle_target();

   chassis.moveToPoint(3, -50, 1500, {.maxSpeed = 70, .minSpeed = 50});
   chassis.waitUntilDone();
   pros::delay(400);

   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPoint(4.5, -67, 1000, {.maxSpeed = 40});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   pros::delay(400);
   
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.tank(15,15,true);
   ladybrown.set_current_target(265);
   pros::delay(1200);

   chassis.tank(0,0,true);



   chassis.moveToPoint(9, -43, 3000, {.forwards = false, .minSpeed = 50, .earlyExitRange = 2});
   
   intake.move_percentage(100, TIMEOUT_MAX);
   intake.move_percentage(100, TIMEOUT_MAX);



   chassis.moveToPoint(-20, -44, 5000, {.maxSpeed = 70, .minSpeed = 60, .earlyExitRange = 3});
   ladybrown.set_current_target(LadyBrown::AWAY);
   chassis.moveToPoint(-52, -44, 5000, {.maxSpeed = 45,.minSpeed = 30, .earlyExitRange = 3});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntil(5);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   pros::delay(800);

   chassis.moveToPoint(-39, -57, 3000, {.maxSpeed = 65, .earlyExitRange = 2});
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntil(5);
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.waitUntilDone();
   pros::delay(700);

   
   chassis.moveToPoint(-58, -65, 1000, {.forwards = false});
   pros::delay(200);
   clamp.set_state(false);
   chassis.waitUntilDone();
   intake.move_percentage(-100, TIMEOUT_MAX);
   pros::delay(100);
  

   // PART THREE

   chassis.moveToPoint(24, -48, 15000, {.maxSpeed = 90,  .minSpeed = 65, .earlyExitRange = 1});
   
   
   chassis.moveToPoint(52, -48, 15000, {.maxSpeed = 65,  .minSpeed = 40, .earlyExitRange = 1});
   chassis.waitUntil(10);
   intake.move_percentage(100, TIMEOUT_MAX);
   ladybrown.cycle_target();

   chassis.moveToPoint(59.25, 14, 3000, {.forwards = false, .maxSpeed = 50, .minSpeed = 40, .earlyExitRange = 2});
   chassis.waitUntilDone();
   pros::delay(100);
   clamp.set_state(true);
   pros::delay(400);


   chassis.moveToPoint(63, 4.5, 3000, {.maxSpeed = 80, .minSpeed = 70, .earlyExitRange = 1});

   chassis.moveToPoint(80, 3.5, 2000, {.minSpeed = 50});
   chassis.waitUntilDone();

   
   //chassis.moveToPoint(chassis.getPose().x - 20*std::cos(chassis.getPose().theta), chassis.getPose().y - 20*std::sin(chassis.getPose().theta), 2000, {.forwards = false, .maxSpeed = 36});
   
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.tank(-28, -28, true);
   ladybrown.set_current_target(LadyBrown::BOTTOM + 10);
   pros::delay(1200);
   chassis.tank(-0, -0, true);

   chassis.moveToPoint(34, 24, 1500, {.maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 2});
   ladybrown.set_current_target(LadyBrown::READY_TO_SCORE);
   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.moveToPoint(58, 48 , 2000, {.maxSpeed = 60, .minSpeed = 50, .earlyExitRange = 3});

   chassis.moveToPoint(64, 49 , 1000, {.maxSpeed = 60, .minSpeed = 50});
   
   chassis.waitUntilDone();
   pros::delay(600);
   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.moveToPoint(45, 64, 1500, {.maxSpeed = 60, .minSpeed = 40});
   chassis.waitUntilDone();
   pros::delay(300);

   //hey

   
   
   chassis.moveToPoint(70, 64, 1200, {.forwards = false});
   pros::delay(350);
   clamp.set_state(false);
   chassis.waitUntilDone();
   intake.move_percentage(-50, TIMEOUT_MAX);
   
   pros::delay(200);
   pros::delay(100);

   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.moveToPoint(56, 25, 2000, {.minSpeed = 90, .earlyExitRange = 5});

   //chassis.moveToPoint(56, -5, 2000, {.minSpeed = 90, .earlyExitRange = 5});

   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.moveToPoint(67, -60, 2000, {.minSpeed = 125, .earlyExitRange = 5});
   

   chassis.moveToPoint(10, 4, 2340, {.forwards = false,.maxSpeed = 65, .minSpeed = 60});
   chassis.waitUntil(10);
   ladybrown.set_current_target(235);
   chassis.moveToPoint(65, -60, 300);
   chassis.waitUntilDone();

   pros::delay(5000);












}
void pid_tuning(){
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout

    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    controller.print(0, 0, "%.2f", chassis.getPose().theta);
    pros::delay(100);
    chassis.turnToHeading(90, 5000);
    chassis.waitUntilDone();
    pros::delay(850);
    controller.print(0, 0, "%.2f", chassis.getPose().theta);
    pros::delay(4000);
    controller.print(0, 0, "%.2f", chassis.getPose().theta);
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


void middle_ring_rush() {


   chassis.setPose(-52, -24, 270);

   chassis.moveToPoint(-20, -24, 3000, {.forwards = false, .maxSpeed = 80});
   chassis.waitUntil(10);
   chassis.cancelMotion();
   chassis.moveToPoint(-19, -24, 3000, {.forwards = false, .maxSpeed = 45});
   chassis.waitUntilDone();
   clamp.set_state(true);
   pros::delay(200);
   intake.move_percentage(100, TIMEOUT_MAX);
   pros::delay(200);


   chassis.moveToPoint(-13, -9, 5000);
   chassis.waitUntil(5);
   intake.move_percentage(0, TIMEOUT_MAX);
   chassis.waitUntilDone();



   chassis.turnToHeading(53, 2000);
   chassis.waitUntilDone();

   right_doinker.set_state(true);

   pros::delay(500);

   chassis.turnToHeading(70, 500);
   chassis.waitUntilDone();

   chassis.moveToPoint(-10, -6, 1000, {
   .minSpeed = 50});
   chassis.waitUntilDone();

   left_doinker.set_state(true);

   pros::delay(500);

   chassis.moveToPose(-45, -25, 85, 5000, {
   .forwards = false, .minSpeed = 100});
   chassis.waitUntilDone();

   chassis.turnToHeading(75, 2000, {.maxSpeed = 60});
   chassis.waitUntilDone();
   left_doinker.set_state(false);
   right_doinker.set_state(false);

   pros::delay(500);
   
   intake.move_percentage(100, TIMEOUT_MAX);
   chassis.moveToPose(-24, -21, 180, 1000, {.earlyExitRange = 3});
   chassis.waitUntilDone();

   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.moveToPoint(-24, -50, 5000, {.maxSpeed = 90});
   chassis.waitUntilDone();
   
   pros::delay(200);
   chassis.moveToPoint(-24, -47, 5000, {.maxSpeed = 90});
   chassis.waitUntilDone();

   chassis.moveToPoint(-46, -55, 3000, {.minSpeed = 100});
   chassis.waitUntilDone();

   chassis.turnToHeading(225, 1000);
   chassis.waitUntilDone();

   intake.move_percentage(100, TIMEOUT_MAX);

   chassis.tank(127, 127, true);
   pros::delay(1600);
   chassis.tank(-15, -15, true);
   pros::delay(500);
   chassis.tank(0, 0, true);

   chassis.moveToPoint(-15, -50, 3000);
   clamp.set_state(false);
   chassis.waitUntilDone();



   intake.move_percentage(0, TIMEOUT_MAX);
}


std::vector<rd::Selector::routine_t> autons = {
   { "middle ring rush", middle_ring_rush},
   {"Skills", skills},
   {"Red Safe", red_safe},
   {"Blue Safe", blue_safe},
   {"Red right", red_rush},
   {"PID", pid_tuning},
   {"Blue Right Alliance Stake", blue_right_alliance_stake},
   {"Red left", red_left},
   {"Solo AWP Red left", solo_awp_red_left},
   {"Blue right", blue_right},


   {"Red Red Alliance Stake", red_right_alliance_stake},
   {"Blue left", blue_left},
   {"Blue Left Alliance Stake", blue_left_alliance},

};