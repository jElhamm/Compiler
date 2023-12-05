/**The purpose of this program is to analyze the source code and identify function calls. 
  * It uses a SourceCodeAnalyzer class that declares data types and functions, and provides methods to analyze the source code and detect function calls. 
  * The analyzeSourceCode function takes the source code as input and utilizes the analyzer object to analyze the code. 
  * The analyzeFunctionCalls function further examines the source code for function calls and provides output regarding the called functions, including their return types.
  **/



#include "SourceCodeAnalyzer.h"
#include <iostream>
#include <sstream>
using namespace std;

SourceCodeAnalyzer::SourceCodeAnalyzer() {
    // Declare some data types
    DataType intType("int");
    DataType floatType("float");
    DataType stringType("string");
    // Declare some functions
    FunctionDefinition addInt("addInt", "int");
    FunctionDefinition multiplyFloats("multiplyFloats", "float");
}
void SourceCodeAnalyzer::analyzeSourceCode(const std::string& sourceCode) {
    analyzer.analyze(sourceCode);
    analyzeFunctionCalls(sourceCode);
}
void SourceCodeAnalyzer::analyzeFunctionCalls(const std::string& sourceCode) {
    std::string functionName;
    std::istringstream codeStream(sourceCode);
    while (codeStream >> functionName) {
        if (analyzer.isDeclared(functionName)) {
            if (analyzer.getDeclaredFunctions().count(functionName)) {
                cout << "---> Called function: " << functionName << " (" << analyzer.getFunctionReturnTypes()[functionName] << ")\n";
            } else {
                cout << "---> Error: Undefined function called - " << functionName << "\n";
            }
        }
    }
}