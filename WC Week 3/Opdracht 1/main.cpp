#include <iostream>
#include "Rational.h"
#include "rational_calc.h"

int main(int argc, char* argv[]) {
    Rational::Rational a(7, 5);
    Rational::Rational b(45, 9);

//    auto c = calculate("3/4 + 67/-3");
//    auto c = calculate("7/5 * 45/9");
//    auto c = calculate("-143/57 / 32/9");
//    auto c = calculate("10/8 - 0/3");
//    auto c = calculate("4/5 - 9/-4");
//    auto c = calculate("5/6 ^ 2");
//    auto c = calculate("64/-8 ^ 3");
//    auto c = calculate("4/0 + 5/3");
//    auto c = calculate("sqrt 144/9");
//    auto c = calculate("sqrt -36/25");
//    auto c = calculate("sqrt 36/6");
//    auto c = calculate("-3/11 ^ 0");

//    print_rational(c);


    if(argc == 1){
        bool active = true;

        while (active){
            std::string expression_1;
            std::string expression_2;
            std::string expression_3;
            std::string expression;

            std::cout << "Enter expression: ";
            std::cin >> expression_1 >> expression_2 >> expression_3;

            expression = expression_1 + " " + expression_2 + " " + expression_3;
            auto c = calculate(expression);
            print_rational(c);
        }


    } else{
        process(argv[1]);
    }



    return 0;
}
