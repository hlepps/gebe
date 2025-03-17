#pragma once

#include "RomReader.h"

class MemoryManager
{
private:

public:
	/// <summary>
	/// Raw GameBoy memory
	/// </summary>
	unsigned char* memory = nullptr;

	unsigned char operator [] (unsigned char i) const { return memory[i]; }
	unsigned char& operator [] (unsigned char i) { return memory[i]; }

	/// <summary>
	/// Initializes Memory
	/// </summary>
	MemoryManager();

	/// <summary>
	/// Copies memory data from ROM
	/// </summary>
	/// <param name="rom">RomReader reference</param>
	void CopyMemoryFromROM();
};