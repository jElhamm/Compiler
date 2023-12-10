// This class, SourceCodeAnalyzer, is responsible for analyzing source code and identifying function calls.


#include "SourceCodeAnalyzer.h"


void SourceCodeAnalyzer::analyzeSourceCode(const std::string& sourceCode) {
    analyzer.analyze(sourceCode);
    analyzeFunctionCalls(sourceCode);
}
void SourceCodeAnalyzer::analyzeFunctionCalls(const std::string& sourceCode) {
    std::vector<std::string> tokens = tokenize(sourceCode);
    for (const std::string& token : tokens) {
        if (analyzer.isDeclared(token)) {
            if (analyzer.getDeclaredFunctions().count(token)) {
                std::cout << "Called function: " << token << " (" << analyzer.getFunctionReturnTypes()[token] << ")" << std::endl;
            } else {
                std::cout << " ! Error: Undefined function called - " << token << std::endl;
            }
        }
    }
}
std::vector<std::string> SourceCodeAnalyzer::tokenize(const std::string& sourceCode) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(sourceCode);
    std::string token;
    while (tokenStream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}