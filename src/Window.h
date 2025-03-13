#pragma once

class Window
{
private:
	const char* title;
	int width;
	int height;

	void Update();

public:
	Window(const char *title, int width, int height);

	void Open();
	void Close();
	
};
