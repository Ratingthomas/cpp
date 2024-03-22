#include "options.h"
#include <stdexcept>

namespace repeat
{

Options parse(int argc, char * argv[])
{
    (void)argc; (void)argv;


    // TODO: implement this function and return the actual, parsed options
    Options result{};
    for (auto i{1}; i < argc; ++i)
    {
        // convert argv[i] to string
        std::string arg{ argv[i] };
        if(arg.starts_with("-")){
            for (size_t j = 0; j < arg.length(); ++j) {
                if(arg[j] == 'n'){
                    result.append_newline = true;
                } else if(arg[j] == 'C'){
                    result.capitalize = true;
                } else if(arg[j] == 'h'){
                    result.help = true;
                }
            }
        }


        if(argc-1 == i){
            result.text = arg;
        }
        else if (arg == "-n" || arg == "--newline"){
            result.append_newline = true;
        }

        else if(arg == "-h" || arg == "--help"){
            result.help = true;
        }

        else if(arg == "-C" || arg == "--capitalize"){
            result.capitalize = true;
        }

        else if(arg.starts_with("--color=")){
            std::size_t found = arg.find("=");
            if(found+1 == arg.size()){
                std::cout << "WARNING: Color value not set! Defaulting to none \n";
                result.color = Color::none;
            } else{
                std::string color = arg.substr(found+1, arg.size());
                if(color == "blue" || color == "red" || color == "green"){
                    result.color = from_string(color);
                } else{
                    std::cout << "WARNING: Color value not valid! Defaulting to none \n";
                    result.color = Color::none;
                }
            }
        }

        else if(arg.starts_with("--repeat=")){
            std::size_t found = arg.find("=");
            if(found+1 == arg.size()){
                std::cout << "WARNING: Repeat value not set! Defaulting to -1 \n";
                result.repeat = -1;
            } else{
                std::string num = arg.substr(found+1, arg.size());
                result.repeat = std::stoi(num);
            }
        }
//        else{
//            std::cout << "WARNING: " << arg << " is not a option \n";
//        }
    }

    return result;
}

Color from_string(const std::string& text)
{
    if (text == "red")
    {
        return Color::red;
    }
    else if (text == "green")
    {
        return Color::green;
    }
    else if (text == "blue")
    {
        return Color::blue;
    }
    else if (text == "none")
    {
        return Color::none;
    }
    else
    {
        throw std::invalid_argument{"Invalid color"};
    }
}

std::ostream& operator<<(std::ostream& out, Color color)
{
    switch(color)
    {
        case Color::red:
            return out << "red";
        case Color::green:
            return out << "green";
        case Color::blue:
            return out << "blue";
        case Color::none:
            return out << "none";
        default:
            return out << "unknown";
    }
}

std::ostream& operator<<(std::ostream& out, Options const& options)
{
    out << "Options:\n";
    out << "  help: " << std::boolalpha << options.help << '\n';
    out << "  capitalize: " << std::boolalpha << options.capitalize << '\n';
    out << "  append_newline: " << std::boolalpha << options.append_newline << '\n';
    out << "  color: " << options.color << '\n';
    out << "  repeat: " << options.repeat << '\n';
    out << "  text: " << options.text << '\n';
    return out;
}
    
} // namespace repeat
