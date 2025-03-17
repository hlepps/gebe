#include <fstream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include "Offsets.h"

#include "RomReader.h"

void RomReader::InitMetadata()
{
	meta = new ROMMetadata;

	std::copy(romData + ROM_TITLE_BEGIN, romData + ROM_TITLE_END, meta->title);
	meta->type = romData[ROM_TYPE];
	meta->romSize = romData[ROM_ROM_SIZE];
	meta->ramSize = romData[ROM_RAM_SIZE];
}

bool RomReader::IsRomSupported()
{
	switch (meta->type)
	{
	case 0x00:			// ROM ONLY
		return true;

	}
	return false;
}

RomReader::RomReader(std::string filename)
{
	ReadRom(filename);
}

void RomReader::ReadRom(std::string filename)
{
	romReady = false;
	if (romData != nullptr)
	{
		delete[] romData;
		romData = nullptr;
	}

	std::cout << "working directory: " << std::filesystem::current_path() << std::endl;
	try {
		std::basic_ifstream<char> input(filename, std::ios::binary | std::ios::ate);
		if (!input.is_open()) return;

		long long size = input.tellg();
		romData = new unsigned char[size];

		input.seekg(0, std::ios::beg);
		input.read((char*)romData, size);
		
		std::cout << "read: " << size << " bytes" << std::endl;

		input.close();

		InitMetadata();

		if (IsRomSupported()) romReady = true;

	}
	catch (const std::exception& e) {
		std::cout << "Exception " << e.what() << std::endl;
	}
}

ROMMetadata& RomReader::GetROMMetadata()
{
	return *meta;
}

bool RomReader::IsROMReady()
{
	return romReady;
}
