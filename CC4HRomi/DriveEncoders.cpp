#include "DriveEncoders.h"
#include <math.h>

double countsToInches(int counts) {
    // one revolution of a Romi wheel corresponds to 1437.09 encoder counts
    // per the Rom32Encoders documentation
    double revs = counts / 1437.09;

    // wheel diameter is 2.75 inches
    double distance = revs*2.75*M_PI;

    return distance;
}

DriveEncoders::DriveEncoders() {
    _encoders.init();
}


void DriveEncoders::reset() {
    _encoders.getCountsAndResetLeft();
    _encoders.getCountsAndResetRight();
}

double DriveEncoders::getLeftEncoderInches() {
    return countsToInches(_encoders.getCountsLeft());
}

double DriveEncoders::getRightEncoderInches() {
    return countsToInches(_encoders.getCountsRight());
}

double DriveEncoders::getAverageEncoderInches() {
    return 0.5*(getLeftEncoderInches() + getRightEncoderInches());
}