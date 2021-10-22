// 
// 
// 

#include "ScreenView.h"
#include "ScreenLine.h";


ScreenView::ScreenView(char * title)
{
	this->title = title;
}

void ScreenView::append(ScreenLine line)
{
	ScreenLine * newArray[(sizeof(this->lines) / sizeof(ScreenLine) ) +1];


	for (int i = 0; i < (sizeof(this->lines) / sizeof(char)); i++) {
		newArray[i] = &this->lines[i];
	}

	newArray[(sizeof(this->lines) / sizeof(char))] =&line;

	this->lines = *newArray;
}


void ScreenView::append(ScreenLine*  lines)
{
}
