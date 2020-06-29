//递归
//如果递归函数调用自己，则被调用的函数也将调用自己，这样将无限循环下去，除非代码中包含种植调用链的内容
#include<iostream>
void countdown(int n);

int main()
{
	countdown(4);//call the recursive function
	return 0;
} 

void countdown(int n)
{
	using namespace std;
	cout<<"Counting down ... "<<n<<endl;
	if(n>0)
	countdown(n-1);//function calls itself
	cout<<n<<": Kaboom!\n";
}
