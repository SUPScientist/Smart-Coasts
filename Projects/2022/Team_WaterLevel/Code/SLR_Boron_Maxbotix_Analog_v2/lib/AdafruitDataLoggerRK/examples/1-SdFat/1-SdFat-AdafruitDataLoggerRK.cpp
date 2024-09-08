
#include "SdFat.h"

// The SD card CS pin on the Adafruit AdaLogger FeatherWing is D5.
const int SD_CHIP_SELECT = D5;
SdFat sd;
unsigned long lastTest = 0;

void tryMeFirst();

void setup() {
	Serial.begin();
}

void loop() {
	if (millis() - lastTest >= 10000) {
		lastTest = millis();
		tryMeFirst();
	}
}

void tryMeFirst() {
	File myFile;

	// Initialize the library
	if (!sd.begin(SD_CHIP_SELECT, SPI_FULL_SPEED)) {
		Serial.println("failed to open card");
		return;
	}

	// open the file for write at end like the "Native SD library"
	if (!myFile.open("test.txt", O_RDWR | O_CREAT | O_AT_END)) {
		Serial.println("opening test.txt for write failed");
		return;
	}
	// if the file opened okay, write to it:
	Serial.print("Writing to test.txt...");
	myFile.println("testing 1, 2, 3.");
	myFile.printf("fileSize: %d\n", myFile.fileSize());

	// close the file:
	myFile.close();
	Serial.println("done.");

	// re-open the file for reading:
	if (!myFile.open("test.txt", O_READ)) {
		Serial.println("opening test.txt for read failed");
		return;
	}
	Serial.println("test.txt content:");

	// read from the file until there's nothing else in it:
	int data;
	while ((data = myFile.read()) >= 0) {
		Serial.write(data);
	}
	// close the file:
	myFile.close();
}
