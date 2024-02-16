#include <iostream>

int main(int argc, char* argv[])
{
    int single_dash = 0;
    int double_dash = 0;
    int no_dash = 0;

    if(argc > 1){
        for (int i = 1; i < argc; ++i) {
            std::string argument = argv[i];

            if(argument.starts_with("--")){
                single_dash++;
            } else if(argument.starts_with("-")){
                double_dash++;
            } else{
                no_dash++;
            }
        }

        for (int i = 0; i < argc; ++i) {
            std::string argument = argv[i];
            if(argument[0] == '-' && argument[1] != '-'){
                std::cout << argument << std::endl;
            }
        }
        for (int i = 0; i < argc; ++i) {
            std::string argument = argv[i];
            if(argument[0] == '-' && argument[1] == '-'){
                std::cout << argument << std::endl;
            }
        }
        for (int i = 0; i < argc; ++i) {
            std::string argument = argv[i];
            if(argument[0] != '-' && argument[1] != '-'){
                std::cout << argument << std::endl;
            }
        }

        std::cout << single_dash << " " << double_dash << " " << no_dash << std::endl;
    } else{
        std::cout << "No arguments" << std::endl;
    }

}
