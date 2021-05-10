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
     * Tank Drive method, where the speeds of the left and right wheel are
     * specified directly.
     * 
     * @param leftSpeed: The speed of the left wheel [-1.0..1.0]. Forward is positive.
     * @param rightSpeed: The speed of the right wheel [-1.0..1.0]. Forward is positive.
     */
    void tankDrive(double leftSpeed, double rightSpeed);

private:
    Romi32U4Motors _motors;
};

