#include "CppUnitTest.h"
#include "../UPOLR2/UPOLR2.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLR2
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(SimpleSum)
		{
			std::string str = "3+5";
			str = ex(str);
			Assert::AreEqual<std::string>("8", str, false);
		}
		TEST_METHOD(SimpleMult)
		{
			std::string str = "3*5";
			str = ex(str);
			Assert::AreEqual<std::string>("15", str, false);
		}
		TEST_METHOD(SimpleDivide)
		{
			std::string str = "10/5";
			str = ex(str);
			Assert::AreEqual<std::string>("2", str, false);
		}
		TEST_METHOD(SimpleSub)
		{
			std::string str = "10-5";
			str = ex(str);
			Assert::AreEqual<std::string>("5", str, false);
		}
		TEST_METHOD(SumMult)
		{
			std::string str = "3+5*10";
			Assert::AreEqual<std::string>("53", ex(str), false);
		}
		TEST_METHOD(ExpinBrack)
		{
			std::string str = "16/(9-5)";
			Assert::AreEqual<std::string>("4", ex(str), false);
		}
		TEST_METHOD(ErrKnownSymbol)
		{
			std::string str = "16-((5+9)";
			Assert::IsFalse(search(parsing(str)));
		}
		TEST_METHOD(ErrUnknownSymbol)
		{
			std::string str = "17+a-b";
			Assert::IsFalse(search(parsing(str)));
		}
		TEST_METHOD(ComplexExp)
		{
			std::string str = "(10+(9-1)*(6+8*2-(5-3)))/10";
			Assert::AreEqual<std::string>("17", ex(str), false);
		}
		TEST_METHOD(NegRes)
		{
			std::string str = "3-8";
			Assert::AreEqual<std::string>("-5", ex(str), false);
		}
		TEST_METHOD(NegPlusFirst)
		{
			std::string str = "-3+8";
			Assert::AreEqual<std::string>("5", ex(str), false);
		}
		TEST_METHOD(NegPlusSec)
		{
			std::string str = "3+(-8)";
			Assert::AreEqual<std::string>("-5", ex(str), false);
		}
		TEST_METHOD(NegMult)
		{
			std::string str = "-3*(-2)";
			Assert::AreEqual<std::string>("6", ex(str), false);
		}
		TEST_METHOD(Squ)
		{
			std::string str = "2-5^2";
			Assert::IsFalse(search(parsing(str)));
		}
	};
}
