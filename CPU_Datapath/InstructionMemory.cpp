#include "InstructionMemory.h"
#include <iostream>
using namespace std;

InstructionMemory::InstructionMemory()
{
	opcode = rs = rt = rd = shamt = funct = immediate = address = 0;

	instruction_array[0] = 0x2324020;	// 0b00000010001100100100000000100000 Rtype
	instruction_array[1] = 0x8D2804B0;	// 0b10001101001010000000010010110000 Itype
	instruction_array[2] = 0x8D0612D;	// 0b00001000110100000110000100101101 Jtype
	/*instruction_array[3] = ;
	instruction_array[4] = ;
	instruction_array[5] = ;
	instruction_array[6] = ;
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
InstructionMemory::FetchInstruction()
{
	for (int i = 0; i < 3; i++)
	{
		opcode = instruction_array[i];
		opcode = (opcode & 0xFC000000);	//0b11111100000000000000000000000000
		opcode >>= 26;

		cout << opcode << endl;
	}
	//if (is_rtype_)
	//{
	//	rs = (rs & 0b00000011111000000000000000000000);
	//	rs >> 21;
	//	rt = (rt & 0b00000000000111110000000000000000);
	//	rt >> 16;
	//	rd = (rd & 0b00000000000000001111100000000000);
	//	rd >> 11;
	//	shamt = (shamt & 0b00000000000000000000011111000000);
	//	shamt >> 6;
	//	funct = (funct & 0b00000000000000000000000000111111);
	//}
	//else if (is_itype_)
	//{
	//	rs = (rs & 0b00000011111000000000000000000000);
	//	rs >> 21;
	//	rt = (rt & 0b00000000000111110000000000000000);
	//	rt >> 16;
	//	immediate = (immediate & 0b00000000000000001111111111111111);
	//}
	//else
	//{
	//	address = (address & 0b00000011111111111111111111111111);
	//}
}