%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
	#include <limits.h>
	#include <stdlib.h>
	#include <float.h>

	#define NO_PARENT_NODE NULL
    #define NO_CHILD_NODE NULL
    #define NO_SYMBOLIC_LINK NULL
    #define NO_SYMBOL_FOUND NULL
	#define NO_VARIABLE_USAGE_NODE NULL
	#define NO_ERRORS NULL
    #define UNKNOWN_SYMBOL_TYPE -1
    #define MAX_IDENTIFIER_LENGTH 55 /*4 extra for spl_ 1 extra char for \0*/
	#define SAFE_ASSIGN(ptr, var, val) if (ptr != NULL) { ptr->var = val; }

	typedef struct _node Node;
	typedef struct _symbolTableEntry SymbolTableEntry;

    /* SYMBOL TABLE */
    typedef enum _symbolTypes
    {
        symbol_id_unknown = 0,
        symbol_id_program,
        symbol_id_variable,
        symbol_id_constant,
        symbol_id_type,
        symbol_id_operator
    } SymbolTypes;

    typedef struct _programDetails
    {
        char acIdentifier[MAX_IDENTIFIER_LENGTH];
        unsigned int uiVariableCount;
        unsigned int uiStatementCount;
    } ProgramDetails;

	typedef enum _variableUsageType
	{
		variable_usage_declaration,
		variable_usage_assignment,
		variable_usage_used
	} VariableUsageType;

	typedef struct _variableUsageDetails
	{
		VariableUsageType usageType;
		unsigned int uiLine;
		unsigned int uiPos;
		Node* pParentNode;
		struct _variableUsageDetails * pNextUsage;
		struct _variableUsageDetails * pPrevUsage;
	} VariableUsageDetails;

    typedef struct _variableDetails
    {
        char acIdentifier[MAX_IDENTIFIER_LENGTH];
        int iType;
		VariableUsageDetails* pFirstUsage;
		VariableUsageDetails* pLastUsage;
    } VariableDetails;

	void EvaluateVariableUsage();
	void CreateVariableDeclaredEntry(SymbolTableEntry* pSymbol, Node* pParentNode);
	void CreateVariableAssignedEntry(SymbolTableEntry* pSymbol, Node* pParentNode);
	void CreateVariableUsedEntry(SymbolTableEntry* pSymbol, Node* pParentNode);
	void CreateVariableUsageEntry(VariableUsageDetails* pUsageDetails, VariableDetails* pVariableDetails, Node* pParentNode);

    typedef struct _constantDetails
    {
        int iType;
        union 
        {
            int i;
            double f;
            char c;
        } value;
    } ConstantDetails;

    typedef struct _typeDetails
    {
        int iType;
    } TypeDetails;

    typedef enum _operatorTypes
    {
        operator_type_unknown = 0,
        operator_type_equality,
        operator_type_not_equal,
        operator_type_less_than,
        operator_type_more_than,
        operator_type_less_equal,
        operator_type_more_equal,
        operator_type_multipulcation,
        operator_type_division,
        operator_type_add,
        operator_type_subtract,
        operator_type_not,
        operator_type_and,
        operator_type_or
    } OperatorTypes;
    void PrintOperatorTypesValue(const OperatorTypes value);
    const char* OperatorTypesValueToString(const OperatorTypes value);

    typedef struct _operatorDetails
    {
        OperatorTypes operatorType;
    } OperatorDetails;

    struct _symbolTableEntry
    {
        struct _symbolTableEntry* pNextTableEntry;
        struct _symbolTableEntry* pPrevTableEntry;
        unsigned char bySymbolType;
        union
        {
            ProgramDetails programDetails;
            VariableDetails variableDetails;
            ConstantDetails constantDetails;
            TypeDetails typeDetails;
            OperatorDetails operatorDetails;
        } symbolDetails;
        
    };

    SymbolTableEntry* g_pSymbolTableStart;
    SymbolTableEntry* g_pSymbolTableEnd;

    SymbolTableEntry* CreateSymbolTableEntry_Variable(const char* pIdentifier);
    SymbolTableEntry* CreateSymbolTableEntry_Type(const int iType);
    SymbolTableEntry* CreateSymbolTableEntry_Constant(const int iType, const void* pValue);
    SymbolTableEntry* CreateSymbolTableEntry_Operator(const OperatorTypes operatorType);

    SymbolTableEntry* GetSymbolTableEntry_Variable(const char* pIdentifier);
    SymbolTableEntry* GetSymbolTableEntry_Type(const int iType);
    SymbolTableEntry* GetSymbolTableEntry_Constant(const int iType, const void* pValue);
    SymbolTableEntry* GetSymbolTableEntry_Operator(const OperatorTypes operatorType);

    const char* GetTypeName(const int iType);

	void CheckIfVariableIsDeclared(SymbolTableEntry* pEntry);

    /* PARSE TREE */
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
        id_type,
        id_integer,
        id_comparator,
        id_read_statement,
        id_if_statement,
        id_if_else_statement,
        id_conditional,
        id_comparison,
        id_for_statement,
		id_for_statement_is_by_to,
        id_while_statement,
        id_do_statement
    } NodeIdentifiers;

    struct _node
    {
        SymbolTableEntry* pSymbolTableEntry;
        NodeIdentifiers byNodeIdentifier;
        struct _node* pFirstChild;
        struct _node* pSecondChild;
        struct _node* pThirdChild;
		struct _node* pParent;
    };

    void PrintNodeIdentifiersValue(const NodeIdentifiers value);
    const char* NodeIdentifiersValueToString(const NodeIdentifiers value);

    Node* CreateNode(SymbolTableEntry* pSymbolTreePointer, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild);
    void PrintTree(const Node* pStartNode, int iLevel);

    /* CODE GENERATION */
    void GenerateCode(const Node* const pStartNode);

    extern unsigned int g_uiCurrentLineNumber;
    extern unsigned long g_ulCurrentLinePosition;
	extern bool g_bOptimisation_DeadStores, g_bOptimisation_FoldConstants, g_bStaticErrorChecking_DivisionByZero, g_bOptimisation_DeadCode;
    extern void PrintLinePositionUpdate();
    extern void IncrementLinePosition(const int iTokenLength);
    extern void ProcessEndOfLine();
    #define HANDLE_WARNING(message, ...) { fprintf(stderr, "[WARNING] - Line %d | Position %d - ", g_uiCurrentLineNumber, g_ulCurrentLinePosition); fprintf(stderr, message, ##__VA_ARGS__); fprintf(stderr, "\n"); }
	#define HANDLE_ERROR(message, ...) { fprintf(stderr, "[ERROR] - Line %d | Position %d - ", g_uiCurrentLineNumber, g_ulCurrentLinePosition); fprintf(stderr, message, ##__VA_ARGS__); fprintf(stderr, "\n"); }

	typedef enum _errorTypes
	{
		error_type_unknown = 0,
		error_type_invalid_character_constant,
		error_type_variable_not_declared,
		error_type_variable_redeclaration,
		error_type_unexpected_symbol,
		error_type_invalid_type_conversion_double_char,
		error_type_invalid_operation_char_multipulcation,
		error_type_invalid_operation_char_division,
		error_type_division_by_zero,
		error_type_identifier_too_long
	} ErrorTypes;

	unsigned int g_uiErrorCount = 0;
	void CreateError(ErrorTypes errorType, const void* const pValue);
	void CheckForDivideByZero(const Node* const pNode);
	void FoldConstants(Node* pNode);
	void RemoveDeadCode(Node* pNode);
%}

%union
{
	long iVal;
	double fVal;
	char cVal;
	Node* pNode;
	SymbolTableEntry* pSymbolTableEntry;
}

