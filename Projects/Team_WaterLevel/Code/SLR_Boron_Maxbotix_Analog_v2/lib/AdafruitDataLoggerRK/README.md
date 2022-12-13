# AdafruitDataLoggerRK

*Library for Adafruit AdaLogger SD card and RTC FeatherWing*

![Adafruit AdaLogger](images/feather-logger.jpg)

This library is just a wrapper around the two things on the FeatherWing:

- [Adafruit\_RTClib\_RK](https://github.com/rickkas7/Adafruit_RTClib_RK), a port of the Adafruit RTCLib (real time clock)
- [SdCardLogHandlerRK](https://github.com/rickkas7/SdCardLogHandlerRK), a utility for writing log files to SD card
- SdFat, included by SdCardLogHandlerRK

The SD card is connected to the SPI bus and the default connection for the CS pin is D5. 

| Pin | Usage |
| --- | ----- | 
| MISO | SD Card DO |
| MOSI | SD Card DI |
| SCK | SD Card SCK | 
| D5 | SD Card CS

The RTC can only be used if the CR1220 battery is inserted. It connects by I2C and uses address 0x68.

| Pin | Usage |
| --- | ----- | 
| D0 | RTC I2C SDA |
| D1 | RTC I2C SCL |

## Examples

There are three examples:

### 1-SdFat

The SdFat example is basically the SdFat TryMeFirst example and shows how to do basic SdFat operations.

### 2-SdRotatingFile

This example makes it easy to write to a rotating log file. Each file is sequentially numbered. The largest number is newest, and writing appends to this file.

The maximum size of the file can be specified, as can the maximum number of files to keep.

This is intended to be used with text-based information, as data is written to the card by lines (ending with \n).

### 3-TimeSync

The TimeSync example shows how the RTC can be set from the cloud time, and how the Time class time can be set from the RTC. This is helpful on the 3rd-generation devices, because the nRF52840 does not maintain time in deep sleep modes or when powered down.

