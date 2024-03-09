//
// Created by Thomas Levels on 28/02/2024.
//

#ifndef OPDRACHT_2_REPLACE_H
#define OPDRACHT_2_REPLACE_H

#include <iostream>

namespace Replace {
    struct ReplaceValue{
        std::string key;
        std::string value;
    };

    struct replacements{
        const int capacity_ = 10;
        std::array<ReplaceValue, 10> pairs_;
        int size_ = 0;

        void process_replacesments(std::string file_name);

        void replace(std::string file_name, char* argv[], int argc);

        std::string redact_replacements(std::string text);
        std::string redact_numbers(std::string text) const;
        std::string redact_dates(std::string text) const;
    };

} // Replace

#endif //OPDRACHT_2_REPLACE_H
