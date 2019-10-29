%{
	#include "spl.y.h"
	#include "code_gen.h"
%}

%union
{
	int iVal;
	float fVal;
	char cVal;
	Node* pNode;
	SymbolTableEntry* pSymbolTableEntry;
}

%token ENDP DECLARATIONS CODE TYPE_CHARACTER TYPE_INTEGER TYPE_REAL IF ELSE NOT OF TYPE THEN ENDIF AND OR DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR NEWLINE WRITE READ ASSIGNMENT_OPERATOR EQUALITY_OPERATOR NOT_EQUAL_TO_OPERATOR LESS_THAN_OPERATOR MORE_THAN_OPERATOR LESS_EQUAL_TO_OPERATOR MORE_EQUAL_TO_OPERATOR OPEN_BRACKET CLOSE_BRACKET COMMA COLON SEMI_COLON PERIOD ADD_OPERATOR SUBTRACT_OPERATOR DIVISION_OPERATOR MULTIPULCATION_OPERATOR
%token<cVal> CHARACTER_CONSTANT
%token<iVal> UNSIGNED_INTEGER SIGNED_INTEGER
%token<fVal> REAL
%token<pSymbolTableEntry> IDENTIFIER
%type<pNode> program block declaration_block statement_list declaration identifier_list type statement assignment_statement value expression term write_statement output_list constant comparator read_statement if_statement if_else_statement conditional logical comparison for_statement while_statement do_statement

%start program

%%

program :
	IDENTIFIER COLON block ENDP IDENTIFIER PERIOD {
		if ($1 != $5)
		{
			HANDLE_WARNING("Program names do not match %s vs %s\n", $1->symbolDetails.variableDetails.acIdentifier, $5->symbolDetails.variableDetails.acIdentifier);
		}

		$1->bySymbolType = symbol_id_program;
		$5->bySymbolType = symbol_id_program;
		SymbolTableEntry* pNewSymbol = malloc(sizeof(SymbolTableEntry));
		pNewSymbol->bySymbolType = symbol_id_program;
		strcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, $1->symbolDetails.variableDetails.acIdentifier);
		pNewSymbol->pNextTableEntry = $1->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = $1->pPrevTableEntry;
		memcpy($1, pNewSymbol, sizeof(SymbolTableEntry));
		strcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, $5->symbolDetails.variableDetails.acIdentifier);
		pNewSymbol->pNextTableEntry = $5->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = $5->pPrevTableEntry;
		memcpy($5, pNewSymbol, sizeof(SymbolTableEntry));
		free(pNewSymbol);

		Node* pParseTree = CreateNode($1, id_program, $3, NO_CHILD_NODE, NO_CHILD_NODE);

		#ifdef DEBUG
			PrintTree(pParseTree, 0);
		#endif

		GenerateCode(pParseTree);

		$$ = pParseTree;
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
		Node* pIdentifierListNode = $1;
		while (pIdentifierListNode != NO_SYMBOL_FOUND)
		{
			pIdentifierListNode->pSymbolTableEntry->symbolDetails.variableDetails.iType = $4->pSymbolTableEntry->symbolDetails.typeDetails.iType;
			pIdentifierListNode = pIdentifierListNode->pFirstChild;
		};

		Node* pNode = CreateNode(NO_SYMBOLIC_LINK, id_declaration, $1, $4, NO_CHILD_NODE);

		$$ = pNode;
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
		$$ = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_CHARACTER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	TYPE_INTEGER {
		//TODO: NOTE: Not sure how to handle this yet
		$$ = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_INTEGER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	TYPE_REAL {
		//TODO: NOTE: Not sure how to handle this yet
		$$ = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_REAL), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
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
	if_else_statement {
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
		MarkSymbolAsAssigned($3);

		$$ = CreateNode($3, id_assignment_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

value :
	OPEN_BRACKET expression CLOSE_BRACKET {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_value, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	IDENTIFIER {
		MarkSymbolAsUsed($1);

		$$ = CreateNode($1, id_value, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	constant {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_value, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

expression :
	expression SUBTRACT_OPERATOR term {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_subtract), id_expression, $1, $3, NO_CHILD_NODE);
	} |
	expression ADD_OPERATOR term {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_add), id_expression, $1, $3, NO_CHILD_NODE);
	} |
	term {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_expression, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

term :
	term MULTIPULCATION_OPERATOR value {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_multipulcation), id_term, $1, $3, NO_CHILD_NODE);
	} |
	term DIVISION_OPERATOR value {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_division), id_term, $1, $3, NO_CHILD_NODE);
	} |
	value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_term, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

