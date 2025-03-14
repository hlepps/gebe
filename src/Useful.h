#pragma once

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