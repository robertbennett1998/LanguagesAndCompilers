%{
	#include <cstdio>
	#include <iostream>
	using namespace std;
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	void yyerror(const char *s);
%}

%union {
  int ival;
  float rval;
  char cval;
}

%token <ival> INTEGER
%token <rval> REAL
%token <cval> CHARACTER

%%

spl :
	CHARACTER { std::cout << "found char " << $1 << "\n"; }

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

	yyparse();

    return 0;
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}

#include <lex.yy.c>