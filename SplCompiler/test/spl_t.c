
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "spl.y"

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
		bool bDeclared;
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
    struct _node
    {
        SymbolTableEntry* pSymbolTableEntry;
        unsigned char byNodeIdentifier;
        struct _node* pFirstChild;
        struct _node* pSecondChild;
        struct _node* pThirdChild;
		struct _node* pParent;
    };

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
        id_comparison,
        id_for_statement,
		id_for_statement_is_by_to,
        id_while_statement,
        id_do_statement
    } NodeIdentifiers;
    void PrintNodeIdentifiersValue(const NodeIdentifiers value);
    const char* NodeIdentifiersValueToString(const NodeIdentifiers value);

    Node* CreateNode(SymbolTableEntry* pSymbolTreePointer, unsigned char byNodeIdentifier, Node* pFirstChild, Node* pSecondChild, Node* pThirdChild);
    void PrintTree(const Node* pStartNode, int iLevel);

    /* CODE GENERATION */
    void GenerateCode(const Node* const pStartNode);

    extern unsigned int g_uiCurrentLineNumber;
    extern unsigned long g_ulCurrentLinePosition;
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


/* Line 189 of yacc.c  */
#line 300 "spl_t.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ENDP = 258,
     DECLARATIONS = 259,
     CODE = 260,
     TYPE_CHARACTER = 261,
     TYPE_INTEGER = 262,
     TYPE_REAL = 263,
     IF = 264,
     ELSE = 265,
     NOT = 266,
     OF = 267,
     TYPE = 268,
     THEN = 269,
     ENDIF = 270,
     AND = 271,
     OR = 272,
     DO = 273,
     WHILE = 274,
     ENDDO = 275,
     ENDWHILE = 276,
     FOR = 277,
     IS = 278,
     BY = 279,
     TO = 280,
     ENDFOR = 281,
     NEWLINE = 282,
     WRITE = 283,
     READ = 284,
     ASSIGNMENT_OPERATOR = 285,
     EQUALITY_OPERATOR = 286,
     NOT_EQUAL_TO_OPERATOR = 287,
     LESS_THAN_OPERATOR = 288,
     MORE_THAN_OPERATOR = 289,
     LESS_EQUAL_TO_OPERATOR = 290,
     MORE_EQUAL_TO_OPERATOR = 291,
     OPEN_BRACKET = 292,
     CLOSE_BRACKET = 293,
     COMMA = 294,
     COLON = 295,
     SEMI_COLON = 296,
     PERIOD = 297,
     ADD_OPERATOR = 298,
     SUBTRACT_OPERATOR = 299,
     DIVISION_OPERATOR = 300,
     MULTIPULCATION_OPERATOR = 301,
     CHARACTER_CONSTANT = 302,
     UNSIGNED_INTEGER = 303,
     REAL = 304,
     IDENTIFIER = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 228 "spl.y"

	long iVal;
	double fVal;
	char cVal;
	Node* pNode;
	SymbolTableEntry* pSymbolTableEntry;



