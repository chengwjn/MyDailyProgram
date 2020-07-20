#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

//Abstract Base Class
class Acctabc
{
private:
    std::string fullname;
    long acctNum;
    double balance;

protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string &Fullname() const { return fullname; }
    long AccNum() const { return acctNum; }
    Formatting SetFormat() const;
    void Restore(Formatting &f) const;

public:
    Acctabc(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
    void Desposit(double amt);
    virtual void Withdraw(double amt) = 0; //pure virtual function
    double Balance() const { return balance; }
    virtual void ViewAcct() const = 0; //pure virtual function
    virtual ~Acctabc() {}
};

#endif