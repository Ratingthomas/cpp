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
        version_{false},
        verbose_{false}
    {}

    Options::Options(int argc, char * argv[]):
        lines_{false},
        words_{false},
        characters_{false},
        bytes_{false},
        longest_line_{false},
        help_{false},
        version_{false},
        verbose_{false}
    {
        parse(argc, argv);
    }

//    void Options::print(std::ostream &out) const {
//        out << "";
//    }

    void Options::parse(int argc, char **argv) {
        for (int i = 1; i < argc; ++i) {
            std::string arg{ argv[i] };
            bool found = false;

            if(arg.starts_with("-")){
                if(strcmp(argv[i], "--help") == 0){
                    help_ = true;
                    found = true;
                }
                else if(strcmp(argv[i], "--version") == 0){
                    version_ = true;
                    found = true;
                }
                else if(strcmp(argv[i], "--verbose") == 0){
                    verbose_ = true;
                    found = true;
                } else{
                    for (size_t j = 0; j < arg.length(); ++j) {
                        if(arg[j] == 'c'){
                            bytes_ = true;
                            found = true;
                        } else if(arg[j] == 'm') {
                            characters_ = true;
                            found = true;
                        } else if(arg[j] == 'w'){
                            words_ = true;
                            found = true;
                        } else if(arg[j] == 'l'){
                            lines_ = true;
                            found = true;
                        } else if(arg[j] == 'L'){
                            longest_line_ = true;
                            found = true;
                        }
                    }
                }

                if(!found){
                    throw std::invalid_argument("Invalid argument passed: " + arg);
                }

            } else{
                file_name_.push_back(argv[i]);
            }
        }
    }

    const std::vector<std::string>& Options::file_names() const {
        return file_name_;
    }

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
        return verbose_;
    }

} // Options