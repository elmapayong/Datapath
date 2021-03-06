#include "Datapath.h"

Datapath::Datapath()
{
	PC = 7;
	PC_adder.setB(1);	//1 to increment to next instruction
}

void Datapath::Run()
{
	while (PC >= 0 && PC < 10){
		cout << "  BEGINNING OF CYCLE:" << endl;
		cout << "PC: " << PC << endl;
		printAll();
		cout << endl;

		/*~~~~~~~ RISING CLOCK EDGE ~~~~~~~*/
		cout << "- RISING CLOCK EDGE - " << endl;
		cout << "Write data into Registers..." << endl;
		cout << "Update PC..." << endl;
		cout << "----------------" << endl;
		cout << "Breaking apart instructions..." << endl;
		instr_mem.FetchInstruction(PC);

		cout << "Sending PC to adder..." << endl;
		//incremment PC to next instruction
		PC_adder.setA(PC);
		PC_adder.Add();

		cout << "Sending to Control and setting all control lines..." << endl;
		//setting all the controls/choices
		control.setOpCode(instr_mem.opcode, instr_mem.funct);
		inst_mux.setChoiceB(control.RegDst);
		branch_mux.setChoiceB(control.Branch);
		data_mem.setMemRead(control.MemRead);
		data_mux.setChoiceB(control.MemtoReg);
		alu_control.setALUOp(control.ALUOp);
		alu.setOperation(alu_control.getOperationType());
		data_mem.setMemWrite(control.MemWrite);
		alu_mux.setChoiceB(control.ALUSrc);
		registers.setRegWrite(control.RegWrite);

		cout << "Figuring out branch line..." << endl;
		//branch line - update PC 
		branch_mux.setA(PC_adder.getResult());
		branch_adder.setA(PC_adder.getResult());
		branch_adder.setB(instr_mem.immediate - 1);
		branch_adder.Add();
		branch_mux.setB(branch_adder.getResult());

		cout << "Sending and setting up to Registers..." << endl;
		//set up registers
		registers.setReadRegisters(instr_mem.rs, instr_mem.rt);
		inst_mux.setA(instr_mem.rt);
		inst_mux.setB(instr_mem.rd);
		registers.setWriteRegister(inst_mux.getResult());

		cout << "Set up ALU and calculate..." << endl;
		//process ALU
		alu.setA(registers.getRsData());
		alu_mux.setA(registers.getRtData());
		alu_mux.setB(instr_mem.immediate);
		alu.setB(alu_mux.getResult());
		alu.calculate();

		//set branch mux control 
		if (control.Branch == true && alu.getZero())
			branch_mux.setChoiceB(true);


		/*~~~~~~~ FALLING CLOCK EDGE ~~~~~~~*/
		cout << "- FALLING CLOCK EDGE - " << endl;

		cout << "Access Data Memory..." << endl;
		//data memory access
		data_mem.setAddress(alu.getResult());
		data_mem.setWriteData(registers.getRtData());
		data_mem.readMemory();

		cout << "Send data from memory..." << endl << endl;
		//send data from memory
		data_mux.setB(data_mem.getReadData());
		data_mux.setA(alu.getResult());
		registers.setWriteData(data_mux.getResult());

		registers.writeDataIntoReg();
		data_mem.writeToMemory();

		/*~~~~~~~ RISING CLOCK EDGE ~~~~~~~*/
		//update PC
		PC = branch_mux.getResult();


		cout << "    END OF CYCLE:" << endl;
		printAll();
		cout << "PC at beginning of next cycle: " << PC << endl;	//DELETE
		cout << endl << endl;
		
		system("pause");
	}
}


void Datapath::printAll()
{
	cout << "\tREGISTERS"
		<< "\t\t\t" << "MEMORY" << endl;

	//for (int i = 0; i < 32; i++)
	//{
	//	registers.printThisRegister(i);
	//	cout << "\t\t";
	//	data_mem.printThisMemory(i);
	//	cout << endl;
	//}

	for (int i = 0; i < 16; i++)
	{
		registers.printThisRegister(i);
		cout << "\t\t";
		registers.printThisRegister(i+16);
		cout << "\t\t";
		data_mem.printThisMemory(i);
		cout << "\t\t";
		data_mem.printThisMemory(i+16);
		cout << endl;
	}
}