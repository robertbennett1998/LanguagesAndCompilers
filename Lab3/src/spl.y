%{
	#ifdef YYDEBUG
		#define YYDEBUG_PRINT_1(s) 			printf(s);
		#define YYDEBUG_PRINT_2(s, ...) 	printf(s, __VA_ARGS__);
											
	#else
		#define YYDEBUG_PRINT_1(s)
		#define YYDEBUG_PRINT_2(s, ...)
	#endif

	#define EXPAND(x) x
	#define GET_YYDEBUG_PRINT_MACRO(_1,_2,NAME,...) NAME
	#define YYDEBUG_PRINT(...) EXPAND(GET_YYDEBUG_PRINT_MACRO(__VA_ARGS__, YYDEBUG_PRINT_2, YYDEBUG_PRINT_1)(__VA_ARGS__))	
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
%token<ival> NUMBER_CONSTANT CHARACTER_CONSTANT

%%

program :
	IDENTIFIER COLON block ENDP IDENTIFIER PERIOD {
		YYDEBUG_PRINT_2("Found Program - First identifier: %s Second identifier: %s\n", "a", "b");
	};

block :
	DECLARATIONS declaration_block CODE statement_list {
		YYDEBUG_PRINT("Found block - with both declarations and code\n");
	} |
	CODE statement_list {
		YYDEBUG_PRINT("Found block - with code only\n");
	};

declaration_block : 
	declaration {
		YYDEBUG_PRINT("Found single declaration\n");
	} |
	declaration_block declaration {
		YYDEBUG_PRINT("Found multiple declaration\n");
	};

declaration :
	identifier_list OF TYPE type SEMI_COLON {
		YYDEBUG_PRINT("Found declaration\n");
	};

identifier_list :
	IDENTIFIER {
		YYDEBUG_PRINT("Found identifier\n");
	} |
	identifier_list COMMA IDENTIFIER {
		YYDEBUG_PRINT("Found identifier list\n");
	};

type :
	CHARACTER {
		YYDEBUG_PRINT("Found character type\n");
	} |
	INTEGER {
		YYDEBUG_PRINT("Found int type\n");
	} |
	REAL {
		YYDEBUG_PRINT("Found real type\n");
	}

statement_list :
	statement {
		YYDEBUG_PRINT("Found statement\n");
	} |
	statement_list SEMI_COLON statement
	{
		YYDEBUG_PRINT("Found multiple statements\n");
	};

statement :
	assignment_statement {
		YYDEBUG_PRINT("statement is assignment statement\n");
	} |
	write_statement {
		YYDEBUG_PRINT("statement is write statement\n");
	};

assignment_statement :
	expression ASSIGNMENT_OPERATOR IDENTIFIER {
		YYDEBUG_PRINT("Found assignement statement\n");
	};

expression :
	term {
		YYDEBUG_PRINT("expression is term\n");
	};

term :
	value {
		YYDEBUG_PRINT("term is value\n");
	};

value :
	constant {
		YYDEBUG_PRINT("Found constant\n");
	};

constant :
	NUMBER_CONSTANT {
		YYDEBUG_PRINT("constant is number constant\n");
	} |
	CHARACTER_CONSTANT {
		YYDEBUG_PRINT("constant is character constant\n");
	};

write_statement :
	WRITE OPEN_BRACKET output_list CLOSE_BRACKET {
		YYDEBUG_PRINT("Write statement found\n");
	} |
	NEWLINE {
		YYDEBUG_PRINT("Newline called\n");
	};

output_list :
	value {
		YYDEBUG_PRINT("Output list single value\n");
	} |
	output_list COMMA value {
		YYDEBUG_PRINT("Output list\n");
	};
%%