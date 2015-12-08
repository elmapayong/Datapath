#include "ALU.h"

ALU::ALU()
{
	a, b, result, zero = 0;
	operation = ALU_Control::OPERATION::AND;	//default
}

void ALU::setOperation(ALU_Control::OPERATION op)
{
	operation = op;
}

int ALU::getResult()
{
	switch (operation)
	{
	case ALU_Control::OPERATION::AND:
		result = a & b;
		return result;
		break;
	case ALU_Control::OPERATION::OR:
		result = a | b;
		return result;
		break;
	case ALU_Control::OPERATION::XOR:
		result = a ^ b;
		return result;
		break;
	case ALU_Control::OPERATION::NOR:
		result = ~(a | b);
		return result;
		break;
	case ALU_Control::OPERATION::ADD:
		result = a + b;
		return result;
		break;
	case ALU_Control::OPERATION::SUB:
		result = a - b;
		return result;
		break;
	default:
		result = -1;
		return result;
		break;
	}
}
