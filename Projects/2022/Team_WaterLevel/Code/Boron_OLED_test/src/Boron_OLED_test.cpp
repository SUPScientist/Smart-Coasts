/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/CLASSES_2021_2022/Fall_2022/OCN_479/Seaport_Tide-SLR/Firmware/Boron_OLED_test/Boron_OLED_test/src/Boron_OLED_test.ino"
/*
 * Project Boron_OLED_test
 * Description: Testing Particle Boron OLED Function
 * Author:
 * Date: 10/27/2022
 */

#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 10 "d:/CLASSES_2021_2022/Fall_2022/OCN_479/Seaport_Tide-SLR/Firmware/Boron_OLED_test/Boron_OLED_test/src/Boron_OLED_test.ino"
OledWingAdafruit display;

SYSTEM_MODE(MANUAL); // uncomment for prelim testing
// SYSTEM_MODE(SEMI_AUTOMATIC); // uncomment for deployment
SYSTEM_THREAD(ENABLED);


void setup() {

Cellular.off(); // turn off cellular for prelim testing (uncomment)

display.setup();

display.clearDisplay();
display.display();
}

void loop() {
display.loop();

if (display.pressedA()) {
display.clearDisplay();

display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("Hey, Summer!");
display.display();
}

if (display.pressedB()) {
}

if (display.pressedC()) {
}
}