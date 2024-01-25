/** 
  * This program implements a closure function and a gotos function used in parser generation. 
  * The closure function calculates the closure of a set of items by expanding non-terminal symbols. 
  * It iterates over the items, checks if the dot position is at the end of the right-hand side, and if not, 
  * it checks if the symbol at the dot position is a non-terminal. If it is, it adds new items based on matching 
  * productions. The gotos function processes a given symbol and generates new items by shifting the dot position 
  * for the items that have the given symbol at the dot position. The program also includes a helper function to 
  * print the state of the items.
 **/



#include "item.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void closure(Item *item[], int count) {
    // Calculate closure of items set
    int i, len, j, k, l;
    Item *temp;                                             // temporary item pointer
    Item *temp1;                                            // another temporary item pointer
    for (i = 0; i < count; i++) {
        temp = (Item *) malloc(sizeof(Item));               // allocate memory for temp
        temp1 = (Item *) malloc(sizeof(Item));              // allocate memory for temp1
        temp->lhs = item[i]->lhs;                           // set temp's lhs to item[i]'s lhs
        strcpy(temp->rhs, item[i]->rhs);                    // copy item[i]'s rhs to temp's rhs
        temp->dot = item[i]->dot;                           // set temp's dot to item[i]'s dot
        temp->prod_number = item[i]->prod_number;           // set temp's prod_number to item[i]'s prod_number
        
        if (temp->dot >= strlen(temp->rhs))
            continue;
        if (!isupper(temp->rhs[temp->dot]))
            continue;
        for (j = 0; j < count; j++) {
            if (I[j]->lhs == temp->rhs[temp->dot]) {
                temp1->lhs = I[j]->lhs;
                strcpy(temp1->rhs, I[j]->rhs);
                temp1->dot = I[j]->dot;
                temp1->prod_number = I[j]->prod_number;
                temp1->dot = 0;
                for (k = 0; k < count; k++) {
                    if (I[k]->lhs == temp1->lhs && strcmp(I[k]->rhs, temp1->rhs) == 0 && I[k]->dot == temp1->dot)
                        break;
                }
                if (k < count)
                    continue;
                
                I[count] = (Item *) malloc(sizeof(Item));
                strcpy(I[count]->rhs, temp1->rhs);
                I[count]->lhs = temp1->lhs;
                I[count]->dot = temp1->dot;
                I[count]->prod_number = temp1->prod_number;
                count++;
            }
        }
    }
}

void gotos(int symbol) {
    int i, j, k, l;
    Item *item[MAX_RULE_SIZE];                               // array of item pointers
    char temp_rhs[20], temp;
    for (i = 0; i < count; i++) {
        strcpy(temp_rhs, "");                               // initialize temp_rhs with an empty string
        if (I[i]->dot >= strlen(I[i]->rhs))
            continue;
            
        temp = I[i]->rhs[I[i]->dot];                        // get the symbol at the dot position
        if (temp == symbol) {
            item[l] = (Item *) malloc(sizeof(Item));        // allocate memory for item[l]
            strcpy(item[l]->rhs, I[i]->rhs);                // copy I[i]'s rhs to item[l]'s rhs
            item[l]->lhs = I[i]->lhs;                       // set item[l]'s lhs to I[i]'s lhs
            item[l]->dot = I[i]->dot;                       // set item[l]'s dot to I[i]'s dot
            item[l]->prod_number = I[i]->prod_number;       // set item[l]'s prod_number to I[i]'s prod_number
            item[l]->dot = item[l]->dot + 1;                // increment item[l]'s dot
            l++;
        }
    }
    closure(item, l);                                // call closure function with item set and l as arguments
}
 