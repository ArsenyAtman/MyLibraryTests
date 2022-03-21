#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<AFile>(const class AFile& t) { return L"AFile"; }
			template<> static std::wstring ToString<EFileMode>(const EFileMode& t) { return L"EFileMode"; }
		}
	}
}

namespace FileTests
{
	TEST_CLASS(FileTests)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			AFile File = AFile("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);

			Assert::AreEqual("..//TestFiles//ReadFile.txt", File.GetFilePath());
			Assert::AreEqual(EFileMode::ReadOnly, File.GetFileMode());
		}

		TEST_METHOD(ReadTest)
		{
			AFile File = AFile("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);
			AString ExpectedString = "Qwerty123\n!@#$%^&*()";
			TArray<char> RealString = File.ReadBytes(File.GetFileSize());

			for (int i = 0; i < ExpectedString.GetLength(); i++)
			{
				Assert::AreEqual(ExpectedString[i], RealString[i]);
			}

			Assert::AreEqual(ExpectedString.GetLength(), RealString.GetLength());
		}

		TEST_METHOD(WriteTest)
		{
			AFile File = AFile("..//TestFiles//WriteFile.txt", EFileMode::ClearAndReadWrite);
			AString StringToWrite = "Qwerty123\n!@#$%^&*()";
			TArray<char> CharArray = TArray<char>(StringToWrite.GetLength());
			for (int i = 0; i < StringToWrite.GetLength(); ++i)
			{
				CharArray.Add(StringToWrite[i]);
			}

			File.WriteBytes(CharArray);
			
			File.Open("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);
			CharArray = File.ReadBytes(File.GetFileSize());

			for (int i = 0; i < StringToWrite.GetLength(); i++)
			{
				Assert::AreEqual(StringToWrite[i], CharArray[i]);
			}

			Assert::AreEqual(StringToWrite.GetLength(), CharArray.GetLength());
			
		}

		TEST_METHOD(SizeTest)
		{
			AFile File = AFile("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);
			AString ExpectedString = "Qwerty123\n!@#$%^&*()";

			Assert::AreEqual(ExpectedString.GetLength(), File.GetFileSize());
		}

		TEST_METHOD(PathTest)
		{
			AFile File = AFile("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);
				
			Assert::AreEqual("..//TestFiles//ReadFile.txt", File.GetFilePath());
		}

		TEST_METHOD(ModeTest)
		{
			AFile File;

			File.Open("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);
			Assert::AreEqual(EFileMode::ReadOnly, File.GetFileMode());

			File.Open("..//TestFiles//ReadFile.txt", EFileMode::WriteOnly);
			Assert::AreEqual(EFileMode::WriteOnly, File.GetFileMode());

			File.Open("..//TestFiles//ReadFile.txt", EFileMode::ReadWrite);
			Assert::AreEqual(EFileMode::ReadWrite, File.GetFileMode());

			File.Close();
			Assert::AreEqual(EFileMode::Closed, File.GetFileMode());
		}

		TEST_METHOD(SetReadWritePositionTest)
		{
			AFile File("..//TestFiles//ReadFile.txt", EFileMode::ReadOnly);

			for (int i = 0; i < 10; i++)
			{
				File.SetReadWritePosition(i);
				Assert::AreEqual(i, File.GetReadWritePosition());
			}
		}

		TEST_METHOD(FileExistsTest)
		{
			Assert::AreEqual(true, AFile::FileExists("..//TestFiles//ReadFile.txt"));
			Assert::AreEqual(true, AFile::FileExists("..//TestFiles//WriteFile.txt"));
			Assert::AreEqual(false, AFile::FileExists("..//TestFiles//__ubefku.txt"));
			Assert::AreEqual(false, AFile::FileExists("..//TestFiles//qwerty.txt"));
		}
	};
}
