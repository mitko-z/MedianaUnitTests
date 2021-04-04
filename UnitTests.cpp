#include "pch.h"
#include "CppUnitTest.h"
#include "../Mediana/Median.h"
#include "../Mediana/Templates.cpp"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestFloatOddData)
		{
			Median<float> med;
			std::vector<float> data{ 5.0f, 10.0f, 2.0f };
			for (size_t i = 0; i < data.size(); ++i)
			{
				med.add(data[i]);
			}
			float expected = 5.0f;
			Assert::AreEqual(expected, med.getMedian());
		}

		TEST_METHOD(TestFloatEvenData)
		{
			Median<float> med;
			std::vector<float> data{ 5.0f, 10.0f, 2.0f, 6.0f};
			for (size_t i = 0; i < data.size(); ++i)
			{
				med.add(data[i]);
			}
			float expected = 5.5f;
			Assert::AreEqual(expected, med.getMedian());
		}

		TEST_METHOD(TestIntData)
		{
			Median<int> med;
			std::vector<int> data{ 5, 10, 2 };
			for (size_t i = 0; i < data.size(); ++i)
			{
				med.add(data[i]);
			}
			int expected = 5;
			Assert::AreEqual(expected, med.getMedian());
		}

		TEST_METHOD(TestZeroElements)
		{
			Median<int> med;
			Assert::AreEqual(0, med.getMedian());
		}


		TEST_METHOD(TestBigData)
		{
			Median<int> med;
			std::vector<int> data(1'000'000, 10);
			for (size_t i = 0; i < data.size(); ++i)
			{
				med.add(data[i]);
			}
			int expected = 10;
			Assert::AreEqual(expected, med.getMedian());
		}
	};
}
