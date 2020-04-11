#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4/medikament.h"
#include "../Lab4/controller.h"

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

		TEST_CLASS(TestController)
		{
			TEST_METHOD(TestModify)
			{
				Medikament med = Medikament("Nurofen", 90, 20, 20.00);
				auto ctrl = Controller();
				auto actual = ctrl.search(med);
				auto expected = true;
				Assert::AreEqual(actual, expected);

				ctrl.modify(med);

				auto actual = ctrl.search(med);
				auto expected = false;
				Assert::AreNotEqual(actual, expected);
			}
			/*TEST_METHOD(modifyNameTest)
			{
				auto med = new Medikament("Nurofen", 90, 20, 20.00);

				med->get_menge -= 10;
				med->get_preis += 5;
				Assert::AreEqual(med->modify());
			}*/
			TEST_METHOD(TestUndoUpdate)
			{
				Medikament med = Medikament("Nurofen", 90, 20, 20.00);
				auto ctrl = Controller();
				auto actual = ctrl.search(med);
				auto expected = true;
				Assert::AreEqual(actual, expected);

				ctrl.modify(med);

				auto actual = ctrl.search(med);
				auto expected = false;
				Assert::AreNotEqual(actual, expected);

				ctrl.undo_update(med);

				auto actual = ctrl.search(med);
				auto expected = true;
				Assert::AreEqual(actual, expected);
			}

			//TEST_METHOD(TestShow)
			//{

			//}

			TEST_METHOD(TestKnappeMenge)
			{
				auto ctrl = Controller();
				Medikament med = Medikament("Nospa", 200, 35, 23.95);
				Medikament med2 = Medikament("Nurofen", 90, 20, 20.00);
				ctrl.knappe_menge(30);
				
			}
		};
	
}
