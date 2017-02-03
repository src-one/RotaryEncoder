#include "RotaryEncoder.h"
RotaryEncoder encoder;

#define ENC_A 2
#define ENC_B 3

int count = 0;
int lastCount = 0;
boolean interruptCalled = false;

void updateOnInterrupt() {
  interruptCalled = true;
}

void interruptGateway() {
  updateOnInterrupt();
}

void updateCount(int value) {
  Serial.println("Value: " + String(value));
}

void updateEncoder() {
  unsigned char result = encoder.process(digitalRead(ENC_A), digitalRead(ENC_B));
  if (result == DIR_NONE) {
    // do nothing
  }
  else if (result == DIR_CW) {
    count ++;
  }
  else if (result == DIR_CCW) {
    count --;
  }

  if(lastCount != count) {
    updateCount(count);
    lastCount = count;
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_A), interruptGateway, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_B), interruptGateway, CHANGE);
}

void loop() {
  if(interruptCalled == true) {
    updateEncoder();
    interruptCalled = false;
  }
}
