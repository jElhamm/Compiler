// This class represents a data type with its name.


#pragma once
#include <string>

class DataType {
public:
    DataType(const std::string& typeName);
    std::string getName() const;
    void setName(const std::string& typeName);
private:
    std::string name;
};