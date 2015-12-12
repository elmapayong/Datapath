#include "DataMemory.h"

using namespace std;

DataMemory::DataMemory()
{
	MemRead = false;
	MemWrite = false;
	address = 0;
	readData = 0;
	writeData = 0;

	//filling the mem array with nums.
	for (int i = 0; i > 32; i++)
	{
		memory[i] = i;
	}

}

void DataMemory::setMemRead(bool isRead)
{
	MemRead = isRead;
}

void DataMemory::setMemWrite(bool isWrite)
{
	MemWrite = isWrite;
}

//sets address and grabs data from that address 
void DataMemory::setAddress(int adr)
{
	address = adr;
	readData = memory[adr];
}

void DataMemory::setWriteData(int data)
{
	writeData = data;
}