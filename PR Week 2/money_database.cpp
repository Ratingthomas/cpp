//
// Created by Thomas Levels on 01/03/2024.
//

#include "money_database.h"

namespace money_database{
    void MoneyDatabase::add(Deposit deposit){
        deposits_[size_] = deposit;
        size_ = size_ + 1;
    }

    int MoneyDatabase::size() const{
        return size_;
    }

    Deposit MoneyDatabase::get(int index) const{
        if(index > size_){
            return Deposit{.currency = "INV", .amount = 0};
        } else{
            return deposits_[index];
        }
    }

    double MoneyDatabase::total_of(std::string currency_code){
        double count = 0;

        for (int i = 0; i < size_; ++i) {
            if(deposits_[i].currency == currency_code){
                count = count + deposits_[i].amount;
            }
        }

        return count;
    }

}

