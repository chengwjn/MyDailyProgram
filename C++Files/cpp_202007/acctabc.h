#ifndef ACCTABC_H_
#define ACCTABC_H_
#include<iostream>
#include<string>

//Abstract Base Class
class Acctabc
{
    private:
    std::string fullname;
    long acctNUm;
    double balance;
    protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
    }
    
}


#endif