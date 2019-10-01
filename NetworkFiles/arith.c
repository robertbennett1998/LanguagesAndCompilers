#include <stdio.h>
int yyparse();

int main(void)
{
    return(yyparse());
}

void yyerror(char *s)
{
    fprintf(stderr, "Error : Exiting %s\n", s);
}

