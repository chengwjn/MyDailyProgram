#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch);                //attemp to read a char
    while (cin.fail() == false) //test for EOF
    {
        cout << ch;
        ++count;
        cin.get(ch); //attempt to read another char
    }
    cout << endl
         << count << "characters read\n";
    return 0;
    //Unix中按ctrl+d可以模拟文件尾条件
    //windows是ctrl+z+enter
}