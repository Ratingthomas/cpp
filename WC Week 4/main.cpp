#include <iostream>
#include "Options.h"

int main(int argc, char * argv[]) {
    try {
//        Options::Options opts{};
        Options::Options opts{argc, argv};
        opts.verbose();
    }
    catch(const std::invalid_argument& exc){
        std::cout << exc.what() << '\n';
        std::cout << "Try `wc --help` for more information.\n";
        return EXIT_FAILURE;
    }

    return 0;
}
