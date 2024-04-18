#include "options.h"

#include <iostream>
#include <iomanip>


exam::Options exam::parse_options(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    Options options{};
    for (int i = 1; i < argc; ++i) {
        std::string arg{argv[i]};
        if (arg.starts_with("--")) {
            if (arg.starts_with("--help")) options.help = true;
            if (arg.starts_with("--sorted")) options.sorted = true;
            if (arg.starts_with("--unique")) options.unique_values = true;
        } else if (arg.starts_with("-")) {
            if (arg.find("h") != std::string::npos) options.help = true;
            if (arg.find("u") != std::string::npos) options.unique_values = true;
            if (arg.find("s") != std::string::npos) options.sorted = true;
        } else {  // not an option / flag, must be a filename
            options.files.push_back(arg);
        }
    }

    return options;
}

std::ostream &exam::operator<<(std::ostream &os, const exam::Options &options) {
    os << "Options:\n";
    os << "  unique_values: " << std::boolalpha << options.unique_values << '\n';
    os << "  sorted: " << std::boolalpha << options.sorted << '\n';
    os << "  help: " << std::boolalpha << options.help << '\n';
    os << "  files:\n";
    for (const auto &file: options.files) {
        os << "    " << file << '\n';
    }
    return os;
}