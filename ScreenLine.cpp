
#include "ScreenLine.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

ScreenLine::ScreenLine(char lines[])
{
	this->line = line;
}

ScreenLine::ScreenLine()
{
}
