#include "Emulator.h"
#include "CommandLineArguments.h"

int main(int argc, char **argv)
{
	CommandLineArguments::Set(argc, argv);
	Emulator::Init();

	return 0;
}
