//
//  strngbad.h
//  strngbad
//
//  Created by 程文捷 on 2020/6/23.
//  Copyright © 2020 程文捷. All rights reserved.
//
#include<iostream>
#ifndef strngbad_h
#define strngbad_h
class StringBad
{
private:
    char *str;//pointer to string
    int len;//length of string
    static int num_trings;//numbers of objects
public:
    StringBad(const char *s);
    StringBad();
    ~StringBad();
    friend std::ostream &operator << (std::ostream& os,const StringBad &st);
};

#endif /* strngbad_h */
