/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./src/spl.y" /* yacc.c:339  */

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
	void DeleteVariableUsage(VariableUsageDetails** ppVariableUsage);
	void DeleteVariableUsageList(VariableUsageDetails** ppVariableUsage);
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
	void DeleteSymbolTable();

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
	void DeleteNode(Node** pNode);
	void DeleteTree(Node** pNode);
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

	bool g_bEvaluateVariableUsageAgain;

#line 297 "./src/spl_t.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 233 "./src/spl.y" /* yacc.c:355  */

	long iVal;
	double fVal;
	char cVal;
	Node* pNode;
	SymbolTableEntry* pSymbolTableEntry;

#line 393 "./src/spl_t.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 410 "./src/spl_t.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   253,   253,   310,   313,   318,   321,   326,   339,   342,
     347,   350,   353,   358,   360,   368,   371,   377,   380,   383,
     386,   389,   392,   395,   398,   403,   423,   426,   431,   436,
     439,   442,   447,   457,   467,   472,   486,   495,   506,   511,
     514,   519,   522,   527,   530,   533,   536,   539,   542,   547,
     554,   559,   564,   566,   568,   573,   583,   588,   596,   601,
     604
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "do_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -52,   -52,   138,   -52,   -52,   -37,   135,   -38,
     -52,   -51,   -12,    24,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -11,    11,   -52,   -52,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    11,    95,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    82,    73,    34,    35,
      36,    47,    48,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 253 "./src/spl.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-5].pSymbolTableEntry) != (yyvsp[-1].pSymbolTableEntry))
		{
			HANDLE_WARNING("Program names do not match %s vs %s", (yyvsp[-5].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier, (yyvsp[-1].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier);
		}

		(yyvsp[-5].pSymbolTableEntry)->bySymbolType = symbol_id_program;
		(yyvsp[-1].pSymbolTableEntry)->bySymbolType = symbol_id_program;
		SymbolTableEntry* pNewSymbol = malloc(sizeof(SymbolTableEntry));
		pNewSymbol->bySymbolType = symbol_id_program;
		strcpy(&pNewSymbol->symbolDetails.programDetails.acIdentifier[4], &(yyvsp[-5].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier[4]); /*Remove spl_*/
		memcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, "prg_", 4); 
		pNewSymbol->pNextTableEntry = (yyvsp[-5].pSymbolTableEntry)->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = (yyvsp[-5].pSymbolTableEntry)->pPrevTableEntry;
		memcpy((yyvsp[-5].pSymbolTableEntry), pNewSymbol, sizeof(SymbolTableEntry));
		if ((yyvsp[-5].pSymbolTableEntry) != (yyvsp[-1].pSymbolTableEntry))
		{
			memcpy(pNewSymbol->symbolDetails.programDetails.acIdentifier, "prg_", 4); 
			strcpy(&pNewSymbol->symbolDetails.programDetails.acIdentifier[4], &(yyvsp[-1].pSymbolTableEntry)->symbolDetails.variableDetails.acIdentifier[4]); /*Remove spl_*/
		}
		pNewSymbol->pNextTableEntry = (yyvsp[-1].pSymbolTableEntry)->pNextTableEntry;
		pNewSymbol->pPrevTableEntry = (yyvsp[-1].pSymbolTableEntry)->pPrevTableEntry;
		memcpy((yyvsp[-1].pSymbolTableEntry), pNewSymbol, sizeof(SymbolTableEntry));
		free(pNewSymbol);

		Node* pParseTree = CreateNode((yyvsp[-5].pSymbolTableEntry), id_program, (yyvsp[-3].pNode), NO_CHILD_NODE, NO_CHILD_NODE);

		#ifdef DEBUG
			PrintTree(pParseTree, 0);
			DeleteTree(&pParseTree);
			DeleteSymbolTable();
            return;
		#endif

		int i = 1;
		do
		{
			i++;
			g_bEvaluateVariableUsageAgain = false;
			EvaluateVariableUsage();
		} while (g_bEvaluateVariableUsageAgain);

		FoldConstants(pParseTree);
		CheckForDivideByZero(pParseTree);
		RemoveDeadCode(pParseTree);

		(yyval.pNode) = pParseTree;
		if (g_uiErrorCount == 0)
		{
			GenerateCode(pParseTree);
		}

		DeleteTree(&pParseTree);
		DeleteSymbolTable();
	}
#line 1639 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 3:
#line 310 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_block, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1647 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 4:
#line 313 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_block, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1655 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 5:
#line 318 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_declaration_block, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1663 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 6:
#line 321 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_declaration_block, (yyvsp[-1].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1671 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 7:
#line 326 "./src/spl.y" /* yacc.c:1646  */
    {
		Node* pNode = (yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_declaration, (yyvsp[-4].pNode), (yyvsp[-1].pNode), NO_CHILD_NODE);

		Node* pIdentifierListNode = (yyvsp[-4].pNode);
		while (pIdentifierListNode != NO_SYMBOL_FOUND)
		{
			pIdentifierListNode->pSymbolTableEntry->symbolDetails.variableDetails.iType = (yyvsp[-1].pNode)->pSymbolTableEntry->symbolDetails.typeDetails.iType;
			CreateVariableDeclaredEntry(pIdentifierListNode->pSymbolTableEntry, pNode);
			pIdentifierListNode = pIdentifierListNode->pFirstChild;
		};
	}
#line 1687 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 8:
#line 339 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode((yyvsp[0].pSymbolTableEntry), id_identifier_list, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1695 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 9:
#line 342 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode((yyvsp[0].pSymbolTableEntry), id_identifier_list, (yyvsp[-2].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1703 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 10:
#line 347 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_CHARACTER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1711 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 11:
#line 350 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_INTEGER), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1719 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 12:
#line 353 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Type((int)TYPE_REAL), id_type, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1727 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 13:
#line 358 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = (yyvsp[0].pNode);
	}
