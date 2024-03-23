#include <iostream>
#include <stdexcept>
#include "Options.h"
#include "Counter.h"
#include "FileCounts.h"

auto help_text = ""; // TODO, fill in with real help text, copied from `wc --help`

int main(int argc, char * argv[]){
    try
    {
        Options::Options opts{argc, argv};

        if (opts.verbose()){
            // print parsed options
            std::cout << opts << std::endl;
//            opts.print(std::cout);
        }

        if (opts.help()){
            std::cout << help_text;
            return EXIT_SUCCESS;
        }

        if (opts.version()){
            // print version, you decide what version your program is
            return EXIT_SUCCESS;
        }

        if (opts.file_names().empty())
        {
            std::cout << "No file names passed.\n";
            std::cout << "Try `wc --help` for more information.\n";
            return EXIT_FAILURE;
        }

        // TODO: handle summing up totals in the loop below
        // FileCounts totals{};

        Counter::Counter counter(opts);

        for (const auto& file_name: opts.file_names())
        {
            auto counts = counter.process(file_name);
            counts.print(std::cout, opts);
        }

        // TODO: print totals if mor than one file processed


        return EXIT_SUCCESS;
    }
    catch(const std::invalid_argument& exc){
        std::cout << exc.what() << '\n';
        std::cout << "Try `wc --help` for more information.\n";
        return EXIT_FAILURE;
    }
}