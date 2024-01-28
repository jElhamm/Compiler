/** 
  * This is the main function of the program.
  * It initializes a Grammar structure, reads the number of grammars from the user, reads the grammars and the start symbol from the user,
  * generates and prints the parsing table based on the grammar, and finally frees the memory.
  * The program returns 0 to indicate successful execution.
 **/



#include <stdio.h>
#include <stdlib.h>
#include "grammar.h"
#include "parsing_table.h"


int main() {
    Grammar grammar;
    initializeGrammar(&grammar);                                // Initialize the Grammar structure.
    int numGrammars;
    printf("\n***********************************************************************");
    printf("---> Enter the number of grammars: ");
    scanf("%d", &numGrammars);                                          // Read the number of grammars from the user.
    printf("--->Enter the grammars (in the format 'A->BC' or 'A->epsilon'):\n");
    for (int i = 0; i < numGrammars; i++) {
        printf("   Grammar %d: ", i + 1);
        scanf("%s", grammar.productions[grammar.productionsCount++]);  // Read the grammars from the user and store them in the grammar structure.
    }
    printf("--->Enter the start symbol: ");
    scanf(" %c", &grammar.startSymbol);                                // Read the start symbol of the grammar from the user.
    drawParsingTable(&grammar);                               // Generate the parsing table based on the grammar.
    printParsingTable(&grammar);                              // Print the parsing table.
    freeMemory(&grammar);                                     // Free the memory allocated for the grammar.
    return 0;
} 