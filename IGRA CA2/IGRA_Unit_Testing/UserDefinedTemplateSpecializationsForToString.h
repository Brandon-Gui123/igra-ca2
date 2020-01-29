#pragma once

#include "pch.h"
#include "CppUnitTest.h"

#include "FooComponent.h"           // for class FooComponent
#include "FooDerivedComponent.h"    // for class FooDerivedComponent
#include "UnitTest_TestComponent.h" // for class UnitTest_TestComponent
#include "CanSpeak.h"               // for abstract class CanSpeak
#include "SpeakerComponent.h"       // for class SpeakerComponent

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<UnitTest_TestComponent>  (const UnitTest_TestComponent &t)    { return L"UnitTest_TestComponent"; }
            template<> static std::wstring ToString<FooComponent>   (const FooComponent &t)     { return L"FooComponent"; }
            template<> static std::wstring ToString<FooDerivedComponent>   (const FooDerivedComponent &t)     { return L"FooComponent"; }
            template<> static std::wstring ToString<CanSpeak>   (const CanSpeak &t)     { return L"CanSpeak"; }
            template<> static std::wstring ToString<SpeakerComponent>   (const SpeakerComponent &t)     { return L"SpeakerComponent"; }

        }
    }
}