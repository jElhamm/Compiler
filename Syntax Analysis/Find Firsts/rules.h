// The code you provided is a header file named "rules.h". This header file defines a structure called Rule,
// which represents a production rule. Each Rule consists of a non-terminal symbol and an array of symbols.



#ifndef RULES_H
#define RULES_H
#define MAX_SYMBOLS 10


typedef struct {
    char nonTerminal;
    char symbols[MAX_SYMBOLS];
    int symbolCount;
} Rule;

#endif



/**
 * The Rule struct has the following members:
 * 
 * 'nonTerminal': a character representing the non-terminal symbol of the production rule.
 * 'symbols'    : an array of characters representing the symbols (terminals or non-terminals) in the production rule.
 * 'symbolCount': an integer indicating the number of symbols in the production rule.
**/