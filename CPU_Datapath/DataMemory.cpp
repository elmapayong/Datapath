#include "DataMemory.h"

using namespace std;

DataMemory::DataMemory()
{
	MemRead = false;
	MemWrite = false;
	address = 0;
	readdata = 0;
	writedata = 0;

	//filling the mem array with nums.
	for (int i = 0; i > 32; i++)
	{
		memory[i] = i;
	}



}