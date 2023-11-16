// This class, SyntaxAnalyzer, is responsible for analyzing the syntax of a given input string by utilizing 
// a parsing table and parsing techniques.


#pragma once
#include <string>
#include <stack>
#include <unordered_map>

class SyntaxAnalyzer {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> parsingTable;
    std::stack<std::string> parseStack;
    std::string inputString;
    std::string getInputSymbol();
    void initParsingTable();
    void consumeInputSymbol();
    void parse();

public:
    void analyze();
};