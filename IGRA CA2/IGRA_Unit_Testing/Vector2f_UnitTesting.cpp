#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/Vector2f.h"	// the main class to test
#include "../IGRA_CA2/Vector3f.h"	// to test casting from Vector2f to Vector3f

namespace IGRAUnitTesting
{
	TEST_CLASS(Vector2f_Shorthand_Values_Test)
	{
		TEST_METHOD(Vector2f_zero)
		{
			// Vector2f::zero should be (0.0f, 0.0f)
			Assert::AreEqual(0.0f, Vector2f::zero.x, 1e-8f);
			Assert::AreEqual(0.0f, Vector2f::zero.y, 1e-8f);
		}

		TEST_METHOD(Vector2f_one)
		{
			// Vector2f::one should be (1.0f, 1.0f)
			Assert::AreEqual(1.0f, Vector2f::one.x, 1e-8f);
			Assert::AreEqual(1.0f, Vector2f::one.y, 1e-8f);
		}

		TEST_METHOD(Vector2f_left)
		{
			// Vector2f::left should be (-1.0f, 0.0f)
			Assert::AreEqual(-1.0f, Vector2f::left.x, 1e-8f);
			Assert::AreEqual(0.0f, Vector2f::left.y, 1e-8f);
		}

		TEST_METHOD(Vector2f_right)
		{
			// Vector2f::right should be (1.0f, 0.0f)
			Assert::AreEqual(1.0f, Vector2f::right.x, 1e-8f);
			Assert::AreEqual(0.0f, Vector2f::right.y, 1e-8f);
		}

		TEST_METHOD(Vector2f_up)
		{
			// Vector2f::up should be (0.0f, 1.0f)
			Assert::AreEqual(0.0f, Vector2f::up.x, 1e-8f);
			Assert::AreEqual(1.0f, Vector2f::up.y, 1e-8f);
		}

		TEST_METHOD(Vector2f_down)
		{
			// Vector2f::down should be (0.0f, -1.0f)
			Assert::AreEqual(0.0f, Vector2f::down.x, 1e-8f);
			Assert::AreEqual(-1.0f, Vector2f::down.y, 1e-8f);
		}
	};

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

		TEST_METHOD(Vector2f_Distance)
		{
			Vector2f position1{4.0f, 4.0f};
			Vector2f position2{3.0f, 10.0f};

			// the distance between the two points should be:
			// sqrt((1.0f * 1.0f) +  (-6.0f * -6.0f)) = sqrt(37)
			// approx. 6.082762...
			Assert::AreEqual(6.0827f, Vector2f::Distance(position1, position2), 1e-4f);
		}

