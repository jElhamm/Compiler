/**
  * This code implements a function called findFollowSet that calculates the follow set for a given non-terminal symbol
  * in a set of grammar rules. It takes an array of Rule structures, the number of rules, the non-terminal symbol to find
  * the follow set for, an array to store the follow set, and a pointer to an integer to keep track of the follow set index.
**/



#include <ctype.h>
#include <string.h>
#include "rules.h"
#include "followSetUtils.h"


// This function adds a symbol to the follow set
void addToFollowSet(char followSet[], int *followSetIndex, char symbol) {
    int i;
    // Symbol already exists in the followSet
    for (i = 0; i < *followSetIndex; i++) {
        if (followSet[i] == symbol) {
            break;
        }
    }

    // Add symbol to followSet if it doesn't already exist
    if (i == *followSetIndex) {
        followSet[*followSetIndex] = symbol;
        (*followSetIndex)++;
    }
}
 