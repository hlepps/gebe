#include <iostream>
#include "RomReader.h"
#include "MainWindow.h"
#include "MemoryManager.h"
#include "Offsets.h"

#include "Emulator.h"



void Emulator::Init()
{
	RomReader romReader("helpful\\tetris.gb");
	std:: cout << romReader.GetROMMetadata().title << std::endl;

	MemoryManager memoryManager;
	memoryManager.CopyMemoryFromROM(romReader);

	Window window(romReader.GetROMMetadata().title, 640, 576);
	window.Open();
}
