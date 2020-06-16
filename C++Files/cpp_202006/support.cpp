#include<iostream>
extern double warming;//use warming from another file
void update(double dt);
void local();
using std::cout;
void update(double dt) //modifies global variable
{
	extern double warming;
	warming +=dt;
	cout<<"UPdating global warming to "<<warming;
	cout<<" degrees.\n";
}
void local() //uses local variable
{
	double warming=0.8;//new variable hides external one
	cout<<"Local warming =" <<warming<<" degrees.\n";
	  //Access global variable with the
	  //scope resolution operator
	cout<<"But global warming = "<<::warming;
	cout<<" degrees.\n";
}