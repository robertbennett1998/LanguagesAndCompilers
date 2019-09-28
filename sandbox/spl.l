%{
	#include <stdio.h>
	#include <stdlib.h>
	extern int yylex();
	unsigned int uiCurrentLineNumber = 1;
	unsigned long ulCurrentLinePos = 1;
	char* pLastToken = 0;

	void setLastToken(char* _pLastToken)
	{
		if (pLastToken != 0)
		{
			free(pLastToken);
			pLastToken = 0;
		}

		pLastToken = malloc(strlen(_pLastToken) * sizeof(char));
		memcpy(pLastToken, _pLastToken, strlen(_pLastToken) * sizeof(char));
	}
%}

%option noyywrap

delim           	[ \t\r]
whitespace			{delim}+
digit           	[0-9]
integer          	{digit}+
number_constant		-?{integer}(?:\.{integer})?
lowercase_letters	[a-z]
uppercase_letters	[A-Z]
character			(?:{lowercase_letters}|{uppercase_letters})
character_constant	[']{character}[']
identifier			(?:(?:(?:[a-z]|[A-Z]))[0-9]*)+

%%

"PROGRAM"				{ setLastToken("PROGRAM"); ulCurrentLinePos += strlen("PROGRAM"); return(PROGRAM); }
"ENDP"  				{ setLastToken("ENDP"); ulCurrentLinePos += strlen("ENDP"); return(ENDP); }
"DECLARATIONS"  		{ setLastToken("DECLARATIONS"); ulCurrentLinePos += strlen("DECLARATIONS"); return(DECLARATIONS); }
"CODE"  				{ setLastToken("CODE"); ulCurrentLinePos += strlen("CODE"); return(CODE); }
"CHARACTER"  			;
"INTEGER"  				;
"REAL"  				; 
"IF"  					;
"OF"  					;
"TYPE"  				; 
"THEN"  				; 
"ENDIF"  				;
"AND"  					;
"OR"  					;
"DO"  					;
"WHILE"  				;
"ENDDO"  				;
"ENDWHILE"  			;
"FOR"  					;
"IS"  					;
"BY"  					;
"TO"  					;
"ENDFOR"  				;
"NEWLINE"  				;
"WRITE"  				;
"READ"  				; 
"->"					;
"<>"					;
"<"						;
">"						;
"<="					;
">="					;
"("						;
")"						;
","						;
":"						{ setLastToken(":"); ulCurrentLinePos += strlen(":"); return(COLON); }
";"						;
"."						{ setLastToken("."); ulCurrentLinePos += strlen("."); return(PERIOD); }
"+"						; 
"-"						; 
"/"						; 
"*"						; 
"\n"					{ ulCurrentLinePos = 1;  uiCurrentLineNumber++; };
{whitespace}			{ setLastToken("whitespace"); ulCurrentLinePos++; }
{identifier}			{ setLastToken(yytext); ulCurrentLinePos += strlen(yytext); yylval.sval = strdup(yytext); return(IDENTIFIER); };
{character_constant}	;
{number_constant}		;

%%