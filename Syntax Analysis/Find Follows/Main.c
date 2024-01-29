// This code is the main function that interacts with the user to input grammar rules 
// and then calculates and displays the follow sets for each non-terminal symbol.



#include <stdio.h>
#include <stdlib.h>
#include "rules.h"
#include "followSetUtils.h"


int main() {
    Rule rules[MAX_RULES];
    int ruleCount = 0;
    printf("\n******************************************************************************");
    printf("---> Enter the non-terminal symbols and rules (Enter q to quit):\n");
    // Taking user input for grammar rules
    while (ruleCount < MAX_RULES) {
        char input[20];
        printf("     - Rule %d: ", ruleCount + 1);
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q'){
            break;
        }
        // Parsing user input into Rule struct
        sscanf(input, "%c %[^\n]", &rules[ruleCount].nonTerminal, rules[ruleCount].symbols);
        rules[ruleCount].symbolCount = strlen(rules[ruleCount].symbols);
        ruleCount++;
    }
    printf("\n******************************************************************************");
    printf("---> Non-terminal symbols:\n");
    // Displaying non-terminal symbols
    for (int i = 0; i < ruleCount; i++) {
        printf("%c\n", rules[i].nonTerminal);
    }
    printf("\n******************************************************************************");
    printf("\n---> Follow Sets:\n");
    // Calculating and displaying follow sets
    for (int i = 0; i < ruleCount; i++) {
        char followSet[10];
        int followSetIndex = 0;
        findFollowSet(rules, ruleCount, rules[i].nonTerminal, followSet, &followSetIndex);
        printf("     - Follow(%c) = {", rules[i].nonTerminal);
        // Add follow symbols to the output
        for (int j = 0; j < followSetIndex; j++) {
            if (followSet[j] != '-' && followSet[j] != '>') {
                printf("%c", followSet[j]);
            }
        }
        printf("}\n");
    }
    return 0;
}