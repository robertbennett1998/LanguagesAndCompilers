#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX_PATH_LENGTH 4096

//Externs
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern void PrintLinePositionUpdate();
extern void GenerateAndPrintWarnings();

#ifdef YYDEBUG
	extern int yydebug;
	yydebug = 1;
#endif

//methods
void yyerror(const char *s);

//Global vars
extern unsigned int g_uiCurrentLineNumber;
extern unsigned long g_ulCurrentLinePosition;

int main(void)
{
	#ifdef RUN_ALL_TESTS
		const int iNumberOfTests = 7;
		FILE** pAllFiles = 0;
		pAllFiles = malloc(sizeof(FILE) * iNumberOfTests);
		pAllFiles[0] = fopen("tests/test.spl", "r");
		pAllFiles[1] = fopen("tests/a.spl", "r");
		pAllFiles[2] = fopen("tests/b.spl", "r");
		pAllFiles[3] = fopen("tests/c.spl", "r");
		pAllFiles[4] = fopen("tests/d.spl", "r");
		pAllFiles[5] = fopen("tests/e.spl", "r"); 
		pAllFiles[6] = fopen("tests/HelloWorld.spl", "r");

		for (int i = 0; i < iNumberOfTests; i++)
		{
			g_uiCurrentLineNumber = 0;
			g_ulCurrentLinePosition = 0;
			if (!pAllFiles[i]) 
			{
				printf("I can't open %d!\n", i);
				return -1;
			}

			printf("-----------------%d-------------------\n", i);
			yyin = pAllFiles[i];
			yyparse();
		}

		free(pAllFiles);
		return 0;
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