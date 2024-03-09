#include <iostream>
#include "Rational.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Rational::Rational a(3, 4);
    Rational::Rational b(5, 6);

    auto c = a.add(b);
    std::cout << c.num() << "/" << c.den() << "\n";

    auto d = a.pow(2);
    std::cout << d.num() << "/" << d.den() << "\n";



    return 0;
}
