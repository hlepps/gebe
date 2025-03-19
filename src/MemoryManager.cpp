#include <iostream>
#include "Offsets.h"
#include "Emulator.h"

#include "MemoryManager.h"

unsigned char& MemoryMap::getMem(int i)
{
	if (i >= MEMORY_ECHO_RAM_BEGIN && i <= MEMORY_ECHO_RAM_END) // internal ram echo mapped to internal ram
	{
		i -= 0x2000;
	}


	return memory[i];
}

MemoryMap::MemoryMap()
{
	memory = new unsigned char[0xFFFF+1];
}

MemoryManager::MemoryManager()
{

}

void MemoryManager::CopyMemoryFromROM()
{
	RomReader& rom = Emulator::GetInstance().GetRomReaderRef();
	std::copy(rom.romData, rom.romData + (MEMORY_ROM_END-MEMORY_ROM_BEGIN), memory.memory + MEMORY_ROM_BEGIN);
}

