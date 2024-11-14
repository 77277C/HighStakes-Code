#pragma once
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "robodash/api.h"
#include "units.hpp"
#include "tracking_wheel.hpp"
#include "pose.hpp"
#include "console.hpp"
#include <cmath>
#include <memory>
#include <optional>
#include "lemlib/api.hpp"


class AbstractOdometry {
public:
    virtual ~AbstractOdometry() = default;
    /**
     * Get the current pose of the robot
     * @return The current pose of the robot
     */
    Pose get_pose() const;
    /**
     * Set the current pose of the robot
     * @param pose The new pose of the robot
     */
    void set_pose(Pose pose);
    /**
     * Update the odometry from the given values
     * @param vertical The vertical distance traveled
     * @param horizontal The horizontal distance traveled
     * @param heading The heading of the robot
     * @param vertical_offset The vertical offset of the tracking wheel
     * @param horizontal_offset The horizontal offset of the tracking wheel
     */
    void update_from_values(double vertical, double horizontal, double heading, double vertical_offset, double horizontal_offset);
    /**
     * Log the current coordinates to the console
     * this function will block foreever
     *
     * @param console The console to log the coordinates to
     */
    void log_coordinates() const;
    /**
     * Initialize the odometry
     */
    virtual void initialize(lemlib::Chassis& chassis) = 0;
    /**
     * Update the odometry
     */
    virtual void update() = 0;
protected:
    Pose current_pose = Pose(0_in, 0_in, 0_rad);
    std::optional<double> previous_vertical;
    std::optional<double> previous_horizontal;
    std::optional<double> previous_heading;
};


class VerticalTrackerImuOdometry : public AbstractOdometry {
public:
    const TrackingWheel& vertical_tracking_wheel;
    const pros::Imu& imu;

    /**
     * Create a new odometry object
     * @param vertical_tracking_wheel The vertical tracking wheel
     * @param imu The inertial sensor
     */
    VerticalTrackerImuOdometry(const TrackingWheel& vertical_tracking_wheel, const pros::Imu& imu);
    /**
     * Initialize the odometry
     */
    void initialize(lemlib::Chassis& chassis) override;
    /**
     * Update the odometry
     */
    void update() override;
};
