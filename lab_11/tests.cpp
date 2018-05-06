#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "def.h"

bool operator== (const Coord3D &lhs, const Coord3D &rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}

bool operator==(const Particle &lhs, const Particle &rhs)
{
    return (lhs.position == rhs.position && lhs.velocity == rhs.velocity);
}


TEST_CASE("Testing funcs.cpp")
{
    Coord3D p1 = {0,6,8};
    Coord3D p2 = {5,0,12};
    Coord3D p3 = {3,4,0};

    Coord3D vel = {1,1,1};

    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    SUBCASE("Task A")
    {
        CHECK(length(&p1)==10);
        CHECK(length(&p2)==13);
        CHECK(length(&p3)==5);
    }

    SUBCASE("TASK B")
    {
        CHECK(*(fartherFromOrigin(&pointP,&pointQ))==pointP);
        CHECK(*(fartherFromOrigin(&p1,&pointP))==pointP);
        CHECK(*(fartherFromOrigin(&p1,&pointQ))==pointQ);
    }

    SUBCASE("TASK C")
    {
        move(&p1,&vel,2);
        CHECK(p1 == Coord3D{2,8,10});
    }
}