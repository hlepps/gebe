#include "Useful.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <format>
#include <bitset>
#include <utility>

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
	return std::format("{:0>4b}", c);
}
std::string ToBinary(unsigned short c)
{
	return std::format("{:0>8b}", c);
}

short combineChars(unsigned char high, unsigned char low) {
	return (static_cast<short>(high) << 8) | static_cast<unsigned char>(low);
}

std::pair<unsigned char, unsigned char> separateChars(unsigned short val)
{
	unsigned char higher = (val >> 8) & 0xFF;
	unsigned char lower = val & 0xFF;
	return { higher, lower };
}

bool GetBit(unsigned char val, char pos)
{
	std::bitset<8> bits(val);
	return bits[pos];
}

bool GetBit(unsigned short val, char pos)
{
	std::bitset<16> bits(val);
	return bits[pos];
}

unsigned char SetBit(unsigned char val, char pos, bool bit)
{
	std::bitset<8> bits(val);
	bits[pos] = bit;
	return static_cast<unsigned char>(bits.to_ulong());
}

unsigned short SetBit(unsigned short val, char pos, bool bit)
{
	std::bitset<16> bits(val);
	bits[pos] = bit;
	return static_cast<unsigned short>(bits.to_ulong());
}
