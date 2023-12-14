// The FunctionDefinition class represents a function definition and provides functionality to manage the function's name and return type.


#ifndef FUNCTIONDEFINITION_H
#define FUNCTIONDEFINITION_H
#include <string>

class FunctionDefinition {
public:
    FunctionDefinition(const std::string& functionName, const std::string& returnType);
    std::string getName() const;
    void setName(const std::string& functionName);
    std::string getReturnType() const;
    void setReturnType(const std::string& returnType);

private:
    std::string name;
    std::string returnType;
};

#endif