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

}