/**
  * This header file defines the structure and functions related to the Item class.
  * An Item represents a production rule with a dot indicating the current position.
 **/



#ifndef ITEM_H
#define ITEM_H
#define MAX_RULE_SIZE 100


typedef struct {
    char lhs;                                   // Left-hand side of production
    char rhs[MAX_RULE_SIZE];                    // Right-hand side of production
    int dot;                                    // Position of the dot in the production
    int prod_number;                            // Production number
} Item;
void closure(Item *item[], int count);          // Calculates closure of the given set of items
void gotos(int symbol);                         // Calculates the GOTO set for the given symbol
void print_state(int n);                        // Prints the state with its items

#endif