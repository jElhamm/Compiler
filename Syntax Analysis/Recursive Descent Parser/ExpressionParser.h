/**
 * The ExpressionParser class represents a recursive descent parser for arithmetic expressions.
 *
 * This class is responsible for parsing arithmetic expressions provided as input strings.
 * It supports basic operators and identifiers, and can evaluate the expressions to determine their validity.
 **/


#pragma once
#include <string>
#include <stdexcept>

class ExpressionParser {
public:
    explicit ExpressionParser(const std::string& expression);
    bool parse();

private:
    std::string input;
    size_t position;

    bool isOperator(char op) const;
    bool isIdentifier(char ch) const;
    void match(char expected);
    bool factor();
    bool term();
    bool expression();
};