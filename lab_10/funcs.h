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