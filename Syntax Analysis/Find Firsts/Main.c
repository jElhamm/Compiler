/**
  * The code is a program that allows the user to enter non-terminal symbols and production rules.
  * It then calculates and displays the first sets for each non-terminal symbol based on the entered rules.
  * The program uses the findFirstSet function from the 'firstSetUtils.h' header file to find the first sets.
**/



#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"
#include "firstSetUtils.h"
#define MAX_RULES 10000
#define MAX_SYMBOLS 10000

int main() {
    Rule rules[MAX_RULES];
    int ruleCount = 0;
    // Prompt for non-terminal symbols and rules
    printf("\n******************************************************************************");
    printf("---> Enter the non-terminal symbols and rules (Enter q to quit):\n");
    // Read rules until the maximum number of rules is reached or user quits
    while (ruleCount < MAX_RULES) {
        char input[20];
        printf("     - Rule %d: ", ruleCount + 1);
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q'){
            break;
        }
        // Parse input and store rule details
        sscanf(input, "%c %[^\n]", &rules[ruleCount].nonTerminal, rules[ruleCount].symbols);
        rules[ruleCount].symbolCount = strlen(rules[ruleCount].symbols);
        ruleCount++;
    }
    
    // Print non-terminal symbols
    printf("\n******************************************************************************");
    printf("---> Non-terminal symbols:\n");
    for (int i = 0; i < ruleCount; i++) {
        printf("%c\n", rules[i].nonTerminal);
    }
    // Calculate and print first sets
    printf("\n******************************************************************************");
    printf("\n---> First Sets:\n");
    for (int i = 0; i < ruleCount; i++) {
        char firstSet[10];
        int firstSetIndex = 0;
        findFirstSet(rules, ruleCount, rules[i].nonTerminal, firstSet, &firstSetIndex);
        printf("     - First(%c) = {", rules[i].nonTerminal);
        // Adding firsts to the output
        for (int j = 0; j < firstSetIndex; j++) {
            if (firstSet[j] != '-' && firstSet[j] != '>') {
                printf("%c", firstSet[j]);
            }
        }
        printf("}\n");
    }
    return 0;
}