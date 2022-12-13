// This example shows how to use the RTCSynchronizer class. You should only use this if you've
// inserted a CR1220 coin cell battery in the AdaLogger. Running the RTC without the battery
// can result in unpredictable behavior.
//
// If the RTC is not synchronized, it will be set from the cloud when the cloud time is received.
// If the Time class time is not set yet, but the RTC is, the RTC will be use to set Time.
// This is particularly handy on the nRF52 as its RTC does not increment in sleep modes and will
// not be accurate.

#include "AdafruitDataLoggerRK.h"

SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler;

RTCSynchronizer rtcSync;

void setup() {
	rtcSync.setup();
}

void loop() {
	rtcSync.loop();
}

