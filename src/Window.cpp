#include "Window.h"

#include "raylib.h"

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
		BeginDrawing();

		ClearBackground(BLACK);

		//displaying register values
		DrawText("A", 640 + 10, 10, 12, WHITE);

		EndDrawing();
	}
}

Window::Window(const char *title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;
}