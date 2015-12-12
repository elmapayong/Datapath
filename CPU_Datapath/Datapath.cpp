#include "Datapath.h"

Datapath::Datapath()
{
	PC = 0;
	PC_adder.setB(1);	//1 to increment to next instruction
}

void
Datapath::Run()
{
	/*~~~~~~~ RISING CLOCK EDGE ~~~~~~~*/

	instr_mem.FetchInstruction(PC);

	//incremment PC to next instruction
	PC_adder.setA(PC);
	PC_adder.Add();

	//setting all the controls/choices
	control.setOpCode(instr_mem.opcode, instr_mem.funct);
	inst_mux.setChoiceB(control.RegDst);
	branch_mux.setChoiceB(control.Branch);		//!!! FIX THIS
	data_mem.setMemRead(control.MemRead);
	data_mux.setChoiceB(control.MemtoReg);
	alu_control.setALUOp(control.ALUOp);
	alu.setOperation(alu_control.getOperationType);
	data_mem.setMemWrite(control.MemWrite);
	alu_mux.setChoiceB(control.ALUSrc);
	registers.setRegWrite(control.RegWrite);
	
	//branch line - update PC 
	branch_mux.setA(PC_adder.getResult());
	branch_adder.setA(PC_adder.getResult());
	branch_adder.setB(instr_mem.immediate);
	branch_adder.Add();
	branch_mux.setB(branch_adder.getResult());

	//set up registers
	registers.setReadRegisters(instr_mem.rs, instr_mem.rt);
	registers.setWriteRegister(inst_mux.getResult());
	
	//!!! DEAL WITH WRITE DATA AT END OF CYCLE

	//process ALU
	alu.setA(registers.getRsData);
	alu_mux.setA(registers.getRtData());
	alu_mux.setB(instr_mem.immediate);
	alu.setB(alu_mux.getResult());
	alu.calculate();
	

	/*~~~~~~~ FALLING CLOCK EDGE ~~~~~~~*/

	//data memory access
	data_mem.setAddress(alu.getResult());
	data_mem.setWriteData(registers.getRtData());
	data_mem.accessMemory();

	//send data from memory
	data_mux.setA(data_mem.getReadData());
	data_mux.setB(alu.getResult());
	registers.setWriteData(data_mux.getResult());


	/*~~~~~~~ RISING CLOCK EDGE ~~~~~~~*/
	//RegWrite
	registers.writeDataIntoReg();
	//update PC
	PC = branch_mux.getResult();


}