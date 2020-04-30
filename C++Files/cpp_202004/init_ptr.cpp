//init_ptr.cpp -- initialize a pointer如何让将指针初始化
#include <iostream>
int main()
{
     using namespace std;
     int higgens = 5;
     int *pt = &higgens;

     cout << "Value of higgens = " << higgens
          << ";Address of higgens = " << &higgens << endl;
     cout << "Value of *pt = " << *pt
          << ";Value of pt = " << pt << endl;
     return 0;
}
//程序解释
//在多数情况下，C++将数组名解释为数组第一个元素的地址。因此，下面的语句将pw声明指向double类型的指针，
//然后将它初始化为wages---wages数组中第一个元素的地址：
//double * pw = wages;
//和所有数组一样，wages也存在下面的等式：
//wages = &wages[0] = address of first element of array
//为表明情况确实如此，该程序在表达式&stacks[0]中显式地使用地址运算符来将ps指针初始化为stacks数组的第一个元素
//