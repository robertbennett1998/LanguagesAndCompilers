%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define NO_CHILD_NODE NULL
	#define NO_SYMBOLIC_LINK NULL

	typedef struct _node
	{
		void* pSymbolTreePointer;
		unsigned char byNodeIdentifier;
		struct _node* pFirstChild;
		struct _node* pSecondChild;
		struct _node* pThirdChild;
		struct _node* pParent;
	} Node;

	typedef enum _nodeIdentifiers
	{
		id_program = 1,
		id_block,
		id_declaration_block,
		id_declaration,
		id_identifier_list,
		id_statement_list,
		id_statement,
		id_assignment_statement,
		id_value,
		id_expression,
		id_term,
		id_write_statement,
		id_output_list,
		id_constant,
		id_number_constant,
		id_integer,
		id_real,
		id_comparator,
		id_read_statement,
		id_if_statement,
		id_if_statement_else,
		id_conditional,
		id_conditional_not,
		id_conditional_and,
		id_conditional_or,
		id_comparison,
		id_for_statement,
		id_for_statement_is_by_to,
		id_while_statement,
		id_do_statement
	} NodeIdentifiers;

	volatile Node* g_pRootNode = NULL;
	Node* CreateNode(char* pSymbolTreePointer, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild);
	void PrintTree(const Node* pStartNode, int iLevel);

	void PrintNodeIdentifiersValue(const NodeIdentifiers value);
	const char* NodeIdentifiersValueToString(const NodeIdentifiers value);
%}

%union
{
	int iVal;
	float fVal;
	char cVal;
	Node* pNode;
	void* pSymbolTreePointer;
}

%token ENDP DECLARATIONS CODE TYPE_CHARACTER TYPE_INTEGER TYPE_REAL IF ELSE NOT OF TYPE THEN ENDIF AND OR DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR NEWLINE WRITE READ ASSIGNMENT_OPERATOR EQUALITY_OPERATOR NOT_EQUAL_TO_OPERATOR LESS_THAN_OPERATOR MORE_THAN_OPERATOR LESS_EQUAL_TO_OPERATOR MORE_EQUAL_TO_OPERATOR OPEN_BRACKET CLOSE_BRACKET COMMA COLON SEMI_COLON PERIOD ADD_OPERATOR SUBTRACT_OPERATOR DIVISION_OPERATOR MULTIPULCATION_OPERATOR
%token<cVal> CHARACTER_CONSTANT
%token<iVal> UNSIGNED_INTEGER SIGNED_INTEGER
%token<fVal> REAL
%token<pSymbolTreePointer> IDENTIFIER
%type<pNode> program block declaration_block statement_list declaration identifier_list type statement assignment_statement value expression term write_statement output_list constant number_constant integer real comparator read_statement if_statement conditional comparison for_statement while_statement do_statement

%start program

%%

program :
	IDENTIFIER COLON block ENDP IDENTIFIER PERIOD {
		g_pRootNode = CreateNode($1, id_program, $3, NO_CHILD_NODE, NO_CHILD_NODE);
		PrintTree(g_pRootNode, 0);
		$$ = g_pRootNode;
	};

block :
	DECLARATIONS declaration_block CODE statement_list {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_block, $2, $4, NO_CHILD_NODE);
	} |
	CODE statement_list {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_block, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	};

declaration_block : 
	declaration {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_declaration_block, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	declaration_block declaration {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_declaration_block, $1, $2, NO_CHILD_NODE);
	};

