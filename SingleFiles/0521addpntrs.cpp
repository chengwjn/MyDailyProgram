#include<iostream>
using namespace std;
int main()
{
	double wages[3]={10000.0,20000.0,30000.0};
	short stacks[3]={3,2,1};
	
	double *pw=wages;
	short *ps=&stacks[0];
	
	cout<<"pw="<<pw<<",*pw="<<*pw<<endl;
	pw=pw+1;
	cout<<"add 1 to the pw pointer:\n";
	cout<<"pw="<<pw<<",*pw="<<*pw<<"\n\n";
}
