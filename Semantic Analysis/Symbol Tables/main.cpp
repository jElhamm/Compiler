 /**
 * This program performs semantic analysis on user input source code. 
 * It reads the source code from the user line by line until the user types 'exit'. 
 * The SourceCodeAnalyzer class is responsible for analyzing the source code and performing the necessary semantic checks.
 **/



#include <iostream>
#include <string>
#include "SourceCodeAnalyzer.h"


int main() {
    // Perform semantic analysis on the user input source code
    SourceCodeAnalyzer codeAnalyzer;
    std::string sourceCode;
    std::cout << "---> Enter the source code (type 'exit' to quit):\n";
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