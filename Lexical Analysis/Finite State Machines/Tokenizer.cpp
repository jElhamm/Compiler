// This code defines a class called Tokenizer which tokenizes an input string and returns a vector of tokens. 
// The tokenizer uses a state machine to determine the type of each character in the input string and group them into tokens. 


#include "Tokenizer.h"

// Constructor to initialize the input string
Tokenizer::Tokenizer(std::string input) : input_(input) {}

// Function to tokenize the input string and return a vector of tokens
std::vector<Token> Tokenizer::tokenize() {
    std::vector<Token> tokens;
    State state = START;
    std::string tokenValue;

    // Loop through each character in the input string
    for (int i = 0; i < input_.length(); i++) {
        char c = input_[i];
        // Switch statement to handle different states of the tokenizer
        switch (state) {
            case START:
                // Check the type of the current character and update the state accordingly
                if (isLetter(c)) {
                    state = IDENTIFIER;
                    tokenValue += c;
                } else if (isDigit(c)) {
                    state = INTEGER;
                    tokenValue += c;
                } else if (isOperator(c)) {
                    state = OPERATOR;
                    tokenValue += c;
                } else if (isDelimiter(c)) {
                    tokens.push_back({getTokenType(state), std::string(1, c)});
                    state = START;
                    tokenValue = "";
                    tokens.push_back({DELIMITER_TOKEN, std::string(1, c)});
                } else if (isWhitespace(c)) {
                    state = START;
                    tokenValue = "";
                } else if (isQuote(c)) {
                    state = STRING;
                    tokenValue += c;
                } else if (isComment(c)) {
                    if (i + 1 < input_.length() && input_[i + 1] == '/') {
                        state = COMMENT;
                        i++;
                    } else {
                        state = OPERATOR;
                        tokenValue += c;
                    }
                } else if (isInvalid(c)) {
                    state = ERROR;
                    tokenValue += c;
                }
                break;

            case IDENTIFIER:
                // If the current character belongs to the identifier, add it to the token value
                if (isLetter(c) || isDigit(c) || isUnderscore(c)) {
                    tokenValue += c;
                } else {
                    // If the current character doesn't belong to the identifier, add the token to the vector and reset the state
                    tokens.push_back({getTokenType(state), tokenValue});
                    state = START;
                    tokenValue = "";
                    i--;
                }
                break;

            case INTEGER:
                    // If the current character belongs to the integer, add it to the token value
                if (isDigit(c)) {
                    tokenValue += c;
                } else if (isFloat(c)) {
                    // If the current character is a decimal point, update the state to FLOAT
                    state = FLOAT;
                    tokenValue += c;
                } else if (isExponent(c)) {
                    // If the current character is an exponent, update the state to FLOAT and add the exponent to the token value
                    state = FLOAT;
                    tokenValue += c;
                    if (i + 1 < input_.length() && isSign(input_[i + 1])) {
                        i++;
                        tokenValue += input_[i];
                    }
                } else if (c == 'x' || c == 'X') {
                    // If the current character is 'x' or 'X', update the state to INTEGER and add it to the token value
                    state = INTEGER;
                    tokenValue += c;
                } else if (c == 'b' || c == 'B') {
                    // If the current character is 'b' or 'B', update the state to INTEGER and add it to the token value
                    state = INTEGER;
                    tokenValue += c;
                } else if (c == 'o' || c == 'O') {
                    // If the current character is 'o' or 'O', update the state to INTEGER and add it to the token value
                    state = INTEGER;
                    tokenValue += c;
                } else {
                    // If the current character doesn't belong to the integer, add the token to the vector and reset the state
                    tokens.push_back({getTokenType(state), tokenValue});
                    state = START;
                    tokenValue = "";
                    i--;
                }
                break;

            case FLOAT:
                    // If the current character belongs to the float, add it to the token value
                if (isDigit(c)) {
                    tokenValue += c;
                } else if (isExponent(c)) {
                    // If the current character is an exponent, add it to the token value
                    state = FLOAT;
                    tokenValue += c;
                    if (i + 1 < input_.length() && isSign(input_[i + 1])) {
                        i++;
                        tokenValue += input_[i];
                    }
                } else {
                    // If the current character doesn't belong to the float, add the token to the vector and reset the state
                    tokens.push_back({getTokenType(state), tokenValue});
                    state = START;
                    tokenValue = "";
                    i--;
                }
                break;

            case OPERATOR:
                    // If the current character belongs to the operator, add it to the token value
                if (isOperator(c)) {
                    tokenValue += c;
                } else {
                    // If the current character doesn't belong to the operator, add the token to the vector and reset the state
                    tokens.push_back({getTokenType(state), tokenValue});
                    state = START;
                    tokenValue = "";
                    i--;
                }
                break;

            case STRING:
                    // If the current character is an escape character, add the next character to the token value
                if (isEscape(c)) {
                    if (i + 1 < input_.length()) {
                        tokenValue += c;
                        i++;
                        tokenValue += input_[i];
                    } else {
                        state = ERROR;
                        tokenValue += c;
                    }
                } else if (isQuote(c)) {
                    // If the current character is a quote, add the token to the vector and reset the state
                    tokenValue += c;
                    tokens.push_back({getTokenType(state), tokenValue});
                    state = START;
                    tokenValue = "";
                } else {
                    // If the current character belongs to the string, add it to the token value
                    tokenValue += c;
                }
                break;

            case COMMENT:
                    // If the current character is a newline, reset the state
                if (c == '\n') {
                    state = START;
                    tokenValue = "";
                } else {
                    // If the current character belongs to the comment, add it to the token value
                    tokenValue += c;
                }
                break;

            case ERROR:
                    // If the current character belongs to the error, add it to the token value
                if (isInvalid(c)) {
                    tokenValue += c;
                } else {
                    // If the current character doesn't belong to the error, add the token to the vector and reset the state
                    tokens.push_back({getTokenType(state), tokenValue});
                    state = START;
                    tokenValue = "";
                    i--;
                }
                break;
        }
    }
    // If the state is not START at the end of the loop, add the token to the vector
    if (state != START) {
        tokens.push_back({getTokenType(state), tokenValue});
    }
    return tokens;
}
 

