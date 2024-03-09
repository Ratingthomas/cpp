//
// Created by Thomas Levels on 26/02/2024.
//

#include "Dictionary.h"

namespace week2 {
    void Dictionary::add(std::string key, std::string value) {
        bool continue_ = true;

        for (int i = 0; i < size_; ++i) {
            if(pairs_[i].key == key){
                continue_ = false;
            }
        }

        if(continue_){
            pairs_[size_] = KeyValue{.key = key, .value = value};
            size_ = size_ + 1;
        }
    }

    std::string Dictionary::get(std::string key) {
        int found = capacity_ + 1;

        for (int i = 0; i < capacity_; ++i) {
            if(pairs_[i].key == key){
                found = i;
            }
        }

        if(found == capacity_ +1){
            return "";
        } else{
            return pairs_[found].value;
        }
    }

    bool Dictionary::contains(std::string key){
        int found = capacity_ + 1;

        for (int i = 0; i < capacity_; ++i) {
            if(pairs_[i].key == key){
                found = i;
            }
        }

        if(found == capacity_ + 1){
            return false;
        } else{
            return true;
        }
    }

    int Dictionary::size(){
        return size_;
    }

    std::string Dictionary::key(int index) {
        return pairs_[index].key;
    }
} // week2