#include "ALU_Control.h"

#include <iostream>

ALU_Control::ALU_Control()
{
	opCode = 0;
	outputOperation = AND;	//default
}

void ALU_Control::setOpCode(int op)
{
	bool subBit = 0;
	//isolate rightmost bit for sub flag
	subBit = 0x00000001 & op;

	ALU_op = op;
	ALU_op >>= 1;	//only want left 3 bits


	//DELETE - does SLT function the same as SUB?


	//all but add & sub correlate directly with OPERATION enum
	if (ALU_op > 3)
	{
		if (subBit)
			outputOperation = SUB;
		else
			outputOperation = ADD;
	}
	else
	{
		outputOperation = (OPERATION)ALU_op;
	}

	//std::cout << ALU_op << std::endl;
	//std::cout << outputOperation << std::endl;
}