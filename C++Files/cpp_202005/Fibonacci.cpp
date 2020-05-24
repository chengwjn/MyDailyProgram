#include <iostream>
int Fibonacci(int num);
int main()
{
    using namespace std;
    int n;
    cin >> n;
    int a = 0;
    a = Fibonacci(n);
    cout << a << endl;
    return 0;
}

int Fibonacci(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
    {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}