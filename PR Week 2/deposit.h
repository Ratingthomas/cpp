//
// Created by Thomas Levels on 01/03/2024.
//
#ifndef PR_WEEK_2_DEPOSIT_H
#define PR_WEEK_2_DEPOSIT_H

#include <iomanip>
#include <iostream>

struct Deposit{
    std::string currency;
    double amount;
};

inline std::ostream& operator<<(std::ostream& out, Deposit const& dep)
{
    return out << dep.currency << ' ' << std::fixed << std::setprecision(2) << dep.amount;
}


#endif //PR_WEEK_2_DEPOSIT_H
