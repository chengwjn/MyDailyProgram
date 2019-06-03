//在C++中，类对象是基于结构的，因此结构编程方面的有些考虑因素也适用于类。
//例如可以按值将对象传递给函数 ，在这种情况下，函数处理的是原始对象的副本
//另外，也可以传递指向对象的指针，这让函数能够操作原始对象。 
#include<iostream>
#include<array>
#include<string>
using namespace std;
//constant data
const int Seasons=4;
const array<string,Seasons> Snames={"Spring","Summer","Fall","Winter"};

//function to modify array object 
void fill(array<double,Seasons>* pa);
//function that uses array object without modifying it
void show(std::array<double,Seasons> da);


int main()
{
	array<double,Seasons> expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(array<double,Seasons>* pa)
{
	for(int i=0;i<Seasons;i++)
	{
		cout<<"Enter "<<Snames[i]<<" expenses:";
		cin>>(*pa)[i];
	}
}
void show(array<double,Seasons>da)
{
	double total=0.0;
	cout<<"\nEXPENSES\n";
	for(int i=0;i<Seasons;i++)
	{
		cout<<Snames[i]<<":$"<<da[i]<<endl;
		total+=da[i];
	}
	cout<<"Total Expenses:$"<<total<<endl;
}
