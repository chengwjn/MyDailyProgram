#ifndef COORDIN_H_INCLUDED
#define COORDIN_H_INCLUDED
struct polar
{
    double distance;//distance from origin
    double angle;//direction from origin
};
struct rect
{
    double x;
    double y;
};
//prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif // COORDIN_H_INCLUDED
