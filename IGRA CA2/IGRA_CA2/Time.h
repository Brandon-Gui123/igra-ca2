#pragma once
class Time
{
private:
public:
	static double deltaTime;
	static double framesPerSecond();
	static void setDeltaTime(double dt);
	Time();
	~Time();
};

