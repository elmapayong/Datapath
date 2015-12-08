#include "Registers.h"

Registers::Registers()
{
	rs, rt, rd = 0;		//inputs
	write_data = 0;
	RegWrite = true;

	//fill registers up with some sample values
	for (int i = 0; i < 25; i++)
	{
		registerArray[i] = i;
	}
}