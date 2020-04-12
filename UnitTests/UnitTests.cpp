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
			TEST_METHOD(TestEmpty)
			{
				auto ctrl = Controller();
				auto actual1 = ctrl.is_empty();
				auto expected1 = true;
				Assert::AreEqual(actual1, expected1);
			}
			TEST_METHOD(TestSearch)
			{
				Medikament med = Medikament("Nospa", 200, 35, 23.95);
				auto ctrl = Controller();
				auto actual1 = ctrl.search(med);
				auto expected1 = false;
				Assert::AreEqual(actual1, expected1);

				ctrl.add(med);

				auto actual2 = ctrl.search(med);
				auto expected2 = true;
				Assert::AreEqual(actual2, expected2);

				Medikament med2 = Medikament("Ibuprofen", 80, 27, 15.95);
				auto actual3 = ctrl.search(med2);
				auto expected3 = false;
				Assert::AreEqual(actual3, expected3);
			}

			TEST_METHOD(TestAddRemove)
			{
				auto ctrl = Controller();
				Medikament med = Medikament("Nospa", 200, 35, 23.95);
				ctrl.add(med);

				auto actual2 = ctrl.is_empty();
				auto expected2 = false;
				Assert::AreEqual(actual2, expected2);

				ctrl.remove(med);

				auto actual3 = ctrl.is_empty();
				auto expected3 = true;
				Assert::AreEqual(actual3, expected3);

				ctrl.undo();
				auto actual4 = ctrl.is_empty();
				auto expected4 = false;
				Assert::AreEqual(actual4, expected4);
			}

			TEST_METHOD(TestModify)
			{
				auto ctrl = Controller();
				Medikament med = Medikament("Nospa", 200, 35, 23.95);
				ctrl.add(med);
				
			}
			/*TEST_METHOD(TestModify)
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
			}*/
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
