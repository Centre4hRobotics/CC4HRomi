#include <CC4HRomi.h>

TouchSensor touch(20);

void setup() {
  // put your setup code here, to run once:

  // turn on serial monitor so we can print values
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  // read the touch sensor
  bool isTouched = touch.isTouched();

  // print status to serial monitor
  if (isTouched)
    Serial.println("Touch sensor triggered");

  // wait a second until next loop
  delay(1000);
}
