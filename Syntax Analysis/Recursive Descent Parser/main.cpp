// This file contains the main function that uses the ExpressionParser class to parse and evaluate arithmetic expressions.


#include <iostream>
#include <string>
#include "ExpressionParser.h"

int main() {
    std::string input;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, input);

    try {
        ExpressionParser parser(input);
        if (parser.parse()) {
            std::cout << "Valid expression!" << std::endl;
        } else {
            std::cout << "Invalid expression!" << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cout << "Parsing error: " << ex.what() << std::endl;
    }

    return 0;
}