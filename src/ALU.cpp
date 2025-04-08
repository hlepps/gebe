#include "InstructionProcessor.h"

#include <exception>
#include <format>
#include <string>
#include <iostream>
#include "Emulator.h"
#include "OPCodeTable.h"
#include "Useful.h"
#include "Offsets.h"

void InstructionProcessor::alu_add(unsigned char val)
{
	unsigned short result = registers->a + val;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) + (val & 0xf)) & 0x10);
	processorFlags.carryFlag = (result > 0xff);
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_adc(unsigned char val)
{
	unsigned char carry = processorFlags.carryFlag;
	unsigned short result = registers->a + val + carry;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) + (val & 0xf) + (carry & 0xf)) & 0x10);
	processorFlags.carryFlag = (result > 0xff);
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_sub(unsigned char val)
{
	unsigned short result = registers->a - val;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 1;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) - (val & 0xf)) < 0);
	processorFlags.carryFlag = (result > 0xff);
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_sbc(unsigned char val)
{
	unsigned char carry = processorFlags.carryFlag;
	unsigned short result = registers->a - val - carry;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 1;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) - (val & 0xf) - (carry & 0xf)) < 0);
	processorFlags.carryFlag = (result > 0xff);
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_and(unsigned char val)
{
	unsigned short result = registers->a & val;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 1;
	processorFlags.carryFlag = 0;
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_or(unsigned char val)
{
	unsigned short result = registers->a | val;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 0;
	processorFlags.carryFlag = 0;
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_xor(unsigned char val)
{
	unsigned short result = registers->a ^ val;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 0;
	processorFlags.carryFlag = 0;
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_cp(unsigned char val)
{
	unsigned short result = registers->a - val;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 1;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) - (val & 0xf)) < 0);
	processorFlags.carryFlag = (result > 0xff);
}

char InstructionProcessor::alu_inc(unsigned char val)
{
	unsigned short result = val++;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) + (val & 0xf)) & 0x10);
	return (result > 0xff);
}

char InstructionProcessor::alu_dec(unsigned char val)
{
	unsigned short result = val--;
	processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.subtractionFlag = 1;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) - (val & 0xf)) < 0);
	return (result > 0xff);
}

void InstructionProcessor::alu_add16(unsigned short val)
{
	unsigned int result = registers->hl + val;
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = (((registers->a & 0xfff) + (val & 0xfff)) & 0x1000);
	processorFlags.carryFlag = (result > 0xfff);
	registers->hl = (result & 0xffff);
}

short InstructionProcessor::alu_inc16(unsigned short val)
{
	unsigned int result = val++;
	return (result > 0xffff);
}

short InstructionProcessor::alu_dec16(unsigned short val)
{
	unsigned int result = val--;
	return (result > 0xffff);
}

void InstructionProcessor::daa()
{
	// https://github.com/mehcode/wadatsumi

	unsigned int result = registers->a;
	unsigned int correction = (processorFlags.carryFlag) ? 0x60 : 0x00;

	if (processorFlags.halfCarryFlag || (!processorFlags.subtractionFlag) && ((result & 0x0f) > 0x09)) {
		correction |= 0x06;
	}

	if (processorFlags.carryFlag || (!processorFlags.subtractionFlag) && (result > 0x99)) {
		correction |= 0x60;
	}

	if (processorFlags.subtractionFlag) {
		result -= correction;
	}
	else {
		result += correction;
	}

	if (((correction << 2) & 0x100) != 0) {
		processorFlags.carryFlag = 1;
	}

	processorFlags.halfCarryFlag = 0;
	processorFlags.zeroFlag = ((result & 0xff) == 0);

	registers->a = (result & 0xff);
}

char InstructionProcessor::rlc(char val, bool ignoreZ)
{
	bool bit = (val & 0x80) >> 7;
	unsigned char result = (val << 1) | bit;
	processorFlags.zeroFlag = (ignoreZ) ? 0 : (result == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 0;
	processorFlags.carryFlag = bit;
	return result;
}

char InstructionProcessor::rl(char val, bool ignoreZ)
{
	bool bit = processorFlags.carryFlag;
	unsigned char result = (val << 1) | bit;
	processorFlags.zeroFlag = (ignoreZ) ? 0 : (result == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 0;
	processorFlags.carryFlag = ((val & 0x80) >> 7);
	return result;
}

char InstructionProcessor::rrc(char val, bool ignoreZ)
{
	bool bit = (val & 0x01);
	unsigned char result = (val >> 1) | (bit << 7);
	processorFlags.zeroFlag = (ignoreZ) ? 0 : (result == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 0;
	processorFlags.carryFlag = bit;
	return result;
}

char InstructionProcessor::rr(char val, bool ignoreZ)
{
	bool bit = processorFlags.carryFlag;
	unsigned char result = (val >> 1) | (bit << 7);
	processorFlags.zeroFlag = (ignoreZ) ? 0 : (result == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = 0;
	processorFlags.carryFlag = (val & 0x01);
	return result;
}
