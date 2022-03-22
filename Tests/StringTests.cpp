#include "../pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<AString>(const class AString& t) { return L"AString"; }
		}
	}
}

namespace StringTests
{

	TEST_CLASS(StringTests)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			AString String = AString("QwErTy12345");

			Assert::AreEqual("QwErTy12345", String);
		}

		TEST_METHOD(CopyConstructorTest)
		{
			AString String1 = AString("QwErTy12345");
			AString String2(String1);

			Assert::AreEqual(String1, String2);
			Assert::AreEqual("QwErTy12345", String1);
		}

		AString CreateTestString()
		{
			AString String = AString("QwErTy12345");
			return String;
		}

		TEST_METHOD(MoveConstructorTest)
		{
			AString String(CreateTestString());

			Assert::AreEqual("QwErTy12345", String);
		}

		TEST_METHOD(CopyOperatorTest)
		{
			AString String1;
			AString String2("qwerty");
			String1 = String2;

			Assert::AreEqual(String1, String2);
			Assert::AreEqual("qwerty", String1);
		}

		TEST_METHOD(MoveOperatorTest)
		{
			AString String;
			String = CreateTestString();

			Assert::AreEqual("QwErTy12345", String);
		}

		TEST_METHOD(ComparsionOperatorTest)
		{
			AString String1 = AString("QwErTy12345");
			AString String2 = AString("QwErTy12345");
			const char* String3 = "QwErTy12345";

			Assert::IsTrue(String3 == String2);
			Assert::IsTrue(String2 == String3);
			Assert::IsTrue(String1 == String2);
			Assert::IsTrue(String1 == String3);

			String2 = AString("Oppa!");

			Assert::IsTrue(String1 != String2);
			Assert::IsTrue(String3 != String2);
			Assert::IsFalse(String3 != String1);
		}

		TEST_METHOD(ConversionTest)
		{
			AString String1 = AString("QwErTy12345");
			const char* String2 = String1;

			Assert::AreEqual("QwErTy12345", String2);
			Assert::AreEqual(String1, String2);
		}

		TEST_METHOD(AccessOperatorTest)
		{
			AString String1 = AString("QwErTy12345");

			Assert::AreEqual('Q', String1[0]);
			Assert::AreEqual('r', String1[3]);
			Assert::AreEqual('1', String1[6]);
			Assert::AreEqual('5', String1[10]);

			String1[10] = '6';
			String1[6] = '6';

			Assert::AreEqual('6', String1[6]);
			Assert::AreEqual('6', String1[10]);
		}

		TEST_METHOD(ConcatTest)
		{
			AString String1 = AString("QwErTy12345");
			AString String2 = AString("QwErTy12345");

			AString String3 = String1 + String2;

			Assert::AreEqual("QwErTy12345QwErTy12345", String3);

			String1 = AString("");
			String2 = AString("");
			String3 = String1 + String2;
			Assert::AreEqual("", String3);

			AString String4;
			String2 = AString("QwErTy12345");
			Assert::AreEqual("QwErTy12345", String4 + String2);
			Assert::AreEqual("QwErTy12345", String2 + String4);
		}

		TEST_METHOD(SplitTest)
		{
			AString String1 = AString("QwErTy12345");

			Assert::AreEqual("ErTy1234", String1.Split(2, 9));
			Assert::AreEqual("Q", String1.Split(0, 0));
			Assert::AreEqual("5", String1.Split(10, 10));

			Assert::AreNotEqual("qwerty", String1.Split(2, 9));

			try
			{
				String1.Split(9, 2);
			}
			catch (AException Exception)
			{

			}
			catch (...)
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(LengthTest)
		{
			AString String1 = AString("QwErTy12345");

			Assert::AreEqual(11, String1.GetLength());

			AString String2 = AString("");

			Assert::AreEqual(0, String2.GetLength());
		}
	};
}
