//usestock2.cpp -- using the Stock class
#include<iostream>
#include"stock20.h"
const int STKS=4;
int main()
{
	//create an array of initialized objects
Stock stocks[STKS]={Stock("NanoSmart",12.20.0},Stock("Boffo Objects",200,2.0},Stock("Monolithic Obelisks",130,3.25},Stock("Fleep Enterprises",60,6.5)};
std::cout<<"Stock holding:\n;
int st;
for(st=0;st<STKS;st++)
	stock[st].show();
const Stock *top=&stock[0];
for(st=1;st<STKS;st++)
	top=&top->topval(stock[st]);
std::cout<<"\nMost valuable holding:\n";
top->show();
return 0;
}
//对象数组
//用户通常需要创建同一个类的多个对象
//可以创建对象数组