/* Line 214 of yacc.c  */
#line 396 "spl_t.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 408 "spl_t.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    15,    18,    20,    23,    29,    31,
      35,    37,    39,    41,    43,    46,    48,    52,    54,    56,
      58,    60,    62,    64,    66,    68,    72,    76,    78,    80,
      84,    88,    90,    94,    98,   100,   102,   104,   107,   109,
     114,   116,   118,   122,   124,   126,   128,   130,   132,   134,
     139,   145,   153,   155,   159,   163,   167,   170,   182,   188,
     194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    50,    40,    53,     3,    50,    42,    -1,
       4,    54,     5,    58,    -1,     5,    58,    -1,    55,    -1,
      54,    55,    -1,    56,    12,    13,    57,    41,    -1,    50,
      -1,    56,    39,    50,    -1,     6,    -1,     7,    -1,     8,
      -1,    59,    -1,    59,    41,    -1,    60,    -1,    59,    41,
      60,    -1,    61,    -1,    66,    -1,    69,    -1,    70,    -1,
      71,    -1,    74,    -1,    75,    -1,    76,    -1,    63,    30,
      50,    -1,    37,    63,    38,    -1,    50,    -1,    65,    -1,
      63,    44,    64,    -1,    63,    43,    64,    -1,    64,    -1,
      64,    46,    62,    -1,    64,    45,    62,    -1,    62,    -1,
      49,    -1,    48,    -1,    44,    48,    -1,    47,    -1,    28,
      37,    67,    38,    -1,    27,    -1,    62,    -1,    67,    39,
      62,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    29,    37,    50,    38,    -1,     9,
      72,    14,    58,    15,    -1,     9,    72,    14,    58,    10,
      58,    15,    -1,    73,    -1,    72,    16,    73,    -1,    72,
      17,    73,    -1,    63,    68,    63,    -1,    11,    73,    -1,
      22,    50,    23,    63,    24,    63,    25,    63,    18,    58,
      26,    -1,    19,    72,    18,    58,    21,    -1,    18,    59,
      19,    72,    20,    -1,    18,    59,    41,    19,    72,    20,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   248,   248,   292,   295,   300,   303,   308,   321,   324,
     329,   332,   335,   340,   342,   350,   353,   359,   362,   365,
     368,   371,   374,   377,   380,   385,   405,   408,   413,   418,
     421,   424,   429,   439,   449,   454,   468,   477,   488,   493,
     496,   501,   504,   509,   512,   515,   518,   521,   524,   529,
     536,   541,   546,   548,   550,   555,   565,   570,   578,   583,
     586
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENDP", "DECLARATIONS", "CODE",
  "TYPE_CHARACTER", "TYPE_INTEGER", "TYPE_REAL", "IF", "ELSE", "NOT", "OF",
  "TYPE", "THEN", "ENDIF", "AND", "OR", "DO", "WHILE", "ENDDO", "ENDWHILE",
  "FOR", "IS", "BY", "TO", "ENDFOR", "NEWLINE", "WRITE", "READ",
  "ASSIGNMENT_OPERATOR", "EQUALITY_OPERATOR", "NOT_EQUAL_TO_OPERATOR",
  "LESS_THAN_OPERATOR", "MORE_THAN_OPERATOR", "LESS_EQUAL_TO_OPERATOR",
  "MORE_EQUAL_TO_OPERATOR", "OPEN_BRACKET", "CLOSE_BRACKET", "COMMA",
  "COLON", "SEMI_COLON", "PERIOD", "ADD_OPERATOR", "SUBTRACT_OPERATOR",
  "DIVISION_OPERATOR", "MULTIPULCATION_OPERATOR", "CHARACTER_CONSTANT",
  "UNSIGNED_INTEGER", "REAL", "IDENTIFIER", "$accept", "program", "block",
  "declaration_block", "declaration", "identifier_list", "type", "code",
  "statement_list", "statement", "assignment_statement", "value",
  "expression", "term", "constant", "write_statement", "output_list",
  "comparator", "read_statement", "if_statement", "if_else_statement",
  "conditional", "comparison", "for_statement", "while_statement",
  "do_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    62,    62,    63,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      70,    71,    72,    72,    72,    73,    73,    74,    75,    76,
      76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     1,     2,     5,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     3,
       3,     1,     3,     3,     1,     1,     1,     2,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       5,     7,     1,     3,     3,     3,     2,    11,     5,     5,
       6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     8,     0,
       5,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,    38,    36,    35,    27,     4,    13,    15,    17,    34,
       0,    31,    28,    18,    19,    20,    21,    22,    23,    24,
       0,     0,     6,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,    37,    14,     0,     0,     0,
       0,     0,     0,     3,     0,     9,    56,    43,    44,    45,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,    26,    16,    25,    30,    29,    33,
      32,     2,    10,    11,    12,     0,    55,     0,    53,    54,
       0,     0,     0,     0,    39,     0,    49,     7,     0,    50,
      59,     0,    58,     0,    42,     0,    60,     0,    51,     0,
       0,     0,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    11,    95,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    82,    73,    34,    35,
      36,    47,    48,    37,    38,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
      -7,    -2,    51,     8,   -52,     3,    -3,    57,   -52,     0,
     -52,    -4,    44,    -3,    44,    19,   -52,    68,    69,    78,
      49,   -52,   -52,   -52,   -52,   -52,    83,   -52,   -52,   -52,
      32,   -25,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      73,    -3,   -52,   105,    81,    44,    77,   100,   -52,    -5,
     118,    96,    78,    90,   -21,   -52,    -3,    91,    78,    78,
      78,    78,   101,   -52,   131,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,    78,    -3,    44,    44,    44,    30,    -3,
      78,   -52,   -10,    94,   -52,   -52,   -52,   -25,   -25,   -52,
     -52,   -52,   -52,   -52,   -52,   103,    29,    17,   -52,   -52,
     113,    44,   121,   -13,   -52,    78,   -52,   -52,    -3,   -52,
     -52,    82,   -52,    78,   -52,   130,   -52,    60,   -52,    78,
      52,    -3,   120,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   -52,   138,   -52,   -52,   -37,   135,   -38,
     -52,   -51,   -12,    24,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -11,    11,   -52,   -52,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      46,    81,    46,    50,    63,    41,    12,    54,    43,    89,
      90,   113,     5,     6,    77,    13,    14,    84,    85,    15,
      60,    61,    58,    59,    16,    17,    18,   108,   104,   105,
      58,    59,   109,    46,    19,    44,    78,    97,     3,    12,
      85,    20,   102,     1,    21,    22,    23,    24,    13,   101,
       8,     4,    15,     8,   114,    45,    66,    16,    17,    18,
      40,    96,    57,    46,    46,    46,   100,    19,   103,    51,
     121,   115,    58,    59,    20,    58,    59,    21,    22,    23,
      24,    19,    87,    88,   122,   119,    98,    99,    20,    46,
     111,    21,    22,    23,    24,    58,    59,    55,    75,    76,
      79,   117,   116,    58,    59,    52,    53,   120,    67,    68,
      69,    70,    71,    72,    74,    19,    75,    76,    64,    80,
      58,    59,    20,    62,    56,    21,    22,    23,    24,    75,
      76,    65,   106,   110,    75,    76,    79,    92,    93,    94,
      83,    86,   112,    91,   107,   118,   123,    42,    49
};

