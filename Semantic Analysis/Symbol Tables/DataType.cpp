// The DataType class represents a data type and provides functionality to get and set its name.


#include "DataType.h"

DataType::DataType(const std::string& typeName) : name(typeName) {}

std::string DataType::getName() const {
    return name;
}

void DataType::setName(const std::string& typeName) {
    name = typeName;
}