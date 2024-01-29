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
 