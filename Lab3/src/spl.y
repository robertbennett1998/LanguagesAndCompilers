%{
%}

%union
{
	int ival;
	float fval;
	char* sval;
}

%token<sval> IDENTIFIER 

//Key words/symbols
%token<ival> ENDP DECLARATIONS CODE CHARACTER INTEGER REAL IF ELSE NOT OF TYPE THEN ENDIF AND OR DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR NEWLINE WRITE READ ASSIGNMENT_OPERATOR EQUALITY_OPERATOR NOT_EQUAL_TO_OPERATOR LESS_THAN_OPERATOR MORE_THAN_OPERATOR LESS_EQUAL_TO_OPERATOR MORE_EQUAL_TO_OPERATOR OPEN_BRACKET CLOSE_BRACKET COMMA COLON SEMI_COLON PERIOD ADD_OPERATOR SUBTRACT_OPERATOR DIVISION_OPERATOR MULTIPULCATION_OPERATOR

//tmp
%token<ival> NUMBER_CONSTANT

%%

program :
	IDENTIFIER COLON block ENDP IDENTIFIER PERIOD {
		printf("Found Program - First identifier: %s Second identifier: %s\n", strdup($1), strdup($5));
	};

block :
	DECLARATIONS declaration_block CODE statement_list {
		printf("Found block - with both declarations and code\n");
	} |
	CODE statement_list {
		printf("Found block - with code only\n");
	};

declaration_block : 
	declaration {
		printf("Found single declaration\n");
	} |
	declaration_block declaration {
		printf("Found multiple declaration\n");
	};

declaration :
	identifier_list OF TYPE type SEMI_COLON {
		printf("Found declaration\n");
	};

identifier_list :
	IDENTIFIER {
		printf("Found identifier\n");
	} |
	identifier_list COMMA IDENTIFIER {
		printf("Found identifier list\n");
	};

type :
	CHARACTER {
		printf("Found character type\n");
	} |
	INTEGER {
		printf("Found int type\n");
	} |
	REAL {
		printf("Found real type\n");
	}

statement_list :
	statement {
		printf("Found statement\n");
	} |
	statement_list SEMI_COLON statement
	{
		printf("Found multiple statements\n");
	};

statement :
	assignment_statement {
		printf("statement is assignment statement\n");
	};

assignment_statement :
	expression ASSIGNMENT_OPERATOR IDENTIFIER {
		printf("Found assignement statement\n");
	};

expression :
	term {
		printf("expression is term\n");
	};

term :
	value {
		printf("term is value\n");
	};

value :
	constant {
		printf("Found constant\n");
	};

constant :
	NUMBER_CONSTANT {
		printf("constant is number constant\n");
	};
%%