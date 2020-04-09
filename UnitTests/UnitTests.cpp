#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4/medikament.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			auto med = new Medikament("Paracetamol", 100.0, 50, 17.99);
			Assert::AreEqual(std::string("Paracetamol"), med->get_name());
			Assert::AreEqual(100.0, med->get_konz());
			Assert::AreEqual(50, med->get_menge());
			Assert::AreEqual(17.99, med->get_preis());
		}
	};
}
