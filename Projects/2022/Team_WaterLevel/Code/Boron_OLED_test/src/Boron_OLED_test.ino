/*
 * Project Boron_OLED_test
 * Description: Testing Particle Boron OLED Function
 * Author:
 * Date: 10/27/2022
 */

#include "oled-wing-adafruit.h"

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
display.println("Hello, World!");
display.display();
}

if (display.pressedB()) {
}

if (display.pressedC()) {
}
}