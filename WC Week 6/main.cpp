#include <iostream>
#include "String.h"

int main() {
    cppf::String str0{};    // default constructor
    cppf::String str1{"Alice"}; // from a string literal
    cppf::String str2 = std::string{"Bob"}; // from std::string
    cppf::String str3{str2};    // copy constructor
    str0 = str1;    // copy assignment operator

    std::cout << str0.c_str() << std::endl;
    std::cout << str0.data() << std::endl;
    std::cout << str1.data() << std::endl;
    std::cout << str2.data() << std::endl;
    std::cout << str3.data() << std::endl;

    cppf::String str{"Alice"};
    std::cout << str.size() << std::endl;  // 5
    std::cout << str.empty() << std::endl;  // 0
    std::cout << str.c_str() << std::endl;  // Alice

    cppf::String str_a{"Alice"};
    str_a.append(" and Bob");

    std::cout << "New: " << str_a.c_str() << std::endl;

    return 0;
}