static const yytype_uint8 yycheck[] =
{
      12,    52,    14,    14,    41,     5,     9,    19,    12,    60,
      61,    24,     4,     5,    19,    18,    19,    38,    56,    22,
      45,    46,    43,    44,    27,    28,    29,    10,    38,    39,
      43,    44,    15,    45,    37,    39,    41,    74,    40,     9,
      78,    44,    79,    50,    47,    48,    49,    50,    18,    19,
      50,     0,    22,    50,   105,    11,    45,    27,    28,    29,
       3,    73,    30,    75,    76,    77,    77,    37,    80,    50,
      18,   108,    43,    44,    44,    43,    44,    47,    48,    49,
      50,    37,    58,    59,   121,    25,    75,    76,    44,   101,
     101,    47,    48,    49,    50,    43,    44,    48,    16,    17,
      18,   113,    20,    43,    44,    37,    37,   119,    31,    32,
      33,    34,    35,    36,    14,    37,    16,    17,    13,    23,
      43,    44,    44,    50,    41,    47,    48,    49,    50,    16,
      17,    50,    38,    20,    16,    17,    18,     6,     7,     8,
      50,    50,    21,    42,    41,    15,    26,     9,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,    40,     0,     4,     5,    53,    50,    54,
      55,    56,     9,    18,    19,    22,    27,    28,    29,    37,
      44,    47,    48,    49,    50,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    69,    70,    71,    74,    75,    76,
       3,     5,    55,    12,    39,    11,    63,    72,    73,    59,
      72,    50,    37,    37,    63,    48,    41,    30,    43,    44,
      45,    46,    50,    58,    13,    50,    73,    31,    32,    33,
      34,    35,    36,    68,    14,    16,    17,    19,    41,    18,
      23,    62,    67,    50,    38,    60,    50,    64,    64,    62,
      62,    42,     6,     7,     8,    57,    63,    58,    73,    73,
      72,    19,    58,    63,    38,    39,    38,    41,    10,    15,
      20,    72,    21,    24,    62,    58,    20,    63,    15,    25,
      63,    18,    58,    26
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 248 "spl.y"
    {
		if ((yyvsp[(1) - (6)].pSymbolTableEntry) != (yyvsp[(5) - (6)].pSymbolTableEntry))
		{
			HANDLE_WARNING("Program names do not match %s vs %s", (yyvsp[(1) - (6)].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier, (yyvsp[(5) - (6)].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier);
		}

		(yyvsp[(1) - (6)].pSymbolTableEntry)->bySymbolType = symbol_id_program;
		(yyvsp[(5) - (6)].pSymbolTableEntry)->bySymbolType = symbol_id_program;
		SymbolTableEntry* pNewSymbol = malloc(sizeof(SymbolTableEntry));
		pNewSymbol->bySymbolType = symbol_id_program;
		strcpy(&pNewSymbol->symbolDetails.programDetails.acIdentifier[4], &(yyvsp[(1) - (6)].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier[4]); /*Remove spl_*/
		memcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, "prg_", 4); 
		pNewSymbol->pNextTableEntry = (yyvsp[(1) - (6)].pSymbolTableEntry)->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = (yyvsp[(1) - (6)].pSymbolTableEntry)->pPrevTableEntry;
		memcpy((yyvsp[(1) - (6)].pSymbolTableEntry), pNewSymbol, sizeof(SymbolTableEntry));
		if ((yyvsp[(1) - (6)].pSymbolTableEntry) != (yyvsp[(5) - (6)].pSymbolTableEntry))
		{
			memcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, "prg_", 4); 
			strcpy(&pNewSymbol->symbolDetails.programDetails.acIdentifier[4], &(yyvsp[(5) - (6)].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier[4]); /*Remove spl_*/
		}
		pNewSymbol->pNextTableEntry = (yyvsp[(5) - (6)].pSymbolTableEntry)->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = (yyvsp[(5) - (6)].pSymbolTableEntry)->pPrevTableEntry;
		memcpy((yyvsp[(5) - (6)].pSymbolTableEntry), pNewSymbol, sizeof(SymbolTableEntry));
		free(pNewSymbol);

		Node* pParseTree = CreateNode((yyvsp[(1) - (6)].pSymbolTableEntry), id_program, (yyvsp[(3) - (6)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);

		#ifdef DEBUG
			PrintTree(pParseTree, 0);
            return;
		#endif

		(yyval.pNode) = pParseTree;
		EvaluateVariableUsage();
		FoldConstants(pParseTree);
		CheckForDivideByZero(pParseTree);
		RemoveDeadCode(pParseTree);
		if (g_uiErrorCount == 0)
		{
        	GenerateCode(pParseTree);
		}
	;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 292 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_block, (yyvsp[(2) - (4)].pNode), (yyvsp[(4) - (4)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 295 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_block, (yyvsp[(2) - (2)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 300 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_declaration_block, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 303 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_declaration_block, (yyvsp[(1) - (2)].pNode), (yyvsp[(2) - (2)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 308 "spl.y"
    {
		Node* pNode = (yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_declaration, (yyvsp[(1) - (5)].pNode), (yyvsp[(4) - (5)].pNode), NO_CHILD_NODE);

		Node* pIdentifierListNode = (yyvsp[(1) - (5)].pNode);
		while (pIdentifierListNode != NO_SYMBOL_FOUND)
		{
			pIdentifierListNode->pSymbolTableEntry->symbolDetails.variableDetails.iType = (yyvsp[(4) - (5)].pNode)->pSymbolTableEntry->symbolDetails.typeDetails.iType;
			CreateVariableDeclaredEntry(pIdentifierListNode->pSymbolTableEntry, pNode);
			pIdentifierListNode = pIdentifierListNode->pFirstChild;
		};
	;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 321 "spl.y"
    {
		(yyval.pNode) = CreateNode((yyvsp[(1) - (1)].pSymbolTableEntry), id_identifier_list, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 324 "spl.y"
    {
		(yyval.pNode) = CreateNode((yyvsp[(3) - (3)].pSymbolTableEntry), id_identifier_list, (yyvsp[(1) - (3)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 329 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_CHARACTER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 332 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_INTEGER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 335 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_REAL), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 340 "spl.y"
    {
		(yyval.pNode) = (yyvsp[(1) - (1)].pNode);
	;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 342 "spl.y"
    {
		g_uiCurrentLineNumber--;
		HANDLE_WARNING("Unexpected semi-colon at the end of the last statement within the code block. This will be ignored.");
		g_uiCurrentLineNumber++;
		(yyval.pNode) = (yyvsp[(1) - (2)].pNode);
	;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 350 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement_list, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 354 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement_list, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 359 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 362 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 365 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 368 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 371 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 374 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 377 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 380 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 385 "spl.y"
    {
		CheckIfVariableIsDeclared((yyvsp[(3) - (3)].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[(3) - (3)].pSymbolTableEntry), id_assignment_statement, (yyvsp[(1) - (3)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableAssignedEntry((yyvsp[(3) - (3)].pSymbolTableEntry), pNode);
		int iExpressionType = GetFinalTypeOfExpression((yyvsp[(1) - (3)].pNode), -1);
		if (iExpressionType == TYPE_REAL && (yyvsp[(3) - (3)].pSymbolTableEntry)->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_type_conversion_double_char, NULL);
		} 
		else if (iExpressionType == TYPE_INTEGER && (yyvsp[(3) - (3)].pSymbolTableEntry)->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
		{
			HANDLE_WARNING("An integer has been assigned to a variable of type characters.");
		}
		else if (iExpressionType == TYPE_REAL && (yyvsp[(3) - (3)].pSymbolTableEntry)->symbolDetails.variableDetails.iType == TYPE_INTEGER)
		{
			HANDLE_WARNING("A real has been assigned to a variable of type integer, this may cause a loss of precision.");
		}
	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 405 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_value, (yyvsp[(2) - (3)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 408 "spl.y"
    {
		CheckIfVariableIsDeclared((yyvsp[(1) - (1)].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[(1) - (1)].pSymbolTableEntry), id_value, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableUsedEntry((yyvsp[(1) - (1)].pSymbolTableEntry), pNode);
	;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 413 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_value, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 418 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_subtract), id_expression, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 421 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_add), id_expression, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 424 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_expression, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 429 "spl.y"
    {
		int iTermType = GetFinalTypeOfExpression((yyvsp[(1) - (3)].pNode), -1);
		int iValueType = GetFinalTypeOfExpression((yyvsp[(3) - (3)].pNode), -1);
		if (iValueType == TYPE_CHARACTER || iTermType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_operation_char_multipulcation, NULL);
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_multipulcation), id_term, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 439 "spl.y"
    {
		int iTermType = GetFinalTypeOfExpression((yyvsp[(1) - (3)].pNode), -1);
		int iValueType = GetFinalTypeOfExpression((yyvsp[(3) - (3)].pNode), -1);
		if (iValueType == TYPE_CHARACTER || iTermType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_operation_char_division, NULL);
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_division), id_term, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 449 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_term, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 454 "spl.y"
    {
		if ((yyvsp[(1) - (1)].fVal) > DBL_MAX)
		{
			HANDLE_WARNING("Constant (%e) is greater then the maximum value an REAL can store (%e). This value will be set to the maximum value (%e).", (yyvsp[(1) - (1)].fVal), DBL_MAX, DBL_MAX);
			(yyvsp[(1) - (1)].fVal) = DBL_MAX;
		}
		else if ((yyvsp[(1) - (1)].fVal) < -DBL_MAX)
		{
			HANDLE_WARNING("Constant (%e) is less then the minimum value an REAL can store (%e). This value will be set to the minimum value (%e).", (yyvsp[(1) - (1)].fVal), -DBL_MAX, -DBL_MAX);
			(yyvsp[(1) - (1)].fVal) = -DBL_MAX;
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_REAL, &(yyvsp[(1) - (1)].fVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 468 "spl.y"
    {
		if ((yyvsp[(1) - (1)].iVal) > (long)INT_MAX)
		{
			HANDLE_WARNING("Constant (%ld) is greater then the maximum value an INTEGER can store (%d). This value will be set to the maximum value (%d).", (yyvsp[(1) - (1)].iVal), INT_MAX, INT_MAX);
			(yyvsp[(1) - (1)].iVal) = INT_MAX;
		}
		
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &(yyvsp[(1) - (1)].iVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 477 "spl.y"
    {
		(yyvsp[(2) - (2)].iVal) = 0L - (yyvsp[(2) - (2)].iVal);
		
		if ((yyvsp[(2) - (2)].iVal) < (long)INT_MIN)
		{
			HANDLE_WARNING("Constant (%ld) is less then the minimum value an INTEGER can store (%d). This value will be set to the minimum value (%d).", (yyvsp[(2) - (2)].iVal), INT_MIN, INT_MIN);
			(yyvsp[(2) - (2)].iVal) = INT_MIN;
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &(yyvsp[(2) - (2)].iVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 488 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_CHARACTER, &(yyvsp[(1) - (1)].cVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 493 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, (yyvsp[(3) - (4)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 496 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 501 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_output_list, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 504 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_output_list, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 509 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_equality), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 512 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 515 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_less_than), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 518 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_more_than), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 521 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_less_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 524 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_more_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 529 "spl.y"
    {
		CheckIfVariableIsDeclared((yyvsp[(3) - (4)].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[(3) - (4)].pSymbolTableEntry), id_read_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableAssignedEntry((yyvsp[(3) - (4)].pSymbolTableEntry), pNode);
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 536 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_if_statement, (yyvsp[(2) - (5)].pNode), (yyvsp[(4) - (5)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 541 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_if_else_statement, (yyvsp[(2) - (7)].pNode), (yyvsp[(4) - (7)].pNode), (yyvsp[(6) - (7)].pNode));
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 546 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_conditional, (yyvsp[(1) - (1)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 548 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_and), id_conditional, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 550 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_or), id_conditional, (yyvsp[(1) - (3)].pNode), (yyvsp[(3) - (3)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 555 "spl.y"
    {
		int iFirstType = GetFinalTypeOfExpression((yyvsp[(1) - (3)].pNode), -1);
		int iSecondType = GetFinalTypeOfExpression((yyvsp[(3) - (3)].pNode), -1);

		if ((iFirstType == TYPE_CHARACTER || iSecondType == TYPE_CHARACTER) && (iFirstType == TYPE_REAL || iSecondType == TYPE_REAL))
		{
			CreateError(error_type_invalid_type_conversion_double_char, NULL);
		}

		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_comparison, (yyvsp[(1) - (3)].pNode), (yyvsp[(2) - (3)].pNode), (yyvsp[(3) - (3)].pNode));
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 565 "spl.y"
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not), id_comparison, (yyvsp[(2) - (2)].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 570 "spl.y"
    {
		CheckIfVariableIsDeclared((yyvsp[(2) - (11)].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[(2) - (11)].pSymbolTableEntry), id_for_statement, CreateNode(NO_SYMBOLIC_LINK, id_for_statement_is_by_to, (yyvsp[(4) - (11)].pNode), (yyvsp[(6) - (11)].pNode), (yyvsp[(8) - (11)].pNode)), (yyvsp[(10) - (11)].pNode), NO_CHILD_NODE);
		CreateVariableAssignedEntry((yyvsp[(2) - (11)].pSymbolTableEntry), pNode);
		CreateVariableUsedEntry((yyvsp[(2) - (11)].pSymbolTableEntry), pNode);
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 578 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_while_statement, (yyvsp[(2) - (5)].pNode), (yyvsp[(4) - (5)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 583 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, (yyvsp[(2) - (5)].pNode), (yyvsp[(4) - (5)].pNode), NO_CHILD_NODE);
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 586 "spl.y"
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, (yyvsp[(2) - (6)].pNode), (yyvsp[(5) - (6)].pNode), NO_CHILD_NODE);
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2371 "spl_t.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 589 "spl.y"


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
			printf("#include <stdio.h>\n\nvoid _spl_flush_stdin()\n{\n\tchar c = -1;\n\tfprintf(stderr, \"\\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: \");\n\tdo\n\t{\n\t\tc = getchar();\n\t\tif (c != EOF)\n\t\t{\n\t\t\tfprintf(stderr,\"%%c\", c);\n\t\t}\n\t} while (c != '\\n' && c != ' ' && c != EOF);\n}\n\nvoid %s()\n{\n", pNode->pSymbolTableEntry->symbolDetails.programDetails.acIdentifier);
			Evaluate(pNode->pFirstChild);
			printf("}\n\n");
			printf("int main()\n{\n\tfprintf(stderr, \"----------------RUNTIME WARNINGS & ERRORS----------------\");\n\t%s();\n\treturn 0;\n}\n", pNode->pSymbolTableEntry->symbolDetails.programDetails.acIdentifier);
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
	printf("{\n");
	g_iIndentLevel++;
	Indent();
	printf("char _spl_bDiscardedCharsFlag = 0;\n");
	Indent();
	printf("while (scanf(\"%s\", &%s) != 1)\n", pFormat, pNode->pSymbolTableEntry->symbolDetails.variableDetails.acIdentifier);
	Indent();
	printf("{\n");
	g_iIndentLevel++;
	Indent();
	printf("char c = getchar();\n");
	Indent();
	printf("if (c == '\\n' || c == ' ' || c == EOF)\n");
	Indent();
	printf("{\n");
	g_iIndentLevel++;
	Indent();
	printf("break;\n");
	g_iIndentLevel--;
	Indent();
	printf("}\n");
	Indent();
	printf("if (_spl_bDiscardedCharsFlag == 0)\n");
	Indent();
	printf("{\n");
	g_iIndentLevel++;
	Indent();
	printf("fprintf(stderr, \"\\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: \");\n");
	Indent();
	printf("_spl_bDiscardedCharsFlag = 1;\n");
	g_iIndentLevel--;
	Indent();
	printf("}\n");
	Indent();
	printf("fprintf(stderr,\"%%c\", c);\n");
	g_iIndentLevel--;
	Indent();
	printf("};\n");

	Indent();
	printf("_spl_flush_stdin();\n");
	g_iIndentLevel--;
	Indent();
	printf("}\n");
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
				WriteReadStatement(pNode, "%d");
			}
			else if (pNode->pSymbolTableEntry->symbolDetails.variableDetails.iType == TYPE_REAL)
			{
				WriteReadStatement(pNode, "%lf");
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

						if (pStatement == pStatement->pParent->pFirstChild)
						{
							pStatement->pParent->pFirstChild = NO_CHILD_NODE;
						}
						else if (pStatement == pStatement->pParent->pSecondChild)
						{
							pStatement->pParent->pSecondChild = NO_CHILD_NODE;
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
	if (pNode == NULL)
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
			else
			{
				Node* pParentNode = pNode->pParent->pParent;
			
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
			
			if (pParentNode->pFirstChild == pNode->pParent)
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
			else if (pParentNode->pSecondChild == pNode->pParent)
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
			else if (pParentNode->pThirdChild == pNode->pParent)
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
			
			if (pParentNode->pFirstChild == pNode->pParent)
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
			else if (pParentNode->pSecondChild == pNode->pParent)
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
			else if (pParentNode->pThirdChild == pNode->pParent)
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
				HANDLE_WARNING("The condition for the while statement is constant and true. This will cause an infinte loop\n");
			}
			else
			{
				if (pParentNode->pFirstChild == pNode->pParent)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pFirstChild = NULL;
				}
				else if (pParentNode->pSecondChild == pNode->pParent)
				{
					/*DeleteNode(pNode);*/
					pParentNode->pSecondChild = NULL;
				}
				else if (pParentNode->pThirdChild == pNode->pParent)
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
	if (pNode == NULL)
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
