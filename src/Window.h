#pragma once

#include <chrono>

/// <summary>
/// Main window class
/// </summary>
class Window
{
private:
	const char* title;
	int width;
	int height;

	/// <summary>
	/// Main loop
	/// </summary>
	void Update();

public:
	static const int FREQUENCY = 4194304; // standard clock cycle frequency in hz
	//static const int CYCLE_PER_FRAME = 70224; // found, dont know if proper
	static const int CYCLE_PER_FRAME = 69905; // counted 
	const std::chrono::microseconds FRAME_INTERVAL = std::chrono::microseconds(16600);

	/// <summary>
	/// Initializes main window
	/// </summary>
	/// <param name="title">Window title</param>
	/// <param name="width">Window width</param>
	/// <param name="height">Window height</param>
	Window(const char* title, int width, int height);

	/// <summary>
	/// Opens main window
	/// </summary>
	void Open();

	/// <summary>
	/// Closes main window
	/// </summary>
	void Close();

	/// <summary>
	/// Changes main window title
	/// </summary>
	/// <param name="title">New main window title</param>
	void ChangeTitle(char* title);
	
};
