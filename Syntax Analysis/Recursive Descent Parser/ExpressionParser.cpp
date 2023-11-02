#include "ExpressionParser.h"


ExpressionParser::ExpressionParser(const std::string& expression) : input(expression), position(0) {}

// Parses the expression and checks if it is fully parsed.
bool ExpressionParser::parse() {
    if (expression()) {
        return position == input.length();
    }
    return false;
}

// Checks if a character is an operator (+, -, *, /).
bool ExpressionParser::isOperator(char op) const {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

// Checks if a character is a valid identifier (alphabetical character).
bool ExpressionParser::isIdentifier(char ch) const {
    return std::isalpha(ch);
}
 