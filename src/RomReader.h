#pragma once

struct ROMMetadata
{
	char title[16];
};

/// <summary>
/// Rom Reader class
/// </summary>
class RomReader
{
private:
	char* romData;

public:
	/// <summary>
	/// Initializes rom reader and loads ROM
	/// </summary>
	/// <param name="filename">ROM filename</param>
	RomReader(char* filename);

	/// <summary>
	/// Reads ROM
	/// </summary>
	/// <param name="filename">ROM filename</param>
	void ReadRom(char *filename);

	ROMMetadata GetROMMetadata();
};