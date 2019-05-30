#include<iostream>
//using namespace std;
int main()
{
	using std::cin;//using declarations
	using std::cout;
	char ch;
	int spaces=0;
	int total=0;
	cin.get(ch);
	while(ch!='.')//quit at end of sentences
	{
		if(ch==' ')//check if ch is a space
		++spaces;
		++total;//done everytime
		cin.get(ch);
	}
	cout<<spaces<<"spaces,"<<total;
	cout<<"character total in sentence\n";
	return 0;
}
