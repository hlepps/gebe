#pragma once

#include <string>
#include <utility>

std::string ToHex(unsigned char c);
std::string ToHex(unsigned short c);

std::string ToBinary(unsigned char c);

short combineChars(unsigned char high, unsigned char low);
std::pair<unsigned char, unsigned char> separateChars(unsigned short val);

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

/// <summary>
/// Sets bit at pos (from right)
/// </summary>
/// <param name="val"></param>
/// <param name="pos"></param>
/// <returns></returns>
unsigned char SetBit(unsigned char val, char pos, bool bit);

/// <summary>
/// Sets bit at pos (from right)
/// </summary>
/// <param name="val"></param>
/// <param name="pos"></param>
/// <returns></returns>
unsigned short SetBit(unsigned short val, char pos, bool bit);