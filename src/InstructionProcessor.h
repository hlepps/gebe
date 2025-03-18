#pragma once

#include <chrono>
#include "DataStructures.h"
#include "MemoryManager.h"


class InstructionProcessor
{
private:
	Registers* registers;
	bool interruptMasterEnable = 0;
	bool halt = 0;
	bool zeroFlag = 0; // z
	bool subtractionFlag = 0; // n
	bool halfCarryFlag = 0; // h
	bool carryFlag = 0; // c


public:
	InstructionProcessor();
	~InstructionProcessor();

	Registers* GetRegistersRef();

	/// <summary>
	/// Reads and processses next instruction
	/// </summary>
	/// <reurns>number of cpu cycles</returns>
	int ProcessNextInstruction();

	void HandleInterrupts();

	/// <summary>
	/// Returns data at position indicated by PC and increments PC
	/// </summary>
	/// <returns>unsigned char with 1 byte of data</returns>
	unsigned char GetData();
};