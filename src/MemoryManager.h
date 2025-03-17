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