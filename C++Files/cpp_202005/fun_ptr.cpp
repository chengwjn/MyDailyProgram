//函数指针
//-1 获取函数的地址
//-2 声明一个函数指针
//-3 使用函数指针来调用函数
//--1.只要使用函数名（后面不跟参数）即可。也就是说，如果think()是一个函数，则think
//就是该函数的地址。要将函数作为参数进行传递，必须传递函数名。一定要区分传递的是函数的地址还是函数的返回值
//--2.声明指向某种数据类型的指针时，必须指定指针指向的类型。同样，声明指向函数的指针时，也必须指定指针指向的函数类型
//fun_ptr.cpp -- pointers to functions
#include <iostream>
double betsy(int);
double pam(int);

//second argument is pointer to a type double function that
//takes a type int argument
void estimate(int lines, double (*pf)(int));

int main()
{
    using namespace std;
    int code;
    cout << "How many lines of code do you need? ";
    cin >> code;
    cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);
    return 0;
}
double betsy(int lns)
{
    return 0.05 * lns;
}
double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}
void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n";
}