constant :
	REAL {
		$$ = CreateNode(CreateSymbolTableEntry_Constant(TYPE_REAL, &$1), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	UNSIGNED_INTEGER {
		$$ = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &$1), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	SUBTRACT_OPERATOR UNSIGNED_INTEGER {
		$2 = -$2;
		$$ = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &$2), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	CHARACTER_CONSTANT {
		$$ = CreateNode(CreateSymbolTableEntry_Constant(TYPE_CHARACTER, &$1), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

write_statement :
	WRITE OPEN_BRACKET output_list CLOSE_BRACKET {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, $3, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	NEWLINE {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

output_list :
	value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_output_list, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	output_list COMMA value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_output_list, $1, $3, NO_CHILD_NODE);
	};

comparator :
	EQUALITY_OPERATOR {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_equality), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	NOT_EQUAL_TO_OPERATOR {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	LESS_THAN_OPERATOR {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_less_than), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	MORE_THAN_OPERATOR {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_more_than), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	} |
	LESS_EQUAL_TO_OPERATOR {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_less_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	} |
	MORE_EQUAL_TO_OPERATOR {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_more_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	};

read_statement :
	READ OPEN_BRACKET IDENTIFIER CLOSE_BRACKET {
		MarkSymbolAsAssigned($3);

		$$ = CreateNode($3, id_read_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	};

if_statement :
	IF conditional THEN statement_list ENDIF {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_if_statement, $2, $4, NO_CHILD_NODE);
	};

if_else_statement :
	IF conditional THEN statement_list ELSE statement_list ENDIF {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_if_else_statement, $2, $4, $6);
	};

conditional :
	logical {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_conditional, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} | conditional AND logical {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_and), id_conditional, $1, $3, NO_CHILD_NODE);
	} | conditional OR logical {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_or), id_conditional, $1, $3, NO_CHILD_NODE);
	};

logical :
	comparison {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_logical, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	NOT comparison {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not), id_logical, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	}

comparison :
	expression comparator expression {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparison, $1, $2, $3);
	};

