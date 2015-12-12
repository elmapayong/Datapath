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

void DataMemory::setAddress(int adr)
{
	address = adr;
}

void DataMemory::setWriteData(int data)
{
	writeData = data;
}

int DataMemory::getReadData()
{
	return readData;
}

//reads or writes memory if MemRead/MemWrite is true
void DataMemory::accessMemory()
{
	if (MemRead)
	{
		readData = memory[address];
	}

	if (MemWrite)
	{
		memory[address] = writeData;
	}
}