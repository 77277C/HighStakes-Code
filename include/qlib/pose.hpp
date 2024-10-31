#pragma once
#include <cmath>
#include <limits>
#include "units.hpp"


double standard_to_compass(double deg);
double compass_to_standard(double deg);
double deg_to_rad(double deg);
double rad_to_deg(double rad);


class Pose {
public:
    double x;
    double y;
    double theta;

    /**
     Construct a new Pose object
     *
     * @param x The x coordinate
     * @param y The y coordinate
     * @param theta The angle in radians
     */
    Pose(double x, double y, double theta = std::numeric_limits<double>::quiet_NaN());
    /**
     * Calculate the distance between this pose and another pose
     *
     * @param other The other pose
     * @return The distance between the two poses
     */
    double distance_to(const Pose& other) const;
    /**
     * Calculate the angle between this pose and another pose
     *
     * @param other The other pose
     * @return The angle between the two poses
     */
    double angle_to(const Pose& other) const;
    /**
     * Calculate the angular error between this pose and another pose
     * @param other The other pose
     * @return The angular error between this pose and another pose
     */
    double angular_error(const Pose& other) const;
};
