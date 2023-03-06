//pointer.cpp -- our first pointer variable
#include <iostream>
int main()
{
    using namespace std;
    int updates = 6;      //declare a variable
    int *p_updates;       //declare pointer to an int
    p_updates = &updates; //assign address of int to pointer

    //express values two ways
    cout << "values :updates = " << updates;
    cout << ",*p_updates =" << *p_updates << endl;

    //express address two days
    cout << "Address: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    //use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;

    cout<<updates<<" locate at "<<p_updates<<endl;
    return 0;
}
//从中可知，int变量updates和指针变量p_updates只不过是同一枚硬币的两面.
//变量updates表示值，并使用&运算符来获取地址；而变量p_updates表示地址，并使用*运算符来获得值
//由于p_updates指向updates，因此*p_updates和updates完全等价。可以使用int变量那样使用*p_ipdates.
