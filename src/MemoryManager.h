#pragma once

#include "RomReader.h"

class MemoryMap
{
private:
	unsigned char* memory = nullptr;

	/// <summary>
	/// Used for additional checks before memory access
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	unsigned char& getMem(int i);

public:
	MemoryMap();
	//unsigned char operator [] (int i) const { return memory[i]; }  // not used for now
	unsigned char& operator [] (int i) { return getMem(i); }

	/// <summary>
	/// Sets addr[pos] = bit
	/// </summary>
	/// <param name="addr"></param>
	/// <param name="pos"></param>
	/// <param name="bit"></param>
	void SetBit(int addr, char pos, bool bit);

	/// <summary>
	/// Gets addr[pos]
	/// </summary>
	/// <param name="addr"></param>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool GetBit(int addr, char pos);

	friend class MemoryManager;
};

class MemoryManager
{
private:

public:
	/// <summary>
	/// Raw GameBoy memory
	/// </summary>
	MemoryMap memory;



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