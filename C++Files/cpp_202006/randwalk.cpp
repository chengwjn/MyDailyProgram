//randwalk.cpp -- using the Vector class
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); //seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
        }
    }
}