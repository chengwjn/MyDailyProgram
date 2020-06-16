//
//  stock00.h
//  Test
//
//  Created by 程文捷 on 2020/6/17.
//  Copyright © 2020 程文捷. All rights reserved.
//

#ifndef stock00_h
#define stock00_h

#include<string>
class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    void total_val;
    void set_tot(){total_val=shares*share_val;}
public:
    void acquire(const std::string &co,long n,double pr);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
};//note semicolon at the end

#endif /* stock00_h */
