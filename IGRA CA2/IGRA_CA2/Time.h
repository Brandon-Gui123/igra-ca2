#pragma once
#include "Timer.h"

class Time
{
private:
	static Timer internalTimer;
	static double m_deltaTime;

public:
	static const double &deltaTime;

};

