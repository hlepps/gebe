#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "RomReader.h"

#include <stdexcept>
#include <iostream>
#include <filesystem>


using namespace std;


RomReader::RomReader(char *filename)
{
	ReadRom(filename);
}



void RomReader::ReadRom(char *filename)
{
	cout << "working directory: " << std::filesystem::current_path() << endl;
	try {
		std::basic_ifstream<char> input(filename, std::ios::binary);
		if (!input.is_open()) return;

		streampos size = input.tellg();

		romData = new char[size];

		input.read(romData, size);
		
		cout << "read: " << size << " bytes" << endl;
	}
	catch (const exception& e) {
		cout << "Exception " << e.what() << endl;
	}
}

ROMMetadata RomReader::GetROMMetadata()
{
	ROMMetadata meta;
	meta.title[0] = (romData[0]);

	return meta;
}
