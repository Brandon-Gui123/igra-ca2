#include "Time.h"

double Time::deltaTime = 0;

Time::Time()
{
}

void Time::setDeltaTime(double dt) {
	deltaTime = dt;
}

double Time::framesPerSecond() {
	return 1 / deltaTime;
}

Time::~Time()
{
}
