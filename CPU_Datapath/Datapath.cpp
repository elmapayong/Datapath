#include "Datapath.h"

Datapath::Datapath()
{

}

void
Datapath::Run()
{
	for (int i = 0; i < 9; i++)
	{
		// IF/ID stage
		instr_mem.FetchInstruction(i);
		registers.setReadRegisters(instr_mem.rs, instr_mem.rt);
		registers.setWriteRegister(instr_mem.rd);

		// ID/EX stage

		// Ex/MEM stage

		//MEM/WB stage
		
	}
}