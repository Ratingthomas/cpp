#include <iostream>
#include "OutputFile.h"
#include <cstdio>

int main() {
    io::OutputFile fw{"output.txt"};

    fw << "Alice has " << 3 << " rats.\n";
    fw << "True of false: does Alice like rats?\n"
       << "Answer: " << true << "\n";

    return 0;
}
