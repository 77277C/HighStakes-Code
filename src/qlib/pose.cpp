#include "qlib/pose.hpp"


double standard_to_compass(double deg) {
    return 90 - deg;
}


double compass_to_standard(double deg) {
    return 90 - deg;
}


double deg_to_rad(double deg) {
    return deg * (M_PI / 180);
}


double rad_to_deg(double rad) {
    return rad * (180 / M_PI);
}


Pose::Pose(double x, double y, double theta)
    : x(x), y(y), theta(theta) {}


double Pose::distance_to(const Pose& other) const {
    // Find the length of the hypotenuse when creating a triangle with these two poses
    return std::hypot(this->x - other.x, this->y - other.y);
}


double Pose::angle_to(const Pose& other) const {
    // atan2 (arctan) takes all 4 quadrants into account
    return std::atan2(other.y - this->y, other.x - this->x);
}


double Pose::angular_error(const Pose &other) const {
    return other.theta - theta;
}
