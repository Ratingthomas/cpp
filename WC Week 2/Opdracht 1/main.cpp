#include <iostream>
#include "Dictionary.h"

int main() {
    week2::Dictionary dict{};

    dict.add("cat", "kissa");
    dict.add("cat", "kissa");
    dict.add("dog", "koira");
    dict.add("horse", "hevonen");

    std::cout << dict.get("cat") << '\n'; // prints kissa
    std::cout << dict.get("dog") << '\n'; // prints koira

    std::cout << dict.contains("horse") << '\n'; // prints 1
    std::cout << dict.contains("pig") << '\n'; // prints 0

    for (auto i = 0; i < dict.size(); ++i)
    {
        std::cout << dict.key(i) << '\n'; // prints cat, dog, horse
    }
    return 0;
}