declaration :
	identifier_list OF TYPE type SEMI_COLON {
		//TODO: NOTE: How do we get the type into the symbol table. Does the type need to become a node?
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_declaration, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

identifier_list :
	IDENTIFIER {
		$$ = CreateNode($1, id_identifier_list, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	identifier_list COMMA IDENTIFIER {
		$$ = CreateNode($3, id_identifier_list, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

type :
	TYPE_CHARACTER {
		//TODO: NOTE: Not sure how to handle this yet
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_identifier_list, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	TYPE_INTEGER {
		//TODO: NOTE: Not sure how to handle this yet
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_identifier_list, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	TYPE_REAL {
		//TODO: NOTE: Not sure how to handle this yet
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_identifier_list, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}

statement_list :
	statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement_list, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	statement_list SEMI_COLON statement
	{
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement_list, $1, $3, NO_CHILD_NODE);
	};

statement :
	assignment_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	write_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	read_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	if_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	for_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	while_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	do_statement {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

assignment_statement :
	expression ASSIGNMENT_OPERATOR IDENTIFIER {
		$$ = CreateNode($3, id_assignment_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

value :
	OPEN_BRACKET expression CLOSE_BRACKET {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_value, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	constant {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_value, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	IDENTIFIER {
		$$ = CreateNode($1, id_value, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

expression :
	expression ADD_OPERATOR term {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_expression, $1, $3, NO_CHILD_NODE);
	} |
	expression SUBTRACT_OPERATOR term {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_expression, $1, $3, NO_CHILD_NODE);
	} | 
	term {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_expression, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

term :
	term MULTIPULCATION_OPERATOR value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_term, $1, $3, NO_CHILD_NODE);
	} |
	term DIVISION_OPERATOR value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_term, $1, $3, NO_CHILD_NODE);
	} |
	value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_term, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

write_statement :
	WRITE OPEN_BRACKET output_list CLOSE_BRACKET {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, $3, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	NEWLINE {
		//TODO: NOTE: Hmmmmm not sure this is right, I think there should be another rule for NEWLINE and then create a node for it or just have id_newline
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

output_list :
	value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_output_list, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	output_list COMMA value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_output_list, $1, $3, NO_CHILD_NODE);
	};

constant :
	number_constant {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_constant, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	CHARACTER_CONSTANT {
		//TODO: NOTE: Not sure about this one either, probs a symbolic link?
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

number_constant :
	integer {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_number_constant, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	real {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_number_constant, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	}

integer :
	UNSIGNED_INTEGER {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_integer, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	SIGNED_INTEGER {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_integer, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

real :
	REAL {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_real, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

comparator :
	EQUALITY_OPERATOR {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	NOT_EQUAL_TO_OPERATOR {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	LESS_THAN_OPERATOR {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	MORE_THAN_OPERATOR {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	} |
	LESS_EQUAL_TO_OPERATOR {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	} |
	MORE_EQUAL_TO_OPERATOR {
		//TODO: HMMMMM
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	};

read_statement :
	READ OPEN_BRACKET IDENTIFIER CLOSE_BRACKET {
		$$ = CreateNode($3, id_read_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

if_statement :
	IF conditional THEN statement_list ENDIF {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_if_statement, $2, $4, NO_CHILD_NODE);
	} |
	IF conditional THEN statement_list ELSE statement_list ENDIF {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_if_statement_else, $2, $4, $6);
	};

conditional :
	comparison {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_conditional, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} | NOT conditional {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_conditional_not, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	} | conditional AND comparison {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_conditional_and, $1, $3, NO_CHILD_NODE);
	} | conditional OR comparison {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_conditional_or, $1, $3, NO_CHILD_NODE);
	};

comparison :
	expression comparator expression {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparison, $1, $2, $3);
	};

for_statement :
	FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR {
		//TODO: THIS ISNT GOING TO WORK
		$$ = CreateNode($2, id_for_statement, CreateNode(NO_SYMBOLIC_LINK, id_for_statement_is_by_to, $4, $6, $8), NO_CHILD_NODE, NO_CHILD_NODE);
	};

while_statement :
	WHILE conditional DO statement_list ENDWHILE {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_while_statement, $2, $4, NO_CHILD_NODE);
	};

do_statement :
	DO statement_list WHILE conditional ENDDO {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, $2, $4, NO_CHILD_NODE);
	};
%%

Node* CreateNode(char* pSymbolTreePointer, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild)
{
	Node* pNode = malloc(sizeof(Node));
	memset(pNode, 0, sizeof(Node));
	pNode->pSymbolTreePointer = pSymbolTreePointer;
	pNode->byNodeIdentifier = byNodeIdentifier;
	pNode->pFirstChild = pFirstChild;
	pNode->pSecondChild = pSecondChild;
	pNode->pThirdChild = pThirdChild;

	if (pFirstChild != NO_CHILD_NODE)
		pFirstChild->pParent = pNode;

	if (pSecondChild != NO_CHILD_NODE)
		pSecondChild->pParent = pNode;

	if (pThirdChild != NO_CHILD_NODE)
		pThirdChild->pParent = pNode;

	return pNode;
}

void PrintTree(const Node* pStartNode, int iLevel)
{
	if (pStartNode == NULL)
		return;

	PrintLevelSpacing(iLevel);
	printf("%s (%d)\n", NodeIdentifiersValueToString(pStartNode->byNodeIdentifier), pStartNode->byNodeIdentifier);

	iLevel++;

	//Select first tree
	PrintTree(pStartNode->pFirstChild, iLevel);

	//Select second tree
	PrintTree(pStartNode->pSecondChild, iLevel);

	//Select third tree
	PrintTree(pStartNode->pThirdChild, iLevel);
}

void PrintLevelSpacing(const int iLevel)
{
	int i;
	printf("Level %d  \t", iLevel);
	for (i = 0; i < iLevel; i++)
		printf("...");
}

void PrintNodeIdentifiersValue(const NodeIdentifiers value) 
{
	printf("%s (%d)\n", NodeIdentifiersValueToString(value), (int)value);
}

const char* NodeIdentifiersValueToString(const NodeIdentifiers value)
{
	switch (value) 
	{ 
		default: 
			return "Unknown value";
		case id_program: 
			return "id_program";
		case id_block: 
			return "id_block";
		case id_declaration_block: 
			return "id_declaration_block";
		case id_declaration: 
			return "id_declaration";
		case id_identifier_list: 
			return "id_identifier_list";
		case id_statement_list: 
			return "id_statement_list";
		case id_statement: 
			return "id_statement";
		case id_assignment_statement: 
			return "id_assignment_statement";
		case id_value: 
			return "id_value";
		case id_expression: 
			return "id_expression";
		case id_term: 
			return "id_term";
		case id_write_statement: 
			return "id_write_statement";
		case id_output_list: 
			return "id_output_list";
		case id_constant: 
			return "id_constant";
		case id_number_constant: 
			return "id_number_constant";
		case id_integer: 
			return "id_integer";
		case id_real: 
			return "id_real";
		case id_comparator: 
			return "id_comparator";
		case id_read_statement: 
			return "id_read_statement";
		case id_if_statement: 
			return "id_if_statement";
		case id_if_statement_else: 
			return "id_if_statement_else";
		case id_conditional: 
			return "id_conditional";
		case id_conditional_not: 
			return "id_conditional_not";
		case id_conditional_and: 
			return "id_conditional_and";
		case id_conditional_or: 
			return "id_conditional_or";
		case id_comparison: 
			return "id_comparison";
		case id_for_statement: 
			return "id_for_statement";
		case id_for_statement_is_by_to: 
			return "id_for_statement_is_by_to";
		case id_while_statement: 
			return "id_while_statement";
		case id_do_statement: 
			return "id_do_statement";
	}
}

#include <lex.yy.c>