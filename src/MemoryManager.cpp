#include <iostream>
#include "Offsets.h"
#include "Emulator.h"

#include "MemoryManager.h"

MemoryManager::MemoryManager()
{
	memory = new unsigned char[0xFFFF];
}

void MemoryManager::CopyMemoryFromROM()
{
	RomReader& rom = Emulator::GetInstance().GetRomReaderRef();
	std::copy(rom.romData, rom.romData + (MEMORY_ROM_END-MEMORY_ROM_BEGIN), memory + MEMORY_ROM_BEGIN);
}

