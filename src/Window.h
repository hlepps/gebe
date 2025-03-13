#pragma once

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
	/// <summary>
	/// Initializes main window
	/// </summary>
	/// <param name="title">Window title</param>
	/// <param name="width">Window width</param>
	/// <param name="height">Window height</param>
	Window(const char *title, int width, int height);

	/// <summary>
	/// Opens main window
	/// </summary>
	void Open();

	/// <summary>
	/// Closes main window
	/// </summary>
	void Close();
	
};
