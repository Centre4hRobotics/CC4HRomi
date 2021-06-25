#include <CC4HRomi.h>

// we will use motors, encoders, and gyro for this.
// Declare all the variables here so we can access
// them anywhere.
DriveMotors motors;
DriveEncoders encoders;
Gyro gyro;

//// Declare two helper functions so we can call them multiple times in our setup()/loop() code
// Function to drive forward 10 inches using the encoders
void driveForward10Inches() {
  // reset the drive encoders
  encoders.reset();

  // keep moving until the robot has driven 10 inches forward
  while(encoders.getAverageEncoderInches() < 10.0) {
    // drive at 50% speed (fast enough!)
    motors.drive(0.5, 0.0);
  }
  // stop driving
  motors.drive(0.0, 0.0);
}


// Function to turn right 90 degrees
void turnRight90() {
  // reset the gyro
  gyro.reset();

  // keep rotating until the robot has turned 90 degrees clockwise
  while(gyro.getAngle() < 90) {
    // rotate at 25% speed (fast enough!)
    motors.drive(0.0, 0.25);
  }
  // stop rotating
  motors.drive(0.0, 0.0);
}


void setup() {
  // initial delay of 5s after powering up before initializing gyro
  delay(5000);

  // initialize gyro. Don't touch the robot while the red LED is on!
  gyro.initialize();

  // drive forward and make a 90 degree right turn 4 times to make a square
  for(int i=0; i<4; ++i) {
    driveForward10Inches();
    turnRight90();
  }
}

// don't do anything in loop
void loop() {}
