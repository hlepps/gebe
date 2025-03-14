#include <iostream>
#include "RomReader.h"
#include "Window.h"
#include "MemoryManager.h"
#include "Offsets.h"

#include "Emulator.h"

Emulator* Emulator::instance = nullptr;

Emulator::Emulator()
{
	romReader = new RomReader("helpful\\tetris.gb");
	std::cout << romReader->GetROMMetadata().title << std::endl;

	memoryManager = new MemoryManager;
	memoryManager->CopyMemoryFromROM(*romReader);
	window = new Window(romReader->GetROMMetadata().title, 640 + 200, 576);
	window->Open();
}

void Emulator::Init()
{
	instance = new Emulator;
}

Emulator& Emulator::GetInstance()
{
	return *instance;
}

RomReader& Emulator::GetRomReaderRef()
{
	return *romReader;
}

MemoryManager& Emulator::GetMemoryManagerRef()
{
	return *memoryManager;
}

Window& Emulator::GetWindowRef()
{
	return *window;
}
