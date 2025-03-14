#pragma once

#include "RomReader.h"
#include "MemoryManager.h"
#include "Window.h"
#include "InstructionProcessor.h"

/// <summary>
/// Emulator class
/// </summary>
class Emulator
{
private:
	static Emulator* instance;

	RomReader* romReader;
	MemoryManager* memoryManager;
	InstructionProcessor* instructionProcessor;
	Window* window;

	Emulator();
	void PrivateInit();
public:
	/// <summary>
	/// Initializes singleton class Emulator
	/// </summary>
	static void Init();

	static Emulator& GetInstance();

	RomReader& GetRomReaderRef();
	MemoryManager& GetMemoryManagerRef();
	InstructionProcessor& GetInstructionProcessorRef();
	Window& GetWindowRef();
};