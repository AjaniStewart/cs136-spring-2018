#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

bool operator==(const Time &lhs, const Time &rhs)
{
    return (lhs.h == rhs.h && lhs.m == rhs.m);
}

bool operator==(const Movie &lhs, const Movie &rhs)
{
    return (lhs.duration == rhs.duration && lhs.genre == rhs.genre && lhs.title == rhs.title);
}

bool operator==(const TimeSlot &lhs, const TimeSlot &rhs)
{
    return (lhs.movie == rhs.movie && lhs.startTime == rhs.startTime);
}

TEST_CASE("Testing funcs.cpp")
{
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    
    SUBCASE("TASK A")
    {
        SUBCASE("minutesSinceMidnight")
        {
            CHECK(minutesSinceMidnight({0,10}) == 10);
            CHECK(minutesSinceMidnight({8,15}) == 495);
            CHECK(minutesSinceMidnight({0,0}) == 0);
            CHECK(minutesSinceMidnight({23,59}) == 1439);
        }
        SUBCASE("minutesUntil")
        {
            CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
            CHECK(minutesUntil({10,30},{10,30}) == 0);
            CHECK(minutesUntil({13,40},{10,30}) == -190);
            CHECK(minutesUntil({10,30},{10,40}) == 10);
        }
    }
    SUBCASE("TASK B")
    {
        SUBCASE("addMinutes")
        {
            CHECK(addMinutes({8,10},75)== Time{9,25});
            CHECK(addMinutes({0,0},120) == Time{2,0});
            CHECK(addMinutes({7,15},45) == Time{8,0});
            CHECK(addMinutes({7,15},0) == Time{7,15});
        }
    }
    SUBCASE("TASK C")
    {
        SUBCASE("TimeSlotString")
        {
            
            CHECK(TimeSlotString(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
            CHECK(TimeSlotString({movie1, {9, 20}}) == "Back to the Future COMEDY (116 min) [starts at 9:20, ends by 11:16]");
        }
    }
    SUBCASE("TASK D")
    {
        SUBCASE("scheduleAfter")
        {
            CHECK(scheduleAfter(morning,movie1) == TimeSlot{movie1,addMinutes(morning.startTime,movie1.duration)});
            CHECK(scheduleAfter(evening, movie1) == TimeSlot{movie1, addMinutes(evening.startTime, movie1.duration)});
            CHECK(scheduleAfter(evening, movie2) == TimeSlot{movie2, addMinutes(evening.startTime, movie2.duration)});
        }   
    }
    SUBCASE("TASK E")
    {
        SUBCASE("timeOverlap")
        {
            CHECK(timeOverlap(morning,evening) == false);
            CHECK(timeOverlap(morning,morning) == true);
        }
    }
}