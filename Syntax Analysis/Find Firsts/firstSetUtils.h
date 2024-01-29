// This is a header file that can be included in other source files to use the 
// findFirstSet and addToFirstSet functions to find the first set in the grammar.



#ifndef FIRSTSETUTILS_H
#define FIRSTSETUTILS_H
#include "rules.h"


void addToFirstSet(char firstSet[], int *firstSetIndex, char symbol);
void findFirstSet(Rule rules[], int ruleCount, char nonTerminal, char firstSet[], int *firstSetIndex);


#endif