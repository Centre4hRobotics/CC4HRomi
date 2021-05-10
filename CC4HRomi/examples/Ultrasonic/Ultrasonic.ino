#include <CC4HRomi.h>

// set the maximum distance of the sensor
const double MAX_DISTANCE = 24.0;

// create the ultrasonic sensor using pins 21 and 22 and the maximum distance
UltrasonicSensor ultrasonic(21, 22, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:

  // turn on serial monitor so we can print values
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

  // read distance
  double distance = ultrasonic.getDistanceInches();

  // print distance to serial monitor
  if (distance < MAX_DISTANCE) {
    Serial.print("Object detected at ");
    Serial.print(distance);
    Serial.println(" inches.");
  }
  else {
    // if returned distance is equal to MAX_DISTANCE, then no object is detected
    Serial.println("No object detected.");
  }
  
  // wait a second until next loop
  delay(1000);
}
