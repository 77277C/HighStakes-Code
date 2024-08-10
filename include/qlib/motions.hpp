#include <memory>
#include <vector>
#include "squiggles.hpp"
#include "pros/motors.hpp"
#include "pros/imu.hpp"
#include "robodash/api.h"
#include "units.hpp"
#include "pose.hpp"
#include "controller.hpp"
#include "drivetrain.hpp"
#include "motion_tracker.hpp"
#include "odometry.hpp"
#include "params.hpp"
#include "constants.h"


enum SwingType {LEFT, RIGHT};
enum MotionType {LINEAR, ANGULAR};


class Motions {
public:
    Drivetrain& drivetrain;
    PIDController& linear_controller;
    PIDController& angular_controller;
    AbstractOdometry& odometry;

    Motions(Drivetrain& drivetrain, PIDController& linear_controller,
            PIDController& angular_controller, AbstractOdometry& odometry);

    bool in_motion() const;
    void end_motion();
    void wait_until_done() const;
    void wait_until(double until, MotionType type) const;

    void turn_to_heading(double heading, MovementParams params = {});
    void swing_to_heading(double heading, SwingType swing_type, MovementParams params = {});
    void move_to_point(double x, double y, LinearMovementParams params = {});

protected:
    bool is_in_motion;
    std::unique_ptr<MotionTracker> motion_tracker = nullptr;
    bool start_motion();
};
