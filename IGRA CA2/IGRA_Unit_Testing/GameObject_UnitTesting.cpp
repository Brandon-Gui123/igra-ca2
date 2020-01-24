#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/GameObject.h"

namespace IGRAUnitTesting
{
    TEST_CLASS(GameObject_Constructors_Test)
    {
        TEST_METHOD(Default_GameObject_Constructor)
        {
            GameObject go{};

            // the constructed GameObject should not have any components in it
            Assert::AreEqual(0, go.GetComponentCount());
        }
    };
}