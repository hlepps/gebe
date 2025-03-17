#include "Window.h"

#include "raylib.h"
#include "Emulator.h"
#include "RegistersDisplay.h"
#include "InputController.h"

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
	while (!WindowShouldClose())
	{
		Emulator::GetInstance().GetInputControllerRef().HandleInput();
		Emulator::GetInstance().GetInstructionProcessorRef().ProcessNextInstruction();

		BeginDrawing();

		ClearBackground(BLACK);

		//displaying register values
		DisplayRegistersOnScreen(640, 0);
		//Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->af += 1;
		//std::cout << (short)Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->f << std::endl;

		EndDrawing();
	}
}

Window::Window(const char *title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;
}