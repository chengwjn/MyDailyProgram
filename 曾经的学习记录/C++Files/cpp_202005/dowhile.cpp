#include <iostream>
int main()
{
    using namespace std;
    // int n;
    // cout<<"Enter numbers in the range 1-10 to find ";
    // cout<<"my favorite number\n";
    // do
    // {
    //     /* code */
    //     cin>>n;
    // } while (/* condition */n!=7);
    // cout<<"Yes,7 is my favorite.\n";
    // return 0;
    double a[5] = {3.5, 3.4, 2.4, 5.6, 4.6};
    for (double i : a)
    {
        cout << i << " " << &i << endl;
    }
}