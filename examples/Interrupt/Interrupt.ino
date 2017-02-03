#include "RotaryEncoder.h"

RotaryEncoder encoder;

boolean interruptCalled = false;

void updateOnInterrupt() {
  interruptCalled = true;
}

void interruptGateway() {
  updateOnInterrupt();
}

void updateEncoder() {
  unsigned char result = encoder.process(digitalRead(2), digitalRead(3));

  if (result == DIR_NONE) {
    // do nothing
  }
  else if (result == DIR_CW) {
    Serial.println("turn left");
  }
  else if (result == DIR_CCW) {
    Serial.println("turn right");
  }
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(2), interruptGateway, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(3), interruptGateway, CHANGE); // for double interrupt usage -> better detection
}

void loop() {
  if(interruptCalled == true) {
    updateEncoder();

    interruptCalled = false;
  }
}
