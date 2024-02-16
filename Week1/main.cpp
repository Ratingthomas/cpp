#include <iostream>
#include <fstream>
#include <sstream>

bool is_empty_line(std::string line){
    if(line.empty()){
        return true;
    } else if (line.find_first_not_of(" \t") == std::string::npos) {
        return true;
    }
    else return false;
}

std::string clean_line(std::string line){
    std::istringstream iss{ line };
    std::string word;

    bool first = true;
    std::string output;

    while (iss >> word){
        if(!ispunct(word[0])){
            if(!first){
                output+= " ";
            } else{
                first = false;
            }
        }
        output += word;
    }

    return output;
}

void check_for_file_name(int argc){
    if(argc < 2){
        std::cout << "File name not given " << std::endl << "example: ./main.a file_name" << std::endl;
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    std::string myText;

    check_for_file_name(argc);

    std::ifstream input{argv[1]};
    std::string file_name = argv[1];

    if(input.fail()){
        std::cout << "File not found" << std::endl;
        exit(0);
    }

    int found = file_name.find_first_of(".");
    std::string new_name = file_name.replace(found, file_name.length(), ".clean");

    std::ofstream output{new_name};

    while (std::getline(input, myText)) {
        if(!is_empty_line(myText)){
            std::string result = clean_line(myText);
            output << result << "\n";
        }
    }
    output.close();
    return 0;
}
