#pragma once


class InputController
{
	bool x;
public:
	/// <summary>
	/// Handles input (sets the bytes in the memory)
	/// </summary>
	static void HandleInput();

	/// <summary>
	/// Initializes InputController - sets 0xFF00 value to 0xF
	/// </summary>
	static void Initialize();
};