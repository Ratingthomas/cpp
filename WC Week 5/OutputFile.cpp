//
// Created by Thomas Levels on 25/03/2024.
//

#include "OutputFile.h"

namespace io {
    OutputFile::OutputFile(const std::string &file_name):
        file_name_{file_name}
    {
        open(file_name);
    }

    bool OutputFile::is_open(){
        if (out_ != nullptr && !error()) {
            return true;
        } else{
            return false;
        }
    }

    bool OutputFile::error() {
        if(std::ferror(out_) == 0){
            return false;
        } else{
            return true;
        }
    }

    bool OutputFile::eof() {
        if(std::feof(out_)){
            return true;
        } else{
            return false;
        }
    }

    void OutputFile::open(const std::string &file_name) {
        out_ = std::fopen(file_name.c_str(), "w");

        if(is_open()){
            std::fprintf(out_, "");
        }
    }

    std::string OutputFile::file_name(){
        return file_name_;
    }

    OutputFile& OutputFile::operator<<(const std::string& value){
        std::cout << "Opening string\n";
        if(!eof()){
            std::fprintf(out_, "%s", value.c_str());
        }

        return *this;
    }

    OutputFile& OutputFile::operator<<(const char *value){
        std::cout << "Opening *char\n";

        if(!eof()){
            std::fprintf(out_, "%s", value);
        }
        return *this;
    }

    OutputFile& OutputFile::operator<<(char value){
        std::cout << "Opening char\n";

        if(!eof()){
            std::fprintf(out_, "%s", &value);
        }
        return *this;
    }

    OutputFile& OutputFile::operator<<(int number){
        std::cout << "Opening number\n";

//        std::string number_str = std::to_string(number);

        if(!eof()){
            std::fprintf(out_, "%d", number);
        }
        return *this;
    }

    OutputFile& OutputFile::operator<<(double number){
        std::cout << "Opening double\n";
        std::string number_str = std::to_string(number);

        if(!eof()){
            std::fprintf(out_, "%s" ,number_str.c_str());
        }
        return *this;
    }

    OutputFile& OutputFile::operator<<(bool value) {
        std::cout << "Opening bool\n";
        if(!eof()){
            if(value){
                std::fprintf(out_, "true");
            } else {
                std::fprintf(out_, "false");
            }
        }
        return *this;
    }

} // OutputFile