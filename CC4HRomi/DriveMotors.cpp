#include "DriveMotors.h"
#include <Arduino.h>

DriveMotors::DriveMotors() {

}

void DriveMotors::drive(double speed, double steer) {
  double xSpeed = constrain(speed, -1.0, 1.0);
  double zRotation = constrain(steer, -1.0, 1.0);

  double leftMotorOutput;
  double rightMotorOutput;

  double maxInput =
      copysign(fmax(fabs(xSpeed), fabs(zRotation)), xSpeed);

  if (xSpeed >= 0.0) {
    // First quadrant, else second quadrant
    if (zRotation >= 0.0) {
      leftMotorOutput = maxInput;
      rightMotorOutput = xSpeed - zRotation;
    } else {
      leftMotorOutput = xSpeed + zRotation;
      rightMotorOutput = maxInput;
    }
  } else {
    // Third quadrant, else fourth quadrant
    if (zRotation >= 0.0) {
      leftMotorOutput = xSpeed + zRotation;
      rightMotorOutput = maxInput;
    } else {
      leftMotorOutput = maxInput;
      rightMotorOutput = xSpeed - zRotation;
    }
  }

  leftMotorOutput = constrain(leftMotorOutput, -1.0, 1.0);
  rightMotorOutput = constrain(rightMotorOutput, -1.0, 1.0);
  
  _motors.setSpeeds(300*leftMotorOutput, 300*rightMotorOutput);
}

void DriveMotors::stop() {
    _motors.setSpeeds(0, 0);
}