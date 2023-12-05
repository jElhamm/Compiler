// This class represents a function definition with its name and return type.


#pragma once
#include <string>

class FunctionDefinition {
public:
    FunctionDefinition(const std::string& functionName, const std::string& returnType);
    std::string getName() const;
    std::string getReturnType() const;
    void setName(const std::string& functionName);
    void setReturnType(const std::string& returnType);
private:
    std::string name;
    std::string returnType;
};