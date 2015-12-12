#ifndef _DataMemory_h
#define _DataMemory_h

#include <iostream>

class DataMemory
{
public:
	DataMemory();
	void setMemRead(bool);
	void setMemWrite(bool);
	void setAddress(int);
	void setWriteData(int);
	int getReadData();
	void accessMemory();	//writes/reads memory if needed

private:
	bool MemRead;
	bool MemWrite;
	int address;
	int readData;
	int writeData;
	int memory[32];

};

#endif