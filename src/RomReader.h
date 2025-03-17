#pragma once
#include <string>


/// <summary>
/// Cartridge Metadata
/// </summary>
struct ROMMetadata
{
	char title[16];
	char type;
	char romSize;
	char ramSize;
};

/// <summary>
/// Rom Reader class
/// </summary>
class RomReader
{
	friend class MemoryManager;

private:
	unsigned char* romData = nullptr;
	bool romReady;
	ROMMetadata* meta = nullptr;

	/// <summary>
	/// Initializes metadata
	/// </summary>
	void InitMetadata();

	/// <summary>
	/// Checks if this rom is supported by the emulator
	/// </summary>
	/// <returns></returns>
	bool IsRomSupported();

public:
	/// <summary>
	/// Initializes rom reader and loads ROM
	/// </summary>
	/// <param name="filename">ROM filename</param>
	RomReader(std::string filename);

	/// <summary>
	/// Reads ROM
	/// </summary>
	/// <param name="filename">ROM filename</param>
	void ReadRom(std::string filename);

	/// <summary>
	/// Return ROM Metadata
	/// </summary>
	/// <returns>ROMMetadata struct</returns>
	ROMMetadata& GetROMMetadata();

	/// <summary>
	/// Return state of readiness of the rom
	/// </summary>
	/// <returns></returns>
	bool IsROMReady();
};