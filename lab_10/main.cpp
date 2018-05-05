#include "funcs.h"
#include <iostream>

int main()
{
    std::cout << "There are " << minutesUntil( {10, 30}, {13, 40} ) << " minutes between 10:30 and 13:40\n";
    std::cout << "75 minutes added to 8:10 is ";
    printTime(addMinutes({8,10},75));
    std::cout << "\n";
    Movie movie1 = {"Back to the Future", COMEDY, 120};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot test = {movie1, {11,14}};
    std::cout << TimeSlotString(morning) << '\n';
    std::cout << TimeSlotString(scheduleAfter(morning, movie1)) << '\n';

    std::cout <<std::boolalpha;
    std::cout << "Movie 1 overlaps with test?: " <<timeOverlap(test,morning) << std::endl;
}