%{
	#include "spl.y.h"
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