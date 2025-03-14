#pragma once

#include "DataStructures.h"
#include "MemoryManager.h"

class InstructionProcessor
{
private:
	Registers registers;
	MemoryManager* memoryManager;

public:
	InstructionProcessor(MemoryManager* memoryManager);
};