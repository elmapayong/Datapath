#include "ALU_Control.h"

#include <iostream>

ALU_Control::ALU_Control()
{
	opCode = 0;
	outputOperation = AND;	//default
}

void ALU_Control::setALUOp(int op)
{
	switch (op)
	{
	case 0:
		outputOperation = ADD;
		break;
	case 2:
		outputOperation = SUB;
	case 4:
		outputOperation = AND;
		break;
	case 5:
		outputOperation = OR;
	case 7:
		outputOperation = NOR;
		break;
	default:
		break;
	}
}