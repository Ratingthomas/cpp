#include <iostream>
#include "Complex.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Complex::Complex a{1.0, 2.0};
    Complex::Complex b{3.0, 4.0};

    auto c = a.add(b);
    std::cout << c << '\n';

    auto d = c.div(a);
    std::cout << d << '\n'; // 3.2-0.4i

    Complex::Complex e{"3 - 4.2i"};  // This calls the Complex::Complex(std::string) constructor
    std::cout << e << '\n'; // 3+4.2i
    return 0;
}
