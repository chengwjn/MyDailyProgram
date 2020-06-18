#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode
        {
            RECT,
            POL
        };
        //RECT for rectangular,POL for Polar modes
    private:
        double x;   //horizontal value
        double y;   //vertical value
        double mag; //length of vector
        double ang; //direction of vector in degree
        Mode mode;  //RECT or POL
        //private methods for setting values
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; } //report x value
        double yval() const { return y; }
        double magval() const { return mag; } //report magnitude
        double angval() const { return ang; } //report angle
        void polar_mode();                    //set mode to POL
        void rect_mode();                     //set mode to RECT
        
    };
} // namespace VECTOR
#endif