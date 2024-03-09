//
// Created by Thomas Levels on 28/02/2024.
//

#include "Replace.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace Replace {
    void replacements::process_replacesments(std::string file_name){
        std::ifstream replacements_file{file_name};

        if(replacements_file.fail()){
            std::cout << "Replacements file not found" << std::endl;
            exit(0);
        }

        std::string line;
        while(std::getline(replacements_file, line)){
            if(!line.empty()){
                std::istringstream iss{ line };
                std::string word;

                bool word_first = true;
                bool word_key = true;
                while (iss >> word){
                    if(word_key){
                        if(word != "|"){
                            if(word_first){
                                pairs_[size_].key += word;
                                word_first = false;
                            } else{
                                pairs_[size_].key += " " + word;
                            }
                        }
                    } else{
                        if(word_first){
                            pairs_[size_].value += word;
                            word_first = false;
                        } else{
                            pairs_[size_].value += " " + word;
                        }
                    }
                    if(ispunct(word[0])){
                        word_key = false;
                        word_first = true;
                    }
                }

                size_ = size_ + 1;
            }

        }
    }

    void replacements::replace(std::string file_name, char* argv[], int argc) {
        std::ifstream file{file_name};

        int found = file_name.find_first_of(".");
        std::string new_name = file_name.replace(found, file_name.length(), ".redacted");

        std::ofstream output{new_name};
        bool process_numbers = false;
        bool process_dates = false;


        if(file.fail()) {
            std::cout << "File not found" << std::endl;
            exit(0);
        }

        for (int i = 0; i < argc; ++i) {
            std::string argument;

            argument = argv[i];

            if(argument == "-n"){
                process_numbers = true;
            }
            if(argument == "-d"){
                process_dates = true;
            }
        }

        std::string line;
        while (std::getline(file, line)){
            std::istringstream iss{line};
            std::string word;

            line = redact_replacements(line);

            if(process_numbers){
                line = redact_numbers(line);
            }

            if(process_dates){
                line = redact_dates(line);
            }
            output << line << "\n";
        }

        output.close();
    }

    std::string replacements::redact_replacements(std::string text) {
        std::string new_value = "";

        for (int i = 0; i < size_; ++i) {
            auto find = text.find(pairs_[i].key);

            while(std::string::npos != find){
                new_value = text.replace(find, pairs_[i].key.size(), pairs_[i].value);
                find = text.find(pairs_[i].key);
            }
        }

        if(new_value == ""){
            return text;
        } else{
            return new_value;
        }

    }

    std::string replacements::redact_numbers(std::string text) const{
        std::istringstream iss{ text };
        std::string word;

        std::string replace;
        std::string new_value;

        while (iss >> word){
            bool number = true;

            for (unsigned long i = 0; i < word.size(); ++i) {
                if(!isdigit(word[i]) && word[i] != '.'){
                    number = false;
                }
            }

            if(number){
                auto find = text.find(word);

                if(std::string::npos != find){
                    new_value = text.replace(find, word.size(), "XXX");
                }
            }
        }

        if(new_value == ""){
            return  text;
        } else{
            return new_value;

        }
    }

    std::string replacements::redact_dates(std::string text) const{
        std::istringstream iss{ text };
        std::string word;

        std::string replace;
        std::string new_value;

//        std::cout << "echo";

        while (iss >> word){
            bool date = true;

            for (unsigned long i = 0; i < word.size(); ++i) {
                if(i == 2 || i == 5){
                    if(word[i] != '-' && word[i] != '/'){
                        date = false;
                    }
                } else{
                    if(!isdigit(word[i])){
                        date = false;
                    }
                }
            }

//            std::cout << date;

            if(date){
                auto find = text.find(word);

                if(std::string::npos != find){
                    new_value = text.replace(find, word.size(), "DATE_HERE");
                }
            }
        }

        if(new_value == ""){
            return  text;
        } else{
            return new_value;

        }
    }

} // Replace