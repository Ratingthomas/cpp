#include <iostream>
#include "OutputFile.h"
#include <cstdio>

int main() {
    OutputFile::OutputFile fw{"test.txt"};

//    fw << "a" << "a";
    fw << "Alice has " << 3 << " rats.\n";
    return 0;
}
