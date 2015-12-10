#include "InstructionMemory.h"
#include <iostream>
using namespace std;

InstructionMemory::InstructionMemory()
{
	opcode = rs = rt = rd = shamt = funct = immediate = address = 0;

	instruction_array[0] = 0x2324020;	// 00000010001100100100000000100000 Rtype add $t0, $s1, $s2
	instruction_array[1] = 0x2334820;	// 00000010001100110100100000100000 Rtype add $t1, $s1, $s3
	instruction_array[2] = 0x22890C80;	// 00100010100010100000110010000000 Itype addi $t2, $s4, 3200(decimal)
	instruction_array[3] =				//                                  
	instruction_array[4] = 0x8E4904B0;	// Itype lw $t1, 1200[$s2] --- 1200 is decimal
	instruction_array[5] = 0x8D0612D;	// Jtype j 0x2324020 <--decimal or hex?
	/*instruction_array[6] = ;
	instruction_array[7] = ;
	instruction_array[8] = ;
	instruction_array[9] = ;
	instruction_array[10] = ;
	instruction_array[11] = ;
	instruction_array[12] = ;
	instruction_array[13] = ;
	instruction_array[14] = ;
	instruction_array[15] = ;
	instruction_array[16] = ;*/
}


void
InstructionMemory::FetchInstruction(int pc)
{
	unsigned int instruction = instruction_array[pc];

	opcode = instruction;
	opcode = (opcode & 0xFC000000);	//0b11111100000000000000000000000000
	opcode >>= 26;

	if (opcode == 0)
		is_rtype_ = true;
	else if (opcode == 0x02 || opcode == 0x03)
		is_jtype_ = true;
	else					// Assuming we're dealing with valid instructions this should suffice.
		is_itype_ = true;	// Otherwise I would have to include a condition here as an "else if" 
							// instead of "else".

	if (is_rtype_)
	{
		rs = (rs & 0x3E0000);
		rs >>= 21;
		rt = (rt & 0x1F0000);
		rt >>= 16;
		rd = (rd & 0xF800);
		rd >>= 11;
		shamt = (shamt & 0x7C0);
		shamt >>= 6;
		funct = (funct & 0x3F);
	}
	else if (is_itype_)
	{
		rs = (rs & 0x3E0000);
		rs >>= 21;
		rt = (rt & 0x1F0000);
		rt >>= 16;
		immediate = (immediate & 0xFFFF);
	}
	else
		address = (address & 0x3FFFFFF);

	// Not sure if we need to reset the bools to false after each instruction is executed...
	is_rtype_ = is_itype_ = is_jtype_ = false;
}