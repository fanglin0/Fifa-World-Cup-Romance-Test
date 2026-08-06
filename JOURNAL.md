# FIFA World Cup Player Love Compatibility Test Journal (total: 

##  7/3/26 ~4.5 hours (recorded on Lapse)
I created the schematic and pcb, wired everything together. I went through a couple designs and had to troubleshoot with friends to finish the design. I looked for the easiest way to get my deaisgn up and running and landed on the Arudino ESP 32.
<img width="815" height="666" alt="Screenshot 2026-07-03 at 6 18 37 PM" src="https://github.com/user-attachments/assets/5c66b1b3-d826-460a-b5c4-cbd4bf8d1cbf" />
<img width="815" height="727" alt="Screenshot 2026-07-03 at 3 00 02 PM" src="https://github.com/user-attachments/assets/923e4688-fe49-48ea-9a7e-18c63adbcd06" />


##  7/4/26 ~3 hours 
I started researching how to code the logic behind my love compatibility test, started looking for and researching C++ tutorials for my Arduino. I also realized that I cannot test my script as I do not (yet) have a in person arduino to connect to my laptop and test on, and the online (free) ones I've tested turns out to be too slow to simulate. So I'm just stringing together tutorial code and hoping it works.
<img width="1023" height="765" alt="Screenshot 2026-07-03 at 7 19 39 PM" src="https://github.com/user-attachments/assets/c594247e-38d6-44bf-9d27-b373011efdaf" />
<img width="658" height="165" alt="Screenshot 2026-07-03 at 6 19 22 PM" src="https://github.com/user-attachments/assets/dba1fdba-41a4-4358-b7e7-9a160d489dc3" />


## 7/5/26 ~6 hours
Finished my schematic pcb and made sure all the wires worked. I trial and error'ed my way through the wiring and then realized there's different layers with the guidance of my friend. I started expeirmenitng and making functions in game.h, had to troubleshoot with chatgpt. 


## 7/6 ~6 hours
Making the personality, the players, questions, and the fucntions in the game to track user motion from the input in buttons. Made ui with animation with the display text


## 7/7 ~4 hours (Lapse partly)
Debugging code. Attempting to rig a 3d case, handheld display like cover for the arduino. 
<img width="631" height="570" alt="Screenshot 2026-07-07 at 8 47 31 PM" src="https://github.com/user-attachments/assets/1cb4a7b6-922c-4425-82a7-cc5eb65bb236" />

## 7/9 ~3 hours GOT REJECTED FROM OUTPOST LMAO
Made a BOM.csv file as per reviewer note. Was told there were multiple traces in your PCB routing that are >90 degrees (whcih ) will cause the routing to either break or act as a fuse). idk how that works and messed around trying to make routing better. Follwoed <a href="https://forum.kicad.info/t/approaching-pcb-track-routing-for-a-newbie/36302/8">this old forum post, and tried to follow guide to make everything on layer and as horizontal as possible.

## 7/10 ~1.8 hours
Made a model.stl file for my onshape case holder thingy, expanded the tracing a bit so changed the shape up as well

## 7/15 ~1.5 hours
Which arudino package is ts...?? <img href=screenshots/Screenshot 2026-07-15 at 1.27.12 PM.png>. Had to go into <a href="https://docs.arduino.cc/hardware/nano-esp32/">Boards Manager</a> and installed the "Arduino ESP32 Boards" package and Adafruit SSD1306 isn't there. use ai help

## 7/16 ~4 hours
`multiple definition of drawCenteredText`. Ok so the display is NOT working. Realized, like my reviewers said, it would not compile as is and arduino doesnt run. Chatgpt said wowki would work. I put my code in and it didn't run? Chatgpt told me my drawing functions were broken, also my repo was empty .ino AND left them in ui.cpp, so the linker was seeing two of everything. i had to make one singular function and move all my functions into one

## 7/17-20 ~8 hours
为什么是 black!! the i2c_scanner sketch (File > Examples > Wire) and display at 0x30 hardcoded that in `display.begin()`. I went down <a href="https://learn.adafruit.com/monochrome-oled-breakouts">a forum rabbit hole and learned very one</a>of these little breakouts prints its pins in a different order — mine is GND/VCC/SCL/SDA but my J3 header in the schematic is 5V/GND/SDA/SCL, which are completely different. I'd followed chatgpt instruction and assumed it was the same but I guess I'd fry something?? if i continue wiring by the label

## 7/21 ~3 hours
<a href="https://docs.arduino.cc/built-in-examples/digital/InputPullupSerial">Turns out with `INPUT_PULLUP` was flipped</a>. The pin sits HIGH and pressing it pulls it to LOW. My chatgpt code `if (digitalRead(pin) == HIGH)` was backwards the entire time :sob:. Then one press was skipping through like 6 questions at once??????? because loop() runs thousands of times a second and holds the button the whole way <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTosE8fUoZ4H_T7w2rj8XvrLZfTz3EG0fz4rPky0lRESw&s=10"> which made my laptop rly hot. <a href="ttps://docs.arduino.cc/built-in-examples/digital/Debounce">Fixed</a> so it only fired on the HIGH->LOW *edge*.


