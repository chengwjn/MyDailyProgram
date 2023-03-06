//usetime2.cpp -- using the third draft of the Time class
//complie usetime2.cpp and mytime2.cpp together
#include<iostream>
#include"mytime2.h"
int main()
{
	using std::cout;
	using std::endl;
	Time weeding(4,35);
	Time waxing(2,47);
	Time total;
	Time diff;
	Time adjusted;
	
	cout<<"weeding time = ";
	waxing.Show();
	cout<<endl;
	
	cout<<"twaxing time = ";
	waxing.Show();
	cout<<endl;
	
	cout<<"total work time = ";
	total =weeding +waxing;//use operator+()
	total.Show();
	cout<<endl;
	
	diff=weeding-waxing;//use operator()-
	cout<<"weeding work time = ";
	adjusted.Show();
	cout<<endl;
	return 0;
}