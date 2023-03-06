#include <iostream>
int main(void)
{
    int ch;
    int count = 0;
    while ((ch = std::cin.get()) != EOF)
    {
        std::cout.put(char(ch));
        ++count;
    }
    std::cout << count << " characters read\n";
    return 0;
}