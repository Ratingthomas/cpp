//
// Created by Thomas Levels on 25/03/2024.
//

#include "OutputFile.h"

namespace OutputFile {
    OutputFile::OutputFile(const std::string &file_name):
        file_name_{file_name}
    {}

    OutputFile& OutputFile::operator<<(const std::string& value){
        return *this;
    }




} // OutputFile