// Class for performing semantic analysis on source code


#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H
#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>


class SemanticAnalyzer {
public:
    bool isDeclared(const std::string& variable);                                               // Check if a variable is declared
    void declareVariable(const std::string& variable, const std::string& type);                 // Declare a variable with a given type
    void declareFunction(const std::string& functionName, const std::string& returnType);       // Declare a function with a given return type
    void analyze(const std::string& sourceCode);                                                // Analyze the source code
    std::unordered_set<std::string>& getDeclaredVariables();                                    // Get the set of declared variables
    std::unordered_set<std::string>& getDeclaredFunctions();                                    // Get the set of declared functions
    std::unordered_map<std::string, std::string>& getVariableTypes();                           // Get the mapping of variable names to their types
    std::unordered_map<std::string, std::string>& getFunctionReturnTypes();                     // Get the mapping of function names to their return types

private:
    std::unordered_set<std::string> declaredVariables;
    std::unordered_set<std::string> declaredFunctions;
    std::unordered_map<std::string, std::string> variableTypes;
    std::unordered_map<std::string, std::string> functionReturnTypes;
    std::vector<std::string> tokenize(const std::string& sourceCode);                           // Tokenize the source code into individual tokens
    bool isVariableAssignment(const std::vector<std::string>& tokens, size_t index);            // Check if a token represents a variable assignment

    // Tokenize a variable assignment into variable name, assignment token, and variable type
    std::vector<std::string> tokenizeVariableAssignment(const std::vector<std::string>& tokens, size_t index);
};

#endif