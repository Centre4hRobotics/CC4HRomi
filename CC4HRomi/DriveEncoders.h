#pragma once

#include <Romi32U4Encoders.h>

/**
 * Class to access the drive encoders of the Romi. Encoders are used to
 * record accurate position of the left and right wheels as they spin.
 * */
class DriveEncoders 
{
public:
    /** 
     * Construct the DriveEncoders class (no inputs) 
     */
    DriveEncoders();

    /**
     * Reset the encoders. Immediately after this call any calls to
     * get{Left/Right/Average}EncoderInches will return 0.0.
     */
    void reset();

    /**
     * Get the current distance traveled by the left wheel in inches.
     */
    double getLeftEncoderInches();

    /**
     * Get the current distance traveled by the right wheel in inches.
     */
    double getRightEncoderInches();

    /**
     * Get the average distance traveled by the two wheels
     */
    double getAverageEncoderInches();
private:
    Romi32U4Encoders _encoders;
};