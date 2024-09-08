/*
 * Project Chlororphyll_flourometer
 * Description:
 * Author: Jessie Wynne
 * Date: 10/27/22
 */

#include <SdFat.h>
#include <Time.h>
SdFat SD;
int MY_LED = D5;
int read1;
int read2;
int read3;
int read4;
int read5;
int val;
File myFile;
#define now
#define month
#define day
#define year
#define hour
#define minute
#define second



// setting the command to D5 where the LED is located 

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);
// The setup() method is called once when the device boots.
void setup()
{
pinMode(10, OUTPUT); // power up data logger
if (!SD.begin(10)) {
return;
}
  // Particle.disconnect();
  // WiFi.off();
	// In order to set a pin, you must tell Device OS that the pin is
	// an OUTPUT pin. This is often done from setup() since you only need
	// to do it once.
	pinMode(MY_LED, OUTPUT);
    analogRead(DEFAULT);
	myFile= SD.open("data.txt", FILE_WRITE);
	myFile.println("Start");
}
// The loop() method is called frequently.
void loop()
{
	if (myFile); {
    for (int j = 0; j < 50; j++) { // collect 50 measurements
delay(10); // delay until next measurement
digitalWrite(4,HIGH);
delay(10); // allow LED to warm up for 1.5 minutes
for (int x = 0; x < 10; x++) { // collect ten measurements
    read1 = analogRead(0);
delay(100);
read2 = analogRead(0);
delay(100);
read3 = analogRead(0);
delay(100);
read4 = analogRead(0);
delay(100);
read5 = analogRead(0);
val = (read1+read2+read3+read4+read5)/5; // average 5 measurements taken 100ms apart
time_t t = (now(t)); // next 28 lines write the date and time to the SD card
if(month(t) < 10) {
myFile.print(0);
}
myFile.print(month(t));
myFile.print("/");
Serial.print(month(t));
Serial.print("/");
if(day(t) < 10) {
myFile.print(0);
}
myFile.print(day(t));
myFile.print("/");
myFile.print(year(t));
myFile.print(" ");
if(hour(t) < 10) {
myFile.print(0);
}
myFile.print(hour(t));
myFile.print(":");
if(minute(t) < 10) {
myFile.print(0);
}
myFile.print(minute(t));
myFile.print(":");
if(second(t) < 10) {
myFile.print(0);
}
myFile.print(second(t));
myFile.print(" @ ");
myFile.println(val);
}
digitalWrite(4,LOW); // turn LED off
}
}
myFile.close(); // closes file
while(1) { // LED blinks when measurements are done
digitalWrite(4,HIGH);
delay(1000);
digitalWrite(4,LOW);
delay(2000);
}

	// And repeat!
  