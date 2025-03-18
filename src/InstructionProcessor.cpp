#include "InstructionProcessor.h"

#include <exception>
#include <format>
#include <string>
#include <iostream>
#include "Emulator.h"
#include "OPCodeTable.h"
#include "Useful.h"
#include "Offsets.h"

InstructionProcessor::InstructionProcessor()
{
	registers = new Registers;
}

InstructionProcessor::~InstructionProcessor()
{
	delete registers;
	registers = nullptr;
}

Registers* InstructionProcessor::GetRegistersRef()
{
	return registers;
}

int InstructionProcessor::ProcessNextInstruction()
{
	try {

		unsigned char inst = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->pc];
		switch (inst)
		{
		case (JP_nn):
		{
			char a = GetData();
			char b = GetData();
			short comb = combineChars(b, a);
			registers->pc = comb;
			return 12;
		} break;
		case (1):
		{

		} break;
		default:
		{
			throw std::invalid_argument(std::format("[ERROR] Unimplemented instruction: '{:0>2X}' at position '{:0>4X}'", inst, registers->pc));
		} break;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
		throw e;
	}
}

void InstructionProcessor::HandleInterrupts()
{

	Emulator::GetInstance().GetMemoryManagerRef().memory[IO_INTERRUPTS] = 0;
}

unsigned char InstructionProcessor::GetData()
{
	unsigned char data = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->pc];
	registers->pc++;
	return data;
}
