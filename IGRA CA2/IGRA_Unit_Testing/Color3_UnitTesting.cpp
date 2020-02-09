// This file is used in a unit testing project which tests the classes and ensures that
// everything runs as intended.
//
// Done by Brandon Gui (p1828865) from DIT/FT/2B/05.

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

    TEST_CLASS(Color3_Casting)
    {
        TEST_METHOD(Color3_Cast_To_Color4)
        {
            Color3<float> color3{0.f, 1.f, 2.f};
            Color4<float> color4{color3};

            // values of the Color4 should be 0, 1, 2, 0
            Assert::AreEqual(0.f, color4.red, 1e-8f);
            Assert::AreEqual(1.f, color4.green, 1e-8f);
            Assert::AreEqual(2.f, color4.blue, 1e-8f);
            Assert::AreEqual(0.f, color4.alpha, 1e-8f);
        }
    };
}