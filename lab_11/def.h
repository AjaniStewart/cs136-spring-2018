#pragma once

struct Coord3D
{
    double x;
    double y;
    double z;
};

struct Particle
{
    Coord3D position;
    Coord3D velocity;
};