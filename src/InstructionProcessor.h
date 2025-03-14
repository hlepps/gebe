#pragma once

#include "DataStructures.h"
#include "MemoryManager.h"

class InstructionProcessor
{
private:
	Registers* registers;

public:
	InstructionProcessor();

	Registers* GetRegistersRef();
};