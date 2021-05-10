#include "Gyro.h"
#include "GyroImpl.h"
#include <Romi32U4.h>

Gyro::Gyro() 
{
}

void Gyro::initialize()
{
    // turn on LED
    ledRed(1);

    // delay to make sure user isn't touching button
    delay(500);

    // perform initialization/calibration
    __initializeGyro();
    
    // turn off LED
    ledRed(0);
}



double Gyro::getAngle() {
    return __getGyroAngle();
}

void Gyro::reset() {
   __resetGyro();
}
