// ScreenManager.h

#ifndef _SCREENMANAGER_h
#define _SCREENMANAGER_h


#include <U8g2lib.h>;
#include <Arduino.h>
#include "ScreenLine.h"
#include "ScreenView.h"

extern const u8g2_cb_t u8g2_cb_r0;
extern const u8g2_cb_t u8g2_cb_r1;
extern const u8g2_cb_t u8g2_cb_r2;
extern const u8g2_cb_t u8g2_cb_r3;
extern const u8g2_cb_t u8g2_cb_mirror;

#define U8G2_R0	(&u8g2_cb_r0)
#define U8G2_R1	(&u8g2_cb_r1)
#define U8G2_R2	(&u8g2_cb_r2)
#define U8G2_R3	(&u8g2_cb_r3)
#define U8G2_MIRROR	(&u8g2_cb_mirror)

class ScreenManager  {

private: 
		U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2;
		int width;
		int height;
		int charWidth;
		int charHeight;
		ScreenView views[];



	public:
		ScreenManager() : u8g2(U8G2_R0, 4, 5, U8X8_PIN_NONE) {};
		unsigned long render(char lines[]);
		void init();
};

#endif