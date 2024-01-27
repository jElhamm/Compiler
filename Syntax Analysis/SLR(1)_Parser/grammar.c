/**
 * The code you provided is a collection of functions related to a parsing table and grammar operations.
 * Here are the main functions and their purposes:   1. getNonTerminalIndex
 *                                                   2. getTerminalIndex
 *                                                   3. closure
 *                                                   4. goTo
 *                                                   5. initializeGrammar
 *                                                   6. freeMemory
 **/



#include "grammar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Get the index of a non-terminal in the grammar
int getNonTerminalIndex(Grammar *grammar, char nonTerminal) {
    return nonTerminal - 'A';
}

// Get the index of a terminal in the grammar
int getTerminalIndex(Grammar *grammar, char terminal) {
    return terminal - 'a';
}
 
// Initialize the grammar structure
void initializeGrammar(Grammar *grammar) {
    strcpy(grammar->nonTerminals, "");
    strcpy(grammar->terminals, "");
    grammar->productionsCount = 0;
    grammar->startSymbol = '\0';
    grammar->closure = NULL;
    grammar->closureSize = 0;
    grammar->transitions = NULL;
    grammar->transitionsSize = 0;
    grammar->table = NULL;
    grammar->statesCount = 0;
}

// Free memory allocated for the grammar structure
void freeMemory(Grammar *grammar) {
    free(grammar->closure);
    free(grammar->transitions);
    for (int i = 0; i < grammar->statesCount; i++) {
        free(grammar->table[i]);
    }
    free(grammar->table);
}