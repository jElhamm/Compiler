// This code defines the DataType class, which represents a data type in the source code.
// It provides methods to get and set the name of the data type.


#include "DataType.h"

DataType::DataType(const std::string& typeName) : name(typeName) {}

std::string DataType::getName() const {
    return name;
}
void DataType::setName(const std::string& typeName) {
    name = typeName;
}