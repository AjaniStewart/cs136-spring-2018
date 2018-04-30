#pragma once
#include <string>

enum Genre
{
    ACTION,
    COMEDY,
    DRAMA,
    ROMANCE,
    THRILLER
};

struct Time
{
    int h;
    int m;
};

struct Movie
{
    std::string title;
    Genre genre;
    int duration;
};

struct TimeSlot
{
    Movie movie;
    Time startTime;
};