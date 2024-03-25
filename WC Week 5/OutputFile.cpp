//
// Created by Thomas Levels on 25/03/2024.
//

#include "OutputFile.h"

namespace OutputFile {
    OutputFile::OutputFile(const std::string &file_name):
        file_name_{file_name}
    {
        FILE* out = std::fopen(file_name.c_str(), "w");

        if (out != nullptr && std::ferror(out) == 0) {
            std::fprintf(out, "");
            std::fclose(out);
        }
    }

    std::string OutputFile::file_name(){
        return file_name_;
    }

    OutputFile::OutputFile::~OutputFile(){

    }

    OutputFile& OutputFile::operator<<(const std::string& value){
        std::cout << "Opening file";
        FILE* out = std::fopen("output.txt", "w");

        if (out != nullptr && std::ferror(out) == 0) {
            std::fprintf(out, "a");
            std::fclose(out);
        }


        return *this;
    }

    OutputFile& OutputFile::operator<<(const char *value){
        std::cout << "Opening char";
        FILE* out = std::fopen(file_name_.c_str(), "a");

        if (out != nullptr && std::ferror(out) == 0) {
            std::fprintf(out, value);
            std::fclose(out);
        }
        return *this;
    }

    OutputFile& OutputFile::operator<<(char value){
        return *this;
    }

    OutputFile& OutputFile::operator<<(int number){
        return *this;
    }

    OutputFile& OutputFile::operator<<(double number){
        return *this;
    }

} // OutputFile