#include "MainWindow.h"

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
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);


		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}
}

Window::Window(const char *title, int width, int height)
{
	this->title = title;
	this->width = width;
	this->height = height;
}