// Functions to check if a character belongs to a certain category
bool Tokenizer::isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool Tokenizer::isDigit(char c) {
    return c >= '0' && c <= '9';
}
bool Tokenizer::isUnderscore(char c) {
    return c == '_';
}
bool Tokenizer::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == '<' || c == '>' || c == '!' || c == '&' || c == '|';
}
bool Tokenizer::isDelimiter(char c) {
    return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == ';' || c == ':';
}
bool Tokenizer::isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
bool Tokenizer::isQuote(char c) {
    return c == '"' || c == '\'';
}
bool Tokenizer::isComment(char c) {
    return c == '/';
}
bool Tokenizer::isFloat(char c) {
    return c == '.';
}
bool Tokenizer::isExponent(char c) {
    return c == 'e' || c == 'E';
}
bool Tokenizer::isSign(char c) {
    return c == '+' || c == '-';
}
bool Tokenizer::isHex(char c) {
    return (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || isDigit(c);
}
bool Tokenizer::isOctal(char c) {
    return c >= '0' && c <= '7';
}
bool Tokenizer::isBinary(char c) {
    return c == '0' || c == '1';
}
bool Tokenizer::isEscape(char c) {
    return c == '\\';
}
bool Tokenizer::isInvalid(char c) {
    return !isLetter(c) && !isDigit(c) && !isUnderscore(c) && !isOperator(c) && !isDelimiter(c) && !isWhitespace(c) && !isQuote(c) && !isComment(c);
}
 

// Token Type
TokenType Tokenizer::getTokenType(State state) {
    switch (state) {
        case IDENTIFIER:
            return IDENTIFIER_TOKEN;
        case INTEGER:
            return INTEGER_TOKEN;
        case FLOAT:
            return FLOAT_TOKEN;
        case OPERATOR:
            return OPERATOR_TOKEN;
        case STRING:
            return STRING_TOKEN;
        case COMMENT:
            return COMMENT_TOKEN;
        case ERROR:
            return ERROR_TOKEN;
        default:
            return ERROR_TOKEN;
    }
}