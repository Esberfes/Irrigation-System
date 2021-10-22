#include "DataManager.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "EEPROM.h"

DataManager::DataManager()
{
	this->lastAddess = 0;
	float f = 0.11;
	EEPROM.put(this->lastAddess, f);
	this->lastAddess += sizeof(float);
}

DataEntry DataManager::put(DataEntry entry) {
	entry.address = this->lastAddess;
	EEPROM.put(this->lastAddess, entry);
	Serial.println(this->lastAddess);
	int size = sizeof(entry);;
	this->lastAddess += size;

	return entry;
}

DataEntry DataManager::get(int address) {
	DataEntry entry;
	EEPROM.get(address, entry);

	return entry;
}

int DataManager::capacity()
{
	return this->bytesCapacity;
}

int DataManager::remingCapacity()
{
	return this->capacity() - this->lastAddess;
}