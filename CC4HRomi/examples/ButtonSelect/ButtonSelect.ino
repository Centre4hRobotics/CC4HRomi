#include <CC4HRomi.h>

RomiBoard board;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // turn off all LEDs
  board.setRedLed(false);
  board.setYellowLed(false);
  board.setGreenLed(false);

  // wait for any of the 3 buttons to be pressed
  int button = board.waitForButtonPress();

  // turn on a different LED depending on which
  // button was pressed
  if (button == 1) {
    board.setYellowLed(true);
  }
  else if (button == 2) {
    board.setGreenLed(true);
  }
  else if (button == 3) {
    board.setRedLed(true);
  }

  // leave light on for 1 second
  delay(1000);
}
