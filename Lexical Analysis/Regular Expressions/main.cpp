// This part of the code is written as an example to show the output of the code.
// According to your needs, you can change or delete this part.


#include <iostream>
#include <string>
#include "lexer.h"

// Print tokens
void print_tokens(std::vector<Token> tokens) {
    for (Token token : tokens) {
        std::string type_str;
        switch (token.type) {
            case INTEGER:
                type_str = "INTEGER";
                break;
            case FLOAT:
                type_str = "FLOAT";
                break;
            case IDENTIFIER:
                type_str = "IDENTIFIER";
                break;
            case OPERATOR:
                type_str = "OPERATOR";
                break;
            case PUNCTUATION:
                type_str = "PUNCTUATION";
                break;
            case KEYWORD:
                type_str = "KEYWORD";
                break;
            case STRING:
                type_str = "STRING";
                break;
            case COMMENT:
                type_str = "COMMENT";
                break;
            default:
                type_str = "UNKNOWN";
                break;
        }
        std::cout << "(" << type_str << ", " << token.value << ")" << std::endl;
    }
}

int main() {
    std::cout << "############################################################\n";
    std::cout << "  Welcome to the program tokenizer!\n";
    std::cout << "  Please enter a program to tokenize:\n";
    // Read input program
    std::string program;
    std::getline(std::cin, program);
    // Tokenize input program
    Lexer lexer;
    std::vector<Token> tokens = lexer.tokenize(program);
    // Print tokens
    std::cout << "\n  Here are the tokens in your program:\n";
    print_tokens(tokens);
    std::cout << "\n  (Thank you for using the program tokenizer!)\n";
    std::cout << "############################################################\n";
    return 0;
}
