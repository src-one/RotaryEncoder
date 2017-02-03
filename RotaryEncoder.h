#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Arduino.h"

// #define HALF_STEP use it for different type of rotary encoders

#define DIR_NONE 0x0
#define DIR_CW 0x10
#define DIR_CCW 0x20

class RotaryEncoder
{
  public:
    RotaryEncoder();
    unsigned char process(bool channel1, bool channel2);
  private:
    unsigned char state;
};

#endif
