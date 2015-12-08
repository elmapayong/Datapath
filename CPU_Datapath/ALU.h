#include "ALU_Control.h"

#ifndef ALU_H
#define ALU_H

class ALU
{
public:
	ALU();
	int a, b;
	int result;
	bool zero;
	void setOperation(ALU_Control::OPERATION);
	int getResult();
private:
	ALU_Control::OPERATION operation;
};

#endif