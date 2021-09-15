// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Irrigation_System.ino
    Created:	10/09/2021 20:35:59
    Author:     Javier Casas Velasco
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
#include "ScreenManger.h"
#include "Screen.h"
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include "DataManager.h"

DataManager dataManager;

void setup()
{
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for Leonardo only
	}
	DataEntry mykey = { 0, 1, "bb"};
	Serial.println("Start");
	//DataEntry inserted = dataManager.put(mykey);
	DataEntry  other = dataManager.get(4);

	Serial.print("Add: ");
	Serial.println(other.address);
	Serial.print("Key: ");
	Serial.println(other.key);
	Serial.print("Value: ");
	Serial.println(other.value);
}

// Add the main program code into the continuous loop() function
void loop()
{
	/*
	DataEntry data = dataManager.get(mykey.address);

	Serial.println(data.value);
	Serial.println(data.address);
	Serial.println(data.key);

	Serial.print("capacity: ");
	Serial.println(dataManager.capacity());
	Serial.print("reaming: ");
	Serial.println(dataManager.remingCapacity());
	unsigned long x = millis();

	delay(1000);
	*/
	
}

