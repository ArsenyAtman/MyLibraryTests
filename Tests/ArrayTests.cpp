#include "../pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<TArray<int>>(const class TArray<int>& t) { return L"TArray<int>"; }
		}
	}
}

namespace ArrayTests
{
	TEST_CLASS(ArrayTests)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array = { 1, 2, 3, 4, 5 };

			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}

		}

		TEST_METHOD(IteratorTest)
		{
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array = { 1, 2, 3, 4, 5 };

			int i = 0;
			for (const int& Value : Array)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
			Assert::AreEqual(i, Array.GetLength());

			i = 0;
			IIterator<int>* it = Array.GetIterator();
			while (it->HasMore())
			{
				Assert::AreEqual(array[i], it->Get());
				it->Next();
				++i;
			}
			Assert::AreEqual(i, Array.GetLength());
			delete it;
		}

		TEST_METHOD(AccessOperatorTest)
		{
			TArray<int> Array = { 1, 2, 3, 4, 5 };

			Assert::AreEqual(1, Array[0]);
			Assert::AreEqual(3, Array[2]);
			Assert::AreEqual(5, Array[4]);
		}

		TEST_METHOD(CopyConstructor)
		{
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array1 = { 1, 2, 3, 4, 5 };
			TArray<int> Array2(Array1);

			for (int i = Array2.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array2[i]);
			}
		}

		TEST_METHOD(CopyOperator)
		{
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array1 = { 1, 2, 3, 4, 5 };
			TArray<int> Array2;
			Array2 = Array1;

			for (int i = Array2.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array2[i]);
			}
		}

		TArray<int> CreateArray()
		{
			TArray<int> Array = { 1, 2, 3, 4, 5 };
			return Array;
		}

		TEST_METHOD(MoveConstructor)
		{
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array(CreateArray());

			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}
		}

		TEST_METHOD(MoveOperator)
		{
			
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array;
			Array = CreateArray();

			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}
		}

		TEST_METHOD(LengthTest)
		{
			TArray<int> Array = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(5, Array.GetLength());
		}

		TEST_METHOD(ComparsionOperatorTest)
		{
			TArray<int> Array = { 1, 2, 3, 4, 5 };
			TArray<int> Array2 = { 1, 2, 3 };
			TArray<int> Array3 = { 1, 2, 3, 4, 5 };

			Assert::IsTrue(Array != Array2);
			Assert::IsTrue(Array == Array3);
			Assert::IsTrue(Array == Array);
		}

		TEST_METHOD(AppendTest)
		{

			int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
			TArray<int> Array1 = { 1, 2, 3 };
			TArray<int> Array2 = { 4, 5, 6, 7, 8, 9, 10, 11 };

			TArray<int> Array;

			Array.Append(Array1);
			Array.Append(Array2);

			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}

			Assert::AreEqual(11, Array.GetLength());
		}

		TEST_METHOD(AddTest)
		{
			int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			TArray<int> Array;
			Array.Add(0);
			Array.Add(1);
			Array.Add(2);
			Array.Add(3);
			Array.Add(4);
			Array.Add(5);
			Array.Add(6);
			Array.Add(7);
			Array.Add(8);
			Array.Add(9);
			Array.Add(10);

			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}

			Assert::AreEqual(11, Array.GetLength());
		}

		TEST_METHOD(InsertBeforeTest)
		{
			int array[] = { 1, 2, 3, 4, 5 };
			TArray<int> Array = { 5 };
			Array.InsertBefore(0, 2);
			Array.InsertBefore(0, 1);
			Array.InsertBefore(2, 4);
			Array.InsertBefore(2, 3);

			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}

			Assert::AreEqual(5, Array.GetLength());
		}

		TEST_METHOD(RemoveAtTest)
		{
			int array[] = { 2, 5, 6, 7, 8 };
			TArray<int> Array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			Array.RemoveAt(10);
			Array.RemoveAt(9);
			Array.RemoveAt(0);
			Array.RemoveAt(0);
			Array.RemoveAt(1);
			Array.RemoveAt(1);
			
			for (int i = Array.GetLength() - 1; i >= 0; --i)
			{
				Assert::AreEqual(array[i], Array[i]);
			}

			Assert::AreEqual(5, Array.GetLength());

			Array.RemoveAt(0);
			Array.RemoveAt(0);
			Array.RemoveAt(0);
			Array.RemoveAt(0);
			Array.RemoveAt(0);

			Assert::AreEqual(0, Array.GetLength());
		}
	};
}
