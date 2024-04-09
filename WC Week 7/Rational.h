//
// Created by Thomas Levels on 05/03/2024.
//
#include <iostream>

#ifndef OPDRACHT_1_RATIONAL_H
#define OPDRACHT_1_RATIONAL_H

namespace Rational{

    class Rational {
        public:
            /* Constructors */
            Rational();

            Rational(int num, int den);
            Rational(int num);
            Rational(std::string str);

            /* Accessors */
            int num() const;
            int den() const;
            std::string str() const;

            bool is_pos() const;
            bool is_neg() const;
            bool is_inf() const;
            bool is_nan() const;

            /* Modifiers */
            void set(int num, int den);
            void str(std::string s);

            Rational add(Rational b) const;
            Rational sub(Rational b) const;
            Rational mul(Rational b) const;
            Rational div(Rational b) const;

            Rational pow(int n) const;
            Rational sqrt() const;

            Rational& operator+=(const Rational& other);
            Rational& operator-=(const Rational& other);
            Rational& operator*=(const Rational& other);
            Rational& operator/=(const Rational& other);

            Rational operator+() const;
            Rational operator-() const;

            bool operator==(const Rational& rhs) const;
            bool operator!=(const Rational& rhs) const;
            bool operator>(const Rational& rhs) const;
            bool operator<(const Rational& rhs) const;
            bool operator>=(const Rational& rhs) const;
            bool operator<=(const Rational& rhs) const;



        private:
            int num_;
            int den_;

            int gcd(int n, int d);

        };

    std::ostream& operator<<(std::ostream &os, const Rational &rhs);

}

Rational::Rational operator+(const Rational::Rational& lhs, const Rational::Rational& rhs);
Rational::Rational operator/(const Rational::Rational& lhs, const Rational::Rational& rhs);
Rational::Rational operator-(const Rational::Rational& lhs, const Rational::Rational& rhs);
Rational::Rational operator*(const Rational::Rational& lhs, const Rational::Rational& rhs);



#endif //OPDRACHT_1_RATIONAL_H
