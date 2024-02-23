#include "pch.h"
#include "CppUnitTest.h"
#include "../7.1(iter)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(CreateTest)
		{
			const int rowCount = 7;
			const int colCount = 6;
			const int Low = -12;
			const int High = 23;

			int** x = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				x[i] = new int[colCount];

			Create(x, rowCount, colCount, Low, High);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(x[i][j] >= Low && x[i][j] <= High);
				}
			}

			for (int i = 0; i < rowCount; i++)
				delete[] x[i];
			delete[] x;
		}
	};
}
