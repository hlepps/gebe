#include "Emulator.h"

#include <iostream>
#include <format>
#include "RomReader.h"
#include "Window.h"
#include "MemoryManager.h"
#include "Offsets.h"
#include "CommandLineArguments.h"
#include "InputController.h"

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


	inputController = new InputController();
	inputController->Initialize();

	instructionProcessor = new InstructionProcessor();

	// Init values
	instructionProcessor->GetRegistersRef()->pc = 0x100;
	instructionProcessor->GetRegistersRef()->af = 0x01;
	instructionProcessor->GetRegistersRef()->f = 0xB0;
	instructionProcessor->GetRegistersRef()->bc = 0x0013;
	instructionProcessor->GetRegistersRef()->de = 0x00D8;
	instructionProcessor->GetRegistersRef()->hl = 0x014D;
	instructionProcessor->GetRegistersRef()->sp = 0xFFFE;
	memoryManager->memory[0xFF05] = 0x00;
	memoryManager->memory[0xFF06] = 0x00;
	memoryManager->memory[0xFF07] = 0x00;
	memoryManager->memory[0xFF10] = 0x80;
	memoryManager->memory[0xFF11] = 0xBF;
	memoryManager->memory[0xFF12] = 0xF3;
	memoryManager->memory[0xFF14] = 0xBF;
	memoryManager->memory[0xFF16] = 0x3F;
	memoryManager->memory[0xFF17] = 0x00;
	memoryManager->memory[0xFF19] = 0xBF;
	memoryManager->memory[0xFF1A] = 0x7F;
	memoryManager->memory[0xFF1B] = 0xFF;
	memoryManager->memory[0xFF1C] = 0x9F;
	memoryManager->memory[0xFF1E] = 0xBF;
	memoryManager->memory[0xFF20] = 0xFF;
	memoryManager->memory[0xFF21] = 0x00;
	memoryManager->memory[0xFF22] = 0x00;
	memoryManager->memory[0xFF23] = 0xBF;
	memoryManager->memory[0xFF24] = 0x77;
	memoryManager->memory[0xFF25] = 0xF3;
	memoryManager->memory[0xFF26] = 0xF1;
	memoryManager->memory[0xFF40] = 0x91;
	memoryManager->memory[0xFF42] = 0x00;
	memoryManager->memory[0xFF43] = 0x00;
	memoryManager->memory[0xFF45] = 0x00;
	memoryManager->memory[0xFF47] = 0xFC;
	memoryManager->memory[0xFF48] = 0xFF;
	memoryManager->memory[0xFF49] = 0xFF;
	memoryManager->memory[0xFF4A] = 0x00;
	memoryManager->memory[0xFF4B] = 0x00;
	memoryManager->memory[0xFFFF] = 0x00;

	timer = new Timer();

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

InputController& Emulator::GetInputControllerRef()
{
	return *inputController;
}

Timer& Emulator::GetTimerRef()
{
	return *timer;
}

Window& Emulator::GetWindowRef()
{
	return *window;
}
