#include "rangefinder.h"

// trigger pin, echo pin
Rangefinder range(7, 6);

void setup() {
  Serial.begin (9600);
}

void loop() {
  // grabs a pulse
  range.pulse();
  // how to use the distance
  float distance = range.get();
  // prints it
  range.print();
  delay(100);
}
