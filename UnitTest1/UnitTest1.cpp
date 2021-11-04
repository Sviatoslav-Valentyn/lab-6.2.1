#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab 6.2.1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int A[] = { 1, -4, 10, -2 };
			Modify(A, 4);
			Assert::AreEqual(A[3], -2);
		}
	};
}
