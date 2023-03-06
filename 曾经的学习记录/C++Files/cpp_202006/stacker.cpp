//stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype> // or ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << " poped\n";
            }
            break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO,or Q to quit.\n";
    }
    cout << "Bye.\n";
    return 0;
}
//类是用户定义的类型的定义。类声明指定了数据将如何存储，同时指定了用来访问和操纵这些数据的方法（类成员函数）
//类表示人们可以类方法的公有接口对类对象执行的操作，这是抽象。类的数据成员可以是私有的（默认值），这意味着只能通过成员函数来访问这些数据，这是数据隐藏。实现的具体细节都是隐藏的，这是封装。
//类定义了一种类型，包括如何使用它。对象是一个变量额或其他数据对象（如由new生成的），并根据类定义被创建和使用。类和对象之间的关系同标准类型与其变量之间的关系相同。
//如果创建给定类的多个对象，则每个对象都有其自己的数据内存空间；但所有的对象都使用同一组成员函数（通常，方法是共有的，而数据是私有的，但这只是策略方面的问题，而不是对类的要求）。

