#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/Vector2f.h"	// the main class to test
#include "../IGRA_CA2/Vector3f.h"	// to test casting from Vector2f to Vector3f

namespace IGRAUnitTesting
{
	TEST_CLASS(Vector2f_Constructors_Test)
	{
		TEST_METHOD(Vector2f_Default_Constructor)
		{
			Vector2f vector{};
			
			// vector should be all 0
			Assert::AreEqual(0.0f, vector.x, 1e-8f);
			Assert::AreEqual(0.0f, vector.y, 1e-8f);
		}

		TEST_METHOD(Vector2f_XY_Constructor)
		{
			Vector2f vector{10.0f, 25.0f};

			// vector should be (10.0f, 25.0f)
			Assert::AreEqual(10.0f, vector.x, 1e-8f);
			Assert::AreEqual(25.0f, vector.y, 1e-8f);
		}
	};

	TEST_CLASS(Vector2f_Methods_Test)
	{
		TEST_METHOD(Vector2f_Set)
		{
			Vector2f current{5.0f, 12.0f};
			current.Set(34.0f, 12.0f);

			// current should now be: (34.0f, 12.0f)
			Assert::AreEqual(34.0f, current.x, 1e-8f);
			Assert::AreEqual(12.0f, current.y, 1e-8f);
		}
	};

}
