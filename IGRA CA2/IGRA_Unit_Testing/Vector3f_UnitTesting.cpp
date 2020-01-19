#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/Vector3f.h"   // the main class to test
#include "../IGRA_CA2/Vector2f.h"   // to test casting from Vector3f to Vector2f

namespace IGRAUnitTesting
{
    TEST_CLASS(Vector3f_Constructors_Test)
    {
        TEST_METHOD(Vector3f_Default_Constructor)
        {
            Vector3f vector{};

            // vector should be (0.0f, 0.0f, 0.0f)
            Assert::AreEqual(0.0f, vector.x, 1e-8f);
            Assert::AreEqual(0.0f, vector.y, 1e-8f);
            Assert::AreEqual(0.0f, vector.z, 1e-8f);
        }

        TEST_METHOD(Vector3f_XYZ_Constructor)
        {
            Vector3f vector{1.0f, 3.0f, 5.0f};

            // vector should be (1.0f, 3.0f, 5.0f)
            Assert::AreEqual(1.0f, vector.x, 1e-8f);
            Assert::AreEqual(3.0f, vector.y, 1e-8f);
            Assert::AreEqual(5.0f, vector.z, 1e-8f);
        }
    };

    TEST_CLASS(Vector3f_Methods_Test)
    {
        TEST_METHOD(Vector3f_Set)
        {
            Vector3f original{5.0f, 12.0f, 9.0f};
            original.Set(1.0f, -3.0f, 12.0f);

            // original should now be (1.0f, -3.0f, 12.0f)
            Assert::AreEqual(1.0f, original.x, 1e-8f);
            Assert::AreEqual(-3.0f, original.y, 1e-8f);
            Assert::AreEqual(12.0f, original.z, 1e-8f);
        }
    };

    TEST_CLASS(Vector3f_Self_Assignment_Operators_Test)
    {
        TEST_METHOD(Self_Add_Vector3f)
        {
            Vector3f current{38.0f, 34.5f, 54.8f};
            
            // also test the return value of +=
            Vector3f sum{current += Vector3f{0.0f, 5.0f, 0.125f}};

            // both current and sum should be equal
            // expected: (38.0f, 39.5f, 54.925f)
            Assert::AreEqual(38.0f, current.x, 1e-8f);
            Assert::AreEqual(39.5f, current.y, 1e-8f);
            Assert::AreEqual(54.925f, current.z, 1e-8f);
            Assert::AreEqual(38.0f, sum.x, 1e-8f);
            Assert::AreEqual(39.5f, sum.y, 1e-8f);
            Assert::AreEqual(54.925f, sum.z, 1e-8f);
        }

        TEST_METHOD(Self_Subtract_Vector3f)
        {
            Vector3f current{10.0f, -2.0f, 2.2f};

            // also test the return value of -=
            Vector3f difference{current -= Vector3f{-10.0f, 2.0f, -0.3f}};

            // both current and difference should be equal
            // expected: (20.0f, -4.0f, 2.5f)
            Assert::AreEqual(20.0f, current.x, 1e-8f);
            Assert::AreEqual(-4.0f, current.y, 1e-8f);
            Assert::AreEqual(2.5f, current.z, 1e-8f);
            Assert::AreEqual(20.0f, difference.x, 1e-8f);
            Assert::AreEqual(-4.0f, difference.y, 1e-8f);
            Assert::AreEqual(2.5f, difference.z, 1e-8f);
        }

        TEST_METHOD(Self_Multiply_Vector3f)
        {
            Vector3f current{0.0f, 12.0f, 39.0f};

            // also test the return value of *=
            Vector3f product{current *= 1.5f};

            // both current and product should be equal
            // expected: (0.0f, 18.0f, 58.5f)
            Assert::AreEqual(0.0f, current.x, 1e-8f);
            Assert::AreEqual(18.0f, current.y, 1e-8f);
            Assert::AreEqual(58.5f, current.z, 1e-8f);
            Assert::AreEqual(0.0f, product.x, 1e-8f);
            Assert::AreEqual(18.0f, product.y, 1e-8f);
            Assert::AreEqual(58.5f, product.z, 1e-8f);
        }

        TEST_METHOD(Self_Divide_Vector3f)
        {
            Vector3f current{-5.0f, 10.0f, 32.0f};

            // also test the return value of /=
            Vector3f quotient{current /= -0.9f};

            // both current and quotient should be equal
            // expected: (5.555...f, -11.111...f, -35.555...f)
            // tolerance (difference allowed between floats) is now 0.0001
            // test will pass if floats are 0.0001f in difference
            Assert::AreEqual(5.5555f, current.x, 1e-4f);
            Assert::AreEqual(-11.1111f, current.y, 1e-4f);
            Assert::AreEqual(-35.5555f, current.z, 1e-4f);
            Assert::AreEqual(5.5555f, quotient.x, 1e-4f);
            Assert::AreEqual(-11.1111f, quotient.y, 1e-4f);
            Assert::AreEqual(-35.5555f, quotient.z, 1e-4f);
        }
    };

