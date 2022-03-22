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
			TArray<int> ExpectedArray1 = { 0, 1, 2, 3, 4, 5 };
			TArray<int> ActualArray1 = { 0, 1, 2, 3, 4, 5 };
			LAlgo::QuickSort(ActualArray1, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray1, ActualArray1);

			TArray<int> ExpectedArray2 = { 0, 1, 2, 3, 4, 5 };
			TArray<int> ActualArray2 = { 5, 4, 3, 2, 1, 0 };
			LAlgo::QuickSort(ActualArray2, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray2, ActualArray2);

			TArray<int> ExpectedArray3 = TArray<int>();
			TArray<int> ActualArray3 = TArray<int>();
			LAlgo::QuickSort(ActualArray3, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray3, ActualArray3);

			TArray<int> ExpectedArray4 = { 0, 1, 2, 3, 4, 5 };
			TArray<int> ActualArray4 = { 0, 5, 3, 2, 4, 1};
			LAlgo::QuickSort(ActualArray4, ESortType::Ascending);
			Assert::AreEqual(ExpectedArray4, ActualArray4);

			TArray<int> ExpectedArray5 = { 5, 4, 3, 2, 1, 0 };
			TArray<int> ActualArray5 = { 0, 1, 2, 3, 4, 5 };
			LAlgo::QuickSort(ActualArray5, ESortType::Descending);
			Assert::AreEqual(ExpectedArray5, ActualArray5);

			TArray<int> ExpectedArray6 = { 5, 4, 3, 2, 1, 0 };
			TArray<int> ActualArray6 = { 0, 5, 3, 2, 4, 1 };
			LAlgo::QuickSort(ActualArray6, ESortType::Descending);
			Assert::AreEqual(ExpectedArray6, ActualArray6);
		}

		TEST_METHOD(MergeSortTest)
		{

		}

		TEST_METHOD(ReverseTest)
		{
			TArray<int> ExpectedArray = { 5, 4, 3, 2, 1, 0 };
			TArray<int> ActualArray = { 0, 1, 2, 3, 4, 5 };
			LAlgo::Reverse(ActualArray);
			Assert::AreEqual(ExpectedArray, ActualArray);

			TList<int> ExpectedList = { 5, 4, 3, 2, 1, 0 };
			TList<int> ActualList = { 0, 1, 2, 3, 4, 5 };
			LAlgo::Reverse(ActualList);
			Assert::AreEqual(ExpectedList, ActualList);
		}
	};
}
