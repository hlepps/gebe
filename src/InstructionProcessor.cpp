#include "InstructionProcessor.h"

InstructionProcessor::InstructionProcessor()
{
	registers = new Registers;
}

Registers* InstructionProcessor::GetRegistersRef()
{
	return registers;
}
