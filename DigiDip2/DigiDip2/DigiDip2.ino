/*
 Name:		DigiDip2.ino
 Created:	5/18/2016 12:26:47 PM
 Author:	ChaseStLaurent
*/

//--------------------------------------
//IMPORT LIBRARIES
#include <SPI\src\SPI.h>
#include <rtcapi.h>
#include <Wire\src\Wire.h>
#include <SD\src\SD.h>
#include <Sspi.h>
//--------------------------------------

//--------------------------------------
//BUTTON SETUP

//Save button connected to digital pin 3
#define saveButton 3
//Power button connected to digital pin 5
#define	powerButton 5
//Undo button connected to digital pin 6
#define	undoButton 6
//Erase All button connected to digital pin 9
#define eraseAllButton 9
//New Set button connected to digital pin 10
#define newSetButton 10
//----------------------------------------

char tempString[10];

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(9600);
	delay(100);
	clearDisplay();
}

// the loop function runs over and over again until power down or reset
void loop() {
}

void clearDisplay() {
	digitalWrite(SSD, LOW);
	Serial.write(0x76); //clear display command
	digitalWrite(SSD, HIGH);
}
void error() {
	clearDisplay();
	Serial.println("SDEr");
	while (1);
}
void s7sSendStringSPI(String toSend) {
	digitalWrite(SSD, LOW);
	for (int i = 0; i < 4; i++) {
		SPI.transfer(toSend[i]);
	}
	digitalWrite(SSD, HIGH);
}

int bucketNumber() {
	//return the number of buckets sampled
}

void saveSample() {
	//save the sample taken
}

void displayDensity() {
	//display the density of the sample
}

int updateDensity() {
	//calculate the density of the sample
}

void newSampleSet() {
	//create new list/array of samples
}

void eraseAll() {
	//erases all the sampled sets
}

void undoSample() {
	//erases density of current sample
}