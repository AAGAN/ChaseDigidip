/*
@author Chase St. Laurent

4 Digit 7 Segment display controlled by Potentiometer readings
(Using Serial)

*/
#include <SoftwareSerial.h>
#include <SoftwareSerial\src\SoftwareSerial.h>

SoftwareSerial Serial7Segment(7, 8);

int cycles = 0;

void setup() {
	Serial.begin(9600); //Start serial communication at 9600 for debug statements
	Serial7Segment.begin(9600);
	Serial7Segment.write('v');
}

void loop() {
	int sensorValue = analogRead(A0);
	Serial.println(sensorValue);
	int correctionFactor = analogRead(A0) * 11;// Increase by a digit and scale 
	if (analogRead(A0) <= 999 && correctionFactor <= 9999) {
		cycles = correctionFactor;
	}
	else {
		cycles = 9999;
	}

	Serial.print("Cycle: ");
	Serial.println(cycles);
	sendValue(cycles);

	delay(1000);
}

//Send the four characters to the display
void sendValue(int tempCycles) {
	char tempString[10];
	sprintf(tempString, "%4d", tempCycles);
	Serial7Segment.print(tempString);
	delay(10);

}
