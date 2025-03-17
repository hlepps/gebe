#pragma once

#include "DataStructures.h"
#include "MemoryManager.h"

class InstructionProcessor
{
private:
	Registers* registers;

public:
	InstructionProcessor();
	~InstructionProcessor();

	Registers* GetRegistersRef();

	/// <summary>
	/// Reads and processses next instruction
	/// </summary>
	void ProcessNextInstruction();

	/// <summary>
	/// Returns data at position indicated by PC and increments PC
	/// </summary>
	/// <returns>unsigned char with 1 byte of data</returns>
	unsigned char GetData();
};