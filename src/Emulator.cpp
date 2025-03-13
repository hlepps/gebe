#include <iostream>
#include "Emulator.h"
#include "RomReader.h"

#include "Window.h"



void Emulator::Init()
{
	RomReader romReader("helpful\\tetris.gb");
	std:: cout << romReader.GetROMMetadata().title << std::endl;

	Window window("gebe", 500, 500);
	window.Open();
}
