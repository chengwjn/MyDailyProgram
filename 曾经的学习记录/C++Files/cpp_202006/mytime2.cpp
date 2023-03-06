//mytime2.cpp -- implementing Time methods
#include<iostream>
#include"mytime2.h"
Time::Time()
{
	hours=miniutes=0;
}
Time::Time(int h,int m)
{
	hours=h;
	miniutes=m;
}
void Time::Addmin(int m)
{
	miniutes+=m;
	hours+=miniutes/60;
	minutes%=60;
}
void Time::AddHr(int h)
{
	hours+=h;
}
void Time::Reset(int h,int m)
{
	hours=h;
	minutes=m;
}
Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours+sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator-(const Time & t) const
{
	Time diff;
	int tot1,tot2;
	tot1=t.minutes+60*t.hours;
	tot2=minutes+60*hours;
	diff.minutes=(tot2-tot1) % 60;
	diff.hours=(tot2-tot1) /60;
	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalminutes=hours*mult*60+minutes*mult;
	result.hours=totalminutes/60;
	result.minutes=totalminutes%60;
	return result;
}

void Time::Show() const
{
	std::cout<<hours<<" hours."<<minutes<<" minutes";
}