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

void Time::SetTimeScale(double value)
{
    timeScale = value;
}
