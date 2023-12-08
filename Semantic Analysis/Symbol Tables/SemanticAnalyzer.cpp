/** This program contains the implementation of a SemanticAnalyzer class, 
 * which analyzes source code and performs tasks like variable declaration, 
 * variable type checking, function declaration, etc.
 **/

 

#include "SemanticAnalyzer.h"
using namespace std;


// Check if a variable is declared
bool SemanticAnalyzer::isDeclared(const std::string& variable) {
    return declaredVariables.count(variable) > 0;
}
// Declare a variable with a given type
void SemanticAnalyzer::declareVariable(const std::string& variable, const std::string& type) {
    declaredVariables.insert(variable);
    variableTypes[variable] = type;
}
// Declare a function with a given return type
void SemanticAnalyzer::declareFunction(const std::string& functionName, const std::string& returnType) {
    declaredFunctions.insert(functionName);
    functionReturnTypes[functionName] = returnType;
}
// Analyze the source code
void SemanticAnalyzer::analyze(const std::string& sourceCode) {
    std::vector<std::string> tokens = tokenize(sourceCode);
    for (size_t index = 0; index < tokens.size(); ++index) {
        const std::string& token = tokens[index];
        if (token == "var") {
            std::string variableName;
            std::string variableType;
            std::string assignmentToken;

            if (isVariableAssignment(tokens, index)) {
                std::vector<std::string> assignmentTokens = tokenizeVariableAssignment(tokens, index);
                variableName = assignmentTokens[0];
                variableType = assignmentTokens[2];
                assignmentToken = assignmentTokens[1];
                index += 2;
            } else {
                variableName = token;
                variableType = tokens[index + 1];
            }
            declareVariable(variableName, variableType);
            cout << "Declared variable: " << variableType << " " << variableName << "\n";
        } else if (isDeclared(token)) {
            cout << "Used variable: " << token << " (" << variableTypes[token] << ")\n";
        } else if (declaredFunctions.count(token)) {
            cout << "Used function: " << token << " (" << functionReturnTypes[token] << ")\n";
        } else {
            cout << "Error: Undefined name used - " << token << "\n";
        }
    }
}
 