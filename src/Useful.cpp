#include "Useful.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <format>
#include <bitset>

std::string ToHex(unsigned char c)
{
	return std::format("{:0>2X}", (short)c);
}

std::string ToHex(unsigned short c)
{
	return std::format("{:0>4X}", static_cast<int>(c));
}

std::string ToBinary(unsigned char c)
{
	return std::format("{:0>8b}", c);
}

short combineChars(char high, char low) {
	return (static_cast<short>(high) << 8) | static_cast<unsigned char>(low);
}

bool GetBit(char val, char pos)
{
	std::bitset<8> bits(val);
	return bits[pos];
}

bool GetBit(short val, char pos)
{
	std::bitset<16> bits(val);
	return bits[pos];
}