    TEST_CLASS(Vector3f_Unary_Operators_Test)
    {
        TEST_METHOD(Negate_Vector3f)
        {
            Vector3f current{0.0f, 32.0f, -87.5f};
            Vector3f negated{-current};

            // negated should be (0.0f, -32.0f, 87.5f)
            Assert::AreEqual(0.0f, negated.x, 1e-8f);
            Assert::AreEqual(-32.0f, negated.y, 1e-8f);
            Assert::AreEqual(87.5f, negated.z, 1e-8f);
        }
    };

    TEST_CLASS(Vector3f_Binary_Operators_Test)
    {
        TEST_METHOD(Add_2_Vector3fs)
        {
            Vector3f left{1.0f, 2.0f, 3.0f};
            Vector3f right{9.0f, 8.0f, 7.1f};

            Vector3f sum{left + right};

            // sum should be (10.0f, 10.0f, 10.1f)
            Assert::AreEqual(10.0f, sum.x, 1e-8f);
            Assert::AreEqual(10.0f, sum.y, 1e-8f);
            Assert::AreEqual(10.1f, sum.z, 1e-8f);
        }

        TEST_METHOD(Subtract_Vector3f_From_Vector3f)
        {
            Vector3f left{-9.0f, 12.0f, 3.0f};
            Vector3f right{-9.0f, -12.0f, 8.0f};

            Vector3f difference{left - right};

            // difference should be (0.0f, 24.0f, -5.0f)
            Assert::AreEqual(0.0f, difference.x, 1e-8f);
            Assert::AreEqual(24.0f, difference.y, 1e-8f);
            Assert::AreEqual(-5.0f, difference.z, 1e-8f);
        }

        TEST_METHOD(Multiply_Vector3f_With_Scalar)
        {
            Vector3f vector{12.0f, 12.0f, -5.0f};
            float multiplier{0.5f};

            Vector3f product{vector * multiplier};

            // product should be (6.0f, 6.0f, -2.5f)
            Assert::AreEqual(6.0f, product.x, 1e-8f);
            Assert::AreEqual(6.0f, product.y, 1e-8f);
            Assert::AreEqual(-2.5f, product.z, 1e-8f);
        }

        TEST_METHOD(Multiply_Scalar_With_Vector3f)
        {
            Vector3f vector{12.0f, 12.0f, -5.0f};
            float multiplier{0.5f};

            Vector3f product{multiplier * vector};

            // product should be (6.0f, 6.0f, -2.5f)
            Assert::AreEqual(6.0f, product.x, 1e-8f);
            Assert::AreEqual(6.0f, product.y, 1e-8f);
            Assert::AreEqual(-2.5f, product.z, 1e-8f);
        }

        TEST_METHOD(Division_Vector3f_With_Scalar)
        {
            Vector3f vector{12.0f, 64.0f, 32.0f};
            float divisor{6.0f};

            Vector3f quotient{vector / divisor};

            // quotient should be (2.0f, 10.6666f, 5.3333f)
            Assert::AreEqual(2.0f, quotient.x, 1e-4f);
            Assert::AreEqual(10.6666f, quotient.y, 1e-4f);
            Assert::AreEqual(5.3333f, quotient.z, 1e-4f);
        }
    };

    TEST_CLASS(Vector3f_Casting)
    {
        TEST_METHOD(Cast_Vector3f_To_Vector2f)
        {
            Vector3f current{3.0f, 4.0f, 9.0f};
            Vector2f casted{current};

            // casted should be (3.0f, 4.0f). 9.0f should be discarded
            Assert::AreEqual(3.0f, casted.x, 1e-8f);
            Assert::AreEqual(4.0f, casted.y, 1e-8f);
        }
    };
}