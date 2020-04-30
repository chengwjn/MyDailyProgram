#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    int i;
    for (i = limit; i; i--) //quits when i to 0
        cout << "i= " << i << endl;
    cout << "Done now that i = " << i << endl;
    return 0;
}