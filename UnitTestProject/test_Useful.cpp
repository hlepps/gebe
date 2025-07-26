#include "pch.h"
#include "CppUnitTest.h"

#include <format>
#include <utility>

#include "../src/Useful.h"
#include "../src/Useful.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
	TEST_CLASS(test_Useful)
	{
	public:
		
		TEST_METHOD(test1_separateChars)
		{
			auto pair = separateChars(0x3C7E);
			Assert::AreEqual((unsigned char)0x3C, pair.first);
		}
		
		TEST_METHOD(test2_separateChars)
		{
			auto pair = separateChars(0x3C7E);
			Assert::AreEqual((unsigned char)0x7E, pair.second);
		}
	};
}
