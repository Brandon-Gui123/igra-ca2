#include "Timer.h"

#include "framework.h"

Timer::Timer()
{}

Timer::~Timer()
{}

void Timer::StartTimer()
{
    __int64 currentTimeInCounts{};

    // countsPerSecond depends on your PC
    if (!QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&countsPerSecond)))
    {
        MessageBox(NULL, L"QueryPerformanceFrequencyFailed.", L"ERROR", MB_OK | MB_ICONINFORMATION);
        return;
    }

    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentTimeInCounts));

    startTimeInCounts = currentTimeInCounts;
    lastTimeInCounts = currentTimeInCounts;
}

double Timer::GetTimePassedSinceStart()
{
    __int64 currentTimeInCounts{};
    double timePassedSeconds{};

    // Calculate time passed in seconds since timer was started
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentTimeInCounts));

    timePassedSeconds = (currentTimeInCounts - startTimeInCounts) / static_cast<double>(countsPerSecond);

    return timePassedSeconds;
}

double Timer::GetTimePassedSinceLastTime()
{
    __int64 currentTimeInCounts{};
    __int64 timePassedSinceLastTimeInCounts{};

    // Calculate time passed in seconds since last call to
    // GetTimePassedSinceLastTime
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentTimeInCounts));

    timePassedSinceLastTimeInCounts = currentTimeInCounts - lastTimeInCounts;

    double timePassedSinceLastTimeInSeconds{(currentTimeInCounts - lastTimeInCounts) / static_cast<double>(countsPerSecond)};

    lastTimeInCounts = currentTimeInCounts;

    return timePassedSinceLastTimeInSeconds;
}