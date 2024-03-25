//
// Created by Thomas Levels on 23/03/2024.
//

#ifndef WC_WEEK_4_FILECOUNTS_H
#define WC_WEEK_4_FILECOUNTS_H

#include "Options.h"

struct FileCounts
{
    std::size_t lines{};
    std::size_t words{};
    std::size_t characters{};
    std::size_t bytes{};
    std::size_t maximum_line_length{};
    std::string file_name{};

    void print(Options::Options const& opt){
        std::string output;

        if (opt.lines()) {
            output += std::to_string(this->lines) + " ";
        }
        if (opt.words()) {
            output += std::to_string(this->words) + " ";
        }
        if (opt.characters()) {
            output += std::to_string(this->characters) + " ";
        }
        if (opt.bytes()) {
            output += std::to_string(this->bytes) + " ";
        }
        if (opt.longest_line()) {
            output += std::to_string(this->maximum_line_length) + " ";
        }

        output += this->file_name + " ";

        std::cout << output << "\n";
    };
};





#endif //WC_WEEK_4_FILECOUNTS_H
