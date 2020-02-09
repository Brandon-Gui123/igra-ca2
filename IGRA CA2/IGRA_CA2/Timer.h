// Done by Brandon Gui (1828865) and Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

class Timer
{
private:
    __int64 startTimeInCounts{0};
    __int64 lastTimeInCounts{0};
    __int64 countsPerSecond{0};

public:

    Timer();
    ~Timer();

    void StartTimer();
    double GetTimePassedSinceLastTime();
    double GetTimePassedSinceStart();
};

