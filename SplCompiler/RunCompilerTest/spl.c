#include <stdlib.h>
#include <stdio.h>

#include "spl_debugging.h"

extern void yyerror(const char *s);
extern int yylex();
extern int yyparse();

#ifdef YYDEBUG
	extern int yydebug;
#endif

int main(void)
{
    #ifdef YYDEBUG
        yydebug = 1;
    #endif

	int iRes = yyparse();
	GenerateAndPrintWarnings();

	return iRes;
}

void yyerror(const char *s) 
{
	printf("EEK, parse error!  Message: %s\n", s);
	PrintLinePositionUpdate();
	exit(-1);
}