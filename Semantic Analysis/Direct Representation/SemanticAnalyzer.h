// Class representing a Semantic Analyzer  --->  header file
// It performs analysis on source code to check for variable and function declarations,
// and detects errors related to undefined names


#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H
#include <string>
#include <unordered_set>
#include <unordered_map>

class SemanticAnalyzer {
public:
    bool isDeclared(const std::string& variable);
    void declareVariable(const std::string& variable, const std::string& type);
    void declareFunction(const std::string& functionName, const std::string& returnType);
    void analyze(const std::string& sourceCode);
    std::unordered_set<std::string>& getDeclaredVariables();
    std::unordered_set<std::string>& getDeclaredFunctions();
    std::unordered_map<std::string, std::string>& getVariableTypes();
    std::unordered_map<std::string, std::string>& getFunctionReturnTypes();
private:
    std::unordered_set<std::string> declaredVariables;
    std::unordered_set<std::string> declaredFunctions;
    std::unordered_map<std::string, std::string> variableTypes;
    std::unordered_map<std::string, std::string> functionReturnTypes;
};

#endif 