// This code defines a Tokenizer class that can be used to tokenize a given input string into a vector of tokens, 
// where each token has a type and a value. The class uses a set of functions to identify the different types of 
// characters in the input string, and a state machine to determine the type of each token based on the current state.


#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>

// Enum to represent the different states the tokenizer can be in
enum State {
    START,
    IDENTIFIER,
    INTEGER,
    FLOAT,
    OPERATOR,
    STRING,
    COMMENT,
    ERROR
};

// Enum to represent the different types of tokens
enum TokenType {
    IDENTIFIER_TOKEN,
    INTEGER_TOKEN,
    FLOAT_TOKEN,
    OPERATOR_TOKEN,
    STRING_TOKEN,
    COMMENT_TOKEN,
    ERROR_TOKEN,
    DELIMITER_TOKEN
};

// Struct to represent a token
struct Token {
    TokenType type;
    std::string value;
};

// Class to tokenize a given input string
class Tokenizer {
public:
    Tokenizer(std::string input);
    // Function to tokenize the input string and return a vector of tokens
    std::vector<Token> tokenize();

private:
    std::string input_;

    // Functions to check if a character belongs to a certain category
    bool isLetter(char c);
    bool isDigit(char c);
    bool isUnderscore(char c);
    bool isOperator(char c);
    bool isDelimiter(char c);
    bool isWhitespace(char c);
    bool isQuote(char c);
    bool isComment(char c);
    bool isFloat(char c);
    bool isExponent(char c);
    bool isSign(char c);
    bool isHex(char c);
    bool isOctal(char c);
    bool isBinary(char c);
    bool isEscape(char c);
    bool isInvalid(char c);

    // Function to determine the token type based on the current state
    TokenType getTokenType(State state);
};

#endif // TOKENIZER_H