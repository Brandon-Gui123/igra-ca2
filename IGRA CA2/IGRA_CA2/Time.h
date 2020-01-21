#pragma once

#include "Program.h"
#include "Timer.h"

class Time
{
private:
	static Timer internalTimer;
	static double m_deltaTime;

public:
	static const double &deltaTime;

	// we only want the Program class to get access to the private variables
	// so Program will handle the internal timer
	friend class Program;
};

