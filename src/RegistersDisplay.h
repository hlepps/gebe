#pragma once

#include "raylib.h"
#include "Emulator.h"
#include "Useful.h"

void DisplayRegistersOnScreen(int offsetX, int offsetY)
{
	int fontSize = 18;
	int horDiff = 20;
	Color color = WHITE;

	DrawText("A", offsetX + 10, offsetY + 10, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->a).c_str(), offsetX + 10, offsetY + 10 + horDiff, fontSize, color);
	DrawText("F", offsetX + 60, offsetY + 10, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->f).c_str(), offsetX + 60, offsetY + 10 + horDiff, fontSize, color);
	DrawText("AF", offsetX + 110, offsetY + 10, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->af).c_str(), offsetX + 110, offsetY + 10 + horDiff, fontSize, color);

	DrawText("B", offsetX + 10, offsetY + 60, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->b).c_str(), offsetX + 10, offsetY + 60 + horDiff, fontSize, color);
	DrawText("C", offsetX + 60, offsetY + 60, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->c).c_str(), offsetX + 60, offsetY + 60 + horDiff, fontSize, color);
	DrawText("BC", offsetX + 110, offsetY + 60, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->bc).c_str(), offsetX + 110, offsetY + 60 + horDiff, fontSize, color);

	DrawText("D", offsetX + 10, offsetY + 110, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->d).c_str(), offsetX + 10, offsetY + 110 + horDiff, fontSize, color);
	DrawText("E", offsetX + 60, offsetY + 110, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->e).c_str(), offsetX + 60, offsetY + 110 + horDiff, fontSize, color);
	DrawText("DE", offsetX + 110, offsetY + 110, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->de).c_str(), offsetX + 110, offsetY + 110 + horDiff, fontSize, color);

	DrawText("H", offsetX + 10, offsetY + 160, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->h).c_str(), offsetX + 10, offsetY + 160 + horDiff, fontSize, color);
	DrawText("L", offsetX + 60, offsetY + 160, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->l).c_str(), offsetX + 60, offsetY + 160 + horDiff, fontSize, color);
	DrawText("HL", offsetX + 110, offsetY + 160, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->hl).c_str(), offsetX + 110, offsetY + 160 + horDiff, fontSize, color);

	DrawText("SP", offsetX + 110, offsetY + 210, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->sp).c_str(), offsetX + 110, offsetY + 210 + horDiff, fontSize, color);

	DrawText("PC", offsetX + 110, offsetY + 260, fontSize, color);
	DrawText(ToHex(Emulator::GetInstance().GetInstructionProcessorRef().GetRegistersRef()->pc).c_str(), offsetX + 110, offsetY + 260 + horDiff, fontSize, color);

	DrawText("0xFF00 (input)", offsetX + 10, offsetY + 310, fontSize, color);
	DrawText(ToBinary(Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00]).c_str(), offsetX + 10, offsetY + 310 + horDiff, fontSize, color);
}