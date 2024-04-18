#include "options.h"

#include <iostream>
#include <iomanip>


exam::Options exam::parse_options(int argc, char* argv[])
{
    (void)argc; (void)argv;
    
    return {false, false, true, {}}; // This is a placeholder
}

std::ostream& exam::operator<<(std::ostream& os, const exam::Options& options)
{
    os << "Options:\n";
    os << "  unique_values: " << std::boolalpha << options.unique_values << '\n';
    os << "  sorted: " << std::boolalpha << options.sorted << '\n';
    os << "  help: " << std::boolalpha << options.help << '\n';
    os << "  files:\n";
    for (const auto& file : options.files)
    {
        os << "    " << file << '\n';
    }
    return os;
}