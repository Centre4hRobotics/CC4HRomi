#include <CC4HRomi.h>

// Create TouchSensor using pin 20.
// Sensor wires should be connected to GROUND and 20
TouchSensor touch(20);

// use RomiBoard too so we can turn on light
RomiBoard board;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read the touch sensor
  bool isTouched = touch.isTouched();

  // turn red LED on if button is pressed.
  if (isTouched)
    board.setRedLed(true);
  else
    board.setRedLed(false);
}
