/**
 * The SyntaxAnalyzer class is responsible for performing syntax analysis on an input string using a parsing table.
 * It uses a stack-based parsing technique to check the validity of the input string based on a set of production rules.
 **/



#include "SyntaxAnalyzer.h"
#include <iostream>

void SyntaxAnalyzer::initParsingTable() {
    // Initialize the parsing table
    parsingTable["E"]["("] = "TG";
    parsingTable["E"]["id"]= "TG";
    parsingTable["G"][")"] = "epsilon";
    parsingTable["G"][std::string()] = "epsilon";
    parsingTable["G"]["+"] = "+TG";
    parsingTable["T"]["("] = "FH";
    parsingTable["T"]["id"]= "FH";
    parsingTable["H"][")"] = "epsilon";
    parsingTable["H"][std::string()] = "epsilon";
    parsingTable["H"]["+"] = "epsilon";
    parsingTable["H"]["*"] = "*FH";
    parsingTable["F"]["("] = "(E)";
    parsingTable["F"]["id"] = "id";
    // Push start symbol onto the stack
    parseStack.push("$");
    parseStack.push("E");
}
 