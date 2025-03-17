#pragma once

#include "RomReader.h"
#include "MemoryManager.h"
#include "Window.h"
#include "InstructionProcessor.h"
#include "InputController.h"

/// <summary>
/// Emulator class
/// </summary>
class Emulator
{
private:
	static Emulator* instance;

	RomReader* romReader;
	MemoryManager* memoryManager;
	InputController* inputController = nullptr;
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
	InputController& GetInputControllerRef();
	InstructionProcessor& GetInstructionProcessorRef();
	Window& GetWindowRef();
};