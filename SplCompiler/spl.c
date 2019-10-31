#include <stdlib.h>
#include <stdio.h>

extern unsigned int g_uiCurrentLineNumber;
extern unsigned long g_ulCurrentLinePosition;
extern void PrintLinePositionUpdate();
extern void IncrementLinePosition(const int iTokenLength);
extern void ProcessEndOfLine();

extern void yyerror(const char *s);
extern int yylex();
extern int yyparse();

#define HANDLE_ERROR(message, ...) { fprintf(stderr, "[ERROR] - Line %d | Position %d - ", g_uiCurrentLineNumber, g_ulCurrentLinePosition); fprintf(stderr, message, ##__VA_ARGS__); fprintf(stderr, "*/\n"); }

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
	HANDLE_ERROR("%s.", s);
	exit(-1);
}