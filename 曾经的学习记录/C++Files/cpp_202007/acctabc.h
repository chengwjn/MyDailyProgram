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
//Brass Account Class
class Brass : public Acctabc
{
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) : Acctabc(s, an, bal) {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public Acctabc
{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string &S = "NUllbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMAx(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; };
    void ResetOwes() { owesBank = 0; }
};

#endif