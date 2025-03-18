#include "Window.h"

#include <chrono>
#include <thread>
#include "raylib.h"
#include "Emulator.h"
#include "RegistersDisplay.h"
#include "InputController.h"
#include "InstructionProcessor.h"

void Window::Open()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(width, height, title);

	// Start main loop
	Update();
}

void Window::Close()
{
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
}

void Window::ChangeTitle(char* title)
{
	this->title = title;
	SetWindowTitle(title);
}

void Window::Update()
{
	Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] = 0b11011111;

	auto startTime = std::chrono::steady_clock::now();
	auto nextFrame = startTime + FRAME_INTERVAL;

	while (!WindowShouldClose())
	{
		int cycleElapsed = 0;
		while (cycleElapsed < CYCLE_PER_FRAME)
		{
			Emulator::GetInstance().GetInputControllerRef().HandleInput();
			cycleElapsed += Emulator::GetInstance().GetInstructionProcessorRef().ProcessNextInstruction();
			Emulator::GetInstance().GetInstructionProcessorRef().HandleInterrupts();

		}

		BeginDrawing();
		ClearBackground(BLACK);

		//displaying register values
		DisplayRegistersOnScreen(640, 0);
		//Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->af += 1;
		//std::cout << (short)Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->f << std::endl;

		EndDrawing();

		cycleElapsed = 0;

		std::this_thread::sleep_until(nextFrame);
		nextFrame += FRAME_INTERVAL;
	}
}

Window::Window(const char *title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;
}