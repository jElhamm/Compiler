// This part of the code is written as an example to show the output of the code.
// and takes an input program from the user and tokens it using the Tokenizer class. 
// It then prints the type and value of each token.



#include <iostream>
#include <string>
#include <vector>
#include "Tokenizer.h"

int main() {
    // Prompt the user for input
    cout << "##########################################################################\n";
    cout << "  Welcome to the program tokenizer!\n";
    cout << "  Please enter a program to tokenize:\n";
    string input;
    getline(cin, input);

    // Tokenize the input using the Tokenizer class
    Tokenizer tokenizer(input);
    vector<Token> tokens = tokenizer.tokenize();

    // Print the type and value of each token
    for (Token token : tokens) {
        cout << "Type: ";
        switch (token.type) {
            case IDENTIFIER_TOKEN:
                cout << "IDENTIFIER";
                break;
            case INTEGER_TOKEN:
                cout << "INTEGER";
                break;
            case FLOAT_TOKEN:
                cout << "FLOAT";
                break;
            case OPERATOR_TOKEN:
                cout << "OPERATOR";
                break;
            case STRING_TOKEN:
                cout << "STRING";
                break;
            case COMMENT_TOKEN:
                cout << "COMMENT";
                break;
            case DELIMITER_TOKEN:
                cout << "DELIMITER";
                break;
            default:
                cout << "UNKNOWN";
                break;
        }
        cout << ", Value: " << token.value << endl;
    }

    return 0;
}