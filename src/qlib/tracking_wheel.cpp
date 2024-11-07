#include "qlib/tracking_wheel.hpp"


// Constructor initializes a TrackingWheel with an offset and wheel diameter
TrackingWheel::TrackingWheel(double offset, double wheel_diameter)
        : offset(offset), wheel_diameter(wheel_diameter) {}

// Get the offset value for this TrackingWheel
double TrackingWheel::get_offset() const {
    return offset;
}

// Get the wheel diameter for this TrackingWheel
double TrackingWheel::get_wheel_diameter() const {
    return wheel_diameter;
}


MotorTrackingWheel::MotorTrackingWheel(const pros::AbstractMotor& motor, int rpm, double offset, double wheel_diameter) :
    motor(motor), rpm(rpm), TrackingWheel(offset, wheel_diameter) {}


double MotorTrackingWheel::get_distance_traveled() const {
    double in;
    switch(motor.get_gearing()) {
        case pros::MotorGears::red:
            in = 100; break;
        case pros::MotorGears::green:
            in = 200; break;
        case pros::MotorGears::blue:
            in = 600; break;
        case pros::MotorGears::invalid:
            return 0;
    }
    return motor.get_position() * M_PI * wheel_diameter * (rpm / in);
}


void MotorTrackingWheel::reset() const {
    motor.tare_position();
    motor.set_encoder_units(pros::MotorUnits::rotations);
}