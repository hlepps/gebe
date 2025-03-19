#pragma once

class Timer
{
private:
	int cyclesElapsed = 0;
	const int DIVIDER_FREQUENCY = 16384;
public:
	Timer();

	/// <summary>
	/// Sest cyclesElapsed to 0;
	/// </summary>
	void SetCyclesToZero();

	/// <summary>
	/// Updates cyclesElapsed and also divider and counter registers
	/// </summary>
	void UpdateCycles(int cycles);
};