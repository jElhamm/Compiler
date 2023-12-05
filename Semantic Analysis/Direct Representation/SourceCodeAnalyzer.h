// This class analyzes source code and checks for function calls.


#pragma once
#include <string>
#include "SemanticAnalyzer.h"

class SourceCodeAnalyzer {
public:
    void analyzeSourceCode(const std::string& sourceCode);
private:
    SemanticAnalyzer analyzer;
    void analyzeFunctionCalls(const std::string& sourceCode);
};