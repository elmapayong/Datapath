#ifndef _DataMemory_h
#define _DataMemory_h

#include <iostream>

class DataMemory
{
public:
	bool MemRead;
	bool MemWrite;
	int address;
	int readData;
	int writeData;
	int memory[32];

	DataMemory();

};

#endif