%token ENDP DECLARATIONS CODE TYPE_CHARACTER TYPE_INTEGER TYPE_REAL IF ELSE NOT OF TYPE THEN ENDIF AND OR DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR NEWLINE WRITE READ ASSIGNMENT_OPERATOR EQUALITY_OPERATOR NOT_EQUAL_TO_OPERATOR LESS_THAN_OPERATOR MORE_THAN_OPERATOR LESS_EQUAL_TO_OPERATOR MORE_EQUAL_TO_OPERATOR OPEN_BRACKET CLOSE_BRACKET COMMA COLON SEMI_COLON PERIOD ADD_OPERATOR SUBTRACT_OPERATOR DIVISION_OPERATOR MULTIPULCATION_OPERATOR
%token<cVal> CHARACTER_CONSTANT
%token<iVal> UNSIGNED_INTEGER
%token<fVal> REAL
%token<pSymbolTableEntry> IDENTIFIER
%type<pNode> program block declaration_block code statement_list declaration identifier_list type statement assignment_statement value expression term write_statement output_list constant comparator read_statement if_statement if_else_statement conditional comparison for_statement while_statement do_statement

%start program

%%

program :
	IDENTIFIER COLON block ENDP IDENTIFIER PERIOD {
		if ($1 != $5)
		{
			HANDLE_WARNING("Program names do not match %s vs %s", $1->symbolDetails.variableDetails.acIdentifier, $5->symbolDetails.variableDetails.acIdentifier);
		}

		$1->bySymbolType = symbol_id_program;
		$5->bySymbolType = symbol_id_program;
		SymbolTableEntry* pNewSymbol = malloc(sizeof(SymbolTableEntry));
		pNewSymbol->bySymbolType = symbol_id_program;
		strcpy(&pNewSymbol->symbolDetails.programDetails.acIdentifier[4], &$1->symbolDetails.variableDetails.acIdentifier[4]); /*Remove spl_*/
		memcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, "prg_", 4); 
		pNewSymbol->pNextTableEntry = $1->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = $1->pPrevTableEntry;
		memcpy($1, pNewSymbol, sizeof(SymbolTableEntry));
		if ($1 != $5)
		{
			memcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, "prg_", 4); 
			strcpy(&pNewSymbol->symbolDetails.programDetails.acIdentifier[4], &$5->symbolDetails.variableDetails.acIdentifier[4]); /*Remove spl_*/
		}
		pNewSymbol->pNextTableEntry = $5->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = $5->pPrevTableEntry;
		memcpy($5, pNewSymbol, sizeof(SymbolTableEntry));
		free(pNewSymbol);

		Node* pParseTree = CreateNode($1, id_program, $3, NO_CHILD_NODE, NO_CHILD_NODE);

		#ifdef DEBUG
			PrintTree(pParseTree, 0);
            return;
		#endif

		EvaluateVariableUsage();
		FoldConstants(pParseTree);
		CheckForDivideByZero(pParseTree);
		RemoveDeadCode(pParseTree);

		$$ = pParseTree;
		if (g_uiErrorCount == 0)
		{
			GenerateCode(pParseTree);
		}
	};

block :
	DECLARATIONS declaration_block CODE code {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_block, $2, $4, NO_CHILD_NODE);
	} |
	CODE code {
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
		Node* pNode = $$ = CreateNode(NO_SYMBOLIC_LINK, id_declaration, $1, $4, NO_CHILD_NODE);

		Node* pIdentifierListNode = $1;
		while (pIdentifierListNode != NO_SYMBOL_FOUND)
		{
			pIdentifierListNode->pSymbolTableEntry->symbolDetails.variableDetails.iType = $4->pSymbolTableEntry->symbolDetails.typeDetails.iType;
			CreateVariableDeclaredEntry(pIdentifierListNode->pSymbolTableEntry, pNode);
			pIdentifierListNode = pIdentifierListNode->pFirstChild;
		};
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
		$$ = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_CHARACTER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	TYPE_INTEGER {
		$$ = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_INTEGER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	TYPE_REAL {
		$$ = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_REAL), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}

code :
	statement_list {
		$$ = $1;
	} | statement_list SEMI_COLON {
		g_uiCurrentLineNumber--;
		HANDLE_WARNING("Unexpected semi-colon at the end of the last statement within the code block. This will be ignored.");
		g_uiCurrentLineNumber++;
		$$ = $1;
	};

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
		CheckIfVariableIsDeclared($3);
		Node* pNode = $$ = CreateNode($3, id_assignment_statement, $1, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableAssignedEntry($3, pNode);
		int iExpressionType = GetFinalTypeOfExpression($1, -1);
		if (iExpressionType == TYPE_REAL && $3->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_type_conversion_double_char, NULL);
		} 
		else if (iExpressionType == TYPE_INTEGER && $3->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
		{
			HANDLE_WARNING("An integer has been assigned to a variable of type characters.");
		}
		else if (iExpressionType == TYPE_REAL && $3->symbolDetails.variableDetails.iType == TYPE_INTEGER)
		{
			HANDLE_WARNING("A real has been assigned to a variable of type integer, this may cause a loss of precision.");
		}
	};

value :
	OPEN_BRACKET expression CLOSE_BRACKET {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_value, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	IDENTIFIER {
		CheckIfVariableIsDeclared($1);
		Node* pNode = $$ = CreateNode($1, id_value, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableUsedEntry($1, pNode);
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
		int iTermType = GetFinalTypeOfExpression($1, -1);
		int iValueType = GetFinalTypeOfExpression($3, -1);
		if (iValueType == TYPE_CHARACTER || iTermType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_operation_char_multipulcation, NULL);
		}

		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_multipulcation), id_term, $1, $3, NO_CHILD_NODE);
	} |
	term DIVISION_OPERATOR value {
		int iTermType = GetFinalTypeOfExpression($1, -1);
		int iValueType = GetFinalTypeOfExpression($3, -1);
		if (iValueType == TYPE_CHARACTER || iTermType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_operation_char_division, NULL);
		}

		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_division), id_term, $1, $3, NO_CHILD_NODE);
	} |
	value {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_term, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	};

constant :
	REAL {
		if ($1 > DBL_MAX)
		{
			HANDLE_WARNING("Constant (%e) is greater then the maximum value an REAL can store (%e). This value will be set to the maximum value (%e).", $1, DBL_MAX, DBL_MAX);
			$1 = DBL_MAX;
		}
		else if ($1 < -DBL_MAX)
		{
			HANDLE_WARNING("Constant (%e) is less then the minimum value an REAL can store (%e). This value will be set to the minimum value (%e).", $1, -DBL_MAX, -DBL_MAX);
			$1 = -DBL_MAX;
		}

		$$ = CreateNode(CreateSymbolTableEntry_Constant(TYPE_REAL, &$1), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	UNSIGNED_INTEGER {
		if ($1 > (long)INT_MAX)
		{
			HANDLE_WARNING("Constant (%ld) is greater then the maximum value an INTEGER can store (%d). This value will be set to the maximum value (%d).", $1, INT_MAX, INT_MAX);
			$1 = INT_MAX;
		}
		
		$$ = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &$1), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	} |
	SUBTRACT_OPERATOR UNSIGNED_INTEGER {
		$2 = 0L - $2;
		
		if ($2 < (long)INT_MIN)
		{
			HANDLE_WARNING("Constant (%ld) is less then the minimum value an INTEGER can store (%d). This value will be set to the minimum value (%d).", $2, INT_MIN, INT_MIN);
			$2 = INT_MIN;
		}

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
		CheckIfVariableIsDeclared($3);
		Node* pNode = $$ = CreateNode($3, id_read_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableAssignedEntry($3, pNode);
	};

if_statement :
	IF conditional THEN code ENDIF {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_if_statement, $2, $4, NO_CHILD_NODE);
	};

if_else_statement :
	IF conditional THEN code ELSE code ENDIF {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_if_else_statement, $2, $4, $6);
	};

conditional :
	comparison {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_conditional, $1, NO_CHILD_NODE, NO_CHILD_NODE);
	} | conditional AND comparison {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_and), id_conditional, $1, $3, NO_CHILD_NODE);
	} | conditional OR comparison {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_or), id_conditional, $1, $3, NO_CHILD_NODE);
	};

comparison :
	expression comparator expression {
		int iFirstType = GetFinalTypeOfExpression($1, -1);
		int iSecondType = GetFinalTypeOfExpression($3, -1);

		if ((iFirstType == TYPE_CHARACTER || iSecondType == TYPE_CHARACTER) && (iFirstType == TYPE_REAL || iSecondType == TYPE_REAL))
		{
			CreateError(error_type_invalid_type_conversion_double_char, NULL);
		}

		$$ = CreateNode(NO_SYMBOLIC_LINK, id_comparison, $1, $2, $3);
	} | NOT comparison {
		$$ = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not), id_comparison, $2, NO_CHILD_NODE, NO_CHILD_NODE);
	};

