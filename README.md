# Compiler 

   This project aims to provide a thorough implementation of a [*Compiler*](https://en.wikipedia.org/wiki/Compiler), covering various essential components essential for language processing and translation.
   Below, you'll find detailed explanations of each major aspect of the project.


## [Lexical Analysis](Lexical%20Analysis)

   * [Finite State Machines](Lexical%20Analysis/Finite%20State%20Machines)

   Finite State Machines (FSMs) are used for lexical analysis to recognize patterns defined by regular expressions.
   They provide a systematic way to represent and recognize tokens in the input stream.


   * [Regular Expressions](Lexical%20Analysis/Regular%20Expressions)
   
   Regular expressions are powerful tools for defining patterns that specify sets of strings.
   In the context of lexical analysis, regular expressions are used to define the syntax of tokens in the language being compiled.


## [Syntax Analysis](Syntax%20Analysis)

   * [Find Firsts](Syntax%20Analysis/Find%20Firsts)
   
   The Find Firsts algorithm determines the set of terminal symbols that can appear as the first symbol of any string derivable from a given non-terminal symbol.
   It's a fundamental step in predictive parsing algorithms.


   * [Find Follows](Syntax%20Analysis/Find%20Follows)

   Find Follows is another crucial algorithm used in syntax analysis.
   It determines the set of terminal symbols that can appear immediately to the right of a non-terminal symbol in any valid derivation.


   * [LL(1) Parser](Syntax%20Analysis/LL(1)_Parser)

   LL(1) parsing is a top-down parsing technique. The LL stands for Left-to-right, Leftmost derivation, and the 1 indicates one token lookahead.
   This parser is efficient and widely used in many compilers.


   * [LR(0) Parser](Syntax%20Analysis/LR(0)_Parser)

   LR(0) parsing is a bottom-up parsing technique that constructs a rightmost derivation in reverse.
   Unlike LL parsing, LR parsing uses zero tokens lookahead.


   * [SLR(1) Parser](Syntax%20Analysis/SLR(1)_Parser)

   SLR(1) parsing is a variant of LR parsing that uses a lookahead of one token to make parsing decisions.
   It's more powerful than LR(0) but less powerful than LR(1) or LALR(1) parsers.


   * [Recursive Descent Parser](Syntax%20Analysis/Recursive%20Descent%20Parser)

   A Recursive Descent Parser is a top-down parser that starts from the top non-terminal of the grammar and recursively predicts which
   production to use by matching the current input token. It's relatively easy to implement and understand.


## [Semantic Analysis](Semantic%20Analysis)

   * [Symbol Tables](Semantic%20Analysis/Symbol%20Tables)

   Symbol tables are data structures used by compilers to store information about various entities such as variable names, function names, etc.,
   along with their attributes. They are essential for type checking, scope resolution, and code optimization.


   * [Direct Representation](Semantic%20Analysis/Direct%20Representation)

   Direct representation refers to representing data structures and operations directly in the memory of a computer.
   It enables efficient manipulation and analysis of program structures during the compilation process.


##  Usage

   Each topic is organized into dedicated directories with clear explanations, code examples, and illustrative diagrams where applicable. 
   You can explore the content by navigating through the directories and reviewing the individual files.

## References
   
   BOOK
 
   * [Advanced Compiler Design and Implementation by Steven S. Muchnick.](https://github.com/rambhawan/Computer-Compiler-Lang/blob/master/Advanced%20Compiler%20Design%20and%20Implementation.pdf)
   * [Compilers: Principles, Techniques, and Tools by Alfred V. Aho.](https://repository.unikom.ac.id/48769/1/Compilers%20-%20Principles%2C%20Techniques%2C%20and%20Tools%20%282006%29.pdf)



   Source Used In Git Hub

   * [Computer-Compiler-Lang](https://github.com/rambhawan/Computer-Compiler-Lang/tree/master)



   Websites

   * [Lexical analysis in Compiler](https://en.wikipedia.org/wiki/Lexical_analysis)
   * [Syntax Analysis in Compiler](https://www.geeksforgeeks.org/introduction-to-syntax-analysis-in-compiler-design/)
   * [Semantic Analysis in Compiler](https://en.wikipedia.org/wiki/Semantic_analysis_(compilers))


## License

   This repository is licensed under the MIT License.
   See the [LICENSE](./LICENSE) file for more details.