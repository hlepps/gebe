#include "CommandLineArguments.h"
#pragma once

int CommandLineArguments::count = 0;
char** CommandLineArguments::arguments = nullptr;

void CommandLineArguments::Set(int c, char** a)
{
	count = c;
	arguments = a;
}

int CommandLineArguments::GetCount()
{
	return count;
}

char** CommandLineArguments::GetArguments()
{
	return arguments;
}
