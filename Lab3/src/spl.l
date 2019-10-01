%{
	//Includes
	#include <stdio.h>
	#include <stdlib.h>

	//Externs
	extern int yylex();

	//Methods
	void PrintToken(const char* pToken);
	void PrintLinePositionUpdate();
	void IncrementLinePosition(const int iTokenLength);
	void ProcessEndOfLine();
	
	//Global vars
	unsigned int g_uiCurrentLineNumber = 1;
	unsigned long g_ulCurrentLinePosition = 1;

	#define EXPAND(x) x
	#define GET_PROCESS_GENERIC_TOKEN_MACRO(_1,_2,NAME,...) NAME
	#define PROCESS_GENERIC_TOKEN(...) EXPAND(GET_PROCESS_GENERIC_TOKEN_MACRO(__VA_ARGS__, PROCESS_GENERIC_TOKEN_2, PROCESS_GENERIC_TOKEN_1)(__VA_ARGS__))	

	#ifdef PRINT 
		#define PROCESS_GENERIC_TOKEN_1(token) 	{\
													PrintToken(#token);\
													IncrementLinePosition(strlen(#token));\
													return token;\
												}

		#define PROCESS_GENERIC_TOKEN_2(token, symbolToPrint) 	{\
																	PrintToken(symbolToPrint);\
																	IncrementLinePosition(strlen(symbolToPrint));\
																	return token;\
																}
	#else
		#define PROCESS_GENERIC_TOKEN_1(token)	{\
													IncrementLinePosition(strlen(#token));\
													return token;\
												}

		#define PROCESS_GENERIC_TOKEN_2(token, symbolToPrint)	{\
													IncrementLinePosition(strlen(symbolToPrint));\
													return token;\
												}
	#endif
%}

%option noyywrap

delim           	[ \t\r]
whitespace         	{delim}+
digit           	[0-9]
integer          	{digit}+
number_constant		-?{integer}(?:\.{integer})?
lowercase_letters	[a-z]
uppercase_letters	[A-Z]
character			(?:{lowercase_letters}|{uppercase_letters})
character_constant	[']{character}[']
identifier			(?:(?:[a-zA-Z])[0-9]*)+

%%

"ENDP"  				PROCESS_GENERIC_TOKEN(ENDP);
"DECLARATIONS"  		PROCESS_GENERIC_TOKEN(DECLARATIONS);
"CODE"  				PROCESS_GENERIC_TOKEN(CODE);
"CHARACTER"  			PROCESS_GENERIC_TOKEN(CHARACTER);
"INTEGER"  				PROCESS_GENERIC_TOKEN(INTEGER);
"REAL"  				PROCESS_GENERIC_TOKEN(REAL);
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
{number_constant}		{ PROCESS_GENERIC_TOKEN(NUMBER_CONSTANT) }
{character_constant}	{ PROCESS_GENERIC_TOKEN(CHARACTER_CONSTANT) }
{identifier}			{ 	
							yylval.sval = strdup(yytext);
							PROCESS_GENERIC_TOKEN(IDENTIFIER, yytext)
						}

%%

void PrintToken(const char* pToken)
{
	printf("TOKEN: %s \n", pToken);
}

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