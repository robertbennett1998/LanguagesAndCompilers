%{
	#include "spl.y.h"
	void PrintToken(const char* pToken);
	void PrintLinePositionUpdate();
	void IncrementLinePosition(const int iTokenLength);
	void ProcessEndOfLine();
	#ifndef PRINT
		extern SymbolTableEntry* CreateSymbolTableEntry_Variable(const char* pIdentifier);
		extern SymbolTableEntry* GetSymbolTableEntry_Variable(const char* pIdentifier);
		extern SymbolTableEntry* g_pSymbolTableStart;
		extern SymbolTableEntry* g_pSymbolTableEnd;
	#endif

	#define EXPAND(x) x
	#define GET_PROCESS_GENERIC_TOKEN_MACRO(_1,_2,NAME,...) NAME
	#define PROCESS_GENERIC_TOKEN(...) EXPAND(GET_PROCESS_GENERIC_TOKEN_MACRO(__VA_ARGS__, PROCESS_GENERIC_TOKEN_2, PROCESS_GENERIC_TOKEN_1)(__VA_ARGS__))	

	#ifdef PRINT 
		#define PROCESS_GENERIC_TOKEN_1(token) 	{\
													PrintToken(#token);\
													IncrementLinePosition(strlen(#token));\
												}

		#define PROCESS_GENERIC_TOKEN_2(token, symbolToPrint) 	{\
																	PrintTokenAndValue(#token, symbolToPrint);\
																	IncrementLinePosition(strlen(symbolToPrint));\
																}
		#define ASSIGN_YYLVAL(x, y)
	#else
		#define PROCESS_GENERIC_TOKEN_1(token)	{\
													IncrementLinePosition(strlen(#token));\
													return token;\
												}

		#define PROCESS_GENERIC_TOKEN_2(token, symbolToPrint)	{\
													IncrementLinePosition(strlen(symbolToPrint));\
													return token;\
												}
		#define ASSIGN_YYLVAL(x, y) yylval.x = y;
	#endif
%}

%option noyywrap

delim           	[ \t\r]
whitespace         	{delim}+
digit           	[0-9]
unsigned_integer    {digit}+

real_number			-?[0-9]+\.[0-9]+
lowercase_letters	[a-z]
uppercase_letters	[A-Z]
character			(?:{lowercase_letters}|{uppercase_letters})
character_constant	[']{character}[']
identifier			(?:(?:[a-zA-Z])[0-9]*)+

%%

"ENDP"  				PROCESS_GENERIC_TOKEN(ENDP);
"DECLARATIONS"  		PROCESS_GENERIC_TOKEN(DECLARATIONS);
"CODE"  				PROCESS_GENERIC_TOKEN(CODE);
"CHARACTER"  			PROCESS_GENERIC_TOKEN(TYPE_CHARACTER);
"INTEGER"  				PROCESS_GENERIC_TOKEN(TYPE_INTEGER);
"REAL"  				PROCESS_GENERIC_TOKEN(TYPE_REAL);
"IF"  					PROCESS_GENERIC_TOKEN(IF);
"ELSE"					PROCESS_GENERIC_TOKEN(ELSE);
"NOT"					PROCESS_GENERIC_TOKEN(NOT);
"OF"  					PROCESS_GENERIC_TOKEN(OF);
"TYPE"  				PROCESS_GENERIC_TOKEN(TYPE);
"THEN"  				PROCESS_GENERIC_TOKEN(THEN);
"ENDIF"  				PROCESS_GENERIC_TOKEN(ENDIF);
"AND"  					PROCESS_GENERIC_TOKEN(AND);
"OR"  					PROCESS_GENERIC_TOKEN(OR);
"DO"  					PROCESS_GENERIC_TOKEN(DO);
"WHILE"  				PROCESS_GENERIC_TOKEN(WHILE);
"ENDDO"  				PROCESS_GENERIC_TOKEN(ENDDO);
"ENDWHILE"  			PROCESS_GENERIC_TOKEN(ENDWHILE);
"FOR"  					PROCESS_GENERIC_TOKEN(FOR);
"IS"  					PROCESS_GENERIC_TOKEN(IS);
"BY"  					PROCESS_GENERIC_TOKEN(BY);
"TO"  					PROCESS_GENERIC_TOKEN(TO);
"ENDFOR"  				PROCESS_GENERIC_TOKEN(ENDFOR);
"NEWLINE"  				PROCESS_GENERIC_TOKEN(NEWLINE);
"WRITE"  				PROCESS_GENERIC_TOKEN(WRITE);
"READ"  				PROCESS_GENERIC_TOKEN(READ);

"->"					PROCESS_GENERIC_TOKEN(ASSIGNMENT_OPERATOR, "->");
"="						PROCESS_GENERIC_TOKEN(EQUALITY_OPERATOR, "=");
"<>"					PROCESS_GENERIC_TOKEN(NOT_EQUAL_TO_OPERATOR, "<>");
"<"						PROCESS_GENERIC_TOKEN(LESS_THAN_OPERATOR, "<");
">"						PROCESS_GENERIC_TOKEN(MORE_THAN_OPERATOR, ">");
"<="					PROCESS_GENERIC_TOKEN(LESS_EQUAL_TO_OPERATOR, "<=");
">="					PROCESS_GENERIC_TOKEN(MORE_EQUAL_TO_OPERATOR, ">=");
"("						PROCESS_GENERIC_TOKEN(OPEN_BRACKET, "(");
")"						PROCESS_GENERIC_TOKEN(CLOSE_BRACKET, ")");
","						PROCESS_GENERIC_TOKEN(COMMA, ",");
":"						PROCESS_GENERIC_TOKEN(COLON, ":");
";"						PROCESS_GENERIC_TOKEN(SEMI_COLON, ";");
"."						PROCESS_GENERIC_TOKEN(PERIOD, ".");
"+"						PROCESS_GENERIC_TOKEN(ADD_OPERATOR, "+");
"-"						PROCESS_GENERIC_TOKEN(SUBTRACT_OPERATOR, "-");
"/"						PROCESS_GENERIC_TOKEN(DIVISION_OPERATOR, "/");
"*"						PROCESS_GENERIC_TOKEN(MULTIPULCATION_OPERATOR, "*");

"\n"					ProcessEndOfLine();
{whitespace}			IncrementLinePosition(strlen(yytext));
{unsigned_integer}		{
							ASSIGN_YYLVAL(iVal, atoi(yytext));
							PROCESS_GENERIC_TOKEN(UNSIGNED_INTEGER, yytext) 				
}
{real_number}			{ 
							ASSIGN_YYLVAL(fVal, atof(yytext));
							PROCESS_GENERIC_TOKEN(REAL, yytext) 
						}
{character_constant}	{
							ASSIGN_YYLVAL(cVal, yytext[1]);
							PROCESS_GENERIC_TOKEN(CHARACTER_CONSTANT, yytext)
						}
{identifier}			{
							char* pIdentifier = malloc(strlen(yytext) + 5);
							strcpy(pIdentifier, "spl_");
							strcat(pIdentifier, yytext);
							ASSIGN_YYLVAL(pSymbolTableEntry, CreateSymbolTableEntry_Variable(pIdentifier))
							PROCESS_GENERIC_TOKEN(IDENTIFIER, pIdentifier)
						}

%%

void PrintToken(const char* pToken)
{
	printf("TOKEN: %s \n", pToken);
}

void PrintTokenAndValue(const char* pToken, const char* pSymbolToPrint)
{
	printf("TOKEN: %s (%s) \n", pToken, pSymbolToPrint);
}

#ifndef PRINT

void PrintLinePositionUpdate()
{
	printf("Line Number: %d Line Position: %d\n", g_uiCurrentLineNumber, g_ulCurrentLinePosition);
}

void IncrementLinePosition(const int iTokenLength)
{
	g_ulCurrentLinePosition += iTokenLength;

	#ifdef LVERBOSE
		PrintLinePositionUpdate();
	#endif
}

void ProcessEndOfLine()
{
	g_uiCurrentLineNumber++;
	g_ulCurrentLinePosition = 1;

	#ifdef LVERBOSE
		PrintLinePositionUpdate();
	#endif
}

#endif