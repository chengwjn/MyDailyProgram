#include <iostream>
void oil(int x);
int main()
{
    using namespace std;
    int texas = 31;
    int year = 2011;
    cout << "In main(),texas = " << texas << ",&texas = ";
    cout << &texas << endl;
    oil(texas);
    cout << "In main(),";
}