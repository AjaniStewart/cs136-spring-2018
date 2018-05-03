#include "labstructs.h"
#include <iostream>
#include <string>

void printTime(Time time)
{
    std::cout << time.h << ":" << time.m;
}

std::string getGenre(Movie m)
{
    switch (m.genre)
    {
    case ACTION:
        return "ACTION";
    case COMEDY:
        return "COMEDY";
    case DRAMA:
        return "DRAMA";
    case ROMANCE:
        return "ROMANCE";
    case THRILLER:
        return "THRILLER";
    }
}

void printMovie(Movie mv)
{
    std::string g = getGenre(mv);
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
    return Time{time0.h + ((min + time0.m) / 60), (time0.m + min) % 60};
}

std::string TimeSlotString(TimeSlot ts)
{
    std::string s;
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    s = ts.movie.title + " " + getGenre(ts.movie) + " (" + std::to_string(ts.movie.duration) + " mins) ";
    s += "[starts at " + std::to_string(ts.startTime.h) + ':' + std::to_string(ts.startTime.m) + ", ends by " 
        + std::to_string(endTime.h) + ':' + std::to_string(endTime.m) + ']';
    return s;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    return TimeSlot{nextMovie, addMinutes(ts.startTime, nextMovie.duration)};
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{   
    //They overlap if the one that starts first is longer than the one that
    //
}