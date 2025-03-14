#include "MCLLocalizer.hpp"

MCLLocalizer::MCLLocalizer(
    pros::Imu* imu,
    lemlib::TrackingWheel* forwardTracker,
    lemlib::TrackingWheel* horizontalTracker,
    pros::Distance* distanceSensorLeft,
    double leftOffset,
    pros::Distance* distanceSensorRight,
    double rightOffset,
    int numParticles
) : 
    imu(imu),
    forwardTracker(forwardTracker),
    horizontalTracker(horizontalTracker),
    distanceSensorLeft(distanceSensorLeft),
    leftOffset(leftOffset),
    distanceSensorRight(distanceSensorRight),
    rightOffset(rightOffset),
    gen(rd()),
    noise_pos(0.0, 0.5),
    noise_heading(0.0, 0.02)
{
    setupFieldWalls();

    initializeParticles(FIELD_SIZE_X/2, FIELD_SIZE_Y/2, 0, 1, 1000);


    // Initialize Kalman Filter
    kf_ = std::make_shared<KalmanFilter>();
}

void MCLLocalizer::setupFieldWalls() {
    // Field perimeter
    fieldWalls.push_back({0, 0, FIELD_SIZE_X, 0});          // Bottom wall
    fieldWalls.push_back({FIELD_SIZE_X, 0, FIELD_SIZE_X, FIELD_SIZE_Y}); // Right wall
    fieldWalls.push_back({FIELD_SIZE_X, FIELD_SIZE_Y, 0, FIELD_SIZE_Y}); // Top wall
    fieldWalls.push_back({0, FIELD_SIZE_Y, 0, 0});          // Left wall

    //more field elements such as walls?
}

void MCLLocalizer::initializeParticles(double x, double y, double theta, double spread, int numParticles) {
    particles.resize(numParticles);

    std::normal_distribution<> init_pos(0.0, spread);
    std::normal_distribution<> init_heading(0.0, spread * 0.1);

    for(auto& p : particles) {
        p.x = x + init_pos(gen);
        p.y = y + init_pos(gen);
        p.theta = normalizeAngle(theta + init_heading(gen));
        p.weight = 1.0 / particles.size();
    }

    pros::Controller controller(pros::E_CONTROLLER_MASTER);
}

double lastUpdateTime_;
void MCLLocalizer::update() {
    // Get current time for delta time calculation
    double currentTime = pros::millis() / 1000.0;
    double dt = currentTime - lastUpdateTime_;
    
    // Get current sensor readings
    double currentForward = forwardTracker->getDistanceTraveled();
    double currentHorizontal = horizontalTracker->getDistanceTraveled();
    double currentImu = imu->get_heading() * M_PI / 180.0;  // Convert to radians

    // Calculate movement deltas
    double deltaForward = currentForward - prevForwardPos;
    double deltaHorizontal = currentHorizontal - prevHorizontalPos;
    double deltaHeading = normalizeAngle(currentImu - prevImuHeading);

    // Motion update for particles
    motionUpdate(deltaForward, deltaHorizontal, deltaHeading);

    // Weight update using distance sensors
    double totalWeight = 0;
    double left_measured_distance = distanceSensorLeft->get() / 25.4;  // Convert mm to inches
    double right_measured_distance = distanceSensorRight->get() / 25.4;

    if (left_measured_distance < MAX_VALID_DISTANCE || right_measured_distance < MAX_VALID_DISTANCE) {
        static pros::Controller controller(pros::E_CONTROLLER_MASTER);
        for(auto& p : particles) {
            p.weight *= calculateWeight(p);
            totalWeight += p.weight;
        }

        // Normalize weights
        if(totalWeight > 0) {
            for(auto& p : particles) {
                p.weight /= totalWeight;
            }
        }
    }

    // Store current readings for next update
    prevForwardPos = currentForward;
    prevHorizontalPos = currentHorizontal;
    prevImuHeading = currentImu;
 // Resample particles
    resample();

    // Get MCL position estimate
    double x, y, theta;
    double weightSum = 0;
    x = y = theta = 0;

    for(const auto& p : particles) {
        x += p.x * p.weight;
        y += p.y * p.weight;
        theta += p.theta * p.weight;
        weightSum += p.weight;
    }

    if(weightSum > 0) {
        x /= weightSum;
        y /= weightSum;
        theta = normalizeAngle(theta / weightSum);
    }

    // Prepare measurement for Kalman filter
    Eigen::Vector3d measurement(x, y, theta);

    // Kalman filter update
    kf_->predict(dt);
    kf_->update(measurement);

    lastUpdateTime_ = currentTime;


    chassis.setPose(x, y, theta, true);
    pros::delay(10);
}

