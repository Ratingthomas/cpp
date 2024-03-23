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

    void print(std::ostream& out, Options::Options const& opt) const;
};

#endif //WC_WEEK_4_FILECOUNTS_H
