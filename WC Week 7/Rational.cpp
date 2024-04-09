//
// Created by Thomas Levels on 05/03/2024.
//

#include "Rational.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <algorithm>

namespace Rational{
    Rational::Rational():
        num_{0},
        den_{1}
    {

    }

    Rational::Rational(int num, int den){
        Rational::set(num, den);
    }

    Rational::Rational(int num){
        num_ = num;
        den_ = 1;
    }

    Rational::Rational(std::string str){
        std::string tmp_num;
        std::string tmp_den;
        char action;
        bool first = true;

        for (int i = 0; i < str.length(); ++i) {
            if(str[i] == '/'){
                first = false;
            } else{
                if(first){
                    tmp_num += str[i];
                } else{
                    tmp_den += str[i];
                }
            }
        }

        int num = std::stoi(tmp_num);
        int den = std::stoi(tmp_den);

        Rational::set(num, den);
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
        if(den_ <= 0){
            return true;
        }
        else{
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
        int gcd = Rational::gcd(num, den);

        num_ = num / gcd;
        den_ = den / gcd;

        if(num_ < 0 && den_ < 0){
            num_ = num_ * -1;
            den_ = den_ * -1;
        }
    }

    int Rational::gcd(int n, int d) {
        int a, b, c;
        a = n;
        b = d;

        while (a % b != 0) {
            c = a % b;
            a = b;
            b = c;
        }

        return b;
    }

    Rational Rational::add(Rational b) const {
        if(is_inf()){
            return (Rational){1, 0};
        } else{
            int a_num = num() * b.den_;
            int b_num = b.num_ * den();

            return {(a_num + b_num), (b.den() * den())};
        }


    }

    Rational Rational::sub(Rational b) const {
        int a_num = num() * b.den_;
        int b_num = b.num_ * den();

        return (Rational){(a_num - b_num), (b.den() * den())};
    }

    Rational Rational::div(Rational b) const {
        return (Rational){(num() * b.den()), (den() * b.num())};
    }

    Rational Rational::mul(Rational b) const {
        return (Rational){num() * b.num_, den() * b.den_};
    }

    Rational Rational::pow(int n) const {
        double num_n = num();
        double den_n = den();
        double pow = n;

        return (Rational){(int) std::pow(num_n, pow), (int) std::pow(den_n, pow)};
    }

    Rational Rational::sqrt() const {
        double num_n = std::sqrt(num());
        double den_n = std::sqrt(den());

        double intpart;
        double fractpart = modf (num_n , &intpart);

        if(fractpart != 0){
            num_n = 0;
            den_n = 0;
        }

        if(!is_nan() && !is_neg() && !is_inf()){
            return (Rational){(int)num_n, (int)den_n};
        } else{
            num_n = 0;
            den_n = 0;

            return (Rational){(int)num_n, (int)den_n};
        }
    }

    Rational &Rational::operator+=(const Rational &other) {
        auto result = this->add(other);
        return *this = result;
    }

    Rational Rational::operator+() const {
        return *this;
    }

    Rational &Rational::operator-=(const Rational &other) {
        auto result = this->sub(other);
        return *this = result;
    }

    Rational &Rational::operator*=(const Rational& other){
        auto result = this->mul(other);
        return *this = result;
    }

    Rational &Rational::operator/=(const Rational &other) {
        auto result = this->div(other);
        return *this = result;
    }

    Rational Rational::operator-() const {
        this->num_ * -1;
        return *this;
    }

    bool Rational::operator==(const Rational& rhs) const{
        if(num() == rhs.num() && den() == rhs.den()){
            return true;
        } else{
            return false;
        }
    }

    bool Rational::operator!=(const Rational& rhs) const{
        if(num() != rhs.num() && den() != rhs.den()){
            return true;
        } else{
            return false;
        }
    }

    bool Rational::operator>(const Rational &rhs) const {
        if(num() > rhs.num() && den() > rhs.den()){
            return true;
        }
        else{
            return false;
        }
    }

    bool Rational::operator<(const Rational &rhs) const {
        if(num() < rhs.num() && den() < rhs.den()){
            return true;
        }
        else{
            return false;
        }
    }

    bool Rational::operator>=(const Rational &rhs) const {
//        return !(*this < rhs);
        if(num() >= rhs.num() && den() >= rhs.den()){
            return true;
        }
        else{
            return false;
        }
    }

    bool Rational::operator<=(const Rational &rhs) const {
        if(num() <= rhs.num() && den() <= rhs.den()){
            return true;
        }
        else{
            return false;
        }
    }

}


Rational::Rational operator+(const Rational::Rational& lhs, const Rational::Rational& rhs){
    return lhs.add(rhs);
}

Rational::Rational operator/(const Rational::Rational& lhs, const Rational::Rational& rhs){
    return lhs.div(rhs);
}

Rational::Rational operator-(const Rational::Rational& lhs, const Rational::Rational& rhs){
    return lhs.sub(rhs);
}

Rational::Rational operator*(const Rational::Rational& lhs, const Rational::Rational& rhs){
    return lhs.mul(rhs);
}

std::ostream& Rational::operator<<(std::ostream &os, const Rational &rhs)
{
    os << rhs.num() << "/" << rhs.den();
    return os;
}