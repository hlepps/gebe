#include "Useful.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <format>

std::string ToHex(unsigned char c)
{
	return std::format("{:X}", (short)c);
}

std::string ToHex(unsigned short c)
{
	return std::format("{:X}", static_cast<int>(c));
}

std::string ToBinary(unsigned char c)
{
	return std::format("{:8b}", c);
}

short combineChars(char high, char low) {
	return (static_cast<short>(high) << 8) | static_cast<unsigned char>(low);
}