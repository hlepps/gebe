#pragma once

#include "RomReader.h"
#include "MemoryManager.h"
#include "Window.h"

/// <summary>
/// Emulator class
/// </summary>
class Emulator
{
private:
	static Emulator* instance;

	RomReader* romReader;
	MemoryManager* memoryManager;
	Window* window;

	Emulator();
public:
	/// <summary>
	/// Initializes singleton class Emulator
	/// </summary>
	static void Init();

	static Emulator& GetInstance();

	RomReader& GetRomReaderRef();
	MemoryManager& GetMemoryManagerRef();
	Window& GetWindowRef();
};