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

		const char* ReadFilePath = "..//Tests//TestFiles//ReadFile.txt";
		const char* WriteFilePath = "..//Tests//TestFiles//ReadFile.txt";

		TEST_METHOD(ConstructorTest)
		{
			AFile File = AFile(ReadFilePath, EFileMode::ReadOnly);

			Assert::AreEqual(ReadFilePath, File.GetFilePath());
			Assert::AreEqual(EFileMode::ReadOnly, File.GetFileMode());
		}

		TEST_METHOD(ReadTest)
		{
			AFile File = AFile(ReadFilePath, EFileMode::ReadOnly);
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
			AFile File = AFile(WriteFilePath, EFileMode::ClearAndReadWrite);
			AString StringToWrite = "Qwerty123\n!@#$%^&*()";
			TArray<char> CharArray = TArray<char>(StringToWrite.GetLength());
			for (int i = 0; i < StringToWrite.GetLength(); ++i)
			{
				CharArray.Add(StringToWrite[i]);
			}

			File.WriteBytes(CharArray);
			
			File.Open(ReadFilePath, EFileMode::ReadOnly);
			CharArray = File.ReadBytes(File.GetFileSize());

			for (int i = 0; i < StringToWrite.GetLength(); i++)
			{
				Assert::AreEqual(StringToWrite[i], CharArray[i]);
			}

			Assert::AreEqual(StringToWrite.GetLength(), CharArray.GetLength());
			
		}

		TEST_METHOD(SizeTest)
		{
			AFile File = AFile(ReadFilePath, EFileMode::ReadOnly);
			AString ExpectedString = "Qwerty123\n!@#$%^&*()";

			Assert::AreEqual(ExpectedString.GetLength(), File.GetFileSize());
		}

		TEST_METHOD(PathTest)
		{
			AFile File = AFile(ReadFilePath, EFileMode::ReadOnly);
				
			Assert::AreEqual(ReadFilePath, File.GetFilePath());
		}

		TEST_METHOD(ModeTest)
		{
			AFile File;

			File.Open(ReadFilePath, EFileMode::ReadOnly);
			Assert::AreEqual(EFileMode::ReadOnly, File.GetFileMode());

			File.Open(ReadFilePath, EFileMode::WriteOnly);
			Assert::AreEqual(EFileMode::WriteOnly, File.GetFileMode());

			File.Open(ReadFilePath, EFileMode::ReadWrite);
			Assert::AreEqual(EFileMode::ReadWrite, File.GetFileMode());

			File.Close();
			Assert::AreEqual(EFileMode::Closed, File.GetFileMode());
		}

		TEST_METHOD(SetReadWritePositionTest)
		{
			AFile File(ReadFilePath, EFileMode::ReadOnly);

			for (int i = 0; i < 10; i++)
			{
				File.SetReadWritePosition(i);
				Assert::AreEqual(i, File.GetReadWritePosition());
			}
		}

		TEST_METHOD(FileExistsTest)
		{
			Assert::AreEqual(true, AFile::FileExists(ReadFilePath));
			Assert::AreEqual(true, AFile::FileExists(WriteFilePath));
			Assert::AreEqual(false, AFile::FileExists("__ubefku.txt"));
			Assert::AreEqual(false, AFile::FileExists("qwerty.txt"));
		}
	};
}
