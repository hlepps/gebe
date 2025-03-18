#pragma once

class Timer
{
private:
	int cyclesElapsed = 0;
public:
	Timer();

	void SetCyclesToZero();
};