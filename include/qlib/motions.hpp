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
#include "odometry.hpp"
#include "params.hpp"
#include "constants.h"
#include "console.hpp"


enum SwingType {LEFT, RIGHT};

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

    void turn_to_heading(double heading, TurnParams params = {});
    void swing_to_heading(double heading, SwingType swing_type, TurnParams params = {});
    void move_to_pose(Pose target, MoveToPoseParams params = {});

protected:
    bool is_in_motion;
    bool start_motion();
};
