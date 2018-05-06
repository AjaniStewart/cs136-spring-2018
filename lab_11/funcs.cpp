#include "def.h"
#include <cmath>

double length(Coord3D *p)
{
    return sqrt((p->x)*(p->x) + (p->y)*(p->y) + (p->z)*(p->z)); 
}

Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2)
{
    return (length(p1) > length(p2) ? p1 : p2);
}

void move(Coord3D *ppos, Coord3D *pvel, double dt)
{
    ppos->x = ppos->x + (pvel->x*dt);
    ppos->y = ppos->y + (pvel->y*dt);
    ppos->z = ppos->z + (pvel->z*dt);
}

Coord3D *createCoord3D(double x, double y, double z)
{
    Coord3D *p = new Coord3D;
    *p = {x,y,z};
    return p;
}

void deleteCoord3D(Coord3D *p)
{
    delete p;
    p = nullptr;
}

Particle *createParticle(double x, double y, double z, double vx, double vy, double vz)
{
    Particle *p = new Particle;
    p->position = *(createCoord3D(x,y,z));
    p->velocity = *(createCoord3D(vx,vy,vz));
    return p;
}

void setVelocity(Particle *p, double vx, double vy, double vz)
{
    p->velocity = *(createCoord3D(vx,vy,vz));
}

Coord3D getPosition(Particle *p)
{
    return p->position;
}

void move(Particle *p, double dt)
{
    move(&(p->position),&(p->velocity),dt);
}

void deleteParticle(Particle *p)
{
    delete p;
    p = nullptr;
}