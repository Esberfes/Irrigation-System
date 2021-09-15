#include <Arduino.h>

#ifndef DATA_DATAENTRY_H_
#define DATA_DATAENTRY_H_

struct DataEntry {
	int address;
	int key;
	char value[16];
};

#endif /* DATA_DATAENTRY_H_ */
