#ifndef SPL_Y_H
#define SPL_Y_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#define NO_CHILD_NODE NULL
#define NO_SYMBOLIC_LINK NULL
#define NO_SYMBOL_FOUND NULL
#define UNKNOWN_SYMBOL_TYPE -1
#define MAX_IDENTIFIER_LENGTH 50

unsigned int g_uiCurrentLineNumber;
unsigned long g_ulCurrentLinePosition;
#define HANDLE_WARNING(message, ...) { printf("/*WARNING (%d:%d): ", g_uiCurrentLineNumber, g_ulCurrentLinePosition); printf(message, ##__VA_ARGS__); printf("*/\n"); }

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

typedef struct _variableDetails
{
	char acIdentifier[MAX_IDENTIFIER_LENGTH];
	int iType;
	bool bAssignedTo;
	bool bUsed;
} VariableDetails;

typedef struct _constantDetails
{
	int iType;
	union 
	{
		int i;
		float f;
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

typedef struct _symbolTableEntry
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
	
} SymbolTableEntry;

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
void MarkSymbolAsAssigned(SymbolTableEntry* pEntry);
void MarkSymbolAsUsed(SymbolTableEntry* pEntry);

typedef struct _node
{
	SymbolTableEntry* pSymbolTableEntry;
	unsigned char byNodeIdentifier;
	struct _node* pFirstChild;
	struct _node* pSecondChild;
	struct _node* pThirdChild;
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
	id_type,
	id_real,
	id_integer,
	id_comparator,
	id_read_statement,
	id_if_statement,
	id_if_else_statement,
	id_conditional,
	id_logical,
	id_conditional_not,
	id_conditional_and,
	id_conditional_or,
	id_comparison,
	id_for_statement,
	id_for_statement_is_by_to,
	id_while_statement,
	id_do_statement
} NodeIdentifiers;

Node* CreateNode(SymbolTableEntry* pSymbolTreePointer, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild);
void PrintTree(const Node* pStartNode, int iLevel);

void PrintNodeIdentifiersValue(const NodeIdentifiers value);
const char* NodeIdentifiersValueToString(const NodeIdentifiers value);
void GenerateAndPrintWarnings();

#endif