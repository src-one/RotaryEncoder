#include "RotaryEncoder.h"

RotaryEncoder encoder;

#define ENC_A 2
#define ENC_B 3

boolean interruptCalled = false;

void updateOnInterrupt() {
  interruptCalled = true;
}

void interruptGateway() {
  updateOnInterrupt();
}

void updateEncoder() {
  unsigned char result = encoder.process(digitalRead(ENC_A), digitalRead(ENC_B));

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
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);

  attachInterrupt(digitalPinToInterrupt(ENC_A), interruptGateway, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(ENC_B), interruptGateway, CHANGE); // for double interrupt usage -> better detection
}

void loop() {
  if(interruptCalled == true) {
    updateEncoder();

    interruptCalled = false;
  }
}
