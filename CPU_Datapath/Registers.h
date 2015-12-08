#ifndef REGISTERS_H
#define REGISTERS_H

class Registers
{
public:
	Registers();
	//from instructions
	int rs;		//read register 1
	int rt;		//read register 2
	int rd;		//write register

	int write_data;
	bool RegWrite;
	int registerArray[25];		//registers
};





#endif