#line 1735 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 14:
#line 360 "./src/spl.y" /* yacc.c:1646  */
    {
		g_uiCurrentLineNumber--;
		HANDLE_WARNING("Unexpected semi-colon at the end of the last statement within the code block. This will be ignored.");
		g_uiCurrentLineNumber++;
		(yyval.pNode) = (yyvsp[-1].pNode);
	}
#line 1746 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 15:
#line 368 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement_list, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1754 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 16:
#line 372 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement_list, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1762 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 17:
#line 377 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1770 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 18:
#line 380 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1778 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 19:
#line 383 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1786 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 20:
#line 386 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1794 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 21:
#line 389 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1802 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 22:
#line 392 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1810 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 23:
#line 395 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1818 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 24:
#line 398 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_statement, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1826 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 25:
#line 403 "./src/spl.y" /* yacc.c:1646  */
    {
		CheckIfVariableIsDeclared((yyvsp[0].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[0].pSymbolTableEntry), id_assignment_statement, (yyvsp[-2].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableAssignedEntry((yyvsp[0].pSymbolTableEntry), pNode);
		int iExpressionType = GetFinalTypeOfExpression((yyvsp[-2].pNode), -1);
		if (iExpressionType == TYPE_REAL && (yyvsp[0].pSymbolTableEntry)->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_type_conversion_double_char, NULL);
		} 
		else if (iExpressionType == TYPE_INTEGER && (yyvsp[0].pSymbolTableEntry)->symbolDetails.variableDetails.iType == TYPE_CHARACTER)
		{
			HANDLE_WARNING("An integer has been assigned to a variable of type characters.");
		}
		else if (iExpressionType == TYPE_REAL && (yyvsp[0].pSymbolTableEntry)->symbolDetails.variableDetails.iType == TYPE_INTEGER)
		{
			HANDLE_WARNING("A real has been assigned to a variable of type integer, this may cause a loss of precision.");
		}
	}
#line 1849 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 26:
#line 423 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_value, (yyvsp[-1].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1857 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 27:
#line 426 "./src/spl.y" /* yacc.c:1646  */
    {
		CheckIfVariableIsDeclared((yyvsp[0].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[0].pSymbolTableEntry), id_value, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableUsedEntry((yyvsp[0].pSymbolTableEntry), pNode);
	}
#line 1867 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 28:
#line 431 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_value, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1875 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 29:
#line 436 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_subtract), id_expression, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1883 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 30:
#line 439 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_add), id_expression, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1891 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 31:
#line 442 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_expression, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1899 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 32:
#line 447 "./src/spl.y" /* yacc.c:1646  */
    {
		int iTermType = GetFinalTypeOfExpression((yyvsp[-2].pNode), -1);
		int iValueType = GetFinalTypeOfExpression((yyvsp[0].pNode), -1);
		if (iValueType == TYPE_CHARACTER || iTermType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_operation_char_multipulcation, NULL);
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_multipulcation), id_term, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1914 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 33:
#line 457 "./src/spl.y" /* yacc.c:1646  */
    {
		int iTermType = GetFinalTypeOfExpression((yyvsp[-2].pNode), -1);
		int iValueType = GetFinalTypeOfExpression((yyvsp[0].pNode), -1);
		if (iValueType == TYPE_CHARACTER || iTermType == TYPE_CHARACTER)
		{
			CreateError(error_type_invalid_operation_char_division, NULL);
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_division), id_term, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 1929 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 34:
#line 467 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_term, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1937 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 35:
#line 472 "./src/spl.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].fVal) > DBL_MAX)
		{
			HANDLE_WARNING("Constant (%e) is greater then the maximum value an REAL can store (%e). This value will be set to the maximum value (%e).", (yyvsp[0].fVal), DBL_MAX, DBL_MAX);
			(yyvsp[0].fVal) = DBL_MAX;
		}
		else if ((yyvsp[0].fVal) < -DBL_MAX)
		{
			HANDLE_WARNING("Constant (%e) is less then the minimum value an REAL can store (%e). This value will be set to the minimum value (%e).", (yyvsp[0].fVal), -DBL_MAX, -DBL_MAX);
			(yyvsp[0].fVal) = -DBL_MAX;
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_REAL, &(yyvsp[0].fVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1956 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 36:
#line 486 "./src/spl.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].iVal) > (long)INT_MAX)
		{
			HANDLE_WARNING("Constant (%ld) is greater then the maximum value an INTEGER can store (%d). This value will be set to the maximum value (%d).", (yyvsp[0].iVal), INT_MAX, INT_MAX);
			(yyvsp[0].iVal) = INT_MAX;
		}
		
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &(yyvsp[0].iVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1970 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 37:
#line 495 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyvsp[0].iVal) = 0L - (yyvsp[0].iVal);
		
		if ((yyvsp[0].iVal) < (long)INT_MIN)
		{
			HANDLE_WARNING("Constant (%ld) is less then the minimum value an INTEGER can store (%d). This value will be set to the minimum value (%d).", (yyvsp[0].iVal), INT_MIN, INT_MIN);
			(yyvsp[0].iVal) = INT_MIN;
		}

		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_INTEGER, &(yyvsp[0].iVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1986 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 38:
#line 506 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Constant(TYPE_CHARACTER, &(yyvsp[0].cVal)), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 1994 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 39:
#line 511 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, (yyvsp[-1].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2002 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 40:
#line 514 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_write_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2010 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 41:
#line 519 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_output_list, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2018 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 42:
#line 522 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_output_list, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 2026 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 43:
#line 527 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_equality), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2034 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 44:
#line 530 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2042 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 45:
#line 533 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_less_than), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2050 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 46:
#line 536 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_more_than), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	}
#line 2058 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 47:
#line 539 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_less_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	}
#line 2066 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 48:
#line 542 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_more_equal), id_comparator, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);		
	}
#line 2074 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 49:
#line 547 "./src/spl.y" /* yacc.c:1646  */
    {
		CheckIfVariableIsDeclared((yyvsp[-1].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[-1].pSymbolTableEntry), id_read_statement, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE);
		CreateVariableAssignedEntry((yyvsp[-1].pSymbolTableEntry), pNode);
	}
#line 2084 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_if_statement, (yyvsp[-3].pNode), (yyvsp[-1].pNode), NO_CHILD_NODE);
	}
#line 2092 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 51:
#line 559 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_if_else_statement, (yyvsp[-5].pNode), (yyvsp[-3].pNode), (yyvsp[-1].pNode));
	}
#line 2100 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 52:
#line 564 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_conditional, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2108 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 53:
#line 566 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_and), id_conditional, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 2116 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 54:
#line 568 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_or), id_conditional, (yyvsp[-2].pNode), (yyvsp[0].pNode), NO_CHILD_NODE);
	}
#line 2124 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 55:
#line 573 "./src/spl.y" /* yacc.c:1646  */
    {
		int iFirstType = GetFinalTypeOfExpression((yyvsp[-2].pNode), -1);
		int iSecondType = GetFinalTypeOfExpression((yyvsp[0].pNode), -1);

		if ((iFirstType == TYPE_CHARACTER || iSecondType == TYPE_CHARACTER) && (iFirstType == TYPE_REAL || iSecondType == TYPE_REAL))
		{
			CreateError(error_type_invalid_type_conversion_double_char, NULL);
		}

		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_comparison, (yyvsp[-2].pNode), (yyvsp[-1].pNode), (yyvsp[0].pNode));
	}
#line 2140 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 56:
#line 583 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(CreateSymbolTableEntry_Operator(operator_type_not), id_comparison, (yyvsp[0].pNode), NO_CHILD_NODE, NO_CHILD_NODE);
	}
#line 2148 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 57:
#line 588 "./src/spl.y" /* yacc.c:1646  */
    {
		CheckIfVariableIsDeclared((yyvsp[-9].pSymbolTableEntry));
		Node* pNode = (yyval.pNode) = CreateNode((yyvsp[-9].pSymbolTableEntry), id_for_statement, CreateNode(NO_SYMBOLIC_LINK, id_for_statement_is_by_to, (yyvsp[-7].pNode), (yyvsp[-5].pNode), (yyvsp[-3].pNode)), (yyvsp[-1].pNode), NO_CHILD_NODE);
		CreateVariableAssignedEntry((yyvsp[-9].pSymbolTableEntry), pNode);
		CreateVariableUsedEntry((yyvsp[-9].pSymbolTableEntry), pNode);
	}
#line 2159 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 58:
#line 596 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_while_statement, (yyvsp[-3].pNode), (yyvsp[-1].pNode), NO_CHILD_NODE);
	}
