#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include "Offsets.h"

#include "RomReader.h"



using namespace std;


RomReader::RomReader(string filename)
{
	ReadRom(filename);
}



void RomReader::ReadRom(string filename)
{
	romReady = false;
	if (romData != nullptr)
	{
		delete[] romData;
		romData = nullptr;
	}

	cout << "working directory: " << std::filesystem::current_path() << endl;
	try {
		std::basic_ifstream<char> input(filename, std::ios::binary | ios::ate);
		if (!input.is_open()) return;

		long long size = input.tellg();
		

		romData = new unsigned char[size];

		input.seekg(0, std::ios::beg);
		input.read((char*)romData, size);
		
		cout << "read: " << size << " bytes" << endl;

		romReady = true;

		input.close();
	}
	catch (const exception& e) {
		cout << "Exception " << e.what() << endl;
	}
}

ROMMetadata RomReader::GetROMMetadata()
{
	ROMMetadata meta;
	std::copy(romData+ROM_TITLE_BEGIN, romData+ROM_TITLE_END, meta.title);

	return meta;
}

bool RomReader::IsROMReady()
{
	return romReady;
}
