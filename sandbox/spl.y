%{
	#include <stdio.h>
	#include <stdlib.h>

	// Declare stuff from Flex that Bison needs to know about:
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern unsigned int uiCurrentLineNumber;
	extern unsigned long ulCurrentLinePos;
	extern char* pLastToken;

	void yyerror(const char *s);
%}

%union
{
	int ival;
	float fval;
	char* sval;
}


// Define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the %union:
%token<sval> IDENTIFIER 

//Key words
%token<ival> PROGRAM COLON ENDP PERIOD DECLARATIONS CODE

%%

program :
	PROGRAM COLON IDENTIFIER block ENDP IDENTIFIER PERIOD {
		printf("Found program: %s\n", $3);
	};

block :
	DECLARATIONS declaration_block CODE statement_list {
		printf("Found program block\n");
	} |
	CODE statement_list {
		printf("Found program block\n");
	};

declaration_block:
	IDENTIFIER IDENTIFIER {
		printf("Found def block\n");
	};

statement_list:
	IDENTIFIER {
		printf("Found code\n");
	};

%%

int main(int argc, char** argv) 
{	
	// Open a file handle to a particular file:
	FILE *myfile = fopen("test.spl", "r");
	// Make sure it is valid:
	if (!myfile) {
	return -1;
	}
	// Set Flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// Parse through the input:
	yyparse();
}

void yyerror(const char *s) 
{
  printf("EEK, parse error!  Message: %s Line Number:Position: %d:%d Last Token: %s\n", s, uiCurrentLineNumber, ulCurrentLinePos, pLastToken);
  free(pLastToken);
  pLastToken = 0;
  // might as well halt now:
  exit(-1);
}

#include "lex.yy.c"