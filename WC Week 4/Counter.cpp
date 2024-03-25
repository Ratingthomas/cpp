//
// Created by Thomas Levels on 23/03/2024.
//

#include "Counter.h"
//#include "FileCounts.h"
#include <sstream>
#include <fstream>
#include <algorithm>

namespace Counter {
    Counter::Counter(const Options::Options &opts):
        opts_{opts}
    {}

    FileCounts Counter::process(const std::string &file_name) {
        std::ifstream input{file_name};
        FileCounts fileCount = {};
        fileCount.file_name = file_name;
        fileCount.maximum_line_length = 0;

        if(input.fail()){
            throw std::invalid_argument("Could not open file: " + file_name);
        }

        std::string line;

        while (std::getline(input, line)){
            fileCount = Counter::process_line(line, fileCount);
        }

        return fileCount;
    }

    size_t Counter::maximum_line_length(std::string line, FileCounts fileCount){
        if(line.length() > fileCount.maximum_line_length){
            return line.length();
        } else{
            return fileCount.maximum_line_length;
        }
    }

    FileCounts Counter::process_line(std::string line, FileCounts fileCount) {
        fileCount.lines++;

        std::istringstream iss{ line };
        std::string word;

        fileCount.maximum_line_length = maximum_line_length(line, fileCount);

        while (iss >> word){
            fileCount.words++;

            fileCount.characters += word.size();
            fileCount.bytes += sizeof(word);
        }

        return fileCount;
    }
} // Counter