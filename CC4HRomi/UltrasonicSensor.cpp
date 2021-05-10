#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin, double maxDistanceInches)
: _ultrasonic(triggerPin, echoPin)
{
    setMaxDistanceInches(maxDistanceInches);
}

double UltrasonicSensor::getDistanceInches() {
    double val = _ultrasonic.read() / 2.54;
    if (val > _maxDistance)
        return _maxDistance;
    return val;
}

void UltrasonicSensor::setMaxDistanceInches(double distanceInches) {
    _maxDistance = distanceInches;
    _ultrasonic.setTimeout(distanceInches * 74 * 2); // microseconds per inch
}