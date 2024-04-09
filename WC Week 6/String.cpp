//
// Created by Thomas Levels on 02/04/2024.
//

#include "String.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace cppf {
    String::String():
        storage_{(char *)"\0"},
        length_{0}
    {};

    String::String(cppf::String const &t):
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

    char String::at(std::size_t index) {
        if(index > length_-1){
            throw std::out_of_range("Index is out of bounce!");
        } else{
            return storage_[index];
        }
    }

    char String::begin() {
        return storage_[0];
    };

    char String::end() {
        return storage_[length_ -1];
    };

    void String::swap(cppf::String& other) {
        std::swap(storage_, other.storage_);
        std::swap(length_, other.length_);
    }

    cppf::String& String::operator=(const cppf::String& other){
        if(this != &other){
            String copy{other};

            std::swap(storage_, copy.storage_);
            std::swap(length_, copy.length_);
        }
        return *this;
    }


    void String::append(const char* str){
        std::string new_ = storage_;
        std::string concatenated = new_ + str;

        char* result = new char[concatenated.length() + 1]; // +1 for null terminator
        std::strcpy(result, concatenated.c_str());

        storage_ = result;
    }

    void String::append(String str)
    {
        append(str.c_str());
    }

    void String::append(const std::string& str)
    {
        append(str.c_str());
    }

    void String::append(char c){
//        const char * ne_ = (const char *) (c);

//        append()
    }

    void String::clear() {
        storage_ = (char *) "\0";
        length_ = 0;
    }

} // cppf