## 7/22 ~3 hours
<img src=screenshots/Screenshot 2026-07-21 at 7.49.57 PM.png>
The blinking heart on the title screen worked!!!! froze the whole program while it blinked bc of delay() Same thing killed the loading bar. i realized ur not supposed to wait but <a href="https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay">  `millis() - lastTime > interval` every frame and only act when i's true. Redid it with heartTimer and loadingTimer as `unsigned long`, which the tutorial says has to be unsigned long or it overflows after 32 seconds. Now the buttons still respond while things are animating. Now things kinda work w the questions but they cut off


## 7/23 ~5 hours
Adafruit GFX just breaks lines in the middle of a word and then happily keeps drawing past the bottom of the panel into nowhere, so half my player descriptions were invisible. <a href=" https://learn.adafruit.com/adafruit-gfx-graphics-l
ibrary"Wrote my own drawWrappedText that counts 21 chars per line</a>, walks *backwards* to the last space so it breaks between words, and takes a maxLines so it physically can't run off the screen. If it runs out of room and there's still text left it chops the last few chars and puts "..." on the end


## 7/24 ~4 hours
Im. so sick oh my lord. "YOUR MATCH!" at text size 2 is 132px wide and the screen is 128, so it was clipped on BOTH sides — dropped the exclamation mark and it fits. The soccer balls were at y=10 which put them straight on top of "WORLD CUP",moved them to y=48 down by the heart. The profile screen was the worst, description and warning wereoverlapping each other, so I put everything on an8px grid (10/18/26 for the description, 36/44/52 for the warning) and used "! " instead of writing out "Warning:" — that saves 7 characters which is the difference between all 12 warnings fitting and 6 of them getting cut off. 
<img src=assets/Screenshot 2026-08-05 at 8.04.36 PM.png>
<!-- screenshot: wokwi sim showing the profile screen fitting -->


## 7/25 ~4.5 hours
Made the actual matching work. Every player has 6 trait numbers (kindness, humor, confidence, creativity, loyalty, ambition) and so does the user by the end of the quiz, so I loop all 12 players, add up the absolute differences, and whoever is closest wins. Everyone was getting Messi no matter what they answered — my traits were all still 0 because I was writing them in the wrong place, they only counted when you hit OK, not while scrolling. Then map() to turn a difference into a percent (https://docs.arduino.cc/language-reference/en/functions/math/map/), backwards on purpose so a *small* difference gives a *big* percent.


## 7/26 ~.75 hours
Added `random(-4, 5)` on top so result percentages wobbles a bit and clamped it to 60-99. 


## 7/27 ~4 hours
Wrote all 12 questions and all 12 player profiles, which took longer than any of the code. And then I reqalized out I could put `\n` like in Java inside the question string and println just handles the line break, so "Your biggest\nstrength?" splits itself. Accoridng to https://docs.arduino.cc/learn/programming/memory-guide/ String is bad on embedded and you should use PROGMEM BUT it compiles and runs fine on the ESP32 rn so I'm leaving it.


## 7/28 ~4 hours
<img src=screenshots/Screenshot 2026-08-05 at 8.12.43 PM.png>
Added LEDs to the sim — 4 that flash when you press a button, 6 as a little score meter bar. These are NOT on my actual PCB, they just make the Wokwi demo look alive. Wrapped the whole thing in `#if DEMO_LEDS` and set that to 0 when `ARDUINO_NANO_ESP32` is defined, so a real hardware build compiles the entire module away instead of driving pins that don't exist. Picking the GPIOs was annoying — had to dodge I2C (8, 9), my buttons (2-5),UART0 (43, 44), USB (19, 20), the strapping pins(0, 45, 46) and the flash/PSRAM pins (26-37). Landed on 6, 7, 10, 11 and 12-17. Also 10 resistorsbecause apparently you cannot just put an LED straight across a pin.


## 7/29 ~2 hours
So Claude tells me after troublsheeoitng that I'd have to reassign A1 to `Module:Arduino_Nano` and re-route, or hand-wire it bc my A1 footprint is a 2x15 header at **1.00 mm** pitch but a real Nano ESP32 has 2.54 mm pins with 15.24 mm between the rows but im gonna leave it 4 now. That's a problem for when I have to build it lmao


## 7/31 ~2 hours
<img src="screenshots/Screenshot 2026-08-05 at 8.10.54 PM.png">
3D case, changed a little to have spaces for the lights 

## 8/2 ~2 hours
<img src=screenshots/Screenshot 2026-08-05 at 7.59.40 PM.png>
Rejected from Horizons for missing BOM list with updated stuff Made one through claude
