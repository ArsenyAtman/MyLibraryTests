#include "../pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<TList<int>>(const class TList<int>& t) { return L"TList<int>"; }
			template<> static std::wstring ToString<TArray<int>>(const class TArray<int>& t) { return L"TArray<int>"; }
		}
	}
}

namespace ListTests
{
	TEST_CLASS(ListTests)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List = { 0, 1, 2, 3, 4, 5 };

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(IteratorTest)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List = { 0, 1, 2, 3, 4, 5 };

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
			Assert::AreEqual(i, 6);

			IIterator<int>* it = List.GetIterator();
			i = 0;
			while(it->HasMore())
			{
				Assert::AreEqual(array[i], it->Get());
				it->Next();
				++i;
			}
			Assert::AreEqual(i, 6);
		}

		TEST_METHOD(PushFwdTest)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List = { 3, 4, 5 };

			List.PushForward(2);
			List.PushForward(1);
			List.PushForward(0);

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(PushBwdTest)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List = { 0, 1, 2 };

			List.PushBack(3);
			List.PushBack(4);
			List.PushBack(5);

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(PopFwdTest)
		{
			int array[] = { 3, 4, 5 };
			TList<int> List = { 0, 1, 2, 3, 4, 5 };

			Assert::AreEqual(0, List.PopForward());
			Assert::AreEqual(1, List.PopForward());
			Assert::AreEqual(2, List.PopForward());

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(PopBwdTest)
		{
			int array[] = { 0, 1, 2 };
			TList<int> List = { 0, 1, 2, 3, 4, 5 };

			Assert::AreEqual(5, List.PopBack());
			Assert::AreEqual(4, List.PopBack());
			Assert::AreEqual(3, List.PopBack());

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(CopyConstructor)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List1 = { 0, 1, 2, 3, 4, 5 };
			TList<int> List2(List1);

			int i = 0;
			for (const int& Value : List2)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(CopyOperator)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List1 = { 0, 1, 2, 3, 4, 5 };
			TList<int> List2;
			List2 = List1;

			int i = 0;
			for (const int& Value : List2)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TList<int> CreateList()
		{
			TList<int> List = { 0, 1, 2, 3, 4, 5 };
			return List;
		}

		TEST_METHOD(MoveConstructor)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List(CreateList());

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(MoveOperator)
		{
			int array[] = { 0, 1, 2, 3, 4, 5 };
			TList<int> List;
			List = CreateList();

			int i = 0;
			for (const int& Value : List)
			{
				Assert::AreEqual(array[i], Value);
				++i;
			}
		}

		TEST_METHOD(LengthTest)
		{
			TList<int> List = { 0, 1, 2, 3, 4, 5 };
			TList<int> List1;

			List.PopBack();
			List.PopBack();
			List.PopBack();

			List.PushBack(0);
			List.PushBack(0);

			Assert::AreEqual(5, List.GetLength());
			Assert::AreEqual(0, List1.GetLength());
		}

		TEST_METHOD(ComparsionOperatorTest)
		{
			TList<int> List = { 1, 2, 3, 4, 5 };
			TList<int> List2 = { 1, 2, 3 };
			TList<int> List3 = { 1, 2, 3, 4, 5 };
			TList<int> List4;
			TList<int> List5;

			Assert::IsTrue(List != List2);
			Assert::IsTrue(List == List3);
			Assert::IsTrue(List == List);
			Assert::IsTrue(List4 == List5);
		}
	};
}
