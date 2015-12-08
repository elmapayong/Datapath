#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
using namespace std;

class Control
{
public:
	//Control(int, int);
	Control();
	//in
	int opCode;
	//out
	bool RegDst;
	bool Branch;
	bool MemRead;
	bool MemtoReg;
	bool ALUOp;
	bool MemWrite;
	bool ALUSrc;
	bool RegWrite;

	void setOpCode(int);

private:
	void clearControlSignals();
	void setControlSignals(int);	//sets all out signals according to opcode
};

#endif