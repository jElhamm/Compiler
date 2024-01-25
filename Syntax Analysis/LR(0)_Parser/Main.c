/** This program implements a parser using the LR(0) parsing technique. 
  * It reads a set of productions (grammatical rules) as input and constructs 
  * the corresponding LR(0) parsing tables: the Action table and the Goto table. 
  * These tables are used for parsing an input string based on the given set of productions.
 **/



#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUCTIONS 20


char terminator[] = {'$', 'i', '+', '*', '(', ')'};         // Array of terminal symbols
char non_terminator[] = {'E', 'T', 'F'};                                // Array of non-terminal symbols
int action[20][20], gotot[20][20];                                                  // Action and Goto tables

int main(){
    printf("\n********************************************************************");
    printf("---> Enter the number of productions: ");
    int n;
    scanf("%d", &n);                                                                // Read the number of productions
    int i, j;
    printf("---> Enter the productions: \n");
    Item *I[MAX_PRODUCTIONS];                                                       // Array of Item pointers
    // Read the productions and initialize the Item structures
    for (i = 0; i < n; i++){
        I[i] = (Item *)malloc(sizeof(Item));
        printf("---> The lhs of production %d: ", i + 1);
        scanf(" %c", &I[i]->lhs);                                                   // Read the lhs of the production
        printf("---> The rhs of production %d: ", i + 1);
        scanf(" %s", I[i]->rhs);                                                    // Read the rhs of the production
        I[i]->dot = 0;                                                              // Initialize dot position to 0
        I[i]->prod_number = i;                                                      // Set the production number
    }
    printf("---> Enter the input string: ");
    scanf("%s", input);                                                             // Read the input string
    count = 0;
    I[count] = (Item *)malloc(sizeof(Item));
    I[count]->lhs = 'Z';
    strcpy(I[count]->rhs, ".E");
    I[count]->dot = 0;
    I[count]->prod_number = -1;
    count++;
    closure(I, count);                                                 // Perform closure operation
    print_state(0);                                                              // Print the initial state

    int state_count = 0;
    while (state_count <= count){                                                    // Construct the Action and Goto tables
        int i;
        for (i = 0; i < 6; i++) {
            gotos(terminator[i]);               // Perform Goto operation for each terminal symbol
            if (count == 0)
                continue;
            int j;
            for (j = 0; j < count; j++){
                printf("I%d -> %c -> I%d", state_count, terminator[i], state_count + 1);
                action[state_count][i] = state_count + 1;
                if (I[j]->dot >= strlen(I[j]->rhs)){
                    printf("reduce by %c -> %s", I[j]->lhs, I[j]->rhs);
                    action[state_count][i] = -1 * (I[j]->prod_number + 1);
                }
            }
        }
        state_count++;
    }

    printf("\n\nAction Table:\n");
    printf("-------------------------------------------------------------------\n");
    printf("State\t");
    for (i = 0; i < 6; i++){
        printf("%c\t", terminator[i]);
    }
    printf("\n");
    // Print the Action table
    for (i = 0; i < state_count; i++){
        printf("%d   \t", i);
        for (j = 0; j < 6; j++){
            printf("%d ", action[i][j]);
        }
        printf("\n");
    }
    printf("\n\nGoto Table:\n");
    printf("-------------------------------------------------------------------\n");
    printf("State\t");
    for (i = 0; i < 3; i++){
        printf("%c\t", non_terminator[i]);
    }
    printf("\n");
    // Print the Goto table
    for (i = 0; i < state_count; i++){
        printf("%d   \t", i);
        for (j = 0; j < 3; j++){
            printf("%d ", gotot[i][j]);
        }
        printf("\n");
    }
    return 0;
}