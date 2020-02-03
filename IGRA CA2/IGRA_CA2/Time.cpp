#include "Time.h"

Timer Time::internalTimer{};

double Time::unscaledDeltaTime{0.0};
double Time::timeScale{1.0};

double Time::GetDeltaTime()
{
    return unscaledDeltaTime * timeScale;
}

double Time::GetGameTime()
{
    return internalTimer.GetTimePassedSinceStart() * timeScale;
}

double Time::GetTimeScale()
{
    return timeScale;
}

double Time::GetUnscaledDeltaTime()
{
    return unscaledDeltaTime;
}

double Time::GetUnscaledGameTime()
{
    return internalTimer.GetTimePassedSinceStart();
}

void Time::SetTimeScale(double value)
{
    timeScale = value;
}
