#include "Emulator.h"
#include "Window.h"
#include "Offsets.h"
#include "Useful.h"

#include "Timer.h"

Timer::Timer()
{
	SetCyclesToZero();
}

void Timer::SetCyclesToZero()
{
	cyclesElapsed = 0;
}

void Timer::UpdateCycles(int cycles)
{
	if (Emulator::GetInstance().GetInstructionProcessorRef().GetProcessorFlags().halt)
		return;

	// divider
	cyclesElapsed += cycles;

	if (cyclesElapsed >= Window::FREQUENCY / DIVIDER_FREQUENCY)
	{
		Emulator::GetInstance().GetMemoryManagerRef().memory[IO_DIVIDER]++;
		cyclesElapsed -= Window::FREQUENCY / DIVIDER_FREQUENCY; // subtracted bcs of trying to emulate cycle consistency
	}

	// timer
	unsigned char tac = Emulator::GetInstance().GetMemoryManagerRef().memory[IO_TIMER_CONTROL];

	if (GetBit(tac, 2))
	{
		unsigned char oldTimer = Emulator::GetInstance().GetMemoryManagerRef().memory[IO_TIMER_COUNTER];

		int cycles = 0;

		switch (GetBit(tac, 0))
		{
		case 0:
		{
			switch (GetBit(tac, 1))
			{
			case 0: // 1024 cycles
			{
				cycles = 1024;
			}break;
			case 1: // 16 cycles
			{
				cycles = 16;
			}break;
			}
		}break;
		case 1:
		{
			switch (GetBit(tac, 1))
			{
			case 0: // 64 cycles
			{
				cycles = 64;
			}break;
			case 1: // 256 cycles
			{
				cycles = 256;
			}break;
			}
		}break;
		}
		
		if (cyclesElapsed >= cycles)
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[IO_TIMER_COUNTER]++;
			if (Emulator::GetInstance().GetMemoryManagerRef().memory[IO_TIMER_COUNTER] < oldTimer) // overflow
			{
				Emulator::GetInstance().GetMemoryManagerRef().memory[IO_TIMER_COUNTER] = Emulator::GetInstance().GetMemoryManagerRef().memory[IO_TIMER_MODULO];
				Emulator::GetInstance().GetMemoryManagerRef().memory[IO_INTERRUPTS] |= INTERRUPT_VALUE_TIMER;
			}

			cyclesElapsed = 0; // set to zero bcs of possibility of changing 
		}
	}

}
