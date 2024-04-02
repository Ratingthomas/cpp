//
// Created by Thomas Levels on 02/04/2024.
//

#include "String.h"

namespace cppf {
    String::String():
        storage_{(char *)"\0"},
        length_{0}
    {};

    String::String(const char * string):
        storage_{(char *) string},
        length_{strlen(string)}
    {}

    String::String(std::string string_):
        storage_{string_.data()},
        length_{string_.length()}
    {}

    const char * String::c_str() {
        return storage_;
    }

    std::size_t String::size() {
        return length_;
    }

    char *String::data() {
        return storage_;
    }

    bool String::empty() {
        if(storage_ == (char *) '\0'){
            return true;
        } else{
            return false;
        }
    }

    const char String::at(std::size_t index) {
        if(index > length_-1){
            throw std::out_of_range("Index is out of bounce!");
        } else{
            return storage_[index];
        }
    }

    const char String::begin() {
        return storage_[0];
    };

    const char String::end() {
        return storage_[length_ -1];
    };

    void String::append(const char* str){
//        char* new_[80];
//        strcpy(new_,storage_);
//        strcat(new_, str);

//        storage_ = (char *) new_;
    }

//    void String::append(const cppf::String& str)
//    {
//        append(str.c_str());
//    }
//
//    void String::append(const std::string& str)
//    {
//        append(str.c_str());
//    }

} // cppf