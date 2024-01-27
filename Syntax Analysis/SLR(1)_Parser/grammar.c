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

//***************************************************************************************************************************
// Compute the closure of a given LR0 item set
void closure(Grammar *grammar, LR0Item *state, int *stateSize) {
    // Copy the items from the closure into the new state
    int closureSize = 0;
    memcpy(state, &(grammar->closure[*stateSize]), sizeof(LR0Item));
    closureSize += *stateSize;

    // Iterate over the items in the state
    for (int i = 0; i < closureSize; i++) {
        Item *item = &(state[i].item);
        // If the dot is before a non-terminal, find productions that can be appended to the item's production
        if (item->dotPosition < strlen(item->production) && item->production[item->dotPosition] >= 'A' && item->production[item->dotPosition] <= 'Z') {
            for (int j = 0; j < grammar->productionsCount; j++) {
                if (grammar->productions[j][0] == item->production[item->dotPosition]) {
                    // Create a new LR0Item with the production and dot position, and add it to the state if it's not already present
                    LR0Item newItem;
                    strcpy(newItem.item.production, grammar->productions[j]);
                    newItem.item.dotPosition = 0;
                    strcpy(newItem.item.lookahead, item->lookahead);
                    int found = 0;
                    for (int k = 0; k < closureSize; k++) {
                        if (strcmp(newItem.item.production, state[k].item.production) == 0 &&
                            newItem.item.dotPosition == state[k].item.dotPosition &&
                            strcmp(newItem.item.lookahead, state[k].item.lookahead) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        state[closureSize++] = newItem;
                    }
                }
            }
        }
    }
    *stateSize = closureSize;  // Update the size of the state
}
//***************************************************************************************************************************
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