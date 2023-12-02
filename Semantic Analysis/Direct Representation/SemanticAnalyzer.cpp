/** 
 * This program demonstrates the SemanticAnalyzer class.
 * SemanticAnalyzer is responsible for analyzing source code and performing semantic analysis.
 * It tracks declared variables and functions, and checks for undefined names.
 * It provides methods to declare variables and functions, as well as retrieve information about them.
 * This is the implementation file for the SemanticAnalyzer class (SemanticAnalyzer.cpp).
 * Note: This class assumes C++ source code as input.
 **/


#include "SemanticAnalyzer.h"
#include <iostream>
#include <sstream>
using namespace std


bool SemanticAnalyzer::isDeclared(const std::string& variable) {
    return declaredVariables.count(variable) > 0;
}
void SemanticAnalyzer::declareVariable(const std::string& variable, const std::string& type) {
    declaredVariables.insert(variable);
    variableTypes[variable] = type;
}
void SemanticAnalyzer::declareFunction(const std::string& functionName, const std::string& returnType) {
    declaredFunctions.insert(functionName);
    functionReturnTypes[functionName] = returnType;
}
std::unordered_set<std::string>& SemanticAnalyzer::getDeclaredVariables() {
    return declaredVariables;
}
std::unordered_set<std::string>& SemanticAnalyzer::getDeclaredFunctions() {
    return declaredFunctions;
}
std::unordered_map<std::string, std::string>& SemanticAnalyzer::getVariableTypes() {
    return variableTypes;
}
std::unordered_map<std::string, std::string>& SemanticAnalyzer::getFunctionReturnTypes() {
    return functionReturnTypes;
}