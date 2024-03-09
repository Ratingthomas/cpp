#include <iostream>
#include <fstream>
#include "Replace.h"


int main(int argc, char* argv[]) {
    Replace::replacements replacements{};

    replacements.process_replacesments(argv[2]);

    // Debug
//    for (int i = 0; i < replacements.size_; ++i) {
//        std::cout << "Key: " << replacements.pairs_[i].key << "Value: " << replacements.pairs_[i].value << "\n";
//    }

    replacements.replace(argv[1], argv, argc);

    return 0;
}
