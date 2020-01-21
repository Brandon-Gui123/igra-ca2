#include "Time.h"

Timer Time::internalTimer{};
double Time::deltaTime{};

double Time::GetDeltaTime()
{
    return deltaTime;
}
