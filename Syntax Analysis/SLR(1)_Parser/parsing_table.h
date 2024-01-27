/** 
  * This code block defines the header file for the parsing table module.
  * It includes the "grammar.h" file.
  * The functions drawParsingTable() and printParsingTable() are declared here.
  * The header guard is used to prevent multiple inclusions of this header file.
  * The #endif marks the end of the header file.
 **/



#ifndef PARSING_TABLE_H
#define PARSING_TABLE_H
#include "grammar.h"


void drawParsingTable(Grammar *grammar);
void printParsingTable(Grammar *grammar);

#endif