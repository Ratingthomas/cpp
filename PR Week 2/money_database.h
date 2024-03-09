//
// Created by Thomas Levels on 01/03/2024.
//

#ifndef PR_WEEK_2_MONEY_DATABASE_H
#define PR_WEEK_2_MONEY_DATABASE_H
#include "deposit.h"
#include <iostream>

namespace money_database {
    struct MoneyDatabase{
        std::array<Deposit, 100> deposits_{};
        int size_ = 0;

        void add(Deposit deposit);
        int size() const;
        Deposit get(int index) const;
        double total_of(std::string currency_code);
    };

    inline std::ostream& operator<<(std::ostream& out, MoneyDatabase const& db)
    {
        out << "Database with size " << db.size_ << " and capacity " << db.deposits_.size() << '\n';
        out << "Deposits are:\n[\n";
        auto comma = "  ";
        for (auto i{0}; i < db.size_; ++i)
        {
            out << comma << db.deposits_[i];
            comma = ",\n  ";
        }

        return out << "\n]";
    }
};


#endif //PR_WEEK_2_MONEY_DATABASE_H
