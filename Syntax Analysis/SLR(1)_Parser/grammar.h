/** 
  * This code block defines the header file for the grammar module.
  * The macro definitions are provided: MAX_PROD_SIZE, MAX_TERM_SIZE, MAX_NON_TERM_SIZE, MAX_GRAMMARS.
  * Several structures are defined: Item, LR0Item, LR0Transition, SLR1TableEntry, Grammar.
  * Some function declarations are provided: initializeGrammar, freeMemory, getNonTerminalIndex, getTerminalIndex, closure, goTo.
  * The header guard is used to prevent multiple inclusions of this header file.
  * The #endif marks the end of the header file.
 **/



#ifndef GRAMMAR_H
#define GRAMMAR_H
#define MAX_PROD_SIZE 10
#define MAX_TERM_SIZE 10
#define MAX_NON_TERM_SIZE 10
#define MAX_GRAMMARS 100


// Structure representing a grammar item. It contains production, dot position, and lookahead.
typedef struct {
    char production[MAX_PROD_SIZE];
    int dotPosition;
    char lookahead[MAX_TERM_SIZE];
} Item;

// Structure representing an LR(0) item. It contains a state and an Item.
typedef struct {
    int state;
    Item item;
} LR0Item;

// Structure representing an LR(0) transition. It contains from state, symbol, and to state.
typedef struct {
    int fromState;
    char symbol;
    int toState;
} LR0Transition;

// Structure representing an SLR(1) table entry. It contains from state, symbol, to state, action, and production index.
typedef struct {
    int fromState;
    char symbol;
    int toState;
    char action;
    int productionIndex;
} SLR1TableEntry;  

// Structure representing a grammar. It contains non-terminals, terminals,
// productions, start symbol, closures, transitions, SLR(1) table, and states count.
typedef struct {
    char nonTerminals[MAX_NON_TERM_SIZE];
    char terminals[MAX_TERM_SIZE];
    char productions[MAX_PROD_SIZE][MAX_TERM_SIZE + MAX_NON_TERM_SIZE + 3];
    int productionsCount;
    char startSymbol;
    LR0Item *closure;
    int closureSize;
    LR0Transition *transitions;
    int transitionsSize;
    SLR1TableEntry **table;
    int statesCount;
} Grammar;

extern void initializeGrammar(Grammar *grammar);
extern void freeMemory(Grammar *grammar);
int getNonTerminalIndex(Grammar *grammar, char nonTerminal);
int getTerminalIndex(Grammar *grammar, char terminal);

#endif                   