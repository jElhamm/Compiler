#include "parsing_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Draw the parsing table based on the grammar
void drawParsingTable(Grammar *grammar) {
    grammar->statesCount = 1;
    // Allocate memory for the parsing table
    grammar->table = (SLR1TableEntry **)malloc(grammar->statesCount * sizeof(SLR1TableEntry *));
    grammar->table[0] = (SLR1TableEntry *)malloc((strlen(grammar->terminals) + strlen(grammar->nonTerminals) + 1) * sizeof(SLR1TableEntry));

    // Initialize the table entries for terminals and non-terminals
    for (int i = 0; i < grammar->statesCount; i++) {
        for (int j = 0; j < strlen(grammar->terminals); j++) {
            grammar->table[i][j].symbol = grammar->terminals[j];
            grammar->table[i][j].action = ' ';
            grammar->table[i][j].productionIndex = -1;
        }
    
        for (int j = 0; j < strlen(grammar->nonTerminals); j++) {
            grammar->table[i][strlen(grammar->terminals) + j].symbol = grammar->nonTerminals[j];
            grammar->table[i][strlen(grammar->terminals) + j].action = ' ';
            grammar->table[i][strlen(grammar->terminals) + j].productionIndex = -1;
        }
    }

    int closureSize = 0;
    // Compute the closure of the grammar and store it in the closure array
    grammar->closure = (LR0Item *)malloc(grammar->productionsCount * sizeof(LR0Item));
    closure(grammar, grammar->closure, &closureSize);

    grammar->statesCount = 1;
    // Allocate memory for the transitions array
    grammar->transitions = (LR0Transition *)malloc(grammar->productionsCount * sizeof(LR0Transition));

    int index = 0;
    // Iterate over the items in the closure
    for (int i = 0; i < closureSize; i++) {
        Item *item = &(grammar->closure[i].item);
        // If the dot is before a symbol other than the start symbol, create a transition
        if (item->dotPosition < strlen(item->production) && item->production[item->dotPosition] != grammar->startSymbol) {
            grammar->transitions[index].fromState = 0;
            grammar->transitions[index].symbol = item->production[item->dotPosition];
            grammar->transitions[index].toState = goTo(grammar, grammar->transitions, index, 0, item->production[item->dotPosition]);
            index++;
        }
    }
}

// Print the parsing table
void printParsingTable(Grammar *grammar) {
    printf("\nParsing Table:\n");
    printf("%8c |", ' ');
    // Print the header row with terminals and non-terminals
    for (int i = 0; i < strlen(grammar->terminals); i++) {
        printf("%8c |", grammar->terminals[i]);
    }
    for (int i = 0; i < strlen(grammar->nonTerminals); i++) {
        printf("%8c |", grammar->nonTerminals[i]);
    }
    printf("\n");
    // Iterate over the states and table entries
    for (int i = 0; i < grammar->statesCount; i++) {
        printf("%8d |", i);
        for (int j = 0; j < strlen(grammar->terminals) + strlen(grammar->nonTerminals) + 1;; j++) {
            if (grammar->table[i][j].action != ' ') {
                printf("%8c%2d |", grammar->table[i][j].action, grammar->table[i][j].productionIndex);
            } else {
                printf("%8c |", ' ');
            }
        }
        printf("\n");
    }
}