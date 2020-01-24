#include "pch.h"
#include "CppUnitTest.h"
#include "UserDefinedTemplateSpecializationsForToString.h"  // for solving error C238

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "TestComponent.h"              // for class TestComponent

#include "../IGRA_CA2/GameObject.h"     // for class GameObject in IGRA CA2 project
#include "../IGRA_CA2/Component.h"      // for class Component in IGRA CA2 project

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
            GameObject go{};

            // add the new kind of component
            go.AddComponent<TestComponent>();

            // we now should have 1 component
            Assert::AreEqual(1, go.GetComponentCount());
        }
    };

    TEST_CLASS(GameObject_GetComponent_Test)
    {
        TEST_METHOD(Getting_A_Known_Component)
        {
            GameObject go{};
            go.AddComponent<TestComponent>();

            // we just added in TestComponent so we should be able to get it
            TestComponent *test{go.GetComponent<TestComponent>()};

            // test if we get a null pointer
            // if we do, fail the test
            Assert::IsNotNull(test);
        }

        TEST_METHOD(Compare_References_Of_Gotten_Components)
        {
            GameObject go{};

            TestComponent &first    {  go.AddComponent<TestComponent>() };
            TestComponent &second   {*(go.GetComponent<TestComponent>())};

            // compare if first and second refer to the same object
            Assert::AreSame(first, second);
        }

        TEST_METHOD(Getting_Component_On_Empty_GameObject)
        {
            GameObject go{};

            // no components in GameObject, so this should be a null pointer
            TestComponent *test{go.GetComponent<TestComponent>()};

            // check if test is a null pointer
            // if it isn't, fail the test
            Assert::IsNull(test);
        }
    };
}