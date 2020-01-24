#pragma once

#include "pch.h"
#include "CppUnitTest.h"

#include "FooComponent.h"   // for class FooComponent
#include "TestComponent.h"  // for class TestComponent

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<TestComponent>  (const TestComponent &t)    { return L"TestComponent"; }
            template<> static std::wstring ToString<FooComponent>   (const FooComponent &t)     { return L"FooComponent"; }
        }
    }
}