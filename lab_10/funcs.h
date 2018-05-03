#pragma once
#include "labstructs.h"
#include <string>

void printTime(Time time);
std::string getGenre(Movie m);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string TimeSlotString(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);