void MCLLocalizer::motionUpdate(double deltaForward, double deltaHorizontal, double deltaHeading) {
    for(auto& p : particles) {
        double noisyForward = deltaForward + noise_pos(gen);
        double noisyHorizontal = deltaHorizontal + noise_pos(gen);
        double noisyHeading = deltaHeading + noise_heading(gen);

        p.x += noisyForward * cos(p.theta) - noisyHorizontal * sin(p.theta);
        p.y += noisyForward * sin(p.theta) + noisyHorizontal * cos(p.theta);
        p.theta = normalizeAngle(p.theta + noisyHeading);

        

    }
}

double MCLLocalizer::calculateWeight(const Particle& p) {
    double weight = 1.0;
    
    // Distance sensor weight
    double left_measured_distance = distanceSensorLeft->get() / 25.4 + leftOffset; // Convert to inches
    double right_measured_distance = distanceSensorRight->get() / 25.4 + rightOffset; // Convert to inches
    left_measured_distance = 9999999999;
    
    if (left_measured_distance < MAX_VALID_DISTANCE) {
        double predicted_distance = predictDistanceReading(p, -M_PI_2);  // Left sensor at 90 degrees
        double diff_left = left_measured_distance - predicted_distance; 
        weight *= exp(-(diff_left * diff_left) / (2 * DISTANCE_NOISE_SD * DISTANCE_NOISE_SD));
    }
    if (right_measured_distance < MAX_VALID_DISTANCE) {
        double predicted_right = predictDistanceReading(p, M_PI_2); // Right sensor at -90 degrees
        double diff_right = right_measured_distance - predicted_right;
        weight *= exp(-(diff_right * diff_right) / (2 * DISTANCE_NOISE_SD * DISTANCE_NOISE_SD));
    }
    
    // Add boundary penalties
    if (p.x < 0 || p.x > FIELD_SIZE_X || p.y < 0 || p.y > FIELD_SIZE_Y) {
        weight *= 0.1;
    }
    
    return weight;
}

double MCLLocalizer::predictDistanceReading(const Particle& p, double sensorAngle) {
    return raycast(p.x, p.y, normalizeAngle(p.theta + sensorAngle));
}

double MCLLocalizer::raycast(double x, double y, double angle) {
    double rayEndX = x + MAX_VALID_DISTANCE * cos(angle);
    double rayEndY = y + MAX_VALID_DISTANCE * sin(angle);
    double minDistance = MAX_VALID_DISTANCE;

    for(const auto& wall : fieldWalls) {
        double intersectX, intersectY;
        if(lineIntersection(x, y, rayEndX, rayEndY,
                           wall.x1, wall.y1, wall.x2, wall.y2,
                           intersectX, intersectY)) {
            double distance = sqrt(pow(x - intersectX, 2) + pow(y - intersectY, 2));
            minDistance = std::min(minDistance, distance);
        }
    }

    return minDistance;
}

bool MCLLocalizer::lineIntersection(double x1, double y1, double x2, double y2,
                                  double x3, double y3, double x4, double y4,
                                  double& intersectX, double& intersectY) {
    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if(denominator == 0) return false;

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

    if(t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        intersectX = x1 + t * (x2 - x1);
        intersectY = y1 + t * (y2 - y1);
        return true;
    }
    return false;
}

void MCLLocalizer::resample() {
    std::vector<Particle> newParticles;
    newParticles.reserve(particles.size());

    std::uniform_real_distribution<> dist(0, 1.0/particles.size());
    double beta = dist(gen);
    int index = 0;
    double maxWeight = 0;
    
    for(const auto& p : particles) {
        maxWeight = std::max(maxWeight, p.weight);
    }

    for(size_t i = 0; i < particles.size(); i++) {
        beta += 2.0 * maxWeight * dist(gen);
        while(beta > particles[index].weight) {
            beta -= particles[index].weight;
            index = (index + 1) % particles.size();
        }
        newParticles.push_back(particles[index]);
        newParticles.back().weight = 1.0 / particles.size();
    }

    particles = std::move(newParticles);
}

void MCLLocalizer::getPose(double& x, double& y, double& theta) {
    x = y = theta = 0;
    double totalWeight = 0;

    for(const auto& p : particles) {
        x += p.x * p.weight;
        y += p.y * p.weight;
        theta += p.theta * p.weight;
        totalWeight += p.weight;
    }

    if(totalWeight > 0) {
        x /= totalWeight;
        y /= totalWeight;
        theta = normalizeAngle(theta / totalWeight);
    }
}

double MCLLocalizer::normalizeAngle(double angle) {
    while(angle > M_PI) angle -= 2 * M_PI;
    while(angle < -M_PI) angle += 2 * M_PI;
    return angle;
}