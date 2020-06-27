#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::istream;
using std::ostream;
class String
{
private:
    char *str;
    int len;
    static int num_string;
    static const int CINLIM = 80;

public:
    String(const char *s);
    String();
    String(const String &);
    ~String(); //destructor
    int length() const { return len; }
};
#endif