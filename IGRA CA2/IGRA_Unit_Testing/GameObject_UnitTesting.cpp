#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../IGRA_CA2/GameObject.h"
#include "../IGRA_CA2/Component.h"

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

    TEST_CLASS(GameObject_AddComponent_Test)
    {
        TEST_METHOD(Adding_A_Component)
        {
            // declare a new kind of component
            class TestComponent : public Component
            {
            public:
                TestComponent(GameObject &go) : Component{go} {};
                ~TestComponent() {};
            };

            GameObject go{};

            // add the new kind of component
            go.AddComponent<TestComponent>();

            // we now should have 1 component
            Assert::AreEqual(1, go.GetComponentCount());
        }
    };
}