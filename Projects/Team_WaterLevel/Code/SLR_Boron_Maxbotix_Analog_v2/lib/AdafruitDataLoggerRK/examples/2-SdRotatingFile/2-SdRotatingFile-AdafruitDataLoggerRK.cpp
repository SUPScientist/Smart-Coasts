// This example shows how to print text data to rotating files on the SD card. When the file reaches
// a certain file size, a new numerically increasing file is created. If the maximum number of files
// is exceeded, the oldest is deleted.
//
// You can find out how to customize the number of files, file size, etc. here:
// https://github.com/rickkas7/SdCardLogHandlerRK

#include "Particle.h"

#include "SdCardLogHandlerRK.h"

SYSTEM_THREAD(ENABLED);

// The SD card CS pin on the Adafruit AdaLogger FeatherWing is D5.
const int SD_CHIP_SELECT = D5;
SdFat sd;

SdCardPrintHandler printToCard(sd, SD_CHIP_SELECT, SPI_FULL_SPEED);

size_t counter = 0;

void setup() {
	Serial.begin();
}

void loop() {
	printToCard.printlnf("testing counter=%d", counter++);
	delay(1000);
}
