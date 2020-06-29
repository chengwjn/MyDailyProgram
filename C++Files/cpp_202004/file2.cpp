#include<iostream>
#include<cmath>
#include"coordin.h"//structure templates,function prototypes
//convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance=sqrt(xypos.x^2+xypos.y^2);
    answer.angle=atan2(xypos.y,xypos.x);
    return answer;
}

//show polar coordinates,converting angle to degree
void show_polar(polar dapos)
{
    using namespace std;
    const double Rad_to_deg =57.295777951;

    cout<<"distance="<<dapos.diatance;
    cout<<",angle="<<dapos.angle*Rad_to_deg;
    cout<<" degrees\n";
}
