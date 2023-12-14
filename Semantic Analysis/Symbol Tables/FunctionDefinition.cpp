// The FunctionDefinition class represents a function definition and provides functionality to get and set its name and return type.


#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(const std::string& functionName, const std::string& returnType)
    : name(functionName), returnType(returnType) {}

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