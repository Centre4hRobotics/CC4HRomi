#include <CC4HRomi.h>

// create the reflectance sensor on pin 4
// sensor should be plugged into ground (GND), 5v (VIN), and 4 (D0)
ReflectanceSensor reflect(4);

// also use the RomiBoard to turn on a LED
RomiBoard board;

void setup() {
  // put your setup code here, to run once:

  // turn on serial monitor so we can print values
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (reflect.isLight()) {
    board.setYellowLed(true);
    Serial.println("Light");
  }
  else {
    board.setYellowLed(false);
    Serial.println("Dark");
  }
}
