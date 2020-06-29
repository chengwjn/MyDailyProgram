#include<iostream>
char *buildstr(char c,int n);//prototype
int main()
{
    using namespace std;
    int times;
    char ch;

    cout<<"Enter a character:";
    cin>>ch;
    cout<<"Enter an integer:";
    cin>>times;
    char *ps=buildstr(ch,times);
    cout<<ps<<endl;
    delete [] ps;//free memory
    ps=buildstr('+',20);
    cout<<ps<<"-DONE-"<<ps<<endl;
    delete [] ps;//free memory
    return 0;
}
//builds string made of n c characters
char *buildstr(char c,int n)
{
    char *pstr=new char[n+1];
    pstr[n]='\0';//terminate string
    while(n-->0)
        pstr[n]=c;//fill rest of string
    return pstr;
}
//要创建包含n个字符的字符串，需要能够存储n+1个字符的空间，以便能够储存空值字符
