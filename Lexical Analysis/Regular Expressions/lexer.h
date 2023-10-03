// Header file for the Lexer class, which tokenizes program strings into a vector of tokens.


#ifndef LEXER_H
#define LEXER_H
#include <regex>
#include <string>
#include <vector>

// Define token types
enum TokenType {
    INTEGER,
    FLOAT,
    IDENTIFIER,
    OPERATOR,
    PUNCTUATION,
    KEYWORD,
    STRING,
    COMMENT
};

// Define token structure
struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer();
    std::vector<Token> tokenize(std::string program);
private:
    std::regex integer;
    std::regex floating_point;
    std::regex identifier;
    std::regex op;
    std::regex keyword;
    std::regex string_literal;
    std::regex comment;
    std::regex punctuation;
};

#endif // LEXER_H