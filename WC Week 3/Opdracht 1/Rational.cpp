//
// Created by Thomas Levels on 05/03/2024.
//

#include "Rational.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

namespace Rational{
    Rational::Rational() {
        num_ = 0;
        den_ = 1;
    }

    Rational::Rational(int num, int den){
        Rational::set(num, den);
    }

    Rational::Rational(int num){
        num_ = num;
        den_ = 1;
    }

    Rational::Rational(std::string str){
        std::string tmp;
        bool first = true;

        for (int i = 0; i < str.size(); ++i) {
            if(isalpha(str[i])){
                if(str[i] == '/'){
                    first = false;
                }

                if(first){
                    num_ += str[i];
                } else{
                    den_ += str[i];
                }
            }
        }

    }

    int Rational::num() const{
        return num_;
    }

    int Rational::den() const{
        return den_;
    }

    std::string Rational::str() const{
        return std::to_string(num_) + "/" + std::to_string(den_);
    }

    bool Rational::is_pos() const{
        if(num_ > 0 || den_ > 0){
            return true;
        } else{
            return false;
        }
    }

    bool Rational::is_neg() const{
        if(num_ < 0 || den_ < 0){
            return true;
        } else{
            return false;
        }
    }

    bool Rational::is_inf() const{
        if(isinf(num_) || isinf(den_)){
            return true;
        } else{
            return false;
        }
    }

    bool Rational::is_nan() const{
        if(isnan(num_) || isnan(den_)){
            return true;
        } else{
            return false;
        }
    }

    void Rational::set(int num, int den){
        if(num != 0 && den != 0){
            int gcd = Rational::gcd(num, den);

            num_ = num / gcd;
            den_ = den / gcd;
        } else{
            num_ = NAN;
            den_ = NAN;
        }

    }

    int Rational::gcd(int num, int den) {
        int result = std::min(num, den);
        while (result > 0) {
            if (num % result == 0 && den % result == 0) {
                break;
            }
            result--;
        }

        return result;
    }

    Rational Rational::add(Rational b) const {
        int a_num = num() * b.den_;
        int b_num = b.num_ * den();

        return (Rational){(a_num + b_num), (b.den() * den())};
    }

    Rational Rational::sub(Rational b) const {
        int a_num = num() * b.den_;
        int b_num = b.num_ * den();

        return (Rational){(a_num - b_num), (b.den() * den())};
    }

    Rational Rational::div(Rational b) const {
        return (Rational){(num() * b.den()), (den() * b.num())};
    }

    Rational Rational::pow(int n) const {
        return (Rational){num() * num(), den() * den()};
    }

    Rational Rational::sqrt() const {
        if(!is_nan()){
            
        }
    }
}
