#include "InputController.h"

#include "raylib.h"
#include "Emulator.h"


void InputController::HandleInput()
{
	char input = ~Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00];

	input = input >> 4;
	input = input << 4;
	// select buttons
	if (input >= 32)
	{
		if (IsKeyDown(KEY_W)) input = input | 0b00000001;
		if (IsKeyDown(KEY_Q)) input = input | 0b00000010;
		if (IsKeyDown(KEY_S)) input = input | 0b00000100;
		if (IsKeyDown(KEY_A)) input = input | 0b00001000;
	}
	// select d-pad
	else if (input >= 16)
	{
		if (IsKeyDown(KEY_RIGHT)) input = input | 0b00000001;
		if (IsKeyDown(KEY_LEFT)) input = input | 0b00000010;
		if (IsKeyDown(KEY_UP)) input = input | 0b00000100;
		if (IsKeyDown(KEY_DOWN)) input = input | 0b00001000;
	}

	Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] = ~input;
}

void InputController::Initialize()
{
	Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] = 0x0;
}
