#include "SdFat.h"
#include "Adafruit_ADS1X15.h"

// The SD card CS pin on the Adafruit AdaLogger FeatherWing is D5.
const int SD_CHIP_SELECT = D5;
SdFat sd;
Adafruit_ADS1115 ads; 
unsigned long lastTest = 0;

void tryMeFirst();

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup..");
  
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful NEVER TO EXCEED +0.3V OVER VDD ON GAINED INPUTS,
  // or exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may DESTROY your ADC!
  //
  //  *** TAKE CARE WHEN SETTING GAIN TO NOT EXCEED ABOVE LIMITS ON INPUT!!
  //                                                                    ADS1015   ADS1115
  //                                                                    -------   -------
   ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit =       3mV       0.1875mV (DEFAULT)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit =     2mV       0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit =     1mV       0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit =     0.5mV     0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit =     0.25mV    0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit =     0.125mV   0.0078125mV  
  ads.begin();
  
  Serial.println("Getting single-ended readings from AIN01,2,3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 0.1875mV for ADS1115)");
}

void loop() {
	if (millis() - lastTest >= 10000) {
		lastTest = millis();
		tryMeFirst();
	}
}

void tryMeFirst() {
	File myFile;

    double multiplier = 0.1875F; //milli Volts per bit for ADS1115
  //double multiplier = 3.0F; //milli Volts per bit for ADS1105

  short adc0, adc1, adc2, adc3;
  double av0, av1, av2, av3;
  
  adc0 = ads.readADC_SingleEnded(0);
  av0 = adc0 * multiplier;
  adc1 = ads.readADC_SingleEnded(1);
  av1 = adc1 * multiplier;
  adc2 = ads.readADC_SingleEnded(2);
  av1 = adc1 * multiplier;
  adc3 = ads.readADC_SingleEnded(3);
  av3 = adc3 * multiplier;
  
  Serial.print("AIN0: "); Serial.print(adc0); Serial.print(", AV0: "); Serial.print(av0,7); Serial.println("mV");
  Serial.print("AIN1: "); Serial.print(adc1); Serial.print(", AV1: "); Serial.print(av1,7); Serial.println("mV");
  Serial.print("AIN2: "); Serial.print(adc2); Serial.print(", AV2: "); Serial.print(av2,7); Serial.println("mV");
  Serial.print("AIN3: "); Serial.print(adc3); Serial.print(", AV3: "); Serial.print(av3,7); Serial.println("mV");
  Serial.println(" ");

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
	myFile.print("millis: ");
  myFile.print(millis());
  myFile.print("Time: ");
  myFile.print(Time.now());
  myFile.print("AIN0: "); myFile.print(adc0); myFile.print(", AV0: "); myFile.print(av0,7); myFile.println("mV");
  myFile.print("AIN1: "); myFile.print(adc1); myFile.print(", AV1: "); myFile.print(av1,7); myFile.println("mV");
  myFile.print("AIN2: "); myFile.print(adc2); myFile.print(", AV2: "); myFile.print(av2,7); myFile.println("mV");
  myFile.print("AIN3: "); myFile.print(adc3); myFile.print(", AV3: "); myFile.print(av3,7); myFile.println("mV");
  myFile.println(" ");

	// close the file:
	myFile.close();
	Serial.println("done.");

}

