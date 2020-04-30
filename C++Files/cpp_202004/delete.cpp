#include <iostream>
#include <cstring> //or string.h
using namespace std;
char *getname(void); //function prototype
int main()
{
    char *name;       //create pointer but no storage
    name = getname(); //assign address of string to name
    cout << name << " at " << (int *)name << "\n";
    delete[] name;    //memory freed
    name = getname(); //reuse freed memory
    cout << name << " at " << (int *)name << "\n";
    delete[] name; //memory freed again
    return 0;
}
char *getname() //return pointer to new string
{
    char temp[80]; //temporary storage
    cout << "Enter last name: ";
    cin >> temp;
    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp); //copy string into smaller space
    return pn;        //temp lost when function ends
}
//它使用cin将输入的单词放到temp数组中，然后使用new分配新内存，以储存该单词。
//程序需要srele(temp)+1个字符（包括空字符)来存储该字符串，因此将这个值提供给new。
//获得空间后，getname()使用标准库函数strcpy()将temp中的字符串复制到新的内存块中。
//该函数并不检查内存快是否能够容纳字符串，但getname()通过使用new请求合适的字节数