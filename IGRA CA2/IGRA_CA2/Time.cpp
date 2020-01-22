#include "Time.h"

Timer Time::internalTimer{};

double Time::deltaTime{0.0};

double Time::GetDeltaTime()
{
    return deltaTime;
}

double Time::GetGameTime()
{
    return internalTimer.GetTimePassedSinceStart();
}
