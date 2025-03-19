#pragma once

#include <string>

std::string ToHex(unsigned char c);
std::string ToHex(unsigned short c);

std::string ToBinary(unsigned char c);

short combineChars(char high, char low);

/// <summary>
/// Returns bit at pos (from right)
/// </summary>
/// <param name="val"></param>
/// <param name="pos"></param>
/// <returns></returns>
bool GetBit(unsigned char val, char pos);

/// <summary>
/// Returns bit at pos (from right)
/// </summary>
/// <param name="val"></param>
/// <param name="pos"></param>
/// <returns></returns>
bool GetBit(unsigned short val, char pos);