for_statement :
	FOR IDENTIFIER IS expression BY expression TO expression DO code ENDFOR {
		CheckIfVariableIsDeclared($2);
		Node* pNode = $$ = CreateNode($2, id_for_statement, CreateNode(NO_SYMBOLIC_LINK, id_for_statement_is_by_to, $4, $6, $8), $10, NO_CHILD_NODE);
		CreateVariableAssignedEntry($2, pNode);
		CreateVariableUsedEntry($2, pNode);
	};

while_statement :
	WHILE conditional DO code ENDWHILE {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_while_statement, $2, $4, NO_CHILD_NODE);
	};

do_statement :
	DO statement_list WHILE conditional ENDDO {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, $2, $4, NO_CHILD_NODE);
	} |
	DO statement_list SEMI_COLON WHILE conditional ENDDO {
		$$ = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, $2, $5, NO_CHILD_NODE);
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
		return pEntry;
	}

	pEntry->pNextTableEntry = NO_SYMBOLIC_LINK;
	pEntry->bySymbolType = symbol_id_variable;
	pEntry->symbolDetails.variableDetails.pFirstUsage = NO_VARIABLE_USAGE_NODE;
	pEntry->symbolDetails.variableDetails.pLastUsage = NO_VARIABLE_USAGE_NODE;
	
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
		
		return pEntry;
	}

	pEntry->pNextTableEntry = NO_SYMBOLIC_LINK;
	pEntry->bySymbolType = symbol_id_constant;
	pEntry->symbolDetails.constantDetails.iType = iType;
	if (iType == TYPE_INTEGER)
	{
		pEntry->symbolDetails.constantDetails.value.i = (int)*(long*)pValue;
	}
	else if (iType == TYPE_REAL)
	{
		pEntry->symbolDetails.constantDetails.value.f = *(double*)pValue;
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
					if (iType == *(double*)pValue)
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

Node* CreateNode(SymbolTableEntry* pSymbolTableEntry, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild)
{
	Node* pNode = malloc(sizeof(Node));
	memset(pNode, 0, sizeof(Node));
	pNode->pParent = NO_PARENT_NODE;
	pNode->pSymbolTableEntry = pSymbolTableEntry;
	pNode->byNodeIdentifier = byNodeIdentifier;
	SAFE_ASSIGN(pFirstChild, pParent, pNode)
	SAFE_ASSIGN(pSecondChild, pParent, pNode)
	SAFE_ASSIGN(pThirdChild, pParent, pNode)
	pNode->pFirstChild = pFirstChild;
	pNode->pSecondChild = pSecondChild;
	pNode->pThirdChild = pThirdChild;

	return pNode;
}

void PrintTree(const Node* pStartNode, int iLevel)
{
	if (pStartNode == NULL)
		return;

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
																									false, 
																									false);
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
				printf("Value = %lf\n", pStartNode->pSymbolTableEntry->symbolDetails.constantDetails.value.f);
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

	
	PrintTree(pStartNode->pFirstChild, iLevel);

	
	PrintTree(pStartNode->pSecondChild, iLevel);

	
	PrintTree(pStartNode->pThirdChild, iLevel);
}

