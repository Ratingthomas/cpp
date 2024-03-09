//
// Created by Thomas Levels on 26/02/2024.
//

#ifndef OPDRACHT_1_DICTIONARY_H
#define OPDRACHT_1_DICTIONARY_H

#include <iostream>

namespace week2 {

    struct KeyValue{
        std::string key;
        std::string value;
    };

    struct Dictionary{
        const int capacity_ = 100;
        std::array<KeyValue, 100> pairs_;
        int size_ = 0;

        void add(std::string key, std::string value);

        std::string get(std::string key);

        bool contains(std::string key);

        int size();

        std::string key(int index);
    };

} // week2

#endif //OPDRACHT_1_DICTIONARY_H
