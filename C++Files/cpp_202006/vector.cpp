#include <cmath>
#include <iostream>
#include "vector.h"
using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR
{
    //compute degrees in one radian
    const double Rad_to_deg = 45 / atan(1.0);
    //should be about 57.2957795130823

    //private methods
    //calculates magnitude from x and y
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }
    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
        {
            ang = atan2(y, x);
        }
    }

    //set x from polar coordinate
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }

    //set y from polar coordinate
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }
    //public methods
    Vector::Vector() //default constructor
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    //constuct vector from rectangular coordinates if form is r
    //(the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
        ///reset from rectangular coordinate it from is
        //RECT (the default) or else from polar coordinates if
        //form is POL
    }
} // namespace VECTOR