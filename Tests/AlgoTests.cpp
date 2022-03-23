#include "../pch.h"
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
			template<> static std::wstring ToString<TList<int>>(const class TList<int>& t) { return L"TList<int>"; }
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

		TEST_METHOD(LinearSearchTest)
		{
			TArray<int> Array = { 0, 1, 2, 3, 4, 5 };

			for (int i = 5; i >= 0; --i)
			{
				Assert::AreEqual(i, LAlgo::LinearSearch(Array, i));
			}
		}

		TEST_METHOD(BinarySearchTest)
		{
			TArray<int> Array = { 0, 1, 2, 3, 4, 5 };

			for (int i = 5; i >= 0; --i)
			{
				Assert::AreEqual(i, LAlgo::BinarySearch(Array, i));
			}
		}

		TEST_METHOD(QuickSortTest)
		{
			TArray<int> ExpectedArray = { 0, 1, 2, 3, 4, 5 };
			TArray<int> ActualArray = { 0, 1, 2, 3, 4, 5 };
			LAlgo::QuickSort(ActualArray, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray, ActualArray);

			ExpectedArray = { 0, 1, 2, 3, 4, 5 };
			ActualArray = { 5, 4, 3, 2, 1, 0 };
			LAlgo::QuickSort(ActualArray, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray, ActualArray);

			ExpectedArray = TArray<int>();
			ActualArray = TArray<int>();
			LAlgo::QuickSort(ActualArray, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray, ActualArray);

			ExpectedArray = { 0, 1, 2, 3, 4, 5 };
			ActualArray = { 0, 5, 3, 2, 4, 1};
			LAlgo::QuickSort(ActualArray, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray, ActualArray);

			ExpectedArray = { 5, 4, 3, 2, 1, 0 };
			ActualArray = { 0, 1, 2, 3, 4, 5 };
			LAlgo::QuickSort(ActualArray, ESortType::Descending);
			Assert::AreEqual(ExpectedArray, ActualArray);

			ExpectedArray = { 5, 4, 3, 2, 1, 0 };
			ActualArray = { 0, 5, 3, 2, 4, 1 };
			LAlgo::QuickSort(ActualArray, ESortType::Descending);
			Assert::AreEqual(ExpectedArray, ActualArray);
		}

		TEST_METHOD(ReverseTest)
		{
			TArray<int> ExpectedArray = { 5, 4, 3, 2, 1, 0 };
			TArray<int> ActualArray = { 0, 1, 2, 3, 4, 5 };
			LAlgo::Reverse(ActualArray);
			Assert::AreEqual(ExpectedArray, ActualArray);

			ExpectedArray = { 6, 5, 4, 3, 2, 1, 0 };
			ActualArray = { 0, 1, 2, 3, 4, 5, 6 };
			LAlgo::Reverse(ActualArray);
			Assert::AreEqual(ExpectedArray, ActualArray);

			TList<int> ExpectedList = { 5, 4, 3, 2, 1, 0 };
			TList<int> ActualList = { 0, 1, 2, 3, 4, 5 };
			LAlgo::Reverse(ActualList);
			Assert::AreEqual(ExpectedList, ActualList);

			ExpectedList = { 6, 5, 4, 3, 2, 1, 0 };
			ActualList = { 0, 1, 2, 3, 4, 5, 6 };
			LAlgo::Reverse(ActualList);
			Assert::AreEqual(ExpectedList, ActualList);
		}
	};
}
