#include<iostream>
template <typename T>//original template
void Swap(T &a,T &b);

template <typename T>//new template
void Swap(T *a,T *b,int n);
void Show(int a[]);
const int Lim=8;
int main()
{
    using namespace std;
    int i=10,j=20;
    cout<<"i,j = "<<i<<", "<<j<<".\n";
    cout<<"Using compiler-generated int swapper:\n";
    Swap(i,j);
}