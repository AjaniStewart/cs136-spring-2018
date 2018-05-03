#include "funcs.h"
#include <iostream>

int main()
{
    //std::cout << minutesUntil( {10, 30}, {13, 40} );
    //printTime(addMinutes({8,10},75));
    Movie movie1 = {"Back to the Future", COMEDY, 120};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    //std::cout << TimeSlotString(morning);
    std::cout << TimeSlotString(scheduleAfter(morning, movie1));
}