#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/Color4.h"     // the main class to test, Color4

namespace IGRAUnitTesting
{
    TEST_CLASS(Color4_Constructors)
    {
        TEST_METHOD(Color4_Default_Constructor)
        {
            Color4<float> color{};

            // values should be 0, 0, 0, 0
            Assert::AreEqual(0.f, color.red, 1e-8f);
            Assert::AreEqual(0.f, color.green, 1e-8f);
            Assert::AreEqual(0.f, color.blue, 1e-8f);
            Assert::AreEqual(0.f, color.alpha, 1e-8f);
        }

        TEST_METHOD(Color4_RGBA_Constructor)
        {
            Color4<float> color{0.f, 58.f, 12.f, 0.1f};

            // values should be 0, 58, 12, 0.1
            Assert::AreEqual(0.f, color.red, 1e-8f);
            Assert::AreEqual(58.f, color.green, 1e-8f);
            Assert::AreEqual(12.f, color.blue, 1e-8f);
            Assert::AreEqual(0.1f, color.alpha, 1e-8f);
        }
    };
}
