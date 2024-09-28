#include "qlib/tests/test_controller.hpp"


void test_pid_proportional() {
    PIDController pid(1, 0, 0, 0, 0, 0, 0, 0);
    ASSERT(pid.compute(10) == 10);
    ASSERT(pid.compute(-10) == -10);
}


void test_pid_integral() {
    PIDController pid(0, 1, 0, 0, 0, 0, 0, 0);
    ASSERT(pid.compute(10) == 10);
    ASSERT(pid.compute(10) == 20);
    ASSERT(pid.compute(10) == 30);
    ASSERT(pid.compute(-10) == -10);
    ASSERT(pid.compute(-10) == -20);
    ASSERT(pid.compute(-10) == -30);
}


void test_pid_derivative() {
    PIDController pid(0, 0, 1, 0, 0, 0, 0, 0);
    ASSERT(pid.compute(10) == 10);
    ASSERT(pid.compute(20) == 10);
    ASSERT(pid.compute(30) == 10);
    ASSERT(pid.compute(-10) == -40);
    ASSERT(pid.compute(-20) == -10);
    ASSERT(pid.compute(-30) == -10);
}


void test_pid_exit_conditions_small_error() {
    PIDController pid(0, 0, 0, 0, 1, 1000, 3, 3000);
    pid.compute(0);

    int start = pros::millis();
    while (!pid.check_exit_conditions(10)) {}
    ASSERT(pros::millis() - start <= 1500);
}


void test_pid_exit_conditions_big_error() {
    PIDController pid(0, 0, 0, 0, 1, 1000, 3, 3000);
    pid.compute(2);

    int start = pros::millis();
    while (!pid.check_exit_conditions(10)) {}
    ASSERT(pros::millis() - start <= 3500);
}


void test_slew_compute() {
    SlewController slew(10, false);
    ASSERT(slew.compute(20) == 10);
    ASSERT(slew.compute(30) == 20);
    ASSERT(slew.compute(30) == 30);
}
