#include <iostream>
int main()
{
    using namespace std;
    int sum[5] = {1, 2, 3, 4, 5};
    int a = 0;
    int *pt = sum + a;
    cout << pt << endl;
    cout << *pt << endl;
}