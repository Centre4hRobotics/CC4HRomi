#include "RomiBoard.h"


RomiBoard::RomiBoard() {}

bool RomiBoard::isButtonAPressed() {
    return _buttonA.isPressed();
}

void RomiBoard::waitForButtonA() {
    _buttonA.waitForPress();
}

bool RomiBoard::isButtonBPressed() {
    return _buttonB.isPressed();
}

void RomiBoard::waitForButtonB() {
    _buttonB.waitForPress();
}

bool RomiBoard::isButtonCPressed() {
    return _buttonC.isPressed();
}

void RomiBoard::waitForButtonC() {
    _buttonC.waitForPress();
}

void RomiBoard::setYellowLed(bool on) {
    ledYellow(on);
}

void RomiBoard::setRedLed(bool on) {
    ledRed(on);
}

void RomiBoard::setGreenLed(bool on) {
    ledGreen(on);
}