// This class defines a lexer that can tokenize a given program string into a vector of tokens.


#include "lexer.h"
#include <iostream>
#include <regex>

// Define regular expressions for tokens
Lexer::Lexer() {
    integer = std::regex("\d+");                                                                                            // Regular expression for integers
    floating_point = std::regex("\d+\.\d+");                                                                                // Regular expression for floating point numbers
    identifier = std::regex("[a-zA-Z_]\w*");                                                                                // Regular expression for identifiers
    op = std::regex("\+|\-|\*|\/|\%|\=|\>|\<|\!|\&|\||\^|\<\<|\>\>|\(|\)|\{|\}|\[|\]|\,|\;|\.");                            // Regular expression for operators
    keyword = std::regex("\b(int|float|double|char|void|if|else|for|while|do|switch|case|break|continue|return)\W");        // Regular expression for keywords
    string_literal = std::regex(R"("[^"\]*(\.[^"\]*)*")");                                                                  // Regular expression for string literals
    comment = std::regex("//.*|/\*.*?\*/");                                                                                 // Regular expression for comments
    punctuation = std::regex("\(|\)|\{|\}|\[|\]|\,|\;|\.");                                                                 // Regular expression for punctuation
}

std::vector<Token> Lexer::tokenize(std::string program) {
    std::vector<Token> tokens;
    std::smatch match;
    while (!program.empty()) {
        if (std::regex_search(program, match, integer)) {
            tokens.push_back({INTEGER, match[0]});                                  // Add integer token to vector
        } else if (std::regex_search(program, match, floating_point)) {
            tokens.push_back({FLOAT, match[0]});                                    // Add floating point token to vector
        } else if (std::regex_search(program, match, identifier)) {
            tokens.push_back({IDENTIFIER, match[0]});                               // Add identifier token to vector
        } else if (std::regex_search(program, match, op)) {
            tokens.push_back({OPERATOR, match[0]});                                 // Add operator token to vector
        } else if (std::regex_search(program, match, punctuation)) {
            tokens.push_back({PUNCTUATION, match[0]});                              // Add punctuation token to vector
        } else if (std::regex_search(program, match, keyword)) {
            tokens.push_back({KEYWORD, match[0]});                                  // Add keyword token to vector
        } else if (std::regex_search(program, match, string_literal)) {
            tokens.push_back({STRING, match[0]});                                   // Add string literal token to vector
        } else if (std::regex_search(program, match, comment)) {
            tokens.push_back({COMMENT, match[0]});                                  // Add comment token to vector
        } else {
            // Invalid token
            std::cerr << "Invalid token: " << program[0] << std::endl;
            program = program.substr(1);
            continue;
        }
        program = match.suffix().str();                                             // Update program string to exclude matched token
    }
    return tokens;                                                                  // Return vector of tokens
}