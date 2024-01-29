// First Set Calculation - Finding the first set for non-terminal symbols in a set of production rules.



#include <ctype.h>
#include "rules.h"
#include "firstSetUtils.h"


// Function to add a symbol to the first set
void addToFirstSet(char firstSet[], int *firstSetIndex, char symbol) {
    int i;
    for (i = 0; i < *firstSetIndex; i++) {
        if (firstSet[i] == symbol) {
            break;
        }
    }
    if (i == *firstSetIndex) {                       // If the symbol is not already in the first set
        firstSet[*firstSetIndex] = symbol;           // Add the symbol to the first set
        (*firstSetIndex)++;
    }
}
 
// Function to find the first set for a given non-terminal symbol in a set of production rules
void findFirstSet(Rule rules[], int ruleCount, char nonTerminal, char firstSet[], int *firstSetIndex) {
    for (int i = 0; i < ruleCount; i++) {
        if (rules[i].nonTerminal == nonTerminal) {
            // If the first symbol of the rule is non-terminal
            if (isupper(rules[i].symbols[0])) {
                // Recursively find the first set for that non-terminal symbol
                findFirstSet(rules, ruleCount, rules[i].symbols[0], firstSet, firstSetIndex);
            }
            // If the first symbol is a terminal
            else {
                for (int j = 0; j < rules[i].symbolCount; j++) {
                    // Add the terminal symbol to the first set
                    addToFirstSet(firstSet, firstSetIndex, rules[i].symbols[j]);
                }
            }
        }
    }
}