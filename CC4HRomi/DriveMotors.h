#pragma once

#include <Romi32U4Motors.h>

/**
 * Class to access the drive motors of the Romi
 */
class DriveMotors
{
public:
    /**
     * Construct the DriveMotors class (no arguments)
     */
    DriveMotors();

    /**
     * Arcade Drive method, where the motion of the robot is specified by 
     * a speed and steering.
     * 
     * @param speed: The robot's forwards/backwards speed [-1.0..1.0]. Forward is positive.
     * @param steer: The robot's rotation rate [-1.0..1.0]. Clockwise is positive.
     */
    void drive(double speed, double steer);

    /**
     * Stop the motors (same as drive(0, 0))
     */
    void stop();
private:
    Romi32U4Motors _motors;
};