for_statement :
	FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR {
		//TODO: THIS ISNT GOING TO WORK
		MarkSymbolAsAssigned($2);
		$$ = CreateNode($2, id_for_statement, CreateNode(NO_SYMBOLIC_LINK, id_for_statement_is_by_to, $4, $6, $8), $10, NO_CHILD_NODE);
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

SymbolTableEntry* CreateSymbolTableEntry_Variable(const char* pIdentifier)
{
	SymbolTableEntry* pEntry = GetSymbolTableEntry_Variable(pIdentifier);
	if (pEntry == NO_SYMBOL_FOUND)
	{
		pEntry = malloc(sizeof(SymbolTableEntry));
		memset(pEntry, 0, sizeof(SymbolTableEntry));
	}
	else
	{
		//printf("Existing symbol table entry: %s\n", pIdentifier);
		return pEntry;
	}

	pEntry->pNextTableEntry = NO_SYMBOLIC_LINK;
	pEntry->bySymbolType = symbol_id_variable;
	pEntry->symbolDetails.variableDetails.bAssignedTo = false;
	pEntry->symbolDetails.variableDetails.bUsed = false;
	//TODO: Should probs add string length check and throw error? or generate a mangled symbol name? or just cut off the symbol name?
	strncpy(pEntry->symbolDetails.variableDetails.acIdentifier, pIdentifier, MAX_IDENTIFIER_LENGTH);

	if (g_pSymbolTableStart == NO_SYMBOLIC_LINK)
	{
		g_pSymbolTableStart = pEntry;
		g_pSymbolTableEnd = pEntry;
	}
	else
	{
		pEntry->pPrevTableEntry = g_pSymbolTableEnd;
		g_pSymbolTableEnd->pNextTableEntry = pEntry;
		g_pSymbolTableEnd = pEntry;
	}

	return pEntry;
}

SymbolTableEntry* CreateSymbolTableEntry_Type(const int iType)
{
	SymbolTableEntry* pEntry = GetSymbolTableEntry_Type(iType);
	if (pEntry == NO_SYMBOL_FOUND)
	{
		pEntry = malloc(sizeof(SymbolTableEntry));
		memset(pEntry, 0, sizeof(SymbolTableEntry));
	}
	else
	{
		//printf("Existing symbol table entry: %s\n", pIdentifier);
		return pEntry;
	}

	pEntry->pNextTableEntry = NO_SYMBOLIC_LINK;
	pEntry->bySymbolType = symbol_id_type;
	pEntry->symbolDetails.typeDetails.iType = iType;

	if (g_pSymbolTableStart == NO_SYMBOLIC_LINK)
	{
		g_pSymbolTableStart = pEntry;
		g_pSymbolTableEnd = pEntry;
	}
	else
	{
		pEntry->pPrevTableEntry = g_pSymbolTableEnd;
		g_pSymbolTableEnd->pNextTableEntry = pEntry;
		g_pSymbolTableEnd = pEntry;
	}

	return pEntry;
}

SymbolTableEntry* CreateSymbolTableEntry_Constant(const int iType, const void* pValue)
{
	SymbolTableEntry* pEntry = GetSymbolTableEntry_Constant(iType, pValue);
	if (pEntry == NO_SYMBOL_FOUND)
	{
		pEntry = malloc(sizeof(SymbolTableEntry));
		memset(pEntry, 0, sizeof(SymbolTableEntry));
	}
	else
	{
		//printf("Existing symbol table entry: %s\n", pIdentifier);
		return pEntry;
	}

	pEntry->pNextTableEntry = NO_SYMBOLIC_LINK;
	pEntry->bySymbolType = symbol_id_constant;
	pEntry->symbolDetails.constantDetails.iType = iType;
	if (iType == TYPE_INTEGER)
	{
		pEntry->symbolDetails.constantDetails.value.i = *(int*)pValue;
	}
	else if (iType == TYPE_REAL)
	{
		pEntry->symbolDetails.constantDetails.value.f = *(float*)pValue;
	}
	else if (iType == TYPE_CHARACTER)
	{
		pEntry->symbolDetails.constantDetails.value.c = *(char*)pValue;
	}

	if (g_pSymbolTableStart == NO_SYMBOLIC_LINK)
	{
		g_pSymbolTableStart = pEntry;
		g_pSymbolTableEnd = pEntry;
	}
	else
	{
		pEntry->pPrevTableEntry = g_pSymbolTableEnd;
		g_pSymbolTableEnd->pNextTableEntry = pEntry;
		g_pSymbolTableEnd = pEntry;
	}

	return pEntry;
}

SymbolTableEntry* CreateSymbolTableEntry_Operator(const OperatorTypes operatorType)
{
	SymbolTableEntry* pEntry = GetSymbolTableEntry_Operator(operatorType);
	if (pEntry == NO_SYMBOL_FOUND)
	{
		pEntry = malloc(sizeof(SymbolTableEntry));
		memset(pEntry, 0, sizeof(SymbolTableEntry));
	}
	else
	{;
		return pEntry;
	}

	pEntry->pNextTableEntry = NO_SYMBOLIC_LINK;
	pEntry->bySymbolType = symbol_id_operator;
	pEntry->symbolDetails.operatorDetails.operatorType = operatorType;

	if (g_pSymbolTableStart == NO_SYMBOLIC_LINK)
	{
		g_pSymbolTableStart = pEntry;
		g_pSymbolTableEnd = pEntry;
	}
	else
	{
		pEntry->pPrevTableEntry = g_pSymbolTableEnd;
		g_pSymbolTableEnd->pNextTableEntry = pEntry;
		g_pSymbolTableEnd = pEntry;
	}

	return pEntry;
}

SymbolTableEntry* GetSymbolTableEntry_Variable(const char* pIdentifier)
{
	SymbolTableEntry* pCurrentEntry = g_pSymbolTableStart;
	while (pCurrentEntry != NO_SYMBOL_FOUND)
	{
		if (strcmp(pIdentifier, pCurrentEntry->symbolDetails.variableDetails.acIdentifier) == 0)
			return pCurrentEntry;

		pCurrentEntry = pCurrentEntry->pNextTableEntry;
	}

	return NO_SYMBOL_FOUND;
}

SymbolTableEntry* GetSymbolTableEntry_Type(const int iType)
{
	SymbolTableEntry* pCurrentEntry = g_pSymbolTableStart;
	while (pCurrentEntry != NO_SYMBOL_FOUND)
	{
		if (pCurrentEntry->bySymbolType == symbol_id_type)
		{
			if (pCurrentEntry->symbolDetails.typeDetails.iType == iType)
			{
				return pCurrentEntry;
			}
		}

		pCurrentEntry = pCurrentEntry->pNextTableEntry;
	}

	return NO_SYMBOL_FOUND;
}

SymbolTableEntry* GetSymbolTableEntry_Constant(const int iType, const void* pValue)
{
	SymbolTableEntry* pCurrentEntry = g_pSymbolTableStart;
	while (pCurrentEntry != NO_SYMBOL_FOUND)
	{
		if (pCurrentEntry->bySymbolType == symbol_id_constant)
		{
			if (pCurrentEntry->symbolDetails.constantDetails.iType == iType)
			{
				if (iType == TYPE_INTEGER)
				{
					if (pCurrentEntry->symbolDetails.constantDetails.value.i == *(int*)pValue)
					{
						return pCurrentEntry;
					}
				}
				else if (iType == TYPE_REAL)
				{
					if (iType == *(float*)pValue)
					{
						return pCurrentEntry;
					}
				}
				else if (iType == TYPE_CHARACTER)
				{
					if (pCurrentEntry->symbolDetails.constantDetails.value.c == *(char*)pValue)
					{
						return pCurrentEntry;
					}
				}
			}
		}

		pCurrentEntry = pCurrentEntry->pNextTableEntry;
	}

	return NO_SYMBOL_FOUND;
}

SymbolTableEntry* GetSymbolTableEntry_Operator(const OperatorTypes operatorType)
{
	SymbolTableEntry* pCurrentEntry = g_pSymbolTableStart;
	while (pCurrentEntry != NO_SYMBOL_FOUND)
	{
		if (pCurrentEntry->bySymbolType == symbol_id_operator)
		{
			if (pCurrentEntry->symbolDetails.operatorDetails.operatorType == operatorType)
			{
				return pCurrentEntry;
			}
		}

		pCurrentEntry = pCurrentEntry->pNextTableEntry;
	}

	return NO_SYMBOL_FOUND;
}

void MarkSymbolAsAssigned(SymbolTableEntry* pEntry)
{
	pEntry->symbolDetails.variableDetails.bAssignedTo = true;
	pEntry->symbolDetails.variableDetails.bUsed = false;
}

void MarkSymbolAsUsed(SymbolTableEntry* pEntry)
{
	if (pEntry->symbolDetails.variableDetails.bAssignedTo == false)
		HANDLE_WARNING("%s is used before it has been assigned to, this will have unexpected consequences!", pEntry->symbolDetails.variableDetails.acIdentifier);

	pEntry->symbolDetails.variableDetails.bUsed = true;
}

Node* CreateNode(SymbolTableEntry* pSymbolTableEntry, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild)
{
	Node* pNode = malloc(sizeof(Node));
	memset(pNode, 0, sizeof(Node));
	pNode->pSymbolTableEntry = pSymbolTableEntry;
	pNode->byNodeIdentifier = byNodeIdentifier;
	pNode->pFirstChild = pFirstChild;
	pNode->pSecondChild = pSecondChild;
	pNode->pThirdChild = pThirdChild;

	return pNode;
}

void PrintTree(const Node* pStartNode, int iLevel)
{
	if (pStartNode == NULL)
		return;

	//printf("%p\n", pStartNode);

	int i;
	printf("Level %d   \t", iLevel);
	for (i = 0; i < iLevel; i++)
		printf("...|");

	printf("%s (%d)", NodeIdentifiersValueToString(pStartNode->byNodeIdentifier), pStartNode->byNodeIdentifier);

	if (pStartNode->pSymbolTableEntry == NO_SYMBOL_FOUND)
	{
		printf("\n");
	}
	else
	{
		if (pStartNode->pSymbolTableEntry->bySymbolType == symbol_id_variable)
		{
			printf(" - Symbol (Variable) Info: Identifier = %s - Type = %s - Assigned To = %d - Used = %d\n", 	pStartNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier, 
																									GetTypeName(pStartNode->pSymbolTableEntry->symbolDetails.variableDetails.iType), 
																									pStartNode->pSymbolTableEntry->symbolDetails.variableDetails.bAssignedTo, 
																									pStartNode->pSymbolTableEntry->symbolDetails.variableDetails.bUsed);
		}
		else if (pStartNode->pSymbolTableEntry->bySymbolType == symbol_id_constant)
		{
			printf(" - Symbol (Constant) Info: Type = %s - ", GetTypeName(pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.iType));
			if (pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_INTEGER)
			{
				printf("Value = %d\n", pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.value.i);
			}
			else if (pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_REAL)
			{
				printf("Value = %f\n", pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.value.f);
			}
			else if (pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_CHARACTER)
			{
				printf("Value = %c\n", pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.value.c);
			}
		}
		else if (pStartNode->pSymbolTableEntry->bySymbolType == symbol_id_operator)
		{
			printf(" - Symbol (Operator) Info: Type = %s\n", OperatorTypesValueToString(pStartNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType));
		}
		else
		{
			printf("\n");
		}
	}
	iLevel++;

	//Select first tree
	PrintTree(pStartNode->pFirstChild, iLevel);

	//Select second tree
	PrintTree(pStartNode->pSecondChild, iLevel);

	//Select third tree
	PrintTree(pStartNode->pThirdChild, iLevel);
}

void GenerateAndPrintWarnings()
{
	//Check symbol tree for any things not assigned to or used
	SymbolTableEntry* pEntry = g_pSymbolTableStart;
	while (pEntry != NO_SYMBOL_FOUND)
	{
		if (pEntry->bySymbolType == symbol_id_variable)
		{
			if (pEntry->symbolDetails.variableDetails.bAssignedTo == false && pEntry->symbolDetails.variableDetails.bUsed == false)
			{
				HANDLE_WARNING("%s is declared but is neither assigned to or used!\n", pEntry->symbolDetails.variableDetails.acIdentifier);
			}
			else if (pEntry->symbolDetails.variableDetails.bAssignedTo == true && pEntry->symbolDetails.variableDetails.bUsed == false)
			{
				HANDLE_WARNING("%s is declared and is assigned to but never used!\n", pEntry->symbolDetails.variableDetails.acIdentifier);
			}
			else if (pEntry->symbolDetails.variableDetails.bAssignedTo == false && pEntry->symbolDetails.variableDetails.bUsed == true)
			{
				HANDLE_WARNING("%s is declared and used but never assigned to, this may have unexpected consequences!\n", pEntry->symbolDetails.variableDetails.acIdentifier);
			}
		}

		pEntry = pEntry->pNextTableEntry;
	}
}

const char* GetTypeName(const int iType)
{
	switch (iType)
	{
		case TYPE_INTEGER:
			return "INTEGER";

		case TYPE_CHARACTER:
			return "CHARACTER";

		case TYPE_REAL:
			return "REAL";
		
		default:
			return "Unknown type";
	}
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
		case id_type: 
			return "id_type";
		case id_real: 
			return "id_real";
		case id_integer: 
			return "id_integer";
		case id_comparator: 
			return "id_comparator";
		case id_read_statement: 
			return "id_read_statement";
		case id_if_statement: 
			return "id_if_statement";
		case id_if_else_statement: 
			return "id_if_else_statement";
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

void PrintOperatorTypesValue(const OperatorTypes value) 
{
	printf("%s (%d)\n", NodeIdentifiersValueToString(value), (int)value);
}

const char* OperatorTypesValueToString(const OperatorTypes value)
{
	switch (value) 
	{ 
		default: 
			return "Unknown value";
		case operator_type_unknown: 
			return "operator_type_unknown";
		case operator_type_equality: 
			return "operator_type_equality";
		case operator_type_not_equal: 
			return "operator_type_not_equal";
		case operator_type_less_than: 
			return "operator_type_less_than";
		case operator_type_more_than: 
			return "operator_type_more_than";
		case operator_type_less_equal: 
			return "operator_type_less_equal";
		case operator_type_more_equal: 
			return "operator_type_more_equal";
		case operator_type_multipulcation: 
			return "operator_type_multipulcation";
		case operator_type_division: 
			return "operator_type_division";
		case operator_type_add: 
			return "operator_type_add";
		case operator_type_subtract: 
			return "operator_type_subtract";
		case operator_type_not: 
			return "operator_type_not";
		case operator_type_and: 
			return "operator_type_and";
		case operator_type_or: 
			return "operator_type_or";
	}
}

#include "lex.yy.c"