//
// Created by Thomas Levels on 18/03/2024.
//

#include "Options.h"

namespace Options {
    Options::Options():
        lines_{false},
        words_{false},
        characters_{false},
        bytes_{false},
        longest_line_{false},
        help_{false},
        version_{false}
    {}

    Options::Options(int argc, char * argv[]):
        lines_{false},
        words_{false},
        characters_{false},
        bytes_{false},
        longest_line_{false},
        help_{false},
        version_{false}
    {
        parse(argc, argv);
    }

    void Options::parse(int argc, char **argv) {
        for (int i = 1; i < argc; ++i) {
            std::string arg{ argv[i] };

            if(arg.starts_with("-")){
                for (size_t j = 0; j < arg.length(); ++j) {
                    if(arg[j] == 'c'){
                        bytes_ = true;
                    } else if(arg[j] == 'm') {
                        characters_ = true;
                    } else if(arg[j] == 'w'){
                        words_ = true;
                    } else if(arg[j] == 'l'){
                        lines_ = true;
                    } else if(arg[j] == 'L'){
                        longest_line_ = true;
                    }
                }
            }

            if(strcmp(argv[i], "--help") == 0){
                help_ = true;
            }
            else if(strcmp(argv[i], "--version") == 0){
                version_ = true;
            } else{

            }
        }
    }

//    const std::vector<std::string>& Options::file_names() const {
//
//    }

    bool Options::bytes() const {
        return bytes_;
    }

    bool Options::lines() const {
        return lines_;
    }

    bool Options::words() const {
        return words_;
    }

    bool Options::characters() const {
        return characters_;
    }

    bool Options::longest_line() const {
        return longest_line_;
    }

    bool Options::help() const {
        return help_;
    }

    bool Options::version() const {
        return version_;
    }

    bool Options::verbose() const {
        std::cout << "lines_ = " << lines_ << "\n";
        std::cout << "words_ = " << words_ << "\n";
        std::cout << "characters_ = " << characters_ << "\n";
        std::cout << "bytes_ = " << bytes_ << "\n";
        std::cout << "longest_line_ = " << longest_line_ << "\n";
        std::cout << "help_ = " << help_ << "\n";
        std::cout << "version_ = " << version_ << "\n";
        return true;
    }

} // Options