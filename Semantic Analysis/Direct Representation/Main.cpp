/**
 * This code demonstrates a simple source code analyzer program.
 * It takes input from the user (line by line) until the user enters 'exit'.
 * The entered source code is stored in a string.
 * The codeAnalyzer object of the SourceCodeAnalyzer class is then used to analyze the source code.
 * Finally, the program exits.
 **/



#include <iostream>
#include <sstream>
#include "SourceCodeAnalyzer.h"
using namespace std;

int main() {
    SourceCodeAnalyzer codeAnalyzer;
    std::string sourceCode;
    cout << "---> Enter the source code (type 'exit' to quit):\n";
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "exit") {
            break;
        }
        sourceCode += line + '\n';
    }
    codeAnalyzer.analyzeSourceCode(sourceCode);
    return 0;
}