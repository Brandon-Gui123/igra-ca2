#pragma once

#include "pch.h"
#include "CppUnitTest.h"

#include "FooComponent.h"           // for class FooComponent
#include "FooDerivedComponent.h"    // for class FooDerivedComponent
#include "TestComponent.h"          // for class TestComponent
#include "CanSpeak.h"               // for abstract class CanSpeak

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<TestComponent>  (const TestComponent &t)    { return L"TestComponent"; }
            template<> static std::wstring ToString<FooComponent>   (const FooComponent &t)     { return L"FooComponent"; }
            template<> static std::wstring ToString<FooDerivedComponent>   (const FooDerivedComponent &t)     { return L"FooComponent"; }
            template<> static std::wstring ToString<CanSpeak>   (const CanSpeak &t)     { return L"CanSpeak"; }
        }
    }
}