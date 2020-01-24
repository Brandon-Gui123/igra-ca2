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

    TEST_CLASS(GameObject_Destructor)
    {
        TEST_METHOD(Default_GameObject_Destructor)
        {
            // declare a new kind of component
            class TestComponent : public Component
            {
            public:
                TestComponent(GameObject &go) : Component{go} {};
                ~TestComponent() {};
            };

            GameObject go{};

            // let's add a bunch of components!
            for (int i{0}; i < 10; ++i)
            {
                go.AddComponent<TestComponent>();
            }

            // the GameObject should now have 10 components
            Assert::AreEqual(10, go.GetComponentCount());

            // call the destructor to remove the components
            go.~GameObject();

            // there should be 0 components in the GameObject
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