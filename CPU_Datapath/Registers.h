#ifndef REGISTERS_H
#define REGISTERS_H

class Registers
{
public:
	Registers();
	//from instruction
	int rs;		//read register 1
	int rt;		//read register 2
	int rsData;	//data in rs register
	int rtData;	//data in rt register
	int rd;		//write register

	bool RegWrite;		//set by Control
	int registerArray[25];		//registers

	void setReadRegisters(int, int);
	void setWriteRegister(int);
	void setRegWrite(bool);
	void writeData(int);		//writes data into register specified by rd
};





#endif