// Demo LEDs for the Wokwi simulator.

// no leg in phgysical pcb but it looks cool in demo i guess...
#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

#if defined(ARDUINO_NANO_ESP32)
  #define DEMO_LEDS 0
#else
  #define DEMO_LEDS 1
#endif
// Button LED indices

const int LED_LEFT  = 0;
const int LED_OK    = 1;
const int LED_RIGHT = 2;
const int LED_RESET = 3;
// How many of each

const int BUTTON_LED_COUNT = 4;
const int METER_LED_COUNT  = 6;
// Functions

// Configure the pins
void initLeds();

// Called once per frame from updateGame()
void updateLeds();

// Light one button LED briefly (non-blocking)
void flashButtonLed(int index);

#endif
