// This class represents a data type and provides functionality to get and set the name of the data type.


#ifndef DATATYPE_H
#define DATATYPE_H
#include <string>


class DataType {
public:
    DataType(const std::string& typeName);
    std::string getName() const;
    void setName(const std::string& typeName);

private:
    std::string name;
};

#endif