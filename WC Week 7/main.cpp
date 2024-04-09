#include <iostream>
#include "Rational.h"

int main() {
    Rational::Rational a{45, 8};
    Rational::Rational b{3, 4};
    Rational::Rational c{45, 8};

    auto add = a + b;
    auto dev = a/b;
    auto sub = a-b;
    auto mul = a*b;

    std::cout << "Add: " << add << std::endl;
    std::cout << "Dev: " << dev << std::endl;
    std::cout << "Sub: " << sub << std::endl;
    std::cout << "Mul: " << mul << std::endl;

    if(a == c){
        std::cout << a << " == " << c << std::endl;
    }

    if(a != b){
        std::cout << a << " != " << b << std::endl;
    }

    if(a > b){
        std::cout << a << " > " << b << std::endl;
    }

    if(b < c){
        std::cout << b << " < " << c << std::endl;
    }

    if(a <= c){
        std::cout << a << " <= " << c << std::endl;
    }

    if(a >= b){
        std::cout << a << " >= " << b << std::endl;
    }

    if(a >= c){
        std::cout << a << " >= " << c << std::endl;
    }

    return 0;
}
