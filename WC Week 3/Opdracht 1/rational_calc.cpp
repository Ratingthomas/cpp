//
// Created by Thomas Levels on 11/03/2024.
//

#include "rational_calc.h"
#include <iostream>
#include <sstream>
#include <fstream>

Rational::Rational calculate(std::string expression){
    std::istringstream iss (expression);
    std::string first_frac;
    std::string second_frac;
    char action;


    if(expression.starts_with("sqrt")){
        std::string sqrt;
        std::string frac;
        iss >> sqrt >> frac;
        Rational::Rational a(frac);

        auto c = a.sqrt();
        return c;
    } else{
        iss >> first_frac >> action >> second_frac;

        if(action == '^'){
            Rational::Rational a(first_frac);
            int pow_ = std::stoi(second_frac);

            auto c = a.pow(pow_);
            return c;
        } else{
            Rational::Rational a(first_frac);
            Rational::Rational b(second_frac);

            if(action == '+'){
                auto c = a.add(b);
                return c;
            } else if(action == '*'){
                auto c = a.mul(b);
                return c;
            } else if(action == '/'){
                auto c = a.div(b);
                return c;
            } else if(action == '-'){
                auto c = a.sub(b);
                return c;
            } else{
                return Rational::Rational{0, 0};
            }
        }
    }
}

void print_rational(Rational::Rational c){
    if(c.num() == 1 && c.den() == 0){
        std::cout << c.num() << "/" << c.den() << " (+inf) \n";
    }
    else if(c.num() == 0 && c.den() == 0){
        std::cout << c.num() << "/" << c.den() << " (NaN) \n";
    }
    else{
        std::cout << c.num() << "/" << c.den() << "\n";
    }
}

void process(std::string name){
    std::ifstream input{name};
    std::ofstream output{"input_file.out"};

    if(input.fail()){
        throw std::logic_error("Could not open file ");
    }

    std::string line;

    while (std::getline(input, line)){
        auto c = calculate(line);
        if(c.num() == 1 && c.den() == 0){
            output << c.num() << "/" << c.den() << " (+inf)\n";
        }
        else if(c.num() == 0 && c.den() == 0){
            output << c.num() << "/" << c.den() << " (NaN)\n";
        }
        else{
            output << c.num() << "/" << c.den() << "\n";
        }
    }

    output.close();
}