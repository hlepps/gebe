#include "InstructionProcessor.h"

#include <exception>
#include <format>
#include <string>
#include <iostream>
#include "Emulator.h"
#include "OPCodeTable.h"
#include "Useful.h"
#include "Offsets.h"


InstructionProcessor::InstructionProcessor()
{
	registers = new Registers;
}

InstructionProcessor::~InstructionProcessor()
{
	delete registers;
	registers = nullptr;
}

Registers* InstructionProcessor::GetRegistersRef()
{
	return registers;
}



void InstructionProcessor::HandleInterrupts()
{
	unsigned char interruptFlag = Emulator::GetInstance().GetMemoryManagerRef().memory[IO_INTERRUPTS];
	unsigned char interruptEnable = Emulator::GetInstance().GetMemoryManagerRef().memory[INTERRUPT_ENABLE];
	unsigned char interruptFired = interruptFlag & interruptEnable;

	if (interruptFlag && interruptEnable) {
		if (processorFlags.halt) {
			processorFlags.halt = false;
			registers->pc++;
		}
		for (unsigned char i = 0; i < 5; i++) {
			if (GetBit(interruptFired, i) && processorFlags.interruptMasterEnable) {
				ExecuteInterrupt(i);
			}
		}
	}
	Emulator::GetInstance().GetMemoryManagerRef().memory[IO_INTERRUPTS] = 0;
}

void InstructionProcessor::ExecuteInterrupt(int interruptNumber)
{
	unsigned char interruptFlag = Emulator::GetInstance().GetMemoryManagerRef().memory[IO_INTERRUPTS];

	interruptFlag = SetBit(interruptFlag, interruptNumber, 0);
	Emulator::GetInstance().GetMemoryManagerRef().memory[IO_INTERRUPTS] = interruptFlag;

	// check later if works
	//Emulator::GetInstance().GetMemoryManagerRef().memory.SetBit(interruptFlag, interruptNumber, 0);
	processorFlags.interruptMasterEnable = false;

	// Push current PC onto stack
	Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (unsigned char)registers->a;
	Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (unsigned char)registers->f;

	// Set PC
	switch (interruptNumber) {
	case INTERRUPT_VALUE_VBLANK:
		registers->pc = 0x40;
		return;
	case INTERRUPT_VALUE_LCD:
		registers->pc = 0x48;
		return;
	case INTERRUPT_VALUE_TIMER:
		registers->pc = 0x50;
		return;
	case INTERRUPT_VALUE_SERIAL:
		registers->pc = 0x58;
		return;
	case INTERRUPT_VALUE_JOYPAD:
		registers->pc = 0x60;
		return;
	}

}

unsigned char InstructionProcessor::GetData()
{
	unsigned char data = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->pc];
	registers->pc++;
	return data;
}

ProcessorFlags InstructionProcessor::GetProcessorFlags()
{
	return processorFlags;
}
