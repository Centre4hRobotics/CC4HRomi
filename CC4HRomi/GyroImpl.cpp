#include "GyroImpl.h"
#include <Wire.h>
#include <LSM6.h>

#define __NODEBUG

LSM6 __gyro;
int __gyroOffset;
unsigned long __lastUpdateTime;
double __angle = 0.0;

const int NUM_CALIBRATION_READINGS = 2048;

// scale factor (dps/LSB) based on gyro settings
// angular rate sensitivity / 1000
// correct for whatever minor error seems to be occurring from testing
const double TURN_RATE_SCALE = 17.50/1000*3645/3600;

void __initializeGyro()
{
    // start i2c
    Wire.begin();

    // start gyro
    __gyro.init();

    // from RotationResist/TurnSensor.cpp
    __gyro.enableDefault();

    // 500 deg/s, everything else default
    __gyro.writeReg(LSM6::CTRL2_G, 0b10000100);

    // Calibrate the gyro.
    int32_t total = 0;
    for (uint16_t i = 0; i < NUM_CALIBRATION_READINGS; i++)
    {
        // Wait for new data to be available, then read it.
        while(!__gyro.readReg(LSM6::STATUS_REG) & 0x08);
        __gyro.read();

        // Add the Z axis reading to the total.
        total += __gyro.g.z;
    }
  
    // store offset
    __gyroOffset = total / NUM_CALIBRATION_READINGS;

#ifdef __DEBUG
    Serial.print("Offset: ");
    Serial.println(__gyroOffset);
#endif

    // set initial angle to zero
    // this will also start the FIFO reading
    __resetGyro();
}

void __resetGyro()
{
     __angle = 0;
    __lastUpdateTime = millis();    
}

double __getGyroAngle() {    
    __integrate();
    // invert so clockwise is positive
    return -1.0*__angle;
}

void __integrate()
{
    if (!__gyro.readReg(LSM6::STATUS_REG) & 0x08)
        return; // no new data

    __gyro.readGyro();

    int16_t val = __gyro.g.z;

#ifdef __DEBUG
    Serial.print("Val: ");
    Serial.print(val);
#endif

    /* Compute turnRate in degrees/second using scale factor computed above. */
    double turnRate = (val - __gyroOffset) * TURN_RATE_SCALE;

#ifdef __DEBUG
    Serial.print(" rate: ");
    Serial.print(turnRate);
#endif


    // Figure out time since last call to __integrate()
    unsigned long m = millis();
    unsigned long dt = m - __lastUpdateTime;
    __lastUpdateTime = m;

    // compute turn in degrees by multiplying turn rate by time in seconds
    double turn = turnRate * dt * 0.001;

    // update integrated angle
    __angle += turn; 

#ifdef __DEBUG
    Serial.print(" angle: ");
    Serial.println(__angle);
#endif

}
