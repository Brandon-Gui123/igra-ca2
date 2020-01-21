#include "Time.h"

Timer Time::internalTimer{};
double Time::m_deltaTime{};

const double &Time::deltaTime{Time::m_deltaTime};