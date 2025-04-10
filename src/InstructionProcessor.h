#pragma once

#include <chrono>
#include "DataStructures.h"
#include "MemoryManager.h"

struct ProcessorFlags {

	bool interruptMasterEnable = 0;
	bool halt = 0;
	bool zeroFlag = 1; // z
	bool subtractionFlag = 0; // n
	bool halfCarryFlag = 1; // h
	bool carryFlag = 1; // c
};

class InstructionProcessor
{
private:
	Registers* registers;

	ProcessorFlags processorFlags;

	void ExecuteInterrupt(int interruptNumber);
	int ProcessCBPrefixInstruction();

	void alu_add(unsigned char val);
	void alu_adc(unsigned char val);
	void alu_sub(unsigned char val);
	void alu_sbc(unsigned char val);

	void alu_and(unsigned char val);
	void alu_or(unsigned char val);
	void alu_xor(unsigned char val);
	void alu_cp(unsigned char val);

	unsigned char alu_inc(unsigned char val);
	unsigned char alu_dec(unsigned char val);

	void alu_add16(unsigned short val);
	unsigned short alu_inc16(unsigned short val);
	unsigned short alu_dec16(unsigned short val);

	void daa();

	unsigned char rlc(unsigned char val, bool ignoreZ);
	unsigned char rl(unsigned char val, bool ignoreZ);
	unsigned char rrc(unsigned char val, bool ignoreZ);
	unsigned char rr(unsigned char val, bool ignoreZ);
	unsigned char sla(unsigned char val);
	unsigned char sra(unsigned char val);
	unsigned char srl(unsigned char val);

	void bit(char pos, unsigned char val);
	unsigned char set(char pos, unsigned char val);
	unsigned char res(char pos, unsigned char val);

	unsigned char swap(unsigned char val);

public:
	InstructionProcessor();
	~InstructionProcessor();

	Registers* GetRegistersRef();

	/// <summary>
	/// Reads and processses next instruction
	/// </summary>
	/// <reurns>number of cpu cycles</returns>
	int ProcessNextInstruction();

	/// <summary>
	/// Handles processor interrupts
	/// </summary>
	void HandleInterrupts();

	/// <summary>
	/// Returns data at position indicated by PC and increments PC
	/// </summary>
	/// <returns>unsigned char with 1 byte of data</returns>
	unsigned char GetData();
	
	/// <summary>
	/// Returns processor flags [read only]
	/// </summary>
	/// <returns>Read only ProcessorFlags</returns>
	ProcessorFlags GetProcessorFlags();
};