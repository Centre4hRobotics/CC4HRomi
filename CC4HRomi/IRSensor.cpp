#include "IRSensor.h"
#include <Arduino.h>

IRSensor::IRSensor(int pin) {
    _pin = pin;

    pinMode(_pin, INPUT);
}

bool IRSensor::isLight() {
    return (digitalRead(_pin) == LOW);
}

bool IRSensor::isDark() {
    return (digitalRead(_pin) == HIGH);
}