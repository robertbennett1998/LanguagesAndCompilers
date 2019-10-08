%{
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
%token<ival> ENDP DECLARATIONS CODE TYPE_CHARACTER TYPE_INTEGER TYPE_REAL IF ELSE NOT OF TYPE THEN ENDIF AND OR DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR NEWLINE WRITE READ ASSIGNMENT_OPERATOR EQUALITY_OPERATOR NOT_EQUAL_TO_OPERATOR LESS_THAN_OPERATOR MORE_THAN_OPERATOR LESS_EQUAL_TO_OPERATOR MORE_EQUAL_TO_OPERATOR OPEN_BRACKET CLOSE_BRACKET COMMA COLON SEMI_COLON PERIOD ADD_OPERATOR SUBTRACT_OPERATOR DIVISION_OPERATOR MULTIPULCATION_OPERATOR UNSIGNED_INTEGER

//tmp
%token<fval> REAL

%%

program :
	identifier COLON block ENDP identifier PERIOD {
		
	};

identifier :
	IDENTIFIER {
		
	};

block :
	DECLARATIONS declaration_block CODE statement_list {
		
	} |
	CODE statement_list {
		
	};

declaration_block : 
	declaration {
		
	} |
	declaration_block declaration {
		
	};

declaration :
	identifier_list OF TYPE type SEMI_COLON {
		
	};

identifier_list :
	identifier {
		
	} |
	identifier_list COMMA identifier {
		
	};

type :
	TYPE_CHARACTER {
		
	} |
	TYPE_INTEGER {
		
	} |
	TYPE_REAL {
		
	}

statement_list :
	statement {
	
	} |
	statement_list SEMI_COLON statement
	{
		
	};

statement :
	assignment_statement {
		
	} |
	write_statement {
		
	} |
	read_statement {
		
	} |
	if_statement {
		
	} |
	for_statement {
		
	} |
	while_statement {
		
	} |
	do_statement {
		
	};

assignment_statement :
	expression ASSIGNMENT_OPERATOR identifier {
		
	};

value :
	OPEN_BRACKET expression CLOSE_BRACKET {
		
	} |
	constant {
		
	} |
	identifier {
		
	};

expression :
	expression ADD_OPERATOR term {
		
	} |
	expression SUBTRACT_OPERATOR term {

	} | 
	term {
		
	};

term :
	term MULTIPULCATION_OPERATOR value {
		
	} |
	term DIVISION_OPERATOR value {
		
	} |
	value {
		
	};

write_statement :
	WRITE OPEN_BRACKET output_list CLOSE_BRACKET {
		
	} |
	NEWLINE {
		
	};

output_list :
	value {
		
	} |
	output_list COMMA value {
		
	};

constant :
	number_constant {
		
	} |
	CHARACTER_CONSTANT {
		
	};

number_constant :
	integer {
		
	} |
	real {
		
	}

integer :
	UNSIGNED_INTEGER {
		
	} |
	SUBTRACT_OPERATOR UNSIGNED_INTEGER;

real :
	REAL {
		
	};

comparator :
	EQUALITY_OPERATOR {
		
	} |
	NOT_EQUAL_TO_OPERATOR {
		
	} |
	LESS_THAN_OPERATOR {
		
	} |
	MORE_THAN_OPERATOR {
		
	} |
	LESS_EQUAL_TO_OPERATOR {
		
	} |
	MORE_EQUAL_TO_OPERATOR {
		
	};

read_statement :
	READ OPEN_BRACKET identifier CLOSE_BRACKET {
		
	};

if_statement :
	IF conditional THEN statement_list ENDIF {
		
	} |
	IF conditional THEN statement_list ELSE statement_list ENDIF {
		
	};

conditional :
	expression comparator expression {
		
	} | NOT conditional {
		
	} | conditional AND conditional {
		
	} | conditional OR conditional {
		
	};

for_statement :
	FOR identifier IS expression BY expression TO expression DO statement_list ENDFOR {
		
	};

while_statement :
	WHILE conditional DO statement_list ENDWHILE {
		
	};

do_statement :
	DO statement_list WHILE conditional ENDDO {
		
	};
%%