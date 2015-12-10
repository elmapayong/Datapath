#ifndef ALU_CONTROL_H
#define ALU_CONTROL_H

class ALU_Control
{
public:
	enum OPERATION
	{
		AND, OR, XOR, NOR, ADD, SUB, SLT
	};


	ALU_Control();
	void setALUOp(int);	//expects 4 bits
	OPERATION outputOperation;
private:
	int opCode;
	int ALU_op;
};

#endif