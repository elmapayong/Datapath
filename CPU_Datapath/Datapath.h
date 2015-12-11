#ifndef Datapath_H
#define Datapath_H

#include "Adder.h"
#include "ALU.h"
#include "ALU_Control.h"
#include "Control.h"
#include "DataMemory.h"
#include "InstructionMemory.h"
#include "Mux.h"
#include "Registers.h"

class Datapath
{
private:
	InstructionMemory instr_mem;
	Adder instr_adder, alu_adder;
	Control control;
	Mux inst_mux, alu_mux, data_mux;
	Registers registers;
	ALU_Control alu_control;
	ALU alu;
	DataMemory data_mem;


public:
	Datapath();
	void Run();
};

#endif Datapath_H