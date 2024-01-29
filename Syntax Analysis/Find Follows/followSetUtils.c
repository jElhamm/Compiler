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
 
// This function finds the follow set for a given non-terminal symbol in a set of rules
void findFollowSet(Rule rules[], int ruleCount, char nonTerminal, char followSet[], int *followSetIndex) {
    // Add $ to the start symbol's follow set
    if (nonTerminal == rules[0].nonTerminal) {
        addToFollowSet(followSet, followSetIndex, '$');
    }

    for (int i = 0; i < ruleCount; i++) {
        for (int j = 0; j < rules[i].symbolCount; j++) {
            if (rules[i].symbols[j] == nonTerminal) {
                if (j == rules[i].symbolCount - 1) {
                    if (rules[i].nonTerminal != nonTerminal) {
                        // Recursive call to find follow set for nonTerminal
                        findFollowSet(rules, ruleCount, rules[i].nonTerminal, followSet, followSetIndex);
                    }
                } else {
                    if (isupper(rules[i].symbols[j + 1])) {
                        char firstSet[10];
                        int firstSetIndex = 0;
                        findFirstSet(rules, ruleCount, rules[i].symbols[j + 1], firstSet, &firstSetIndex);
                        // Add symbols from firstSet to followSet
                        for (int k = 0; k < firstSetIndex; k++) {
                            if (firstSet[k] != '-' && firstSet[k] != '>') {
                                addToFollowSet(followSet, followSetIndex, firstSet[k]);
                            }
                        }
                        // If epsilon exists in firstSet, find follow set for nonTerminal
                        if (strchr(firstSet, '-') != NULL) {
                            // Recursive call to find follow set for nonTerminal
                            findFollowSet(rules, ruleCount, rules[i].nonTerminal, followSet, followSetIndex); 
                        }
                    } else {
                        // Add symbol to followSet
                        addToFollowSet(followSet, followSetIndex, rules[i].symbols[j + 1]);
                    }
                }
            }
        }
    }
}