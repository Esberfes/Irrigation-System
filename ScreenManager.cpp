// 
// 
// 

#include "ScreenManager.h"
#include <u8g2lib.h>;
#include <Arduino.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


unsigned long ScreenManager::render(char lines[])
{
	
	for (unsigned int a = 0; a < sizeof(lines) / sizeof(lines[0]); a = a + 1) {
		Serial.println(lines[a]);
	}

	unsigned long start = millis();
	this->u8g2.firstPage();
	do {
		


	} while (this->u8g2.nextPage());

	return millis() - start;
}

void ScreenManager::init(){
	u8g2_SetI2CAddress(this->u8g2.getU8g2(), 0x3C * 2);

	//bool U8G2::begin(uint8_t menu_select_pin, uint8_t menu_next_pin, uint8_t menu_prev_pin, uint8_t menu_up_pin = U8X8_PIN_NONE, uint8_t menu_down_pin = U8X8_PIN_NONE, uint8_t menu_home_pin = U8X8_PIN_NONE)
	this->u8g2.begin();
	this->u8g2.setFont(u8g2_font_6x10_mr);
	this->width = this->u8g2.getWidth();
	this->height = this->u8g2.getHeight();
	this->charWidth = 6;
	this->charHeight = 10;
}
 