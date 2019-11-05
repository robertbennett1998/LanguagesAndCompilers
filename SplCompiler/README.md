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

##Design Decisions

##Parse Tree

##Symbol Table
###Program
###Variables
###Constants
###Operators
###Types

##Tests

##Variable Usage Tree

##Evaluation

##Future Plans