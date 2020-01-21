#include "Timer.h"

#include "framework.h"

void Timer::StartTimer()
{
    __int64 currentTimeInCounts;

    // countsPerSecond depends on your PC
    if (!QueryPerformanceFrequency(
        (LARGE_INTEGER *) &countsPerSecond))
    {
        MessageBox(NULL, L"QueryPerformanceFrequencyFailed.", L"ERROR", MB_OK | MB_ICONINFORMATION);
        return;
    }
    QueryPerformanceCounter((LARGE_INTEGER *) &currentTimeInCounts);
    startTimeInCounts = currentTimeInCounts;
    lastTimeInCounts = currentTimeInCounts;
}

double Timer::GetTimePassedSinceStart()
{
    __int64 currentTimeInCounts;
    double timePassedSeconds;
    // Calculate time passed in seconds since timer was started
    QueryPerformanceCounter((LARGE_INTEGER *) &currentTimeInCounts);
    timePassedSeconds = (currentTimeInCounts - startTimeInCounts) /
        (double) countsPerSecond;

    return timePassedSeconds;
}

double Timer::GetTimePassedSinceLastTime()
{
    __int64 currentTimeInCounts, timePassedSinceLastTimeInCounts;
    // Calculate time passed in seconds since last call to
    // GetTimePassedSinceLastTime
    QueryPerformanceCounter((LARGE_INTEGER *) &currentTimeInCounts);
    timePassedSinceLastTimeInCounts =
        currentTimeInCounts - lastTimeInCounts;
    double timePassedSinceLastTimeInSeconds =
        (currentTimeInCounts - lastTimeInCounts) /
        (double) countsPerSecond;
    lastTimeInCounts = currentTimeInCounts;
    return timePassedSinceLastTimeInSeconds;
}