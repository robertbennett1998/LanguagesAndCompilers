%{
  #include <cstdio>

  #include "spl.tab.h"  // to get the token types from Bison

%}

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

"PROGRAM"			{ return PROGRAM; }
"ENDP"  			{ return ENDP; }
"."					{ return PERIOD; }
":"					{ return COLON; }

{identifier}		{ return IDENTIFIER; }

[ \t\n]           ;
";"				  { return BLOCK; }
[0-9]+\.[0-9]+    { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+            { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z0-9]+      {
  // We have to strdup yytext because Flex will change it for the next token.
  // Note that this memory must be freed somewhere, so that's why we call
  // free() above in the Bison section.  (Aside: we use free() instead of
  // delete because strdup is a C function that uses malloc, not a C++
  // function that uses new.)
  yylval.sval = strdup(yytext);
  return STRING;
}

%%