#pragma once
#include "pose.hpp"
#include "odometry.hpp"


class MotionTracker {
public:
    MotionTracker(const AbstractOdometry& odometry);
    double get_distance() const;
    double get_angle() const;
    void update();

protected:
    Pose initial_pose;
    Pose previous_pose;
    const AbstractOdometry& odometry;
    double distance;
    double theta;
};