void GenerateAndPrintWarnings()
{
	SymbolTableEntry* pEntry = g_pSymbolTableStart;
	while (pEntry != NO_SYMBOL_FOUND)
	{
		pEntry = pEntry->pNextTableEntry;
	}

	EvaluateVariableUsage();
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
		case id_type: 
			return "id_type";
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

int g_iIndentLevel;

void Indent()
{
	int i;
	for (i = 0; i < g_iIndentLevel; i++)
		printf("\t");
}

void Evaluate_StatementList(const Node* const pNode);
void Evaluate_WriteStatement(const Node* const pNode);
void Evaluate_DeclarationBlock(const Node* const pNode);

void Evaluate(const Node* const pNode)
{
	if (pNode == NO_CHILD_NODE)
		return;

	switch (pNode->byNodeIdentifier)
	{
		case id_program:
		{
			g_iIndentLevel = 0;
			printf("#include <stdio.h>\n\nvoid _spl_flush_stdin()\n{\n\tchar c = -1;\n\tdo\n\t{\n\t\tc = getchar();\n\t} while (c != '\\n' && c != ' ' && c != EOF);\n}\n\nvoid _spl_read(const char* pFormat, void* pValue)\n{\n\twhile (scanf(pFormat, pValue) != 1)\n\t{\n\t\tgetchar();\n\t};\n\t_spl_flush_stdin();\n}\n\nvoid %s()\n{\n", pNode->pSymbolTableEntry->symbolDetails.programDetails.acIdentifier);
			Evaluate(pNode->pFirstChild);
			printf("}\n\n");
			printf("int main()\n{\n\t%s();\n\treturn 0;\n}\n", pNode->pSymbolTableEntry->symbolDetails.programDetails.acIdentifier);
			break;
		}

		case id_block:
		{
			g_iIndentLevel++;

			Evaluate(pNode->pFirstChild);
			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				printf("\n");
				Evaluate(pNode->pSecondChild);
			}

			break;
		}

		case id_declaration_block:
		{
			Evaluate_DeclarationBlock(pNode);
			break;
		}

		case id_statement_list:
		{
			Evaluate_StatementList(pNode);
			break;
		}

		default:
		{
			printf("[Evaluate: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

void GenerateCode(const Node* const pStartNode)
{
	g_iIndentLevel = 0;
	Evaluate(pStartNode);
}

void WriteReadStatement(const Node* const pNode, const char* pFormat)
{
	Indent();
	printf("_spl_read(\"%s\", &%s);\n", pFormat, pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);
}

void Evaluate_StatementList(const Node* const pNode)
{
	if (pNode == NULL)
		return;

	switch (pNode->byNodeIdentifier)
	{
		case id_statement_list:
		{
			if (pNode->pFirstChild != NO_CHILD_NODE)
			{
				Evaluate_StatementList(pNode->pFirstChild);
			}
			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				Evaluate_StatementList(pNode->pSecondChild);
			}
			
			break;
		}

		case id_statement:
		{
			Evaluate_StatementList(pNode->pFirstChild);
			break;
		}

		case id_assignment_statement:
		{
			Indent();
			printf("%s = ", pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);

			Evaluate_StatementList(pNode->pFirstChild);
			printf(";\n");
			break;
		}

		case id_write_statement:
		{
			Evaluate_WriteStatement(pNode);
			break;
		}

		case id_read_statement:
		{
			
			if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
			{
				WriteReadStatement(pNode, " %c");
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_INTEGER)
			{
				WriteReadStatement(pNode, " %d");
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_REAL)
			{
				WriteReadStatement(pNode, " %lf");
			}

			break;
		}

		case id_if_statement:
		{
			Indent();
			printf("if (");
			Evaluate_StatementList(pNode->pFirstChild);
			printf(")\n");
			Indent();
			printf("{\n");
			g_iIndentLevel++;
			Evaluate_StatementList(pNode->pSecondChild);
			g_iIndentLevel--;
			Indent();
			printf("}\n");
			break;
		}

		case id_if_else_statement:
		{
			Indent();
			printf("if (");
			Evaluate_StatementList(pNode->pFirstChild);
			printf(")\n");
			Indent();
			printf("{\n");
			g_iIndentLevel++;
			Evaluate_StatementList(pNode->pSecondChild);
			g_iIndentLevel--;
			Indent();
			printf("}\n");
			Indent();
			printf("else\n");
			Indent();
			printf("{\n");
			g_iIndentLevel++;
			Evaluate_StatementList(pNode->pThirdChild);
			g_iIndentLevel--;
			Indent();
			printf("}\n");
			break;
		}

		case id_for_statement:
		{
			char* pIdentifier = pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier;
			char* pByName = NULL;
			if (pNode->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild->pFirstChild->byNodeIdentifier != id_constant)
			{
				Indent();
				if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_INTEGER)
				{
					pByName = "_spl_integer_by";

					static char bDefined = 0;
					if (!bDefined)
					{
						printf("int ");
						bDefined = 1;
					}
					printf("%s = ", pByName);
					Evaluate_StatementList(pNode->pFirstChild->pSecondChild);
					printf(";\n");
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
				{
					pByName = "_spl_character_by";

					static char bDefined = 0;
					if (!bDefined)
					{
						printf("char ");
						bDefined = 1;
					}
					printf("%s = ", pByName);
					Evaluate_StatementList(pNode->pFirstChild->pSecondChild);
					printf(";\n");
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_REAL)
				{
					pByName = "_spl_real_by";

					static char bDefined = 0;
					if (!bDefined)
					{
						printf("double ");
						bDefined = 1;
					}
					printf("%s = ", pByName);
					Evaluate_StatementList(pNode->pFirstChild->pSecondChild);
					printf(";\n");
				}
			}

			Indent();
			printf("for (%s = ", pIdentifier);
			Evaluate_StatementList(pNode->pFirstChild->pFirstChild);
			printf("; ");
			Evaluate_StatementList(pNode->pFirstChild->pSecondChild);
			printf(" < 0 ? %s >= ", pIdentifier);
			Evaluate_StatementList(pNode->pFirstChild->pThirdChild);
			printf(" : %s <= ", pIdentifier);
			Evaluate_StatementList(pNode->pFirstChild->pThirdChild);
			if (pNode->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild->pFirstChild->byNodeIdentifier != id_constant)
			{
				printf("; %s += %s", pIdentifier, pByName);
				printf(")\n");
			}
			else
			{
				printf("; %s += ", pIdentifier);
				Evaluate_StatementList(pNode->pFirstChild->pSecondChild);
				printf(")\n");
			}
			Indent();
			printf("{\n");
			g_iIndentLevel++;
			Evaluate_StatementList(pNode->pSecondChild);
			if (pNode->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild->pFirstChild != NULL &&
				pNode->pFirstChild->pSecondChild->pFirstChild->pFirstChild->pFirstChild->byNodeIdentifier != id_constant)
			{
				Indent();
				printf("%s = ", pByName);
				Evaluate_StatementList(pNode->pFirstChild->pSecondChild);
				printf(";\n");
			}
			g_iIndentLevel--;
			Indent();
			printf("}\n");

			break;
		}

		case id_while_statement:
		{
			Indent();
			printf("while (");
			Evaluate_StatementList(pNode->pFirstChild);
			printf(")\n");
			Indent();
			printf("{\n");
			g_iIndentLevel++;
			Evaluate_StatementList(pNode->pSecondChild);
			g_iIndentLevel--;
			Indent();
			printf("};\n");
			break;
		}

		case id_do_statement:
		{
			Indent();
			printf("do\n");
			Indent();
			printf("{\n");
			g_iIndentLevel++;
			Evaluate_StatementList(pNode->pFirstChild);
			g_iIndentLevel--;
			Indent();
			printf("} while (");
			Evaluate_StatementList(pNode->pSecondChild);
			printf(");\n");
			break;
		}

		case id_expression:
		{
			if (pNode->pSecondChild == NO_CHILD_NODE)
			{
				Evaluate_StatementList(pNode->pFirstChild);				
			}
			else
			{
				printf("(");
				Evaluate_StatementList(pNode->pFirstChild);
				if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_add)
				{
					printf(" + ");
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_subtract)
				{
					printf(" - ");
				}
				Evaluate_StatementList(pNode->pSecondChild);
				printf(")");
			}
			
			break;
		}

		case id_term:
		{
			if (pNode->pSecondChild == NO_CHILD_NODE)
			{
				Evaluate_StatementList(pNode->pFirstChild);
			}
			else
			{
				printf("(");
				Evaluate_StatementList(pNode->pFirstChild);
				if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_multipulcation)
				{
					printf(" * ");
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_division)
				{
					printf(" / ");
				}
				Evaluate_StatementList(pNode->pSecondChild);
				printf(")");
			}

			break;
		}

		case id_value:
		{
			if (pNode->pFirstChild != NO_CHILD_NODE)
			{
				Evaluate_StatementList(pNode->pFirstChild);
			}
			else
			{
				printf("%s", pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);
			}
			
			break;
		}

		case id_constant:
		{
			if (pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_INTEGER)
			{
				printf("%d", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.i);
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_REAL)
			{
				printf("%lf", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.f);
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_CHARACTER)
			{
				printf("'%c'", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.c);
			}
			else
			{
				printf("[Unknown Constant Type]");
			}

			break;
		}

		case id_conditional:
		{
			if (pNode->pSecondChild == NO_CHILD_NODE)
			{
				Evaluate_StatementList(pNode->pFirstChild);				
			}
			else
			{
				if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_and)
				{
					printf("((");
					Evaluate_StatementList(pNode->pFirstChild);
					printf(")");
					printf(" && ");
					printf("(");
					Evaluate_StatementList(pNode->pSecondChild);
					printf("))");
				}
				else
				{
					printf("((");
					Evaluate_StatementList(pNode->pFirstChild);
					printf(")");
					printf(" || ");
					printf("(");
					Evaluate_StatementList(pNode->pSecondChild);
					printf("))");
				}
			}

			break;
		}

		case id_comparison:
		{
			if (pNode->pSecondChild == NO_CHILD_NODE)
			{
				printf("!(");
				Evaluate_StatementList(pNode->pFirstChild);
				printf(")");
			}
			else
			{
				printf("(");
				Evaluate_StatementList(pNode->pFirstChild);
				printf(" ");
				Evaluate_StatementList(pNode->pSecondChild);
				printf(" ");
				Evaluate_StatementList(pNode->pThirdChild);
				printf(")");
			}
			break;
		}

		case id_comparator:
		{
			switch (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType)
			{
				case operator_type_equality:
					printf("==");
					break;

				case operator_type_not_equal:
					printf("!=");
					break;

				case operator_type_less_than:
					printf("<");
					break;

				case operator_type_more_than:
					printf(">");
					break;

				case operator_type_less_equal:
					printf("<=");
					break;
				
				case operator_type_more_equal:
					printf(">=");
					break;

				default:
					printf("[Unknown Operator For Comparison]");
					break;
			}

			break;
		}

		default:
		{
			printf("[Evaluate_StatementList: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

int OrderTypes(int currType, int newType)
{
	/*printf("Curr: %s, New: %s\n", GetTypeName(currType), GetTypeName(newType));*/
	if (currType == TYPE_CHARACTER)
	{
		if (newType == TYPE_REAL)
		{
			return newType;
		}
		else
		{
			return currType;
		}
		
	}
	else if (currType == TYPE_INTEGER)
	{
		if (newType == TYPE_CHARACTER || newType == TYPE_REAL)
		{
			return newType;
		}
		else
		{
			return currType;
		}
	}
	else if (currType == TYPE_REAL)
	{
		return currType;
	}
	else
	{
		return newType;
	}
	
	return -1;
}

int GetFinalTypeOfExpression(const Node* const pNode, const int _currType)
{
	int currType = _currType;
	switch (pNode->byNodeIdentifier)
	{
		case id_expression:
		{
			currType = OrderTypes(currType, GetFinalTypeOfExpression(pNode->pFirstChild, _currType));
			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				currType = OrderTypes(currType, GetFinalTypeOfExpression(pNode->pSecondChild, _currType));
			}
			
			return currType;
		}

		case id_term:
		{
			currType = OrderTypes(currType, GetFinalTypeOfExpression(pNode->pFirstChild, _currType));
			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				currType = OrderTypes(currType, GetFinalTypeOfExpression(pNode->pSecondChild, _currType));
			}
			
			return currType;
		}

		case id_value:
		{
			if (pNode->pFirstChild == NO_CHILD_NODE)
			{
				currType = pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType;
			}
			else
			{
				currType = OrderTypes(currType, GetFinalTypeOfExpression(pNode->pFirstChild, _currType));
			}
			
			return currType;
		}

		case id_constant:
		{
			
			return pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType;
		}

		default:
		{
			printf("[GetFinalTypeOfExpression: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

void Evaluate_OutputList_Format(const Node* const pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	switch (pNode->byNodeIdentifier)
	{
		case id_output_list:
		{
			Evaluate_OutputList_Format(pNode->pFirstChild);

			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				Evaluate_OutputList_Format(pNode->pSecondChild);
			}

			break;
		}

		case id_value:
		{
			if (pNode->pFirstChild != NO_CHILD_NODE)
			{
				Evaluate_OutputList_Format(pNode->pFirstChild);
			}
			else
			{
				if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
				{
					printf("%%c");
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_INTEGER)
				{
					printf("%%d");
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_REAL)
				{
					printf("%%lf");
				}
			}

			break;
		}

		case id_constant:
		{
			if (pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_CHARACTER)
			{
				printf("%c", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.c);
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_INTEGER)
			{
				printf("%d", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.i);
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_REAL)
			{
				printf("%lf", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.f);
			}

			break;
		}

		case id_expression:
		{
			int iType =  GetFinalTypeOfExpression(pNode, -1);
			if (iType == TYPE_CHARACTER)
			{
				printf("%%c");
			}
			else if (iType == TYPE_INTEGER)
			{
				printf("%%d");
			}
			else if (iType == TYPE_REAL)
			{
				printf("%%lf");
			}

			break;
		}

		default:
		{
			printf("[Evaluate_OutputList_Format: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

void Evaluate_OutputList_Parameters(const Node* const pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	switch (pNode->byNodeIdentifier)
	{
		case id_output_list:
		{
			Evaluate_OutputList_Parameters(pNode->pFirstChild);

			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				Evaluate_OutputList_Parameters(pNode->pSecondChild);
			}

			break;
		}

		case id_value:
		{
			if (pNode->pFirstChild != NO_CHILD_NODE)
			{
				Evaluate_OutputList_Parameters(pNode->pFirstChild);
			}
			else
			{
				printf(", %s", pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);
			}

			break;
		}

		case id_expression:
		{
			int iType =  GetFinalTypeOfExpression(pNode, -1);
			if (iType == TYPE_CHARACTER)
			{
				printf(", (char)");
			}
			else if (iType == TYPE_INTEGER)
			{
				printf(", (int)");
			}
			else if (iType == TYPE_REAL)
			{
				printf(", (double)");
			}

			Evaluate_StatementList(pNode);

			break;
		}

		case id_constant:
		{
			break;
		}

		default:
		{
			printf("[Evaluate_OutputList_Parameters: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

void Evaluate_WriteStatement(const Node* const pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	switch (pNode->byNodeIdentifier)
	{
		case id_write_statement:
		{
			Indent();
			if (pNode->pFirstChild == NO_CHILD_NODE)
			{
				printf("printf(\"\\n\");\n");
			}
			else
			{
				printf("printf(\"");
				Evaluate_OutputList_Format(pNode->pFirstChild);
				printf("\"");
				Evaluate_OutputList_Parameters(pNode->pFirstChild);
				printf(");\n");
			}

			break;
		}

		default:
		{
			printf("[Evaluate_WriteStatement: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

void Evaluate_DeclarationBlock(const Node* const pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	switch (pNode->byNodeIdentifier)
	{
		case id_declaration_block:
		{
			Evaluate_DeclarationBlock(pNode->pFirstChild);

			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				Evaluate_DeclarationBlock(pNode->pSecondChild);
			}

			break;
		}

		case id_declaration:
		{
			
			Indent();
			Evaluate_DeclarationBlock(pNode->pSecondChild);
			Evaluate_DeclarationBlock(pNode->pFirstChild);

			printf(";\n");

			break;
		}

		case id_type:
		{
			int iType = pNode->pSymbolTableEntry->symbolDetails.typeDetails.iType;
			if (iType == TYPE_INTEGER)
			{
				printf("int ");
			}
			else if (iType == TYPE_REAL)
			{
				printf("double ");
			}
			else if (iType == TYPE_CHARACTER)
			{
				printf("char ");
			}
			else
			{
				printf("[UNKNOWN TYPE - %d] ", pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType);
			}

			break;
		}

		case id_identifier_list:
		{
			if (pNode->pFirstChild != NO_CHILD_NODE)
			{
				Evaluate_DeclarationBlock(pNode->pFirstChild);
				printf(", ", pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);
			}

			printf("%s = 1", pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);

			break;
		}

		default:
		{
			printf("[Evaluate_DeclarationBlock: NOT IMPLEMENTED - %s]", NodeIdentifiersValueToString(pNode->byNodeIdentifier));
			break;
		}
	}
}

void CreateError(ErrorTypes errorType, const void* const pValue)
{
	g_uiErrorCount++;
	switch (errorType)
	{
		case error_type_variable_redeclaration:
			HANDLE_ERROR("Variable (%s) has been redeclared.", (char*)pValue);
			break;

		case error_type_variable_not_declared:
			HANDLE_ERROR("Variable (%s) has been used but not declared.", (char*)pValue);
			break;

		case error_type_invalid_character_constant:
			HANDLE_ERROR("Invalid character constant (%s).", (char*)pValue);
			break;

		case error_type_unexpected_symbol:
			HANDLE_ERROR("Unexpected symbol (%s).", (char*)pValue);
			break;

		case error_type_invalid_type_conversion_double_char:
			HANDLE_ERROR("Invalid type conversion (real to character).");
			break;

		case error_type_invalid_operation_char_multipulcation:
			HANDLE_ERROR("Cannot apply the multipulcation operator to a character type.");
			break;

		case error_type_invalid_operation_char_division:
			HANDLE_ERROR("Cannot apply the division operator to a character type.");
			break;

		case error_type_identifier_too_long:
			HANDLE_ERROR("Identifier is too long (%d characters). Max length is 50 characters.", *(int*)pValue);
			break;

		case error_type_division_by_zero:
			HANDLE_ERROR("Division by constant zero. This is undefined.");
			break;

		default:
			HANDLE_ERROR("Unknown Error.");
			break;
	}
}

void EvaluateVariableUsage()
{
	fprintf(stderr, "\n---- Evaluating Variable Usage ----\n");
	SymbolTableEntry* pSymbol = g_pSymbolTableStart;
	while (pSymbol != NO_SYMBOL_FOUND)
	{
		if (pSymbol->bySymbolType == symbol_id_variable)
		{
			VariableDetails* pVariableDetails = &pSymbol->symbolDetails.variableDetails;
			const char* pVariableIdentifier = &pVariableDetails->acIdentifier[4];
			if (pVariableDetails->pFirstUsage == NO_VARIABLE_USAGE_NODE || pVariableDetails->pFirstUsage->usageType != variable_usage_declaration)
			{
				CreateError(error_type_variable_not_declared, pVariableIdentifier);
				pSymbol = pSymbol->pNextTableEntry;
				continue;
			}

			VariableUsageDetails* pUsage = pVariableDetails->pFirstUsage->pNextUsage;
			bool bUsedOnce = false, bUsed = false;
			VariableUsageDetails* pAssigned = NO_VARIABLE_USAGE_NODE;
			while (pUsage != NO_VARIABLE_USAGE_NODE)
			{
				if (pUsage->usageType == variable_usage_declaration)
				{
					CreateError(error_type_variable_redeclaration, pVariableIdentifier);
					break;
				}
				else if (pUsage->usageType == variable_usage_assignment)
				{
					if (pUsage->pPrevUsage->usageType == variable_usage_assignment && bUsed == false)
					{
						/*Find statement*/
						Node* pStatement = pUsage->pPrevUsage->pParentNode;
						while (pStatement->byNodeIdentifier != id_statement)
						{
							pStatement = pStatement->pParent;
						};

						/*Optimise the redundant assignment*/
						if (g_bOptimisation_DeadStores)
						{
							if (pStatement == pStatement->pParent->pFirstChild)
							{
								pStatement->pParent->pFirstChild = NO_CHILD_NODE;
							}
							else if (pStatement == pStatement->pParent->pSecondChild)
							{
								pStatement->pParent->pSecondChild = NO_CHILD_NODE;
							}
						}

						if (pStatement->pFirstChild->byNodeIdentifier == id_read_statement)
						{
							HANDLE_WARNING("Previous usage of variable %s was an assignment, therefore the assignment at line: %d | pos: %d was redundant; therefore, this statement has been optimised out. Warning this was a read statement.", pVariableIdentifier, pUsage->pPrevUsage->uiLine, pUsage->pPrevUsage->uiPos);
						}
						else
						{
							HANDLE_WARNING("Previous usage of variable %s was an assignment, therefore the assignment at line: %d | pos: %d was redundant; therefore, this statement has been optimised out.", pVariableIdentifier, pUsage->pPrevUsage->uiLine, pUsage->pPrevUsage->uiPos);
						}
					}

					bUsed = false;
					pAssigned = pUsage;
				}
				else if (pUsage->usageType == variable_usage_used)
				{
					if (pAssigned == NO_VARIABLE_USAGE_NODE)
					{
						HANDLE_WARNING("Variable %s is used at line: %d | pos: %d before it has been assigned to. It will have a default value of 1.", pVariableIdentifier, pUsage->pPrevUsage->uiLine, pUsage->pPrevUsage->uiPos);
					}

					bUsed = true;
					bUsedOnce = true;
				}

				pUsage = pUsage->pNextUsage;
			};

			if (bUsedOnce == false)
			{
				HANDLE_WARNING("The variable %s is never used.", pVariableIdentifier);
			}
			else if (bUsed == false)
			{
				HANDLE_WARNING("The variable %s is not used after the assignment statement (line: %d | pos: %d).", pVariableIdentifier,  pAssigned->uiLine, pAssigned->uiPos);
			}
		}

		pSymbol = pSymbol->pNextTableEntry;
	};
}

void CreateVariableDeclaredEntry(SymbolTableEntry* pSymbol, Node* pParentNode)
{
	VariableDetails* pVariableDetails = &pSymbol->symbolDetails.variableDetails;
	VariableUsageDetails* pUsageDetails = malloc(sizeof(VariableUsageDetails));
	pUsageDetails->usageType = variable_usage_declaration;
	CreateVariableUsageEntry(pUsageDetails, pVariableDetails, pParentNode);
}

void CreateVariableAssignedEntry(SymbolTableEntry* pSymbol, Node* pParentNode)
{
	VariableDetails* pVariableDetails = &pSymbol->symbolDetails.variableDetails;
	VariableUsageDetails* pUsageDetails = malloc(sizeof(VariableUsageDetails));
	pUsageDetails->usageType = variable_usage_assignment;
	CreateVariableUsageEntry(pUsageDetails, pVariableDetails, pParentNode);
}

void CreateVariableUsedEntry(SymbolTableEntry* pSymbol, Node* pParentNode)
{
	VariableDetails* pVariableDetails = &pSymbol->symbolDetails.variableDetails;
	VariableUsageDetails* pUsageDetails = malloc(sizeof(VariableUsageDetails));
	pUsageDetails->usageType = variable_usage_used;
	CreateVariableUsageEntry(pUsageDetails, pVariableDetails, pParentNode);
}

void CreateVariableUsageEntry(VariableUsageDetails* pUsageDetails, VariableDetails* pVariableDetails, Node* pParentNode)
{
	pUsageDetails->uiLine = g_uiCurrentLineNumber;
	pUsageDetails->uiPos = g_ulCurrentLinePosition;
	pUsageDetails->pParentNode = pParentNode;
	pUsageDetails->pNextUsage = NO_VARIABLE_USAGE_NODE;
	pUsageDetails->pPrevUsage = NO_VARIABLE_USAGE_NODE;

	if (pVariableDetails->pFirstUsage == NO_VARIABLE_USAGE_NODE)
	{
		pVariableDetails->pFirstUsage = pUsageDetails;
		pVariableDetails->pLastUsage = pUsageDetails;
	}
	else
	{
		pUsageDetails->pPrevUsage = pVariableDetails->pLastUsage;
		pVariableDetails->pLastUsage->pNextUsage = pUsageDetails;
		pVariableDetails->pLastUsage = pUsageDetails;
	}
}

void CheckIfVariableIsDeclared(SymbolTableEntry* pEntry)
{
	if (pEntry != NO_SYMBOLIC_LINK && pEntry->bySymbolType == symbol_id_variable)
	{
		if (pEntry->symbolDetails.variableDetails.pFirstUsage == NO_VARIABLE_USAGE_NODE || pEntry->symbolDetails.variableDetails.pFirstUsage->usageType != variable_usage_declaration)
		{
			CreateError(error_type_variable_not_declared,&pEntry->symbolDetails.variableDetails.acIdentifier[4]);
		}
	}
}

Node* EvaluateExpresion(Node* pNode, bool* pIsConst)
{
	if (pNode == NULL)
	{
		return NULL;
	}

	if (pNode->pSymbolTableEntry != NULL && pNode->pSymbolTableEntry->bySymbolType == symbol_id_variable)
	{
		*pIsConst = false;
		return NULL;
	}

	switch (pNode->byNodeIdentifier)
	{
		case id_expression:
			EvaluateExpresion(pNode->pFirstChild, pIsConst);
			EvaluateExpresion(pNode->pSecondChild, pIsConst);
			EvaluateExpresion(pNode->pThirdChild, pIsConst);
			break;

		case id_term:
			EvaluateExpresion(pNode->pFirstChild, pIsConst);
			EvaluateExpresion(pNode->pSecondChild, pIsConst);
			EvaluateExpresion(pNode->pThirdChild, pIsConst);
			break;

		case id_value:
			EvaluateExpresion(pNode->pFirstChild, pIsConst);
			EvaluateExpresion(pNode->pSecondChild, pIsConst);
			EvaluateExpresion(pNode->pThirdChild, pIsConst);
			break;

		case id_constant:
			if (*pIsConst != false)
			{
				*pIsConst = true;
			}
			break;

		default:
			*pIsConst = false;
			return NULL;
	}

	return pNode;
}

size_t GetSizeOfType(const int iType)
{
	if (iType == TYPE_INTEGER)
	{
		return sizeof(int);
	}
	else if (iType == TYPE_REAL)
	{
		return sizeof(double);
	}
	else if (iType == TYPE_CHARACTER)
	{
		return sizeof(char);
	}
}

void* AllocateType(const int iType)
{
	return malloc(sizeof(GetSizeOfType(iType)));
}

void AssignInt(void** pValue, const int iType, int iValue)
{
	if (iType == TYPE_INTEGER)
	{
		*(int*)*pValue = iValue;
	}
	else if (iType == TYPE_REAL)
	{
		*(double*)*pValue = iValue;
	}
	else if (iType == TYPE_CHARACTER)
	{
		*(char*)*pValue = iValue;
	}
}

void AssignReal(void** pValue, const int iType, double dValue)
{
	if (iType == TYPE_INTEGER)
	{
		*(int*)*pValue = dValue;
	}
	else if (iType == TYPE_REAL)
	{
		*(double*)*pValue = dValue;
	}
	else if (iType == TYPE_CHARACTER)
	{
		*(char*)*pValue = dValue;
	}
}

void AssignChar(void** pValue, const int iType, int cValue)
{
	if (iType == TYPE_INTEGER)
	{
		*(int*)*pValue = cValue;
	}
	else if (iType == TYPE_REAL)
	{
		*(double*)*pValue = cValue;
	}
	else if (iType == TYPE_CHARACTER)
	{
		*(char*)*pValue = cValue;
	}
}

bool g_bExitEvaluation = false;
void* EvaluateConstantExpression(Node* pNode, int* iType)
{
	if (pNode == NULL || g_bExitEvaluation == true)
	{
		return NULL;
	}

	*iType = GetFinalTypeOfExpression(pNode, -1);
	int iTypeOne = 0, iTypeTwo = 0;
	void* pFinalValue = AllocateType(*iType);
	switch (pNode->byNodeIdentifier)
	{
		case id_expression:
			if (pNode->pFirstChild != NO_CHILD_NODE && pNode->pSecondChild != NO_CHILD_NODE)
			{
				iTypeOne = GetFinalTypeOfExpression(pNode->pFirstChild, -1);
				iTypeTwo = GetFinalTypeOfExpression(pNode->pSecondChild, -1);
			}
			else
			{
				return EvaluateConstantExpression(pNode->pFirstChild, iType);
			}
			
			if (pNode->pSymbolTableEntry != NO_SYMBOL_FOUND)
			{
				if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_add)
				{
					if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_INTEGER)
					{
						AssignInt(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_CHARACTER)
					{
						AssignChar(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(char*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_INTEGER)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_CHARACTER)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(char*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_CHARACTER && iTypeTwo == TYPE_INTEGER)
					{
						AssignChar(&pFinalValue, *iType, *(char*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_CHARACTER && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(char*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_CHARACTER && iTypeTwo == TYPE_CHARACTER)
					{
						AssignChar(&pFinalValue, *iType, *(char*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) + *(char*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
				}
				else if (pNode->pSymbolTableEntry != NULL && pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_subtract)
				{
					if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_INTEGER)
					{
						AssignInt(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_CHARACTER)
					{
						AssignChar(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(char*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_INTEGER)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_CHARACTER)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(char*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_CHARACTER && iTypeTwo == TYPE_INTEGER)
					{
						AssignChar(&pFinalValue, *iType, *(char*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_CHARACTER && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(char*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_CHARACTER && iTypeTwo == TYPE_CHARACTER)
					{
						AssignChar(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) - *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
				}
			}

			break;

		case id_term:
			if (pNode->pFirstChild != NO_CHILD_NODE && pNode->pSecondChild != NO_CHILD_NODE)
			{
				iTypeOne = GetFinalTypeOfExpression(pNode->pFirstChild, -1);
				iTypeTwo = GetFinalTypeOfExpression(pNode->pSecondChild, -1);
			}
			else
			{
				return EvaluateConstantExpression(pNode->pFirstChild, iType);
			}

			if (pNode->pSymbolTableEntry != NO_SYMBOL_FOUND)
			{
				if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_multipulcation)
				{
					if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_INTEGER)
					{
						AssignInt(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) * *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) * *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_INTEGER)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) * *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_REAL)
					{
						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) * *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo));
					}
				}
				else if (pNode->pSymbolTableEntry != NULL && pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_division)
				{
					if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_INTEGER)
					{
						int iDenom = *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo);
						if (iDenom == 0)
						{
							g_bExitEvaluation = true;
							return NULL;
						}

						AssignInt(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) / iDenom);
					}
					else if (iTypeOne == TYPE_INTEGER && iTypeTwo == TYPE_REAL)
					{
						double dDenom = *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo);
						if (dDenom == 0.0)
						{
							g_bExitEvaluation = true;
							return NULL;
						}

						AssignReal(&pFinalValue, *iType, *(int*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) / dDenom);
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_INTEGER)
					{
						int iDenom = *(int*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo);
						if (iDenom == 0)
						{
							g_bExitEvaluation = true;
							return NULL;
						}

						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) / iDenom);
					}
					else if (iTypeOne == TYPE_REAL && iTypeTwo == TYPE_REAL)
					{
						double dDenom = *(double*)EvaluateConstantExpression(pNode->pSecondChild, &iTypeTwo);
						if (dDenom == 0.0)
						{
							g_bExitEvaluation = true;
							return NULL;
						}

						AssignReal(&pFinalValue, *iType, *(double*)EvaluateConstantExpression(pNode->pFirstChild, &iTypeOne) / dDenom);
					}
				}
			}

			break;

		case id_value:
			if (pNode->pFirstChild->byNodeIdentifier == id_expression)
			{
				return EvaluateConstantExpression(pNode->pFirstChild, iType);
			}

			*iType = pNode->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.iType;
			if (*iType == TYPE_INTEGER)
			{
				return &pNode->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.value.i;
			}
			else if (*iType == TYPE_REAL)
			{
				return &pNode->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.value.f;
			}
			else if (*iType == TYPE_CHARACTER)
			{
				return &pNode->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.value.c;
			}

			break;

		default:
			if (pNode->pFirstChild != NO_CHILD_NODE)
			{
				return EvaluateConstantExpression(pNode->pFirstChild, iType);
			}
			break;
	}

	return pFinalValue;
}

void CheckForDivideByZero(const Node* const pNode)
{
	if (pNode == NULL || g_bStaticErrorChecking_DivisionByZero == false)
	{
		return;
	}

	if (pNode->byNodeIdentifier == id_term && pNode->pSymbolTableEntry != NO_SYMBOLIC_LINK && pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_division)
	{
		if (pNode->pSecondChild->pFirstChild != NO_CHILD_NODE && pNode->pSecondChild->pFirstChild->byNodeIdentifier == id_constant)
		{
			if (pNode->pSecondChild->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_INTEGER && pNode->pSecondChild->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.value.i == 0)
			{
				CreateError(error_type_division_by_zero, NULL);
			}
			else if (pNode->pSecondChild->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.iType == TYPE_REAL && pNode->pSecondChild->pFirstChild->pSymbolTableEntry->symbolDetails.constantDetails.value.f == 0.0)
			{
				CreateError(error_type_division_by_zero, NULL);
			}
			return;
		}
	}

	CheckForDivideByZero(pNode->pFirstChild);
	CheckForDivideByZero(pNode->pSecondChild);
	CheckForDivideByZero(pNode->pThirdChild);
}

bool g_bExitDeadCodeRemoval = false;
bool RemoveDeadCode_Iter(Node* pNode)
{
	if (pNode == NULL || g_bExitDeadCodeRemoval)
	{
		return false;
	}

	bool bFinal = true;

	switch (pNode->byNodeIdentifier)
	{
		case id_comparison:
		{
			if (pNode->pSecondChild == NO_CHILD_NODE)
			{
				bFinal = !RemoveDeadCode_Iter(pNode->pFirstChild);
			}
			else
			{
				bool bFirstConst = true;
				bool bSecondConst = true;
				EvaluateExpresion(pNode->pFirstChild, &bFirstConst);
				EvaluateExpresion(pNode->pThirdChild, &bSecondConst);
				if (bFirstConst == true && bSecondConst == true)
				{
					int iFirstType = -1;
					int iSecondType = -1;
					void* pFirstValue = EvaluateConstantExpression(pNode->pFirstChild, &iFirstType);
					void* pSecondValue = EvaluateConstantExpression(pNode->pThirdChild, &iSecondType);
					if (iFirstType == TYPE_INTEGER && iSecondType == TYPE_INTEGER)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(int*)pFirstValue == *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(int*)pFirstValue != *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(int*)pFirstValue < *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(int*)pFirstValue > *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(int*)pFirstValue <= *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(int*)pFirstValue >= *(int*)pSecondValue;
						}
					}
					else if (iFirstType == TYPE_INTEGER && iSecondType == TYPE_REAL)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(int*)pFirstValue == *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(int*)pFirstValue != *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(int*)pFirstValue < *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(int*)pFirstValue > *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(int*)pFirstValue <= *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(int*)pFirstValue >= *(double*)pSecondValue;
						}
					}
					else if (iFirstType == TYPE_INTEGER && iSecondType == TYPE_CHARACTER)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(int*)pFirstValue == (int)*(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(int*)pFirstValue != (int)*(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(int*)pFirstValue < (int)*(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(int*)pFirstValue > (int)*(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(int*)pFirstValue <= (int)*(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(int*)pFirstValue >= (int)*(char*)pSecondValue;
						}
					}
					else if (iFirstType == TYPE_REAL && iSecondType == TYPE_INTEGER)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(double*)pFirstValue == *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(double*)pFirstValue != *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(double*)pFirstValue < *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(double*)pFirstValue > *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(double*)pFirstValue <= *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(double*)pFirstValue >= *(int*)pSecondValue;
						}
					}
					else if (iFirstType == TYPE_REAL && iSecondType == TYPE_REAL)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(double*)pFirstValue == *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(double*)pFirstValue != *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(double*)pFirstValue < *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(double*)pFirstValue > *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(double*)pFirstValue <= *(double*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(double*)pFirstValue >= *(double*)pSecondValue;
						}
					}
					else if (iFirstType == TYPE_CHARACTER && iSecondType == TYPE_CHARACTER)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(char*)pFirstValue == *(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(char*)pFirstValue != *(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(char*)pFirstValue < *(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(char*)pFirstValue > *(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(char*)pFirstValue <= *(char*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(char*)pFirstValue >= *(char*)pSecondValue;
						}
					}
					else if (iFirstType == TYPE_CHARACTER && iSecondType == TYPE_INTEGER)
					{
						if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_equality)
						{
							bFinal = *(char*)pFirstValue == *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_not_equal)
						{
							bFinal = *(char*)pFirstValue != *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_than)
						{
							bFinal = *(char*)pFirstValue < *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_than)
						{
							bFinal = *(char*)pFirstValue > *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_less_equal)
						{
							bFinal = *(char*)pFirstValue <= *(int*)pSecondValue;
						}
						else if (pNode->pSecondChild->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_more_equal)
						{
							bFinal = *(char*)pFirstValue >= *(int*)pSecondValue;
						}
					}
				}
				else
				{
					/*Expression is not constant*/
					g_bExitDeadCodeRemoval = true;
					return;
				}
			}
			break;
		}

		case id_conditional:
		{
			bool bFirst = RemoveDeadCode_Iter(pNode->pFirstChild);
			if (pNode->pSecondChild != NO_CHILD_NODE)
			{
				bool bSecond = RemoveDeadCode_Iter(pNode->pSecondChild);
				if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_and)
				{
					bFinal = bFinal && bSecond;
				}
				else if (pNode->pSymbolTableEntry->symbolDetails.operatorDetails.operatorType == operator_type_or)
				{
					bFinal = bFinal || bSecond;
				}
			}
			else
			{
				bFinal = bFirst;
			}
			
			break;	
		}

		default:
			break;
	}

	return bFinal;
}

void RemoveDeadCode(Node* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	if (pNode->byNodeIdentifier == id_do_statement)
	{
		g_bExitDeadCodeRemoval = false;
		bool bConstRes = RemoveDeadCode_Iter(pNode->pSecondChild);
		if (!g_bExitDeadCodeRemoval)
		{
			if (bConstRes)
			{
				HANDLE_WARNING("The condition for the do while statement is constant and true. This will cause an infinte loop.\n");
			}
			else if (g_bOptimisation_DeadCode)
			{
				Node* pParentNode = pNode->pParent->pParent;
				HANDLE_WARNING("The condition for the do while statement is constant and false. This means the loop is redundant and may be optimised out.\n");

				if (pParentNode->pFirstChild == pNode->pParent)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pFirstChild = pNode->pFirstChild;
				}
				else if (pParentNode->pSecondChild == pNode->pParent)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pSecondChild = pNode->pFirstChild;
				}
				if (pParentNode->pThirdChild == pNode->pParent)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pThirdChild = pNode->pFirstChild;
				}
			}
		}
	}
	else
	{
		g_bExitDeadCodeRemoval = false;
		bool bConstRes = RemoveDeadCode_Iter(pNode->pFirstChild);
		if (pNode->byNodeIdentifier == id_if_statement && !g_bExitDeadCodeRemoval)
		{
			Node* pParentNode = pNode->pParent->pParent;
			
			if (bConstRes)
			{
				HANDLE_WARNING("The condition for the if statement is constant and true. The conditional checks are redundant and may be optimised out.\n");
			}
			else
			{
				HANDLE_WARNING("The condition for the if statement is constant and false. The code will never execute may be optimised out.\n");
			}

			if (pParentNode->pFirstChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				/*DeleteNode(pNode);*/
				if (bConstRes == true)
				{
					pParentNode->pFirstChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pFirstChild = NULL;
				}
			}
			else if (pParentNode->pSecondChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				/*DeleteNode(pNode);*/
				if (bConstRes == true)
				{
					pParentNode->pSecondChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pSecondChild = NULL;
				}
			}
			else if (pParentNode->pThirdChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				/*DeleteNode(pNode);*/
				if (bConstRes == true)
				{
					pParentNode->pThirdChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pThirdChild = NULL;
				}
			}
			return;
		}
		else if (pNode->byNodeIdentifier == id_if_else_statement && !g_bExitDeadCodeRemoval)
		{
			Node* pParentNode = pNode->pParent->pParent;
			if (bConstRes)
			{
				HANDLE_WARNING("The condition for the if else statement is constant and true. Therefore the else code path is redundant and may be optimised out.\n");
			}
			else
			{
				HANDLE_WARNING("The condition for the if else statement is constant and false. Therefore the if code path is redundant and may be optimised out.\n");
			}

			if (pParentNode->pFirstChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				/*DeleteNode(pNode);*/
				if (bConstRes)
				{
					pParentNode->pFirstChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pFirstChild = pNode->pThirdChild;
				}
			}
			else if (pParentNode->pSecondChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				/*DeleteNode(pNode);*/
				if (bConstRes)
				{
					pParentNode->pSecondChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pSecondChild = pNode->pThirdChild;
				}
			}
			else if (pParentNode->pThirdChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				/*DeleteNode(pNode);*/
				if (bConstRes)
				{
					pParentNode->pThirdChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pThirdChild = pNode->pThirdChild;
				}
			}
			return;
		}
		else if (pNode->byNodeIdentifier == id_while_statement && !g_bExitDeadCodeRemoval)
		{
			Node* pParentNode = pNode->pParent->pParent;
			
			if (bConstRes == true)
			{
				HANDLE_WARNING("The condition for the while statement is constant and true. This will cause an infinte loop.\n");
			}
			else
			{
				HANDLE_WARNING("The condition for the while statement is constant and false. This loop is redundant and may be optimised out.\n");
				if (pParentNode->pFirstChild == pNode->pParent && g_bOptimisation_DeadCode)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pFirstChild = NULL;
				}
				else if (pParentNode->pSecondChild == pNode->pParent && g_bOptimisation_DeadCode)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pSecondChild = NULL;
				}
				else if (pParentNode->pThirdChild == pNode->pParent && g_bOptimisation_DeadCode)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pThirdChild = NULL;
				}
			}
			return;
		}
	}

	RemoveDeadCode(pNode->pFirstChild);
	RemoveDeadCode(pNode->pSecondChild);
	RemoveDeadCode(pNode->pThirdChild);
}

void FoldConstants(Node* pNode)
{
	if (pNode == NULL || g_bOptimisation_FoldConstants == false)
	{
		return;
	}

	if (pNode->byNodeIdentifier == id_expression || pNode->byNodeIdentifier == id_term)
	{
		bool bIsConst = true;
		int iType = GetFinalTypeOfExpression(pNode, -1);
		EvaluateExpresion(pNode, &bIsConst);
		if (bIsConst)
		{
			void* pValue = EvaluateConstantExpression(pNode, &iType);
			if (pValue != NULL)
			{
				Node* pParentNode = pNode->pParent;
				if (pParentNode->pFirstChild == pNode)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pFirstChild = 	CreateNode(NO_SYMBOLIC_LINK, id_expression, 
												CreateNode(NO_SYMBOLIC_LINK, id_term, 
												CreateNode(NO_SYMBOLIC_LINK, id_value, 
												CreateNode(CreateSymbolTableEntry_Constant(iType, pValue), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE), 
												NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE);
				}
				else if (pParentNode->pSecondChild == pNode)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pSecondChild = CreateNode(NO_SYMBOLIC_LINK, id_expression, 
												CreateNode(NO_SYMBOLIC_LINK, id_term, 
												CreateNode(NO_SYMBOLIC_LINK, id_value, 
												CreateNode(CreateSymbolTableEntry_Constant(iType, pValue), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE), 
												NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE);
				}
				else if (pParentNode->pThirdChild == pNode)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pThirdChild = 	CreateNode(NO_SYMBOLIC_LINK, id_expression, 
												CreateNode(NO_SYMBOLIC_LINK, id_term, 
												CreateNode(NO_SYMBOLIC_LINK, id_value, 
												CreateNode(CreateSymbolTableEntry_Constant(iType, pValue), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE), 
												NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE);
				}
			}
			return;
		}
	}

	g_bExitEvaluation = false;
	FoldConstants(pNode->pFirstChild);
	g_bExitEvaluation = false;
	FoldConstants(pNode->pSecondChild);
	g_bExitEvaluation = false;
	FoldConstants(pNode->pThirdChild);
}

#include "lex.yy.c"