		TEST_METHOD(Vector2f_GetMagnitude)
		{
			Vector2f position1{4.0f, 4.0f};
			Vector2f position2{3.0f, 10.0f};

			Vector2f delta{position2 - position1};

			// the distance between the two points should again be:
			// approx. 6.082762...
			Assert::AreEqual(6.0827f, delta.GetMagnitude(), 1e-4f);
		}
	};

	TEST_CLASS(Vector2f_Unary_Operators_Test)
	{
		TEST_METHOD(Negate_Vector2f)
		{
			Vector2f current{-5.0f, 32.0f};
			Vector2f negated{-current};

			// negated should be (5.0f, -32.0f)
			Assert::AreEqual(5.0f, negated.x, 1e-8f);
			Assert::AreEqual(-32.0f, negated.y, 1e-8f);
		}
	};

	TEST_CLASS(Vector2f_Binary_Operators_Test)
	{
	public:
		
		TEST_METHOD(Add_2_Vector2fs)
		{
			Vector2f left{12.0f, 86.0f};
			Vector2f right{32.0f, 12.0f};

			Vector2f sum{left + right};

			// expected output: (44.0f, 98.0f)
			Assert::AreEqual(44.0f, sum.x, 1e-8f);
			Assert::AreEqual(98.0f, sum.y, 1e-8f);
		}

		TEST_METHOD(Subtract_Vector2f_From_Vector2f)
		{
			Vector2f left{100.0f, 90.0f};
			Vector2f right{50.0f, 31.0f};

			Vector2f difference{left - right};

			// expected output: (50.0f, 59.0f)
			Assert::AreEqual(50.0f, difference.x, 1e-8f);
			Assert::AreEqual(59.0f, difference.y, 1e-8f);
		}

		TEST_METHOD(Multiply_Vector2f_And_Scalar)
		{
			Vector2f vector{3.0f, 8.0f};
			float multiplier{5.0f};

			Vector2f product{vector * multiplier};

			// expected output: (15.0f, 40.0f)
			Assert::AreEqual(15.0f, product.x, 1e-8f);
			Assert::AreEqual(40.0f, product.y, 1e-8f);
		}

		TEST_METHOD(Multiply_Scalar_And_Vector2f)
		{
			Vector2f vector{3.0f, 8.0f};
			float multiplier{5.0f};

			Vector2f product{multiplier * vector};

			// expected output: (15.0f, 40.0f)
			Assert::AreEqual(15.0f, product.x, 1e-8f);
			Assert::AreEqual(40.0f, product.y, 1e-8f);
		}

		TEST_METHOD(Divide_Vector2f_And_Scalar)
		{
			Vector2f vector{12.0f, 9.0f};
			float divisor{4.0f};

			Vector2f quotient{vector / divisor};

			// expected output: (3.0f, 2.25f)
			Assert::AreEqual(3.0f, quotient.x, 1e-8f);
			Assert::AreEqual(2.25f, quotient.y, 1e-8f);
		}
	};

	TEST_CLASS(Vector2f_Self_Assignment_OperatorsTest)
	{
		TEST_METHOD(Self_Add_Vector2f)
		{
			Vector2f current{1.0f, 5.0f};

			// to also test the return value of +=
			Vector2f sum{current += Vector2f{9.0f, 5.0f}};

			// current and sum should now be equal
			// expected: (10.0f, 10.0f)
			Assert::AreEqual(10.0f, current.x, 1e-8f);
			Assert::AreEqual(10.0f, current.y, 1e-8f);
			Assert::AreEqual(10.0f, sum.x, 1e-8f);
			Assert::AreEqual(10.0f, sum.y, 1e-8f);
		}

		TEST_METHOD(Self_Subtract_Vector2f)
		{
			Vector2f current{9.0f, 10.0f};

			// also testing the return value of -=
			Vector2f difference{current -= Vector2f{1.0f, 11.0f}};

			// current and difference should now be equal
			// expected: (8.0f, -1.0f)
			Assert::AreEqual(8.0f, current.x, 1e-8f);
			Assert::AreEqual(-1.0f, current.y, 1e-8f);
			Assert::AreEqual(8.0f, difference.x, 1e-8f);
			Assert::AreEqual(-1.0f, difference.y, 1e-8f);
		}

		TEST_METHOD(Self_Multiply_Vector2f)
		{
			Vector2f current{10.0f, 12.0f};

			// also testing the return value of *=
			Vector2f product{current *= -5.0f};

			// current and product should now be equal
			// expected: (-50.0f, -60.0f)
			Assert::AreEqual(-50.0f, current.x, 1e-8f);
			Assert::AreEqual(-60.0f, current.y, 1e-8f);
			Assert::AreEqual(-50.0f, product.x, 1e-8f);
			Assert::AreEqual(-60.0f, product.y, 1e-8f);
		}

		TEST_METHOD(Self_Divide_Vector2f)
		{
			Vector2f current{24.0f, 32.0f};

			// also testing the return value of /=
			Vector2f quotient{current /= 0.25f};

			// current and quotient should now be equal
			// expected: (96.0f, 128.0f)
			Assert::AreEqual(96.0f, current.x, 1e-8f);
			Assert::AreEqual(128.0f, current.y, 1e-8f);
			Assert::AreEqual(96.0f, quotient.x, 1e-8f);
			Assert::AreEqual(128.0f, quotient.y, 1e-8f);
		}
	};

	TEST_CLASS(Vector2f_Casting)
	{
		TEST_METHOD(Cast_Vector2f_To_Vector3f)
		{
			Vector2f original{10.0, 32.0f};
			Vector3f vector{original};

			// vector should be (10.0f, 32.0f, 0.0f)
			Assert::AreEqual(10.0f, vector.x, 1e-8f);
			Assert::AreEqual(32.0f, vector.y, 1e-8f);
			Assert::AreEqual(0.0f, vector.z, 1e-8f);
		}
	};
}
