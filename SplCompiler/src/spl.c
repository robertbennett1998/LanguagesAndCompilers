#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

extern unsigned int g_uiCurrentLineNumber;
extern unsigned long g_ulCurrentLinePosition;
extern void PrintLinePositionUpdate();
extern void IncrementLinePosition(const int iTokenLength);
extern void ProcessEndOfLine();

extern void yyerror(const char *s);
extern int yylex();
extern int yyparse();

#define HANDLE_ERROR(message, ...) { fprintf(stderr, "[ERROR] - Line %d | Position %d - ", g_uiCurrentLineNumber, g_ulCurrentLinePosition); fprintf(stderr, message, ##__VA_ARGS__); fprintf(stderr, "\n"); }

#if YYDEBUG == 1
	extern int yydebug;
#endif

bool g_bOptimisation_DeadStores, g_bOptimisation_FoldConstants, g_bStaticErrorChecking_DivisionByZero, g_bOptimisation_DeadCode;
const char* const g_pCompilerVersion = "1.0.0";

void ProcessArgs(int argc, char **argv)
{
	int i = 1;
	for (; i < argc; i++)
	{
		if (strcmp(argv[i], "--noOptimisations") == 0)
		{
			printf("/*All optimisations are disabled*/\n");
			g_bOptimisation_DeadStores = false;
			g_bOptimisation_FoldConstants = false;
			g_bStaticErrorChecking_DivisionByZero = false;
			g_bOptimisation_DeadCode = false;
		}
		else if (strcmp(argv[i], "--noDeadStores") == 0)
		{
			printf("/*Dead store optimisation is disabled*/\n");
			g_bOptimisation_DeadStores = false;
		}
		else if (strcmp(argv[i], "--noConstantFolding") == 0)
		{
			printf("/*Constant folding is disabled*/\n");
			g_bOptimisation_FoldConstants = false;
		}
		else if (strcmp(argv[i], "--noDeadCode") == 0)
		{
			printf("/*Dead code optimisation is disabled*/\n");
			g_bOptimisation_DeadCode = false;
		}
		else if (strcmp(argv[i], "--noStaticErrors") == 0)
		{
			printf("/*All static errors are disabled*/\n");
			g_bStaticErrorChecking_DivisionByZero = false;
		}
		else if (strcmp(argv[i], "--noDivisionByZeroCheck") == 0)
		{
			printf("/*The static error check division by zero is disabled*/\n");
			g_bStaticErrorChecking_DivisionByZero = false;
		}
		else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
		{
			printf("Simple Programming Langauge (SPL) Compiler %s built on %s at %s.\n", g_pCompilerVersion, __DATE__, __TIME__);
			exit(0);
		}
		else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
		{
			printf("SPL Compiler Help:\n");
			printf("\tOptimisation Flags:\n");
			printf("\t\tAll optimisations are enabled by default, these flags will disable these optimisations.\n");
			printf("\t\t--noOptimisations: Will disable all optimisations.\n");
			printf("\t\t--noDeadStores: Will disable the optimisation of redundant variable assignments.\n");
			printf("\t\t--noConstantFolding: Will disable constant folding i.e. (2 + 2) is replaced with the constant 4.\n");
			printf("\t\t--noDeadCode: Will disable the optimisation of removing code that will never run due to constantly false expression.\n\n");

			printf("\t\tStatic Error Checking Flags:\n");
			printf("\t\tAll static error checks are enabled by default, these flags will disable these static error checks.\n");
			printf("\t\t--noStaticErrors: Will disable all static error checking.\n");
			printf("\t\t--noDivisionByZeroCheck: Will disable static error checking for constant division by zeros.\n\n");

			printf("\t\tMisc:\n");
			printf("\t\t-v, --version: Will print the current version of the compiler and the date and time it was built.\n");
			exit(0);
		}
		else
		{
			printf("Argument %s is not recognised.\n", argv[i]);
			printf("Please use the -h or --help flag to see a list of valid arguments.\n");
			exit(0);
		}
	}
}
int main(int argc, char **argv)
{
	g_bOptimisation_DeadStores = true;
	g_bOptimisation_FoldConstants = true;
	g_bStaticErrorChecking_DivisionByZero = true;
	g_bOptimisation_DeadCode = true;
	ProcessArgs(argc, argv);

    #if YYDEBUG == 1
        yydebug = 1;
    #endif

	return yyparse();
}

void yyerror(const char *s) 
{
	HANDLE_ERROR("%s.", s);
	exit(1);
}