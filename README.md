Features
--------
* Debounce handling with support for high rotation speeds
* Correctly handles direction changes mid-step
* Checks for valid state changes for more robust counting / noise immunity
* Interrupt based or polling in loop()
* Counts full-steps (default) or half-steps

The following is the typical sequence of code on the output when moving from one step to the next:

    Position   Bit1   Bit2
    ----------------------
    Step1      0      0
    1/4        1      0
    1/2        1      1
    3/4        0      1
    Step2      0      0

- From an initial 0 - 0, Bit 1 goes high, Bit 0 stays low
- Then both bits are high, halfway through the step
- Then Bit 1 goes low, but Bit 2 stays high
- Finally at the end of the step, both bits return to 0
