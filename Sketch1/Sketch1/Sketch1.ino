/*
 Name:		LEDTest.ino
 Created:	5/18/2016 9:55:34 AM
 Author:	ChaseStLaurent
*/

void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
}


void loop() {
	oscillateLED();
}

// Turn LED on and then off
void oscillateLED() {
	digitalWrite(13, HIGH);
	Serial.println("LED on");
	delay(1000);
	digitalWrite(13, LOW);
	Serial.println("LED off");
	delay(1000);
}
