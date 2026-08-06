# Bill of Materials — World Cup Love Machine

Derived from `outpost.kicad_sch` / `outpost.kicad_pcb` (6 placed components) plus the
mechanical and firmware requirements.

## Electronics

| Ref | Qty | Part | Spec | KiCad footprint |
|-----|-----|------|------|-----------------|
| A1 | 1 | Arduino Nano ESP32 | ESP32-S3, USB-C, 3.3 V logic | `Connector_PinHeader_1.00mm:PinHeader_2x15_P1.00mm_Horizontal` — **see Known issues** |
| J3 | 1 | 4-pin header, 2.54 mm vertical | Carries the I2C OLED: 5V, GND, SDA, SCL | `Connector:FanPinHeader_1x04_P2.54mm_Vertical` |
| SW1 | 1 | Tactile push button, 6 mm THT | LEFT | `Button_Switch_THT:SW_PUSH_6mm` |
| SW2 | 1 | Tactile push button, 6 mm THT | OK | `Button_Switch_THT:SW_PUSH_6mm` |
| SW3 | 1 | Tactile push button, 6 mm THT | RIGHT | `Button_Switch_THT:SW_PUSH_6mm` |
| SW4 | 1 | Tactile push button, 6 mm THT | RESET | `Button_Switch_THT:SW_PUSH_6mm` |

No resistors or capacitors are required. The buttons use the ESP32's internal
pull-ups (`INPUT_PULLUP` in `WorldCupLoveMachine.ino`) and are wired
button-to-GND, so no external pull-ups are on the board.

## Off-board parts

| Qty | Part | Spec |
|-----|------|------|
| 1 | SSD1306 OLED module | 128×64, I2C, address `0x3C`, 4-pin (monochrome) |
| 1 | Custom PCB | 2-layer; fab with `outpost.kicad_pcb` + `outpost-PTH.drl` / `outpost-NPTH.drl` |
| 1 | 3D-printed enclosure | Print from `model.stl` (source: `step.step`) |
| 1 | USB-C cable | Power + programming |
| 1 | Pin header / socket strip for A1 | Pitch must match the board — see Known issues |

## Pin mapping

From `WorldCupLoveMachine.ino` and the schematic net labels:

| Signal | Arduino pin | Goes to |
|--------|-------------|---------|
| LEFT | D2 | SW1 |
| OK | D3 | SW2 |
| RIGHT | D4 | SW3 |
| RESET | D5 | SW4 |
| SDA | A4 | J3 (OLED) |
| SCL | A5 | J3 (OLED) |
| 5V | VUSB/5V | J3 (OLED) |
| GND | GND | J3, SW1–SW4 |

J3's net order in the schematic runs 5V, GND, SDA, SCL. Many SSD1306 breakouts
ship as GND, VCC, SCL, SDA — **wire by label, not by position.**

## Firmware build

Board package: **Arduino ESP32 Boards** (`arduino:esp32`), board *Arduino Nano ESP32*
(FQBN `arduino:esp32:nano_nora`).

Libraries (Library Manager):

- Adafruit SSD1306
- Adafruit GFX Library
- Adafruit BusIO (pulled in as a dependency)

`Wire` ships with the core. Build with the Arduino IDE, or:

```sh
arduino-cli lib install "Adafruit SSD1306" "Adafruit GFX Library"
arduino-cli compile --fqbn arduino:esp32:nano_nora .
arduino-cli upload  --fqbn arduino:esp32:nano_nora -p /dev/ttyACM0 .
```

The sketch folder name must stay `WorldCupLoveMachine` to match the `.ino`.

## Simulator (no hardware needed)

The firmware runs unmodified in [Wokwi](https://wokwi.com) — see [`sim/README.md`](sim/README.md)
for setup, and [`sim/diagram.json`](sim/diagram.json) for the wiring.

Board: `board-esp32-s3-devkitc-1`. The Arduino Nano ESP32 is an ESP32-S3, so the button
pins (2/3/4/5) and the default-`Wire` OLED init carry over with no code changes.

Wokwi link: _(paste the Share URL here once the project is saved)_

These parts exist **only in the simulation** — they are not on the PCB:

| Qty | Part | Purpose |
|-----|------|---------|
| 4 | LED | One per button, flashes on press (GPIO 6, 7, 10, 11) |
| 6 | LED | Compatibility "score meter" bar (GPIO 12–17) |
| 10 | 220 Ω resistor | One per LED |

`leds.h` sets `DEMO_LEDS` to 0 when `ARDUINO_NANO_ESP32` is defined, so hardware builds
compile the LED module away entirely and never drive those GPIOs. If you ever do want
lights on a real board, that guard is the single place to change.

## Known issues

- **A1 footprint pitch mismatch.** The schematic symbol's default footprint is
  `Module:Arduino_Nano`, but the placed A1 instance uses a 2×15 header at
  **1.00 mm** pitch (pads on a 1 mm grid in `outpost.kicad_pcb`). An Arduino Nano
  ESP32 has 2.54 mm pitch pins with 15.24 mm between rows, so it will not fit
  these holes. Re-assign A1 to `Module:Arduino_Nano` and re-route before ordering
  boards, or plan to hand-wire the module.
- `parts.zip` contains the two drill files, not a parts list.
