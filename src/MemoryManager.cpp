#include <iostream>
#include <bitset>
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

void MemoryMap::SetBit(int addr, char pos, bool bit)
{
	std::bitset<8> bits(getMem(addr));
	bits[pos] = bit;
	memory[addr] = static_cast<unsigned char>(bits.to_ulong());
}

bool MemoryMap::GetBit(int addr, char pos)
{
	std::bitset<8> bits(getMem(addr));
	return bits[pos];
}

MemoryManager::MemoryManager()
{

}

void MemoryManager::CopyMemoryFromROM()
{
	RomReader& rom = Emulator::GetInstance().GetRomReaderRef();
	std::copy(rom.romData, rom.romData + (MEMORY_ROM_END-MEMORY_ROM_BEGIN), memory.memory + MEMORY_ROM_BEGIN);
}

