#pragma once

#include <Romi32U4.h>

/**
 * Class to access the on-board buttons and LEDs of the Romi
 */
class RomiBoard 
{
public:
    /**
     * Construct the RomiBoard object
     */
    RomiBoard();

    /**
     * Check if Button A is currently pressed.
     * @return true if the button is currently pressed.
     */
    bool isButtonAPressed();

    /**
     * Wait until Button A is pressed then return.
     */
    void waitForButtonA();

    /**
     * Check if Button B is currently pressed.
     * @return true if the button is currently pressed.
     */
    bool isButtonBPressed();

    /**
     * Wait until Button B is pressed then return.
     */
    void waitForButtonB();

    /**
     * Check if Button C is currently pressed.
     * @return true if the button is currently pressed.
     */
    bool isButtonCPressed();

    /**
     * Wait until Button C is pressed then return.
     */
    void waitForButtonC();

    /**
     * Turn on/off the Yellow LED.
     * @param on True to turn the light on, false to turn it off
     */
    void setYellowLed(bool on);

   /**
     * Turn on/off the Yellow LED.
     * @param on True to turn the light on, false to turn it off
     */
    void setRedLed(bool on);

    /**
     * Turn on/off the Green LED. Note that this light will do other things if the
     * USB is connected.
     * 
     * @param on True to turn the light on, false to turn it off
     */
    void setGreenLed(bool on);

private:
    Romi32U4ButtonA _buttonA;
    Romi32U4ButtonB _buttonB;
    Romi32U4ButtonC _buttonC;
};