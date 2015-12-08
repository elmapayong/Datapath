#ifndef _DataMemory_h
#define _DataMemory_h

#include <iostream>

class DataMemory
{
public:
	bool MemRead;
	bool MemWrite;
	int address;
	int readdata;
	int writedata;
	int memory[32];

	DataMemory();


};

#endif