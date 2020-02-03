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

	// we only want the Program class to get access to the private variables
	// so Program will handle the internal timer
	friend class Program;
};

