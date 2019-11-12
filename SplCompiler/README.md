#SPL Compiler
##Introduction
This readme will outline the steps taken to create the SPL compiler, it will cover why certain decisions were made. It will also highlight the main features of the compiler. Furthermore, it will outline to folder structure, files contained and extra tests that are included.

##Assumptions

##Files and Folder Structure
```
| -- /bin                               | Folder containing the compiled binaries.
    | -- compiler.exe                   | The spl compiler.
    | -- lexer.exe                      | This executable will read and print the tokens within an SPL file.
    | -- parser.exe                     | This executable will parse the tokens from flex and print the bison debug information.
    | -- tree.exe                       | This executable will parse the tokens from flex and create and print the parse tree in a nice format.
| -- /src                               | This directory contains all the source for the four executables.
    | -- spl.c                          |
    | -- spl.y                          | This is the bison file, it also contains all the logic for optimisations and error and warning generation.
    | -- spl.l                          | This is the lex file that parses raw text into lexemes which are fed into bison.
| -- /tests                             | This directory contains all the tests that were both created and part of the course work files. The details of the tests are in the test section of this document.
    | -- a.spl                          |
    | -- assigned_used.spl              |
    | -- assignment_optimisation.spl    |
    | -- b.spl                          |
    | -- c.spl                          |
    | -- calculator.spl                 |
    | -- constant_folding.spl           |
    | -- d.spl                          |
    | -- e.spl                          |
    | -- final_types.spl                |
    | -- HelloWorld.spl                 |
    | -- identifier_too_long.spl        |
    | -- limits.spl                     |
    | -- not_declared.spl               |
    | -- operator.spl                   |
    | -- read.spl                       |
    | -- redeclaration.spl              |
    | -- unassigned_used.spl            |
    | -- var_usage.spl                  |
    | -- write_expressions.spl          |
    | -- zero_division.spl              |
| -- 600087ACW2019.pdf                  | This is the assesed course work description and contains the basic specification for the language.
| -- spl_bnf.txt                        | This is the bnf that was derrived from the railroad diagrams within 600087ACW2019.pdf.
| -- makefile                           | This is the make file that will build the executables found in the bin directory.
| -- README.md                          | This is this file.
```

##Highlights
This compiler implements the following optimisations:
- Dead store removal.
- Dead code removal.
- Constant folding.

It also provides warnings for the following:
- Program names not matching.
- Unexpected semi-colons at the end of the last statement in a statement list.
- Type conversion where an overflow or loss of precision may occur.
- Constants which are greater then the upper and lower values of integers and reals.
- When assignments are redundant.
- The use of uninitialised variables.
- Variables that are never used; either in the entire program or after the last assignment.
- Infinite loops.

##Parse Tree

##Symbol Table
For the symbol table I chose to use a double linked list rather then an array. This removed the limit on the number of symbols and it also allowed me to break the table down in to multiple sections i.e. a seperate sub-table for variables, operators, constants and types. This will allow the compiler to be optimised as the language develops and the need to compiler larger programs arises. While the current implementation adds little performance benifit especially considering that the programs been compiled are so small. The other benifit to this is there is no real limit to the details that can be stored and it is very maintainable to add extra features.

###Program
###Variables
###Constants
###Operators
###Types

##Variable Usage Tree
As the parse tree is being generated a double linked list is being created that tracks the usage of each variable. Each variable is then evaluated and checked to ensure they are not undeclared or redeclared and then redundant assignments are removed.

##Tests

##Evaluation


##Future Plans