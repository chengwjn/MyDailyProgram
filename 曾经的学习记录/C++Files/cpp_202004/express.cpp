#include <iostream>
int main()
{
    using namespace std;
    int x;

    cout << "The expression x = 100 has the value";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;
    cout << "The expression x<3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x>3 has the value ";
    cout << (x > 3) << endl;
    cout.setf(ios_base::boolalpha); //a newer C++ feature
                                    //cout.setf(ios::boolalpha)函数调用设置了一个标记，该标记命令cout显示true和false而不是1和0
    cout << "The expression x<3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x>3 has the value ";
    cout << (x > 3) << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "C++ knows loops.\n";
    // }
    // cout << i << endl; --> i no longer defined;
    return 0;
}