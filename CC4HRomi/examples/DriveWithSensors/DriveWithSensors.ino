#include <CC4HRomi.h>

// we will use motors, encoders, and gyro for this.
// Declare all the variables here so we can access
// them anywhere.
DriveMotors motors;
DriveEncoders encoders;
Gyro gyro;


void setup() {
  // initial delay of 5s after powering up before initializing gyro
  delay(5000);

  // initialize gyro. Don't touch the robot while the red LED is on!
  gyro.initialize();

  //// Drive forward 10 inches
  // reset the drive encoders to 0
  encoders.reset();
  
  // wait until encoders reach 10 inches
  while(encoders.getAverageEncoderInches() < 10.0) {
     // drive forward at 50% speed
     motors.drive(0.5, 0.0);
  }

  //// Turn 180 degrees
  // reset the gyro
  gyro.reset();

  // keep rotating until the robot has turned 90 degrees clockwise
  while(gyro.getAngle() < 180) {
    // rotate at 25%
    motors.drive(0.0, 0.25);
  }

  //// Drive back to starting point
  // reset the drive encoders to 0
  encoders.reset();
  
  // wait until encoders reach 10 inches
  while(encoders.getAverageEncoderInches() < 10.0) {
     // drive forward at 50% speed
     motors.drive(0.5, 0.0);
  }
  
  //// Stop
  motors.stop();
}


// don't do anything in loop
void loop() {}
