#include <CC4HRomi.h>

/**
 * This sketch contains the basics for a Romi using the CC4H Robotics Romi library. 
 * It assumes the following sensors are plugged in:
 * 
 * * An ultrasonic sensor on pins 21 and 22
 * * A reflectance sensor on pin 4
 */


// the DriveMotors used to control the left and right drive motors
DriveMotors motors;
// the DriveEncoders used to measure motion of the left and right motors
DriveEncoders encoders;
// the Gyro used to track the rotation of the robot
Gyro gyro;
// the UltrasonicSensor, used to sense distance to objects
UltrasonicSensor ultrasonic(21, 22);
// The ReflectanceSensor, used to sense light/dark objects on the ground in front of the robot
ReflectanceSensor reflect(4);

void setup() {
  // put your setup code here, to run once:
  
  // initial delay of 5s after powering up before initializing gyro
  delay(5000);

  // initialize gyro. Don't touch the robot while the red LED is on!
  gyro.initialize();
}


void loop() {
  // put your main code here, to run repeatedly:


  
  // usually a good idea to have a short delay before restarting main loop
  delay(20);
}
