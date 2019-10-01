%{
	#ifdef YYDEBUG
		#define YYDEBUG_PRINT(s, ...) 	printf(s, ##__VA_ARGS__);								
	#else
		#define YYDEBUG_PRINT(s, ...)
	#endif
%}

%union
{
	int ival;
	float fval;
	char* sval;
	char cval;
}

%token<sval> IDENTIFIER

%token<cval> CHARACTER_CONSTANT

//Key words/symbols
%token<ival> ENDP DECLARATIONS CODE TYPE_CHARACTER TYPE_INTEGER TYPE_REAL IF ELSE NOT OF TYPE THEN ENDIF AND OR DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR NEWLINE WRITE READ ASSIGNMENT_OPERATOR EQUALITY_OPERATOR NOT_EQUAL_TO_OPERATOR LESS_THAN_OPERATOR MORE_THAN_OPERATOR LESS_EQUAL_TO_OPERATOR MORE_EQUAL_TO_OPERATOR OPEN_BRACKET CLOSE_BRACKET COMMA COLON SEMI_COLON PERIOD ADD_OPERATOR SUBTRACT_OPERATOR DIVISION_OPERATOR MULTIPULCATION_OPERATOR INTEGER

//tmp
%token<fval> REAL

%%

program :
	identifier COLON block ENDP identifier PERIOD {
		YYDEBUG_PRINT("Found Program\n");
	};

identifier :
	IDENTIFIER {
		YYDEBUG_PRINT("Found identifier (%s)\n", $1);
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
	identifier {
		YYDEBUG_PRINT("Found identifier\n");
	} |
	identifier_list COMMA identifier {
		YYDEBUG_PRINT("Found identifier list\n");
	};

type :
	TYPE_CHARACTER {
		YYDEBUG_PRINT("Found character type\n");
	} |
	TYPE_INTEGER {
		YYDEBUG_PRINT("Found int type\n");
	} |
	TYPE_REAL {
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
	} |
	read_statement {
		YYDEBUG_PRINT("statement is read statement\n");
	} |
	if_statement {
		YYDEBUG_PRINT("statement is if statement\n");
	} |
	for_statement {
		YYDEBUG_PRINT("statement is for statement\n");
	} |
	while_statement {
		YYDEBUG_PRINT("statement is while statement\n");
	} |
	do_statement {
		YYDEBUG_PRINT("statement is do statement\n");
	};

assignment_statement :
	expression ASSIGNMENT_OPERATOR identifier {
		YYDEBUG_PRINT("Found assignement statement\n");
	};

value :
	constant {
		YYDEBUG_PRINT("Found constant\n");
	} |
	identifier {
		YYDEBUG_PRINT("Found identifer (as value)\n");
	} |
	OPEN_BRACKET expression CLOSE_BRACKET {
		YYDEBUG_PRINT("Found expression (as value)\n");
	};

expression :
	term {
		YYDEBUG_PRINT("expression is term\n");
	} |
	expression ADD_OPERATOR term {
		YYDEBUG_PRINT("expression is expr + term\n");
	} |
	expression SUBTRACT_OPERATOR term {
		YYDEBUG_PRINT("expression is expr - term\n");
	};

term :
	value {
		YYDEBUG_PRINT("term is value\n");
	} |
	term MULTIPULCATION_OPERATOR value {
		YYDEBUG_PRINT("term is term * value\n");
	} |
	term DIVISION_OPERATOR value {
		YYDEBUG_PRINT("term is term / value\n");
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

constant :
	number_constant {
		YYDEBUG_PRINT("constant is number constant\n");
	} |
	CHARACTER_CONSTANT {
		YYDEBUG_PRINT("constant is character constant\n");
	};

number_constant :
	signed_integer {
		YYDEBUG_PRINT("Number constant is integer\n");
	} |
	real {
		YYDEBUG_PRINT("Number constant is real\n");
	}

signed_integer :
	INTEGER {
		YYDEBUG_PRINT("integer\n");
	};

real :
	REAL {
		YYDEBUG_PRINT("real\n");
	};

comparator :
	EQUALITY_OPERATOR {
		YYDEBUG_PRINT("Comparator is eq op\n");
	} |
	NOT_EQUAL_TO_OPERATOR {
		YYDEBUG_PRINT("Comparator is not eq op\n");
	} |
	LESS_THAN_OPERATOR {
		YYDEBUG_PRINT("Comparator is < op\n");
	} |
	MORE_THAN_OPERATOR {
		YYDEBUG_PRINT("Comparator is > op\n");
	} |
	LESS_EQUAL_TO_OPERATOR {
		YYDEBUG_PRINT("Comparator is <= op\n");
	} |
	MORE_EQUAL_TO_OPERATOR {
		YYDEBUG_PRINT("Comparator is >= op\n");
	};

read_statement :
	READ OPEN_BRACKET identifier CLOSE_BRACKET {
		YYDEBUG_PRINT("Read statement for identifier \n");
	};

if_statement :
	IF conditional THEN statement_list ENDIF {
		YYDEBUG_PRINT("Found if statement \n");
	} |
	IF conditional THEN statement_list ELSE statement_list ENDIF {
		YYDEBUG_PRINT("Found if else statement \n");
	};

conditional :
	expression comparator expression {
		YYDEBUG_PRINT("expr comp expr \n");
	} | NOT conditional {
		YYDEBUG_PRINT("not conditional \n");
	} | conditional AND conditional {
		YYDEBUG_PRINT("conditional and conditional \n");
	} | conditional OR conditional {
		YYDEBUG_PRINT("conditional or conditional \n");
	};

for_statement :
	FOR identifier IS expression BY expression TO expression DO statement_list ENDFOR {
		YYDEBUG_PRINT("Found for statement \n");
	};

while_statement :
	WHILE conditional DO statement_list ENDWHILE {
		YYDEBUG_PRINT("Found while statement \n");
	};

do_statement :
	DO statement_list WHILE conditional ENDDO {
		YYDEBUG_PRINT("Found do statement \n");
	};
%%