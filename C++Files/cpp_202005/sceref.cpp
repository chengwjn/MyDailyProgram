#include <iostream>
int main()
{
    using namespace std;
    int rats = 101;
    int &rodents = rats; //rodents is a reference

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ",rodents address = " << &rodents << endl;

    //cout << ",rodents address = " << &rodents << endl;
    int bunnies = 50; //can we change the reference?
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ",rats = " << rats;
    cout << ",rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ",rodents address = " << &rodents << endl;
    return 0;
}