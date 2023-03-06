#include <iostream>
int main()
{
    using namespace std;
    int i; //create a counter
    for (i = 0; i < 5; i++)
    {
        cout << "C++ knows loops.\n";
    }
    cout << "C++ knows when to stop.\n";
    for (int m = 0; m < 3; m++)
    {
        cout << "this is another one.\n";
    }
    cout << "it stoped.\n";
    return 0;
}