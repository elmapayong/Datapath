#pragma once

class InstructionMemory
{
public:
	// Instruction variables
	int opcode, rs, rt, rd, shamt, funct;	// R-type variables
	int immediate;	// opcode, rs, rt, and immediate belong to I-type format
	int address;	// Target address for J-type instruction
	// Constructor & destructor
	InstructionMemory();
	// Function
	void FetchInstruction();

private:
	// For simplicity we will deal with basic
	// instruction formats: R-type, I-type, J-type.
	int instruction_array[2]; // Itype jump instruction

	bool is_rtype_, is_itype_, is_jtype_;
};