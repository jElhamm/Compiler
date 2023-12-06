// This code defines the FunctionDefinition class, which represents a function definition in the source code.
// It provides methods to get and set the function name and return type.


#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(const std::string& functionName, const std::string& returnType) : name(functionName), returnType(returnType) {}

std::string FunctionDefinition::getName() const {
    return name;
}
void FunctionDefinition::setName(const std::string& functionName) {
    name = functionName;
}
std::string FunctionDefinition::getReturnType() const {
    return returnType;
}
void FunctionDefinition::setReturnType(const std::string& returnType) {
    this->returnType = returnType;
}