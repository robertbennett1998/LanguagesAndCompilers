%{
	#include <stdlib.h>
	#include <iostream>
	#include <string>
	#include <sstream>
	extern int yylex();
	unsigned int uiLineCount = 0;
	std::stringstream ssOut;
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

%%

"ENDP"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDP' keyword (" << yytext << ")\n"; }
"DECLARATIONS"  		{ ssOut << yytext << "|"; } //{ std::cout << "Found 'DECLARATIONS' keyword (" << yytext << ")\n"; }
"CODE"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'CODE' keyword (" << yytext << ")\n"; }
"CHARACTER"  			{ ssOut << yytext << "|"; } //{ std::cout << "Found 'CHARACTER' keyword (" << yytext << ")\n"; }
"INTEGER"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'INTEGER' keyword (" << yytext << ")\n"; }
"REAL"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'REAL' keyword (" << yytext << ")\n"; }
"IF"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'IF' keyword (" << yytext << ")\n"; }
"OF"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'OF' keyword (" << yytext << ")\n"; }
"TYPE"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'TYPE' keyword (" << yytext << ")\n"; }
"THEN"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'THEN' keyword (" << yytext << ")\n"; }
"ENDIF"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDIF' keyword (" << yytext << ")\n"; }
"AND"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDIF' keyword (" << yytext << ")\n"; }
"OR"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDIF' keyword (" << yytext << ")\n"; }
"DO"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'DO' keyword (" << yytext << ")\n"; }
"WHILE"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'WHILE' keyword (" << yytext << ")\n"; }
"ENDDO"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDDO' keyword (" << yytext << ")\n"; }
"ENDWHILE"  			{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDWHILE' keyword (" << yytext << ")\n"; }
"FOR"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'FOR' keyword (" << yytext << ")\n"; }
"IS"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'IS' keyword (" << yytext << ")\n"; }
"BY"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'BY' keyword (" << yytext << ")\n"; }
"TO"  					{ ssOut << yytext << "|"; } //{ std::cout << "Found 'TO' keyword (" << yytext << ")\n"; }
"ENDFOR"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'ENDFOR' keyword (" << yytext << ")\n"; }
"NEWLINE"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'NEWLINE' keyword (" << yytext << ")\n"; }
"WRITE"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'WRITE' keyword (" << yytext << ")\n"; }
"READ"  				{ ssOut << yytext << "|"; } //{ std::cout << "Found 'READ' keyword (" << yytext << ")\n"; }

"->"					{ ssOut << yytext << "|"; } //{ std::cout << "Found '->' symbol (" << yytext << ")\n"; }
"="						{ ssOut << yytext << "|"; } //{ std::cout << "Found '=' symbol (" << yytext << ")\n"; }
"<>"					{ ssOut << yytext << "|"; } //{ std::cout << "Found '<>' symbol (" << yytext << ")\n"; }
"<"						{ ssOut << yytext << "|"; } //{ std::cout << "Found '<' symbol (" << yytext << ")\n"; }
">"						{ ssOut << yytext << "|"; } //{ std::cout << "Found '>' symbol (" << yytext << ")\n"; }
"<="					{ ssOut << yytext << "|"; } //{ std::cout << "Found '<=' symbol (" << yytext << ")\n"; }
">="					{ ssOut << yytext << "|"; } //{ std::cout << "Found '>=' symbol (" << yytext << ")\n"; }
"("						{ ssOut << yytext << "|"; } //{ std::cout << "Found '(' symbol (" << yytext << ")\n"; }
")"						{ ssOut << yytext << "|"; } //{ std::cout << "Found ')' symbol (" << yytext << ")\n"; }
","						{ ssOut << yytext << "|"; } //{ std::cout << "Found ',' symbol (" << yytext << ")\n"; }
":"						{ ssOut << yytext << "|"; } //{ std::cout << "Found ':' symbol (" << yytext << ")\n"; }
";"						{ ssOut << yytext << "|"; } //{ std::cout << "Found ';' symbol (" << yytext << ")\n"; }
"."						{ ssOut << yytext << "|"; } //{ std::cout << "Found '.' symbol (" << yytext << ")\n"; }
"+"						{ ssOut << yytext << "|"; } //{ std::cout << "Found '+' symbol (" << yytext << ")\n"; }
"-"						{ ssOut << yytext << "|"; } //{ std::cout << "Found '-' symbol (" << yytext << ")\n"; }
"/"						{ ssOut << yytext << "|"; } //{ std::cout << "Found '/' symbol (" << yytext << ")\n"; }
"*"						{ ssOut << yytext << "|"; } //{ std::cout << "Found '*' symbol (" << yytext << ")\n"; }

"\n"					{ uiLineCount++; } //
{character_constant}	{ ssOut << yytext << "|"; } //{ std::cout << "Found a character constant (" << yytext << ")\n"; }
{number_constant}		{ ssOut << yytext << "|"; } //{ std::cout << "Found a numeric constant (" << yytext << ")\n"; }
{identifier}			{ ssOut << yytext << "|"; } //{ std::cout << "Found an identifier (" << yytext << ")\n"; }

%%

int main(void)
{
	// open a file handle to a particular file:
	FILE *myfile = fopen("test.spl", "r");
	// make sure it's valid:
	if (!myfile) {
		std::cout << "I can't open test.spl!" << std::endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	while (yylex()) {}

	std::cout << ssOut.str();

    return 0;
}
