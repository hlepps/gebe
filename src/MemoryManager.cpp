#include <iostream>
#include "Offsets.h"

#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
	memory = new char[0xFFFF];
}

void MemoryManager::CopyMemoryFromROM(RomReader& rom)
{
	std::copy(rom.romData, rom.romData + (MEMORY_ROM_END-MEMORY_ROM_BEGIN), memory + MEMORY_ROM_BEGIN);
}

