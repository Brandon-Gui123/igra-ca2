#pragma once

#include "Program.h"
#include "Timer.h"

// A class where you can get information about time from this program.
class Time
{
private:
	static Timer internalTimer;
	static double deltaTime;
	static double timeScale;

public:
	// Gets the time passed since the last frame, in seconds.
	static double GetDeltaTime();

	// Gets the time passed since the game starts, where everything is loaded.
	static double GetGameTime();

	// Gets the scale at which time passes.
	// Time scale is a multiplier for timed operations.
	// When time scale is at 1.0, time passes as fast as realtime.
	// When time scale is at 0.5, time passes two times slower than realtime.
	static double GetTimeScale();

	// we only want the Program class to get access to the private variables
	// so Program will handle the internal timer
	friend class Program;
};

