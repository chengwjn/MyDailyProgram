#include<iostream>
using namespace std;
void simple();
int main()
{
	cout<<"main() will call the simple() fuction:\n";
	simple();//function call
	cout<<"main() is finished with the simple() function.\n";
	return 0;
}
//function definition
void simple()
{
	cout<<"I am but a simple function.\n";
}
