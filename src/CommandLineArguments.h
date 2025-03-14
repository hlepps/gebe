#pragma once

class CommandLineArguments
{
private:
	static int count;
	static char** arguments;

public:
	static void Set(int c, char** a);

	static int GetCount();
	static char** GetArguments();
};