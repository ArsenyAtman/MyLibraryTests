#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<LAlgo>(const class LAlgo& t) { return L"LAlgo"; }
			template<> static std::wstring ToString<TArray<int>>(const class TArray<int>& t) { return L"TArray<int>"; }
		}
	}
}

namespace AlgoTests
{
	TEST_CLASS(AlgoTests)
	{
	public:

		TEST_METHOD(SimpleTypeSwapTest)
		{
			int Value1 = 10;
			int Value2 = 20;

			int ExpectedValue1 = Value2;
			int ExpectedValue2 = Value1;

			LAlgo::Swap(Value1, Value2);

			Assert::AreEqual(ExpectedValue1, Value1);
			Assert::AreEqual(ExpectedValue2, Value2);

		}

		TEST_METHOD(ComplexTypeSwapTest)
		{
			TArray<int> Value1 = { 1, 2, 3 };
			TArray<int> Value2 = { 3, 2, 1 };

			TArray<int> ExpectedValue1 = Value2;
			TArray<int> ExpectedValue2 = Value1;

			LAlgo::Swap(Value1, Value2);

			Assert::AreEqual(ExpectedValue1, Value1);
			Assert::AreEqual(ExpectedValue2, Value2);

		}
	};
}