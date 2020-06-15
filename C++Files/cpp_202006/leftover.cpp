//函数重载
//函数特征标(function signature)
//leftover.cpp -- overloading the left() function
#include <iostream>
unsigned long left(unsigned long num, unsigned ct);
char *left(const char *str, int n = 1);
int main()
{
    using namespace std;
    char *trip = "Hawaii!";     //test value
    unsigned long n = 12345678; //test value
    int i;
    char *temp;
    for (i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp; //pointer to temporary storage
    }
    return 0;
}
//This function returns the first ct digits of the number num.
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;
    if (ct == 0 || num == 0)
        return 0;
    while (n /= 10)
        digits++;
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
            num /= 10;
        return num; //return left ce digits
    }
    else
        return num; //return the whole number
}

char *left(const char *str, int n)
{
    if (n < 0)
        n = 0;
    char *p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i]; //copy characters
    while (i <= n)
        p[i++] = '\0'; //set rest of string to '\0'
    return p;
}

//何时使用函数重载
//虽然函数重载很吸引人，但也不能滥用。仅当函数基本上执行相同的任务，但使用不同形式的数据时，
//才应用函数重载