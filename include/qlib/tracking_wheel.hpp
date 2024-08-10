#pragma once
#include <cmath>
#include <vector>
#include <memory>
#include "pros/abstract_motor.hpp"


class TrackingWheel {
public:
    /**
     * Constructor initializes a TrackingWheel with an offset and wheel diameter
     * @param offset the offset value for this TrackingWheel
     * @param wheel_diameter the wheel diameter for this TrackingWheel
     */
    TrackingWheel(double offset, double wheel_diameter);
    virtual ~TrackingWheel() = default;
    /**
     * Get the offset value for this TrackingWheel
     */
    double get_offset() const;
    /**
     * Get the wheel diameter for this TrackingWheel
     */
    double get_wheel_diameter() const;
    /**
     * Get the distance traveled by this TrackingWheel
     */
    virtual double get_distance_traveled() const = 0;
    /**
     * Reset the position of this TrackingWheel
     */
    virtual void reset() const = 0;

protected:
    double offset;
    double wheel_diameter;
};


class MotorTrackingWheel : public TrackingWheel {
public:
    /**
     * Constructor initializes a MotorTrackingWheel with an offset, wheel diameter, and motor
     * @param motor the motor for this MotorTrackingWheel
     * @param rpm the rpm value for this MotorTrackingWheel
     * @param offset the offset value for this MotorTrackingWheel
     * @param wheel_diameter the wheel diameter for this MotorTrackingWheel
     */
    MotorTrackingWheel(const pros::AbstractMotor& motor, int rpm, double offset, double wheel_diameter);
    /**
     * Get the distance traveled by this MotorTrackingWheel
     */
    double get_distance_traveled() const override;
    /**
     * Reset the position of this MotorTrackingWheel
     */
    void reset() const override;
protected:
    // An abstract motor can be a motor or a motor group
    const pros::AbstractMotor& motor;
    int rpm;
};
