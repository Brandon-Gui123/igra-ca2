#include "pch.h"
#include "CppUnitTest.h"
#include "UserDefinedTemplateSpecializationsForToString.h"  // for solving error C238

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "TestComponent.h"              // for class TestComponent
#include "FooComponent.h"               // for class FooComponent
#include "FooDerivedComponent.h"        // for class FooDerivedComponent

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

        TEST_METHOD(Getting_Component_On_GameObject_That_Lacks_It)
        {
            GameObject go{};
            go.AddComponent<TestComponent>();

            // get a component that doesn't exist in the GameObject
            FooComponent *foo{go.GetComponent<FooComponent>()};

            // check if foo is a null pointer
            // if it isn't, fail the test
            Assert::IsNull(foo);
        }

        TEST_METHOD(Get_First_Occurence_Of_Component_In_GameObject)
        {
            GameObject go{};

            // add a bunch of components to simulate (possible) real-life use case
            go.AddComponent<FooComponent>();
            go.AddComponent<FooComponent>();
            TestComponent &first{go.AddComponent<TestComponent>()};
            go.AddComponent<FooComponent>();
            TestComponent &second{go.AddComponent<TestComponent>()};
            TestComponent &third{go.AddComponent<TestComponent>()};

            TestComponent &test{*(go.GetComponent<TestComponent>())};

            // test should be the first occurence of TestComponent
            // and not the second or third!
            Assert::AreSame(first, test);
            Assert::AreNotSame(second, test);
            Assert::AreNotSame(third, test);
        }

        TEST_METHOD(Get_Base_Component_From_Derived)
        {
            GameObject go{};

            // add dervied components
            go.AddComponent<FooDerivedComponent>();

            // get component but done with a base class
            // we should get an object and not a null pointer
            FooComponent *foo{go.GetComponent<FooComponent>()};

            Assert::IsNotNull(foo);
        }
    };
}