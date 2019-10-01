#include "spl.tab.h"
#include "lex.yy.c"

#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 4096

//Externs
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern void PrintLinePositionUpdate();

//methods
void yyerror(const char *s);

//Global vars
extern unsigned int g_uiCurrentLineNumber;
extern unsigned long g_ulCurrentLinePosition;

int main(void)
{
	char aucFilePath[MAX_PATH_LENGTH];
	printf("Please enter a file path: ");
	scanf("%s", aucFilePath);

	// open a file handle to a particular file:
	FILE *myfile = fopen(aucFilePath, "r");
	// make sure it's valid:
	if (!myfile) {
		printf("I can't open %s!\n", aucFilePath);
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	yyparse();

    return 0;
}

void yyerror(const char *s) 
{
	printf("EEK, parse error!  Message: %s\n", s);
	PrintLinePositionUpdate();
	exit(-1);
}