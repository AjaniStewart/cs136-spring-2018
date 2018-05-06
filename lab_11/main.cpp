#include <iostream>
#include "def.h"
#include "funcs.h"

using namespace std;

int main()
{
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166

    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl
         << endl;

    Coord3D *ans = fartherFromOrigin(&pointP, &pointQ);

    cout << "ans = " << ans << endl; // So which point is farther?

    move(&pos, &vel, 2.0); // struct pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4

    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while (time < 3.0)
    {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}
