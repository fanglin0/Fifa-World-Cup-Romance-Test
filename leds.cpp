// Demo LEDs for the Wokwi simulator.
#include "leds.h"
#include "game.h"

#if DEMO_LEDS
// Pin assignments; Chosen to avoid I2C (8, 9), the buttons (2-5),
// UART0 (43, 44), USB (19, 20), the strapping pins
// (0, 45, 46) and flash/PSRAM (26-37).
static const int buttonLedPins[BUTTON_LED_COUNT] = {

    6,   // LEFT
    7,   // OK
    10,  // RIGHT
    11   // RESET

};

static const int meterLedPins[METER_LED_COUNT] = {

    12, 13, 14, 15, 16, 17

};
// Button LED flash timers

const unsigned long ledFlashTime = 120;

static unsigned long ledOffAt[BUTTON_LED_COUNT] = { 0, 0, 0, 0 };
// Init

void initLeds()
{

    for(int i = 0; i < BUTTON_LED_COUNT; i++)
    {

        pinMode(buttonLedPins[i], OUTPUT);

        digitalWrite(buttonLedPins[i], LOW);

        ledOffAt[i] = 0;

    }

    for(int i = 0; i < METER_LED_COUNT; i++)
    {

        pinMode(meterLedPins[i], OUTPUT);

        digitalWrite(meterLedPins[i], LOW);

    }

}
// Flash One Button LED
//
// Non-blocking - updateLeds() turns it back off.

void flashButtonLed(int index)
{

    if(index < 0 || index >= BUTTON_LED_COUNT)
        return;

    digitalWrite(buttonLedPins[index], HIGH);

    ledOffAt[index] = millis() + ledFlashTime;

}
// Score Meter

static void setMeter(int litCount)
{

    for(int i = 0; i < METER_LED_COUNT; i++)
    {

        digitalWrite(
            meterLedPins[i],
            i < litCount ? HIGH : LOW
        );

    }

}
// Per-Frame Update

void updateLeds()
{


    // Expire any button flashes


    for(int i = 0; i < BUTTON_LED_COUNT; i++)
    {

        if(ledOffAt[i] != 0 && millis() >= ledOffAt[i])
        {

            digitalWrite(buttonLedPins[i], LOW);

            ledOffAt[i] = 0;

        }

    }


    // Meter


    switch(gameState)
    {
        // Chase while "analyzing"

        case LOADING:

            setMeter(0);

            digitalWrite(
                meterLedPins[
                    (loadingProgress / 4) % METER_LED_COUNT
                ],
                HIGH
            );

            break;
        // Fill to the match percentage
        //
        // compatibilityScore is clamped to 60..99 by
        // calculateCompatibility(), so this maps exactly
        // onto 1..METER_LED_COUNT lit LEDs.

        case RESULT:
        case PROFILE:

            setMeter(
                map(
                    compatibilityScore,
                    60,
                    99,
                    1,
                    METER_LED_COUNT
                )
            );

            break;

        default:

            setMeter(0);

            break;

    }

}

#else
// Real hardware has no LEDs - everything compiles away.

void initLeds() {}

void updateLeds() {}

void flashButtonLed(int) {}

#endif
