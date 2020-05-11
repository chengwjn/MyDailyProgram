#include <iostream>
int square(int num)
{
    return num * num;
}
int power(int num1, int num2)
{
    int result = 1;
    for (int i = 0; i < num2; i++)
    {
        result *= num1;
    }
    return result;
}
int square(int num);
int power(int num1, int num2);
int main()
{
    using namespace std;
    int a = 3;
    a = square(a);
    cout << a << endl;
    int b = 3;
    b = power(b, b);
    cout << b << endl;
    return 0;
}