#include <iostream>
#include <stdexcept>
#include "Options.h"
#include "Counter.h"
#include "FileCounts.h"

auto help_text = "WC Help"
                 "\n-l  Lines "
                 "\n-w  Words"
                 "\n-m  Characters"
                 "\n-c  Bytes"
                 "\n-L  Longest Line \n";

int main(int argc, char * argv[]){
    try
    {
        Options::Options opts{argc, argv};

        if (opts.verbose()){
            // print parsed options
            std::cout << opts << std::endl;
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
            std::cout << "Try `./main.a --help` for more information.\n";
            return EXIT_FAILURE;
        }

        // TODO: handle summing up totals in the loop below
        FileCounts totals{};

        Counter::Counter counter(opts);
        int count = 0;

        for (const auto& file_name: opts.file_names())
        {
            count++;
            auto counts = counter.process(file_name);
            counts.print(opts);

            totals.lines += counts.lines;
            totals.words += counts.words;
            totals.characters += counts.characters;
            totals.bytes += counts.bytes;
            totals.maximum_line_length += counts.maximum_line_length;
            totals.file_name = "total";
        }

        if(count > 1){
            totals.print(opts);
        }

        return EXIT_SUCCESS;
    }
    catch(const std::invalid_argument& exc){
        std::cout << exc.what() << '\n';
        std::cout << "Try `wc --help` for more information.\n";
        return EXIT_FAILURE;
    }
}