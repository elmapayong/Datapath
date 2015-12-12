#ifndef REGISTERS_H
#define REGISTERS_H

class Registers
{
public:
	Registers();
	void setReadRegisters(int s, int t);	//sets read registers and grabs their data
	void setWriteRegister(int d);
	void setRegWrite(bool);
	int getRsData();
	int getRtData();
	void writeData(int);		//writes data into register specified by rd

private:
	int registerArray[25];		//registers

	//from instruction
	int rs;		//read register 1
	int rt;		//read register 2
	int rsData;	//data in rs register
	int rtData;	//data in rt register
	int rd;		//write register

	//set by Control
	bool RegWrite;
};





#endif