#include "rangefinder.h"
#include "display.h"

// trigger pin, echo pin
Rangefinder range(7, 6);

// pin A is pin 2
// pin B is pin 3
// pin C is pin 4
// ...
// pin DP is pin 11
Display disp(2, 3, 4, 5, 8, 9, 10, 11);

void setup() {
  Serial.begin (9600);
}

void loop() {
  // grabs a pulse
  range.pulse();
  // how to use the distance
  float distance = range.get(); // distance in cm
  int distanceDigit = distance / 10;
  if (distanceDigit > 9) {
    distanceDigit = 9;
  }
  Display.write(distanceDigit);
  // prints it to the serial port
  range.print();
  delay(100);
}
