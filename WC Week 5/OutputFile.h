//
// Created by Thomas Levels on 25/03/2024.
//

#ifndef WC_WEEK_5_OUTPUTFILE_H
#define WC_WEEK_5_OUTPUTFILE_H
#include <iostream>

namespace OutputFile {

    class OutputFile {
    public:
        // constructor, opens the file with the given name
        OutputFile(const std::string& file_name);

        // default constructor, initializes the object without opening a file
        // and with an empty file name
        OutputFile();

        // destructor
        ~OutputFile();

        // opens the file with the given name, closes the previous file if it was open
        void open(const std::string& file_name);
        // closes the file
        void close();

        // writes the given value to the file if it is open
        // all those functions use std::fprintf or std::fputs

        OutputFile& operator<<(const std::string& value);
        OutputFile& operator<<(const char *value);
        OutputFile& operator<<(char value);
        OutputFile& operator<<(int number);
        OutputFile& operator<<(double number);

        // writes "true" or "false" to the file
        OutputFile& operator<<(bool value);

    private:
        std::string file_name_;
    };

} // OutputFile

#endif //WC_WEEK_5_OUTPUTFILE_H
