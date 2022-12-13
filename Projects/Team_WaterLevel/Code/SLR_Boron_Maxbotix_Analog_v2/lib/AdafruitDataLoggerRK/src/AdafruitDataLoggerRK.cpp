#include "AdafruitDataLoggerRK.h"


RTCSynchronizer::RTCSynchronizer() {

}

RTCSynchronizer::~RTCSynchronizer() {

}

void RTCSynchronizer::setup() {
	hasRTC = rtc.begin();
	syncTime();
}

void RTCSynchronizer::loop() {
	syncTime();
}

void RTCSynchronizer::syncTime() {
	if (!hasRTC) {
		return;
	}

	// We have an RTC on the I2C bus

	if (!rtc.initialized()) {
		if (Time.isValid()) {
			// We have time from the cloud, so use it to set the RTC
		    uint32_t now = Time.now();

		    Log.info("setting RTC from cloud %s", Time.format(now, TIME_FORMAT_DEFAULT).c_str());

		    rtc.adjust(DateTime(Time.year(now), Time.month(now), Time.day(now), Time.hour(now), Time.minute(now), Time.second(now)));
		}
	}
	else {
		if (!Time.isValid()) {
			// RTC is initialized, but we haven't gotten time from the cloud, so set the time that way
			DateTime now = rtc.now();

			Time.setTime(now.unixtime());

		    Log.info("setting Time from RTC %s", Time.format(Time.now(), TIME_FORMAT_DEFAULT).c_str());
		}
	}
}

