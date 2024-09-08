#ifndef __ADAFRUITDATALOGGERRK_H
#define __ADAFRUITDATALOGGERRK_H

// https://www.adafruit.com/product/2922
// Optional CR1220

// https://learn.adafruit.com/adafruit-adalogger-featherwing/overview

// I2C realtime clock PCF8523
// https://github.com/adafruit/RTClib

#include "Adafruit_RTClib_RK.h"
#include "SdFat.h"


/**
 * @brief Class to synchronize the Adafruit AdaLogger RTC to and from the Particle time
 */
class RTCSynchronizer {
public:
	/**
	 * @brief Constructor. You typically make this object a global variable.
	 */
	RTCSynchronizer();

	/**
	 * @brief Destructor. You typically don't destruct this, as it's typically a global object.
	 */
	virtual ~RTCSynchronizer();

	/**
	 * @brief Call from setup(). Required.
	 */
	void setup();

	/**
	 * @brief Call from loop(). Required.
	 */
	void loop();

	/**
	 * @brief Used internally from setup and loop methods
	 */
	void syncTime();

protected:
	RTC_PCF8523 rtc;
	bool hasRTC = false;
};

#endif /* __ADAFRUITDATALOGGERRK_H */
