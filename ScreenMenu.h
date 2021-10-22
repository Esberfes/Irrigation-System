// ScreenMenu.h

#ifndef _SCREENMENU_h
#define _SCREENMENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "ScreenLine.h";
#include "ScreenView.h";
#include "stdio.h"

class MenuEvent {

	public:
	
};

class ScreenMenuClass
{
 protected:


 public:
	void init();
};

extern ScreenMenuClass ScreenMenu;

#endif

