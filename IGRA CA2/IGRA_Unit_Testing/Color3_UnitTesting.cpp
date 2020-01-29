#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/Color3.h"     // the main class we want to test, Color3
#include "../IGRA_CA2/Color4.h"     // for class Color4, to test implicit conversion from Color3 to Color4

namespace IGRAUnitTesting
{
    TEST_CLASS(Color3_Constructors_Test)
    {
        TEST_METHOD(Color3_Default_Constructor)
        {
            Color3<float> color{};

            // all values should be 0
            Assert::AreEqual(0.f, color.red, 1e-8f);
            Assert::AreEqual(0.f, color.green, 1e-8f);
            Assert::AreEqual(0.f, color.blue, 1e-8f);
        }

        TEST_METHOD(Color3_RGB_Constructor)
        {
            Color3<float> color{0.f, 23.f, 87.f};

            // values should be 0, 23 and 87
            Assert::AreEqual(0.f, color.red, 1e-8f);
            Assert::AreEqual(23.f, color.green, 1e-8f);
            Assert::AreEqual(87.f, color.blue, 1e-8f);
        }
    };
}