//addpntrs.cpp -- pointer addition
#include <iostream>
int main()
{
    // using namespace std;
    // int i = 0;
    // int *p_i;
    // p_i = &i;
    // cout << "i= " << i << endl;
    // cout << "address = " << p_i << endl;
    // i++;
    // p_i = &i;
    // cout << "i= " << i << endl;
    // cout << "address = " << p_i << endl;
    // p_i++;
    // cout << p_i << endl;
    // cout << *p_i;
    // return 0;
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    //here are two ways to get the address of an array
    double *pw = wages;     //name of an array=address
    short *ps = &stacks[0]; //or use address operator
    //with array element
    cout << "pw= " << pw << ", *pw= " << *pw << endl;
    //20200404，今日目标--->深刻理解指针，please
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw= " << pw << ",*pw = " << *pw << "\n\n";
    cout << "ps" << ps << ",*ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps =" << ps << ",*ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";
    cout << "stack[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks << ",*(stacks+1) = " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    return 0;
}