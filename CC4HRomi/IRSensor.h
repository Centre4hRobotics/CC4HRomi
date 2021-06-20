#pragma once

/**
 * Class to access a digital IR sensor to detect proximity or light/dark.
 * The signal pin of the sensor needs to be wired to any one free I/O pin on the Romi
 * (see instructions).
 */
class IRSensor
{
public:
    /**
     * Construct the IR sensor on a given pin.
     * 
     * @param pin The pin plugged into the sensor.
     */
    IRSensor(int pin);

    /**
     * Return the current state of the sensor.
     * 
     * @return Returns true if the sensor is currently sensing dark colors, false otherwise.
     */
    bool isDark();

    /**
     * Return the current state of the sensor.
     * 
     * @return Returns true if the sensor is currently sensing light colors, false otherwise.
     */
    bool isLight();
private:
    int _pin;
};