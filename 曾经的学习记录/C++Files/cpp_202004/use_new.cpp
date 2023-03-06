//use_new.cpp -- using the new operator
#include <iostream>
int main()
{
    using namespace std;
    int nights = 1001;
    int *pt = new int; //allocate space for an int
    *pt = 1001;        //store a value there

    cout << "night value = ";
    cout << nights << " :location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;
    double *pd = new double; //allocate space for a double
    *pd = 1000001.0;         //store a double there

    cout << "double ";
    cout << "value = " << *pd << ":location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "size of pt= " << sizeof(pt);
    cout << ":size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl; //注意书中指针长度是4的原因是32位系统

    int i = 1111;
    int *p_i;
    p_i = &i;
    cout << sizeof(i) << endl;
    cout << sizeof(&i) << endl;
    cout << sizeof(p_i) << endl;
    cout << sizeof(*p_i) << endl;
    if (&i == p_i)
    {
        cout << "yes" << endl;
    }
    return 0;
}
//自动格式化快捷键：shift + option + F