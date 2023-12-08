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
 
// Tokenize the source code into individual tokens
std::vector<std::string> SemanticAnalyzer::tokenize(const std::string& sourceCode) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(sourceCode);
    std::string token;
    while (tokenStream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
// Check if a token represents a variable assignment
bool SemanticAnalyzer::isVariableAssignment(const std::vector<std::string>& tokens, size_t index) {
    return std::find(tokens.begin() + index, tokens.end(), "=") != tokens.end();
}
// Tokenize a variable assignment into variable name, assignment token, and variable type
std::vector<std::string> SemanticAnalyzer::tokenizeVariableAssignment(const std::vector<std::string>& tokens, size_t index) {
    std::vector<std::string> assignmentTokens;
    std::string variableName;
    std::string assignmentToken;
    std::string variableType;
    if (index < tokens.size() - 2) {
        variableName = tokens[index];                   // Extract the variable name from the tokens
        assignmentToken = tokens[index + 1];            // Extract the assignment token (=) from the tokens
        variableType = tokens[index + 2];               // Extract the variable type from the tokens
    }
    assignmentTokens.push_back(variableName);           // Store the variable name in the assignmentTokens vector
    assignmentTokens.push_back(assignmentToken);        // Store the assignment token in the assignmentTokens vector
    assignmentTokens.push_back(variableType);           // Store the variable type in the assignmentTokens vector
    return assignmentTokens;                            // Return the vector of assignment tokens
}


// Get the set of declared variables
std::unordered_set<std::string>& SemanticAnalyzer::getDeclaredVariables() {
    return declaredVariables;
}
// Get the set of declared functions
std::unordered_set<std::string>& SemanticAnalyzer::getDeclaredFunctions() {
    return declaredFunctions;
}
// Get the mapping of variable names to their types
std::unordered_map<std::string, std::string>& SemanticAnalyzer::getVariableTypes() {
    return variableTypes;
}
// Get the mapping of function names to their return types
std::unordered_map<std::string, std::string>& SemanticAnalyzer::getFunctionReturnTypes() {
    return functionReturnTypes;
}