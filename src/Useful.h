#pragma once

#include <string>

std::string ToHex(unsigned char c);
std::string ToHex(unsigned short c);

std::string ToBinary(unsigned char c);

short combineChars(char high, char low);

bool GetBit(char val, char pos);
bool GetBit(short val, char pos);