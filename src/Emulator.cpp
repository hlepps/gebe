#include <iostream>
#include "RomReader.h"
#include "Window.h"
#include "MemoryManager.h"
#include "Offsets.h"
#include "CommandLineArguments.h"

#include "Emulator.h"

Emulator* Emulator::instance = nullptr;

Emulator::Emulator()
{

}

void Emulator::PrivateInit()
{
	romReader = new RomReader(CommandLineArguments::GetArguments()[1]);
	std::cout << "Title: " << romReader->GetROMMetadata().title << std::endl;

	memoryManager = new MemoryManager;
	memoryManager->CopyMemoryFromROM();

	instructionProcessor = new InstructionProcessor();

	window = new Window(romReader->GetROMMetadata().title, 640 + 200, 576);
	window->Open();
}

void Emulator::Init()
{
	instance = new Emulator;
	instance->PrivateInit();
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

InstructionProcessor& Emulator::GetInstructionProcessorRef()
{
	return *instructionProcessor;
}
Window& Emulator::GetWindowRef()
{
	return *window;
}
