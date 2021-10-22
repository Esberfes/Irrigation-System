#ifndef DATA_DATAMANAGER_H_
#define DATA_DATAMANAGER_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "DataEntry.h"
#include "EEPROM.h"
/*
 Esta clase es la ecargada de gestionar todo lo relacionado con la persistencia de datos en la placa.
 Se utilizará la memoria EEPROM


 ┌─────────────────────────┬────────────────┐
 │         Placa           │ Memoria(bytes) │
 ├─────────────────────────┼────────────────┤
 │ ATmega328P              │           1024 │
 │ ATmega168, ATmega8      │            512 │
 │ ATmega1280, ATmega2560  │           4096 │
 └─────────────────────────┴────────────────┘
 */

class DataManager {
	/*
	 Es la capacidad total de la memoria EEPROM en bytes
	 */
	const int bytesCapacity = EEPROM.length();

	/*
	 Ultima dirección de memoria insertada en la EEPROM
	 */
	int lastAddess;


	DataEntry CHECK_INTERVAL = {};

public:
	DataManager();
	DataEntry put(DataEntry entry);
	DataEntry get(int address);
	int capacity();
	int remingCapacity();
};

#endif /* DATA_DATAMANAGER_H_ */

