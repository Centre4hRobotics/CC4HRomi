#pragma once

#include <LSM6.h>

/**
 * Class to access the onboard gyro on the Romi to determine rotation angle.
 */
class Gyro 
{
public:
    /**
     * Construct the Gyro (no arguments).
     */
    Gyro();

    /**
     * Initialize and calibrates the Gyro. This must be called once before the gyro is used and
     * takes about 2 seconds to complete. The robot must be stationary and not be touched
     * while initializing, so you should always include a delay before calling this
     * so you can get your finger off the power button.
     */
    void initialize();

    /**
     * Reset the robot gyro. Immediately after calling this, getAngle() will return 0.0.
     */
    void reset();

    /**
     * Get the current yaw angle of the robot in degrees. Clockwise rotation returns
     * a positive angle.
     */
    double getAngle();
};