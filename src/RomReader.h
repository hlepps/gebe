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
	friend class MemoryManager;

private:
	char* romData = nullptr;
	bool romReady;

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

	/// <summary>
	/// Return ROM Metadata
	/// </summary>
	/// <returns>ROMMetadata struct</returns>
	ROMMetadata GetROMMetadata();

	/// <summary>
	/// Return state of readiness of the rom
	/// </summary>
	/// <returns></returns>
	bool IsROMReady();
};