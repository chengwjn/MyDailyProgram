#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int count;
    cout << "Enter characters;enter # to quit:\n";
    cin.get(ch);
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch); //use it again
    }
    cout << endl
         << count << "characters read\n";
    return 0;
}