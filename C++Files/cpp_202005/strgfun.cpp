#include <iostream>
unsigned int c_in_str(const char *str, char ch);
int main()
{
    using namespace std;
    char mmm[15] = "mininum";
    char *wail = "ululate";
    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');
    return 0;
}
unsigned int c_in_str(const char *str, char ch)
{
    unsigned int count = 0;
    while (*str)
    {
        if (*str == ch)
            count++;
        str++;
    }
    return count;
}