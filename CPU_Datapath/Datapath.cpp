#include "Datapath.h"

Datapath::Datapath()
{
	PC = 0;
	PC_adder.b = 1;
}

void
Datapath::Run()
{
	instr_mem.FetchInstruction(PC);

	//incremment PC to next instruction
	PC_adder.a = PC;
	PC_adder.Add();

	//setting all the controls/choices
	control.setOpCode(instr_mem.opcode, instr_mem.funct);
	inst_mux.setChoiceA(control.RegDst);
	alu_mux.setChoiceA(control.Branch);
	data_mem.setMemRead(control.MemRead);
	data_mux.setChoiceA(control.MemtoReg);
	alu_control.setALUOp(control.ALUOp);
	data_mem.setMemWrite(control.MemWrite);
	alu_mux.setChoiceA(control.ALUSrc);
	registers.setRegWrite(control.RegWrite);
	
	branch_mux.setA(PC_adder.result);
	branch_adder.setA(PC_adder.result);
	branch_adder.setB(instr_mem.immediate);
	branch_adder.Add();
	branch_mux.setB(branch_adder.result);





	branch_mux.a =
	
	instr_adder.result

	registers.setReadRegisters(instr_mem.rs, instr_mem.rt);
	registers.setRegWrite(inst_mux.getResult());





	//for (int i = 0; i < 9; i++)
	//{
	//	// IF/ID stage
	//	instr_mem.FetchInstruction(i);
	//	registers.setReadRegisters(instr_mem.rs, instr_mem.rt);
	//	registers.setWriteRegister(instr_mem.rd);

	//	// ID/EX stage

	//	// Ex/MEM stage

	//	//MEM/WB stage
	//	
	//}
}