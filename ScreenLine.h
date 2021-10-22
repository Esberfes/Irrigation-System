// Screen.h

#ifndef _SCREEN_h
#define _SCREEN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ScreenLine {

	private:
		int x;
		int y;

	public:
		char* line;
		ScreenLine(char* line);
		ScreenLine();
};

#endif
