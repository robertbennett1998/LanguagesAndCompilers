%{
	#include <stdlib.h>
	#include <iostream>
	extern int yylex();
%}

%option noyywrap

delim           	[ \t\r]
ws              	{delim}+
digit           	[0-9]
integer          	{digit}+
number_constant		-?{integer}(?:\.{integer})?
lowercase_letters	[a-z]
uppercase_letters	[A-Z]
character			(?:{lowercase_letters}|{uppercase_letters})
character_constant	[']{character}[']
identifier			(?:(?:{character}){digit}*)+
comparator			=|<>|<|>|<=|>=

%%

"ENDP"  				{ std::cout << "Found 'ENDP' keyword (" << yytext << ")\n"; }
"DECLARATIONS"  		{ std::cout << "Found 'DECLARATIONS' keyword (" << yytext << ")\n"; }
"CODE"  				{ std::cout << "Found 'CODE' keyword (" << yytext << ")\n"; }
"CHARACTER"  			{ std::cout << "Found 'CHARACTER' keyword (" << yytext << ")\n"; }
"INTEGER"  				{ std::cout << "Found 'INTEGER' keyword (" << yytext << ")\n"; }
"REAL"  				{ std::cout << "Found 'REAL' keyword (" << yytext << ")\n"; }
"IF"  					{ std::cout << "Found 'IF' keyword (" << yytext << ")\n"; }
"OF"  					{ std::cout << "Found 'OF' keyword (" << yytext << ")\n"; }
"TYPE"  				{ std::cout << "Found 'TYPE' keyword (" << yytext << ")\n"; }
"THEN"  				{ std::cout << "Found 'THEN' keyword (" << yytext << ")\n"; }
"ENDIF"  				{ std::cout << "Found 'ENDIF' keyword (" << yytext << ")\n"; }
"AND"  					{ std::cout << "Found 'ENDIF' keyword (" << yytext << ")\n"; }
"OR"  					{ std::cout << "Found 'ENDIF' keyword (" << yytext << ")\n"; }
"DO"  					{ std::cout << "Found 'DO' keyword (" << yytext << ")\n"; }
"WHILE"  				{ std::cout << "Found 'WHILE' keyword (" << yytext << ")\n"; }
"ENDDO"  				{ std::cout << "Found 'ENDDO' keyword (" << yytext << ")\n"; }
"ENDWHILE"  			{ std::cout << "Found 'ENDWHILE' keyword (" << yytext << ")\n"; }
"FOR"  					{ std::cout << "Found 'FOR' keyword (" << yytext << ")\n"; }
"IS"  					{ std::cout << "Found 'IS' keyword (" << yytext << ")\n"; }
"BY"  					{ std::cout << "Found 'BY' keyword (" << yytext << ")\n"; }
"TO"  					{ std::cout << "Found 'TO' keyword (" << yytext << ")\n"; }
"ENDFOR"  				{ std::cout << "Found 'ENDFOR' keyword (" << yytext << ")\n"; }
"NEWLINE"  				{ std::cout << "Found 'NEWLINE' keyword (" << yytext << ")\n"; }
"WRITE"  				{ std::cout << "Found 'WRITE' keyword (" << yytext << ")\n"; }
"READ"  				{ std::cout << "Found 'READ' keyword (" << yytext << ")\n"; }

"="						{ std::cout << "Found '=' symbol (" << yytext << ")\n"; }
"<>"					{ std::cout << "Found '<>' symbol (" << yytext << ")\n"; }
"<"						{ std::cout << "Found '<' symbol (" << yytext << ")\n"; }
">"						{ std::cout << "Found '>' symbol (" << yytext << ")\n"; }
"<="					{ std::cout << "Found '<=' symbol (" << yytext << ")\n"; }
">="					{ std::cout << "Found '>=' symbol (" << yytext << ")\n"; }
"("						{ std::cout << "Found '(' symbol (" << yytext << ")\n"; }
")"						{ std::cout << "Found ')' symbol (" << yytext << ")\n"; }
","						{ std::cout << "Found ',' symbol (" << yytext << ")\n"; }
":"						{ std::cout << "Found ':' symbol (" << yytext << ")\n"; }
";"						{ std::cout << "Found ';' symbol (" << yytext << ")\n"; }
"."						{ std::cout << "Found '.' symbol (" << yytext << ")\n"; }
"+"						{ std::cout << "Found '+' symbol (" << yytext << ")\n"; }
"-"						{ std::cout << "Found '-' symbol (" << yytext << ")\n"; }
"/"						{ std::cout << "Found '/' symbol (" << yytext << ")\n"; }
"*"						{ std::cout << "Found '*' symbol (" << yytext << ")\n"; }

{ws}            		; /* Do Nothing */
{character_constant}	{ std::cout << "Found a character constant (" << yytext << ")\n"; }
{number_constant}		{ std::cout << "Found a numeric constant (" << yytext << ")\n"; }
{identifier}			{ std::cout << "Found an identifier (" << yytext << ")\n"; }

%%

int main(void)
{
	int token = 0;
	while (token = yylex())
	{
		printf("Token %d\n", token);
	}

    return 0;
}