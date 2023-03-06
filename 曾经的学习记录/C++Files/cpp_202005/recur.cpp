//递归！！！
//C++不允许main()调用自己
//void recurs(argumentlist)
//{
//   statements1
//    if(test)
//       recurs(arguments)
//    statements2
//}
//只要if语句为true，每个recurs()调用都将执行statements1，然后再调用recurs
//而不会执行statements2.
//recur.cpp -- using recursion
#include <iostream>
void countdown(int n);

int main()
{
    countdown(4);
    return 0;
}

void countdown(int n)
{
    using namespace std;
    cout << "Counting down ..." << n << endl;
    if (n > 0)
        countdown(n - 1);
    cout << n << ": Kaboom!\n";
}