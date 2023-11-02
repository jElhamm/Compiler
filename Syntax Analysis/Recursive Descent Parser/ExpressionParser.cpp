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
 
// Function to match the expected character in the input string
void ExpressionParser::match(char expected) {
    if (position < input.length() && input[position] == expected) {
        position++;
    } else {
        throw std::runtime_error("Expected '" + std::string(1, expected) + "'");
    }
}

// Function to parse a factor in the expression
bool ExpressionParser::factor() {
    if (position < input.length()) {
        if (isIdentifier(input[position]) || std::isdigit(input[position])) {
            position++;
        } else if (input[position] == '(') {
            position++;
            // Parse the expression within the parentheses
            if (!expression()) {
                return false;
            }
            // After parsing the expression, expect a closing parenthesis
            match(')');
        } else {
            throw std::runtime_error("Invalid character");
        }
    } else {
        throw std::runtime_error("Unexpected end of input");
    }
    return true;
}
 
// Function to parse a term in the expression
bool ExpressionParser::term() {
    if (!factor()) {
        return false;
    }
    while (position < input.length() && isOperator(input[position])) {
        position++;
        if (!factor()) {
            return false;
        }
    }
    return true;
}

// Function to parse an expression
bool ExpressionParser::expression() {
    if (!term()) {
        return false;
    }
    while (position < input.length() && isOperator(input[position])) {
        position++;
        if (!term()) {
            return false;
        }
    }
    return true;
}