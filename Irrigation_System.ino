// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Irrigation_System.ino
    Created:	10/09/2021 20:35:59
    Author:     Javier Casas Velasco
*/

#include "Test.h"
#include <U8g2lib.h>
#include <EEPROM.h>
#include "ScreenMenu.h"
#include "ScreenView.h"
#include <U8x8lib.h>
#include "ScreenLine.h"
#include "ScreenManager.h"
#include "DataManager.h"


DataManager dataManager;
ScreenManager screenManger;

void setup()
{
	Serial.begin(9600);
	while (!Serial) {
		; // wait for serial port to connect. Needed for Leonardo only
	}
	screenManger.init();
	Serial.println("setup");

}

// Add the main program code into the continuous loop() function
void loop()
{
	Serial.println("loop");


	screenManger.render({"hi"});

	delay(1000);
}