#line 2167 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 59:
#line 601 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, (yyvsp[-3].pNode), (yyvsp[-1].pNode), NO_CHILD_NODE);
	}
#line 2175 "./src/spl_t.c" /* yacc.c:1646  */
    break;

  case 60:
#line 604 "./src/spl.y" /* yacc.c:1646  */
    {
		(yyval.pNode) = CreateNode(NO_SYMBOLIC_LINK, id_do_statement, (yyvsp[-4].pNode), (yyvsp[-1].pNode), NO_CHILD_NODE);
	}
#line 2183 "./src/spl_t.c" /* yacc.c:1646  */
    break;


#line 2187 "./src/spl_t.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 607 "./src/spl.y" /* yacc.c:1906  */


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
				printf("%f", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.f);
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
					printf("%%f");
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
				printf("%f", pNode->pSymbolTableEntry->symbolDetails.constantDetails.value.f);
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
				printf("%%f");
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
								DeleteNode(&pStatement->pParent->pFirstChild);
							}
							else if (pStatement == pStatement->pParent->pSecondChild)
							{
								DeleteNode(&pStatement->pParent->pSecondChild);
							}

							VariableUsageDetails* pUsageToDelete = pUsage->pPrevUsage;
							pUsage->pPrevUsage = pUsage->pPrevUsage->pPrevUsage;
							pUsage->pPrevUsage->pNextUsage = pUsage;
							DeleteVariableUsage(&pUsageToDelete);
							g_bEvaluateVariableUsageAgain = true;
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
					pParentNode->pFirstChild = pNode->pFirstChild;
					DeleteNode(&pNode);
				}
				else if (pParentNode->pSecondChild == pNode->pParent)
				{
					pParentNode->pSecondChild = pNode->pFirstChild;
					DeleteNode(&pNode);
				}
				if (pParentNode->pThirdChild == pNode->pParent)
				{
					pParentNode->pThirdChild = pNode->pFirstChild;
					DeleteNode(&pNode);
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
				if (bConstRes == true)
				{
					pParentNode->pFirstChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pFirstChild = NULL;
				}
				DeleteNode(&pNode);
			}
			else if (pParentNode->pSecondChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				if (bConstRes == true)
				{
					pParentNode->pSecondChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pSecondChild = NULL;
				}
				DeleteNode(&pNode);
			}
			else if (pParentNode->pThirdChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				if (bConstRes == true)
				{
					pParentNode->pThirdChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pThirdChild = NULL;
				}
				DeleteNode(&pNode);
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
				if (bConstRes)
				{
					pParentNode->pFirstChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pFirstChild = pNode->pThirdChild;
				}
				DeleteNode(&pNode);
			}
			else if (pParentNode->pSecondChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				if (bConstRes)
				{
					pParentNode->pSecondChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pSecondChild = pNode->pThirdChild;
				}
				DeleteNode(&pNode);
			}
			else if (pParentNode->pThirdChild == pNode->pParent && g_bOptimisation_DeadCode)
			{
				if (bConstRes)
				{
					pParentNode->pThirdChild = pNode->pSecondChild;
				}
				else
				{
					pParentNode->pThirdChild = pNode->pThirdChild;
				}
				DeleteNode(&pNode);
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
					DeleteNode(&pNode);
					pParentNode->pFirstChild = NULL;
				}
				else if (pParentNode->pSecondChild == pNode->pParent && g_bOptimisation_DeadCode)
				{
					DeleteNode(&pNode);
					pParentNode->pSecondChild = NULL;
				}
				else if (pParentNode->pThirdChild == pNode->pParent && g_bOptimisation_DeadCode)
				{
					DeleteNode(&pNode);
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
					DeleteNode(&pNode);
					pParentNode->pFirstChild = 	CreateNode(NO_SYMBOLIC_LINK, id_expression, 
												CreateNode(NO_SYMBOLIC_LINK, id_term, 
												CreateNode(NO_SYMBOLIC_LINK, id_value, 
												CreateNode(CreateSymbolTableEntry_Constant(iType, pValue), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE), 
												NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE);
				}
				else if (pParentNode->pSecondChild == pNode)
				{
					DeleteNode(&pNode);
					pParentNode->pSecondChild = CreateNode(NO_SYMBOLIC_LINK, id_expression, 
												CreateNode(NO_SYMBOLIC_LINK, id_term, 
												CreateNode(NO_SYMBOLIC_LINK, id_value, 
												CreateNode(CreateSymbolTableEntry_Constant(iType, pValue), id_constant, NO_CHILD_NODE, NO_CHILD_NODE, NO_CHILD_NODE), 
												NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE), NO_CHILD_NODE, NO_CHILD_NODE);
				}
				else if (pParentNode->pThirdChild == pNode)
				{
					DeleteNode(&pNode);
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

void DeleteNode(Node** pNode)
{
	if (*pNode == NULL)
	{
		return;
	}

	free(*pNode);
	*pNode = NULL;
}

void DeleteTree(Node** pNode)
{
	if (*pNode == NULL)
	{
		return;
	}

	DeleteTree(&(*pNode)->pFirstChild);
	DeleteTree(&(*pNode)->pSecondChild);
	DeleteTree(&(*pNode)->pThirdChild);

	DeleteNode(&(*pNode)->pFirstChild);
	DeleteNode(&(*pNode)->pSecondChild);
	DeleteNode(&(*pNode)->pThirdChild);
}

void DeleteSymbolTableEntry(SymbolTableEntry** ppSymbolTableEntry)
{
	if (*ppSymbolTableEntry == NULL)
	{
		return;
	}

	free(*ppSymbolTableEntry);
	*ppSymbolTableEntry = NULL;
}

void DeleteSymbolTable()
{
	SymbolTableEntry* pCurrentEntry = g_pSymbolTableStart;
	while (pCurrentEntry != NO_SYMBOL_FOUND)
	{
		if (pCurrentEntry->bySymbolType == symbol_id_variable)
		{
			DeleteVariableUsageList(&pCurrentEntry->symbolDetails.variableDetails.pFirstUsage);
			pCurrentEntry->symbolDetails.variableDetails.pLastUsage = NULL;
		}

		pCurrentEntry = pCurrentEntry->pNextTableEntry;
		if (pCurrentEntry != NULL)
			DeleteSymbolTableEntry(&pCurrentEntry->pPrevTableEntry);
	}
}

void DeleteVariableUsage(VariableUsageDetails** ppVariableUsage)
{
	if (*ppVariableUsage == NULL)
	{
		return;
	}

	free(*ppVariableUsage);
	*ppVariableUsage = NULL;
}

void DeleteVariableUsageList(VariableUsageDetails** ppVariableUsage)
{
	VariableUsageDetails* pCurrentUsage = *ppVariableUsage;
	while (pCurrentUsage != NULL)
	{
		pCurrentUsage = pCurrentUsage->pNextUsage;
		if (pCurrentUsage != NULL)
			DeleteVariableUsage(&pCurrentUsage->pPrevUsage);
	};

	*ppVariableUsage = NULL;
}

#include "lex.yy.c"
