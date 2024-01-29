// This header file contains utility functions for working with follow sets.



#include "rules.h"
#ifndef FOLLOWSETUTILS_H
#define FOLLOWSETUTILS_H


void addToFollowSet(char followSet[], int *followSetIndex, char symbol);
void findFollowSet(Rule rules[], int ruleCount, char nonTerminal, char followSet[], int *followSetIndex);


#endif