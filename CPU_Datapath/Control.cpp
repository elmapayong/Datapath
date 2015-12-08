#include "Control.h"

//Control::Control(int ins, int op) : instruction(ins), opCode(op)
//{
//
//}


//set all initial values to 0
Control::Control()
{
	opCode = 0;
	clearControlSignals();
}


//sets opCode and turns on corresponding signals
void Control::setOpCode(int instruction)
{
	opCode = instruction;
	clearControlSignals();
	setControlSignals(opCode);
}

//clears all controlSignals
void Control::clearControlSignals()
{
	RegDst, Branch, MemRead, MemtoReg, ALUOp, MemWrite, ALUSrc, RegWrite = false;
}


//turns on signals based on type and opcode
void Control::setControlSignals(int opCode)
{
	//R-format &
	//I-format AND, OR, XOR, Add, Sub
	if (opCode == 0)
	{
		RegDst = true;
		RegWrite = true;
		ALUOp = true;
	}
	//I-format lw
	else if (opCode == 10)	//1010
	{
		ALUSrc = true;
		MemtoReg = true;
		RegWrite = true;
		MemRead = true;
	}
	//I-format sw
	else if (opCode == 11)	//1011
	{
		ALUSrc = true;
		MemWrite = true;
	}
	//J-format - beq
	else if (opCode == 12 || opCode == 13)	//1100 || 1101
	{
		Branch = true;
	}
	else
	{
		cout << "Wrong opCode." << endl;
	}
}