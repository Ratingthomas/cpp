//
// Created by Thomas Levels on 02/04/2024.
//

#ifndef WC_WEEK_6_STRING_H
#define WC_WEEK_6_STRING_H

#include <iostream>

namespace cppf {
    class String {
        public:
            String();
            String(const char* string);
            String(std::string string_);
//            ~String();

            const char* c_str();
            char* data();
            bool empty();
            std::size_t size();

            const char at(std::size_t index);
            const char begin();
            const char end();

            String(String& t){
                storage_ = t.storage_;
                length_ = t.length_;
            }

            void append(const char* str);
            void append(const cppf::String& str);
            void append(const std::string& str);
        private:
            char * storage_;
            std::size_t length_;
    };
} // cppf

#endif //WC_WEEK_6_STRING_H
