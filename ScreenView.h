// ScreenView.h

#ifndef _SCREENVIEW_h
#define _SCREENVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "ScreenLine.h";
	
class ScreenView
{
 private:
	 ScreenLine*  &lines;
	 char* title;

 public:
ScreenView(char* title);
	void append(ScreenLine line);
	void append(ScreenLine* lines);
};


#endif

