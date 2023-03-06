#include <string>
namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
        /* data */
    };
    void getPerson(Person &);
    void showPerson(const Person &);

} // namespace pers
namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
        /* data */
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
} // namespace debts