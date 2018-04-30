#include "labstructs.h"
#include <iostream>
#include <string>

void printTime(Time time)
{
    std::cout << time.h << ":" << time.m;
}

void printMovie(Movie mv)
{
    std::string g;
    switch (mv.genre)
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
    printMovie(ts.movie);
    std::cout << " ";
    printTime(ts.startTime);
}

int minutesSinceMidnight(Time time)
{
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later)
{
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min)
{
    return Time{time0.h + min / 60, time0.m + min % 60};
}