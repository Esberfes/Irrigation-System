// 
// 
// 

#include "ScreenManager.h"
#include <u8g2lib.h>;
#include <Arduino.h>
#include <Keypad.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] =
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = { 2,3,4,5 }; 
byte colPins[numCols] = { 6,7,8,9 } ;

//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
unsigned long start = millis();
char lastKey;

/// <summary>
/// Renders the specified lines.
/// </summary>
/// <param name="lines">The lines.</param>
/// <returns></returns>
unsigned long ScreenManager::render(char lines[])
{
	char keypressed = myKeypad.getKey();
	if (keypressed != NO_KEY)
	{
		lastKey = keypressed;
	}

	if (millis() - start > 500)
	{
		this->u8g2.firstPage();
		do {
			// Curremt key
			u8g2.drawStr(this->u8g2.getDisplayWidth() - 1, 15, String(lastKey).c_str());

			// Title
			u8g2.drawStr(12, 15, "Irrigator 2000");
			this->u8g2.drawHLine(0, 16, this->u8g2.getDisplayWidth());

			// Mode
			u8g2.drawStr(0,  31, "Modo");
			u8g2.drawStr((u8g2.getDisplayWidth() / 2) + 5, 31, "Auto");
			this->u8g2.drawVLine(this->u8g2.getDisplayWidth() / 2, 16, 16);
			this->u8g2.drawHLine(0, 32, this->u8g2.getDisplayWidth());
		
			// Config	
			u8g2.drawStr(18, 47, "Configuracion");
			this->u8g2.drawHLine(0, 48, this->u8g2.getDisplayWidth());


			// Sensors
			u8g2.drawStr(0, 64, String(String("Sn1: ") + String(random(10, 100)) + String("%")).c_str());
			u8g2.drawStr((u8g2.getDisplayWidth() / 2) + 5, 64, String(String("S2: ") + String(random(10, 100)) + String("%")).c_str());
			this->u8g2.drawVLine(this->u8g2.getDisplayWidth() / 2, 48, 16);
			this->u8g2.drawHLine(0, 64, this->u8g2.getDisplayWidth());

			for (unsigned int a = 0; a < sizeof(lines) / sizeof(lines[0]); a = a + 1) {
				Serial.println(lines[a]);
				const char* aa = &lines[0];
				//u8g2.drawStr(0, a + 30 + 1, aa);
			}

		} while (this->u8g2.nextPage());

		start = millis();
	}

	
	return millis() - start;
}

void ScreenManager::init(){
	u8g2_SetI2CAddress(this->u8g2.getU8g2(), 0x3C * 2);
	this->u8g2.begin();
	this->u8g2.setFont(u8g2_font_6x10_mr);
	this->width = this->u8g2.getWidth();
	this->height = this->u8g2.getHeight();
	this->charWidth = 6;
	this->charHeight = 10;
}
 