#include<iostream>
int tom=3;//external variable definition
int dick=30;//external variable definition
static int harry=300;//ststic ,internal linkage
void remote_access();
int main()
{
	using namespace std;
	cout<<"main() reports the following addresses:\n";
	cout<<&tom<<" =&tom, "<<&dick<<" =&dick, ";
	cout<<&harry<<" =&harry\n";
	remote_access();
	return 0;
}