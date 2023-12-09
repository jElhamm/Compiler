/*
 * This program is a source code analyzer that analyzes source code to perform certain tasks.
 * It includes the SourceCodeAnalyzer class, which serves as the main analyzer for the source code.
 * The main purpose of this program is to analyze function calls in the source code.
 * The SourceCodeAnalyzer class utilizes the SemanticAnalyzer class to perform semantic analysis tasks.
 * Additionally, it includes the necessary headers for data types and function definitions.
 */



#ifndef SOURCECODEANALYZER_H
#define SOURCECODEANALYZER_H
#include <iostream>
#include <string>
#include <vector>
#include "SemanticAnalyzer.h"
#include "DataType.h"
#include "FunctionDefinition.h"

class SourceCodeAnalyzer {
public:
    void analyzeSourceCode(const std::string& sourceCode);

private:
    SemanticAnalyzer analyzer;
    void analyzeFunctionCalls(const std::string& sourceCode);
    std::vector<std::string> tokenize(const std::string& sourceCode);
};

#endif