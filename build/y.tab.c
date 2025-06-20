/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 1000
#define MAX_TEMPS 100
#define MAX_LABELS 100

extern int yylineno;
extern char* yytext;
extern int line_num;
extern void init_lexer();

// Symbol table entry
typedef struct {
    char name[50];
    char type[20];    // "integer", "float", "integer_array", "float_array"
    int array_size;   // 0 for non-arrays
    int declared;
} symbol_t;

// Symbol table
symbol_t symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int temp_count = 0;
int label_count = 0;

// Function prototypes
void yyerror(const char* s);
int yylex(void);
int lookup_symbol(const char* name);
int add_symbol(const char* name, const char* type, int array_size);
char* new_temp(void);
char* new_label(void);

#line 108 "build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 4,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* FLOAT_LITERAL  */
  YYSYMBOL_PROGRAM = 6,                    /* PROGRAM  */
  YYSYMBOL_BEGIN_ = 7,                     /* BEGIN_  */
  YYSYMBOL_END = 8,                        /* END  */
  YYSYMBOL_DECLARE = 9,                    /* DECLARE  */
  YYSYMBOL_AS = 10,                        /* AS  */
  YYSYMBOL_INTEGER_TYPE = 11,              /* INTEGER_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 12,                /* FLOAT_TYPE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_TO = 14,                        /* TO  */
  YYSYMBOL_DOWNTO = 15,                    /* DOWNTO  */
  YYSYMBOL_ENDFOR = 16,                    /* ENDFOR  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ENDIF = 20,                     /* ENDIF  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_LPAREN = 25,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 26,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 27,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 28,                  /* RBRACKET  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MINUS = 30,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 31,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 32,                    /* DIVIDE  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_EQ = 37,                        /* EQ  */
  YYSYMBOL_NE = 38,                        /* NE  */
  YYSYMBOL_UMINUS = 39,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_program_body = 43,              /* program_body  */
  YYSYMBOL_declaration_list = 44,          /* declaration_list  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_identifier_list = 46,           /* identifier_list  */
  YYSYMBOL_array_identifier = 47,          /* array_identifier  */
  YYSYMBOL_type_spec = 48,                 /* type_spec  */
  YYSYMBOL_statement_list = 49,            /* statement_list  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_assignment_statement = 51,      /* assignment_statement  */
  YYSYMBOL_for_statement = 52,             /* for_statement  */
  YYSYMBOL_if_statement = 53,              /* if_statement  */
  YYSYMBOL_condition = 54,                 /* condition  */
  YYSYMBOL_print_statement = 55,           /* print_statement  */
  YYSYMBOL_expression = 56                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    73,    88,    91,    93,    97,   134,   140,
     151,   157,   167,   168,   171,   173,   177,   178,   179,   180,
     184,   198,   215,   224,   236,   237,   241,   242,   243,   244,
     245,   246,   250,   254,   261,   267,   273,   283,   294,   301,
     308,   315,   322,   329
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "PROGRAM", "BEGIN_", "END",
  "DECLARE", "AS", "INTEGER_TYPE", "FLOAT_TYPE", "FOR", "TO", "DOWNTO",
  "ENDFOR", "IF", "THEN", "ELSE", "ENDIF", "PRINT", "ASSIGN", "SEMICOLON",
  "COMMA", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "GE", "LE", "GT", "LT", "EQ", "NE", "UMINUS",
  "$accept", "program", "$@1", "program_body", "declaration_list",
  "declaration", "identifier_list", "array_identifier", "type_spec",
  "statement_list", "statement", "assignment_statement", "for_statement",
  "if_statement", "condition", "print_statement", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     3,    14,   -49,   -49,     9,   -49,   -49,    23,    40,
     -49,    59,    19,    -9,   -49,    22,   -49,    25,    38,    41,
     -49,   -49,   -49,   -49,   -49,    73,    42,    40,    15,    15,
      76,    15,    15,    55,   -49,   -49,    63,   -49,    57,   -49,
     -49,    15,    15,    81,   120,    68,    66,    65,    94,   -49,
     -49,    15,   -21,   -49,   -49,    15,    15,    15,    15,    69,
      15,    87,    15,    15,    15,    15,    15,    15,    15,    64,
     125,   -49,    39,    39,   -49,   -49,    15,    27,   -49,   129,
     129,   129,   129,   129,   129,   101,   -49,   -49,    85,    15,
      15,     4,    83,   -49,   108,   115,   -49,   -49,   -49,   -49,
     -49,    61,    52,    72,   -49,   -49,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     3,    14,     0,
       6,     0,    10,     0,     8,     0,     4,     0,     0,     0,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     9,    36,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       7,     0,     0,    42,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    38,    39,    40,    41,     0,     0,    14,    26,
      27,    28,    29,    30,    31,     0,    32,    37,     0,     0,
       0,     0,     0,    21,     0,     0,    14,    24,    33,    14,
      14,     0,     0,     0,    25,    22,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,   -49,   -49,   -49,    80,   -49,   -48,
     -49,   -49,   -49,   -49,   -49,   -49,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,     7,     8,    10,    13,    14,    36,    11,
      20,    21,    22,    23,    46,    24,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    26,    47,    48,     1,    71,     3,    15,    55,    56,
      57,    58,    52,    53,     4,    27,     6,    17,    38,    39,
      40,    18,    70,    96,    97,    19,    72,    73,    74,    75,
      91,    77,     9,    79,    80,    81,    82,    83,    84,    85,
      41,    89,    90,    12,    28,    42,    25,    88,   101,    29,
      30,   102,   103,    34,    35,    15,    55,    56,    57,    58,
      94,    95,    15,    31,    15,    17,    32,    16,   105,    18,
      57,    58,    17,    19,    17,    15,    18,    33,    18,    45,
      19,   104,    19,    49,    51,    17,    50,    86,   106,    18,
      60,    76,    61,    19,    55,    56,    57,    58,    62,    63,
      64,    65,    66,    67,    54,    78,    98,    37,    93,     0,
      55,    56,    57,    58,    55,    56,    57,    58,    68,     0,
      69,     0,     0,    55,    56,    57,    58,    92,     0,     0,
      55,    56,    57,    58,    99,     0,     0,    55,    56,    57,
      58,   100,     0,     0,    55,    56,    57,    58,    59,    55,
      56,    57,    58,    87,    55,    56,    57,    58,    55,    56,
      57,    58
};

static const yytype_int8 yycheck[] =
{
      29,    10,    31,    32,     6,    26,     3,     3,    29,    30,
      31,    32,    41,    42,     0,    24,     7,    13,     3,     4,
       5,    17,    51,    19,    20,    21,    55,    56,    57,    58,
      78,    60,     9,    62,    63,    64,    65,    66,    67,    68,
      25,    14,    15,     3,    22,    30,    27,    76,    96,    27,
      25,    99,   100,    11,    12,     3,    29,    30,    31,    32,
      89,    90,     3,    25,     3,    13,    25,     8,    16,    17,
      31,    32,    13,    21,    13,     3,    17,     4,    17,     3,
      21,    20,    21,    28,    27,    13,    23,    23,    16,    17,
      22,    22,    26,    21,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    23,    18,    23,    27,    23,    -1,
      29,    30,    31,    32,    29,    30,    31,    32,    24,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    26,    -1,    -1,
      29,    30,    31,    32,    26,    -1,    -1,    29,    30,    31,
      32,    26,    -1,    -1,    29,    30,    31,    32,    28,    29,
      30,    31,    32,    28,    29,    30,    31,    32,    29,    30,
      31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    41,     3,     0,    42,     7,    43,    44,     9,
      45,    49,     3,    46,    47,     3,     8,    13,    17,    21,
      50,    51,    52,    53,    55,    27,    10,    24,    22,    27,
      25,    25,    25,     4,    11,    12,    48,    47,     3,     4,
       5,    25,    30,    56,    56,     3,    54,    56,    56,    28,
      23,    27,    56,    56,    23,    29,    30,    31,    32,    28,
      22,    26,    33,    34,    35,    36,    37,    38,    24,    26,
      56,    26,    56,    56,    56,    56,    22,    56,    18,    56,
      56,    56,    56,    56,    56,    56,    23,    28,    56,    14,
      15,    49,    26,    23,    56,    56,    19,    20,    23,    26,
      26,    49,    49,    49,    20,    16,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    41,    43,    44,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     4,     0,     2,     5,     1,     3,
       1,     4,     1,     1,     0,     2,     1,     1,     1,     1,
       4,     7,    10,    10,     7,     9,     3,     3,     3,     3,
       3,     3,     5,     7,     1,     1,     1,     4,     3,     3,
       3,     3,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 74 "src/parser.y"
    {
        if (!(yyvsp[0].strval)) {
            yyerror("Invalid program name");
            return 1;
        }
        printf("START %s\n\n", (yyvsp[0].strval));
    }
#line 1231 "build/y.tab.c"
    break;

  case 3: /* program: PROGRAM IDENTIFIER $@1 program_body  */
#line 82 "src/parser.y"
    {
        printf("HALT %s\n\n", (yyvsp[-2].strval));
    }
#line 1239 "build/y.tab.c"
    break;

  case 7: /* declaration: DECLARE identifier_list AS type_spec SEMICOLON  */
#line 98 "src/parser.y"
    {
        char* list = strdup((yyvsp[-3].id_attr).text);
        char* token = strtok(list, ",");
        while (token) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = 0;

            char* bracket = strchr(token, '[');
            if (bracket) {
                *bracket = '\0';
                int size;
                if (sscanf(bracket + 1, "%d]", &size) != 1) {
                    yyerror("Invalid array declaration");
                    return 1;
                }
                char array_type[30];
                sprintf(array_type, "%s_array", (yyvsp[-1].strval));
                if (add_symbol(token, array_type, size) == -1) return 1;
                printf("Declare %s, %s,%d\n", token,
                       strcmp((yyvsp[-1].strval), "integer") == 0 ? "Integer_array" : "Float_array",
                       size);
            } else {
                if (add_symbol(token, (yyvsp[-1].strval), 0) == -1) return 1;
                printf("Declare %s, %s\n", token,
                       strcmp((yyvsp[-1].strval), "integer") == 0 ? "Integer" : "Float");
            }
            token = strtok(NULL, ",");
        }
        free(list);
        printf("\n");
    }
#line 1277 "build/y.tab.c"
    break;

  case 8: /* identifier_list: array_identifier  */
#line 135 "src/parser.y"
    {
        (yyval.id_attr).text = (yyvsp[0].id_attr).text;
        (yyval.id_attr).is_array = (yyvsp[0].id_attr).is_array;
        (yyval.id_attr).array_size = (yyvsp[0].id_attr).array_size;
    }
#line 1287 "build/y.tab.c"
    break;

  case 9: /* identifier_list: identifier_list COMMA array_identifier  */
#line 141 "src/parser.y"
    {
        (yyval.id_attr).text = malloc(strlen((yyvsp[-2].id_attr).text) + strlen((yyvsp[0].id_attr).text) + 2);
        sprintf((yyval.id_attr).text, "%s,%s", (yyvsp[-2].id_attr).text, (yyvsp[0].id_attr).text);
        free((yyvsp[-2].id_attr).text);
        (yyval.id_attr).is_array = (yyvsp[0].id_attr).is_array;
        (yyval.id_attr).array_size = (yyvsp[0].id_attr).array_size;
    }
#line 1299 "build/y.tab.c"
    break;

  case 10: /* array_identifier: IDENTIFIER  */
#line 152 "src/parser.y"
    {
        (yyval.id_attr).text = strdup((yyvsp[0].strval));
        (yyval.id_attr).is_array = 0;
        (yyval.id_attr).array_size = 0;
    }
#line 1309 "build/y.tab.c"
    break;

  case 11: /* array_identifier: IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET  */
#line 158 "src/parser.y"
    {
        (yyval.id_attr).text = malloc(strlen((yyvsp[-3].strval)) + 20);
        sprintf((yyval.id_attr).text, "%s[%d]", (yyvsp[-3].strval), (yyvsp[-1].intval));
        (yyval.id_attr).is_array = 1;
        (yyval.id_attr).array_size = (yyvsp[-1].intval);
    }
#line 1320 "build/y.tab.c"
    break;

  case 12: /* type_spec: INTEGER_TYPE  */
#line 167 "src/parser.y"
                 { (yyval.strval) = strdup("integer"); }
#line 1326 "build/y.tab.c"
    break;

  case 13: /* type_spec: FLOAT_TYPE  */
#line 168 "src/parser.y"
                 { (yyval.strval) = strdup("float"); }
#line 1332 "build/y.tab.c"
    break;

  case 20: /* assignment_statement: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 185 "src/parser.y"
    {
        int idx = lookup_symbol((yyvsp[-3].strval));
        if (idx == -1) {
            yyerror("Undefined variable");
            return 1;
        }
        if (strstr(symbol_table[idx].type, "array")) {
            yyerror("Cannot assign to array");
            return 1;
        }
        char* store_op = strstr(symbol_table[idx].type, "integer") ? "I_STORE" : "F_STORE";
        printf("%s %s,%s\n\n", store_op, (yyvsp[-1].expr).addr, (yyvsp[-3].strval));
    }
#line 1350 "build/y.tab.c"
    break;

  case 21: /* assignment_statement: IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON  */
#line 199 "src/parser.y"
    {
        int idx = lookup_symbol((yyvsp[-6].strval));
        if (idx == -1) {
            yyerror("Undefined array");
            return 1;
        }
        if (!strstr(symbol_table[idx].type, "array")) {
            yyerror("Not an array");
            return 1;
        }
        char* store_op = strstr(symbol_table[idx].type, "integer") ? "I_STORE" : "F_STORE";
        printf("%s %s,%s[%s]\n\n", store_op, (yyvsp[-1].expr).addr, (yyvsp[-6].strval), (yyvsp[-4].expr).addr);
    }
#line 1368 "build/y.tab.c"
    break;

  case 22: /* for_statement: FOR LPAREN IDENTIFIER ASSIGN expression TO expression RPAREN statement_list ENDFOR  */
#line 216 "src/parser.y"
    {
        char* loop_label = new_label();
        printf("I_STORE %s,%s\n", (yyvsp[-5].expr).addr, (yyvsp[-7].strval));
        printf("%s:\n", loop_label);
        printf("INC %s\n", (yyvsp[-7].strval));
        printf("I_CMP %s,%s\n", (yyvsp[-7].strval), (yyvsp[-3].expr).addr);
        printf("JLE %s\n\n", loop_label);
    }
#line 1381 "build/y.tab.c"
    break;

  case 23: /* for_statement: FOR LPAREN IDENTIFIER ASSIGN expression DOWNTO expression RPAREN statement_list ENDFOR  */
#line 225 "src/parser.y"
    {
        char* loop_label = new_label();
        printf("I_STORE %s,%s\n", (yyvsp[-5].expr).addr, (yyvsp[-7].strval));
        printf("%s:\n", loop_label);
        printf("DEC %s\n", (yyvsp[-7].strval));
        printf("I_CMP %s,%s\n", (yyvsp[-7].strval), (yyvsp[-3].expr).addr);
        printf("JGE %s\n\n", loop_label);
    }
#line 1394 "build/y.tab.c"
    break;

  case 26: /* condition: expression GE expression  */
#line 241 "src/parser.y"
                             { printf("F_CMP %s,%s\nJL ", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr); }
#line 1400 "build/y.tab.c"
    break;

  case 27: /* condition: expression LE expression  */
#line 242 "src/parser.y"
                               { printf("F_CMP %s,%s\nJG ", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr); }
#line 1406 "build/y.tab.c"
    break;

  case 28: /* condition: expression GT expression  */
#line 243 "src/parser.y"
                               { printf("F_CMP %s,%s\nJLE ", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr); }
#line 1412 "build/y.tab.c"
    break;

  case 29: /* condition: expression LT expression  */
#line 244 "src/parser.y"
                               { printf("F_CMP %s,%s\nJGE ", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr); }
#line 1418 "build/y.tab.c"
    break;

  case 30: /* condition: expression EQ expression  */
#line 245 "src/parser.y"
                               { printf("F_CMP %s,%s\nJNE ", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr); }
#line 1424 "build/y.tab.c"
    break;

  case 31: /* condition: expression NE expression  */
#line 246 "src/parser.y"
                               { printf("F_CMP %s,%s\nJE ", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr); }
#line 1430 "build/y.tab.c"
    break;

  case 32: /* print_statement: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 251 "src/parser.y"
    {
        printf("CALL print, %s\n\n", (yyvsp[-2].expr).addr);
    }
#line 1438 "build/y.tab.c"
    break;

  case 33: /* print_statement: PRINT LPAREN expression COMMA expression RPAREN SEMICOLON  */
#line 255 "src/parser.y"
    {
        printf("CALL print,%s,%s\n\n", (yyvsp[-4].expr).addr, (yyvsp[-2].expr).addr);
    }
#line 1446 "build/y.tab.c"
    break;

  case 34: /* expression: INTEGER_LITERAL  */
#line 262 "src/parser.y"
    {
        (yyval.expr).addr = malloc(20);
        sprintf((yyval.expr).addr, "%d", (yyvsp[0].intval));
        (yyval.expr).type = strdup("integer");
    }
#line 1456 "build/y.tab.c"
    break;

  case 35: /* expression: FLOAT_LITERAL  */
#line 268 "src/parser.y"
    {
        (yyval.expr).addr = malloc(20);
        sprintf((yyval.expr).addr, "%.2f", (yyvsp[0].floatval));
        (yyval.expr).type = strdup("float");
    }
#line 1466 "build/y.tab.c"
    break;

  case 36: /* expression: IDENTIFIER  */
#line 274 "src/parser.y"
    {
        int idx = lookup_symbol((yyvsp[0].strval));
        if (idx == -1) {
            yyerror("Undefined variable");
            return 1;
        }
        (yyval.expr).addr = strdup((yyvsp[0].strval));
        (yyval.expr).type = strdup(symbol_table[idx].type);
    }
#line 1480 "build/y.tab.c"
    break;

  case 37: /* expression: IDENTIFIER LBRACKET expression RBRACKET  */
#line 284 "src/parser.y"
    {
        int idx = lookup_symbol((yyvsp[-3].strval));
        if (idx == -1) {
            yyerror("Undefined array");
            return 1;
        }
        (yyval.expr).addr = malloc(strlen((yyvsp[-3].strval)) + strlen((yyvsp[-1].expr).addr) + 3);
        sprintf((yyval.expr).addr, "%s[%s]", (yyvsp[-3].strval), (yyvsp[-1].expr).addr);
        (yyval.expr).type = strdup("float");
    }
#line 1495 "build/y.tab.c"
    break;

  case 38: /* expression: expression PLUS expression  */
#line 295 "src/parser.y"
    {
        char* temp = new_temp();
        printf("F_ADD %s,%s,%s\n", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
        (yyval.expr).addr = temp;
        (yyval.expr).type = strdup("float");
    }
#line 1506 "build/y.tab.c"
    break;

  case 39: /* expression: expression MINUS expression  */
#line 302 "src/parser.y"
    {
        char* temp = new_temp();
        printf("F_SUB %s,%s,%s\n", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
        (yyval.expr).addr = temp;
        (yyval.expr).type = strdup("float");
    }
#line 1517 "build/y.tab.c"
    break;

  case 40: /* expression: expression MULTIPLY expression  */
#line 309 "src/parser.y"
    {
        char* temp = new_temp();
        printf("F_MUL %s,%s,%s\n", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
        (yyval.expr).addr = temp;
        (yyval.expr).type = strdup("float");
    }
#line 1528 "build/y.tab.c"
    break;

  case 41: /* expression: expression DIVIDE expression  */
#line 316 "src/parser.y"
    {
        char* temp = new_temp();
        printf("F_DIV %s,%s,%s\n", (yyvsp[-2].expr).addr, (yyvsp[0].expr).addr, temp);
        (yyval.expr).addr = temp;
        (yyval.expr).type = strdup("float");
    }
#line 1539 "build/y.tab.c"
    break;

  case 42: /* expression: MINUS expression  */
#line 323 "src/parser.y"
    {
        char* temp = new_temp();
        printf("F_UMINUS %s,%s\n", (yyvsp[0].expr).addr, temp);
        (yyval.expr).addr = temp;
        (yyval.expr).type = strdup("float");
    }
#line 1550 "build/y.tab.c"
    break;

  case 43: /* expression: LPAREN expression RPAREN  */
#line 330 "src/parser.y"
    {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1558 "build/y.tab.c"
    break;


#line 1562 "build/y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 335 "src/parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}

int lookup_symbol(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_symbol(const char* name, const char* type, int array_size) {
    if (symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table overflow");
        return -1;
    }
    if (lookup_symbol(name) != -1) {
        yyerror("Variable already declared");
        return -1;
    }

    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].array_size = array_size;
    symbol_table[symbol_count].declared = 1;

    return symbol_count++;
}

char* new_temp(void) {
    char* temp = malloc(10);
    sprintf(temp, "T&%d", temp_count++);
    return temp;
}

char* new_label(void) {
    char* label = malloc(10);
    sprintf(label, "lb&%d", label_count++);
    return label;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file.microex>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", argv[1]);
        return 1;
    }

    extern FILE* yyin;
    yyin = fp;
    init_lexer();
    int result = yyparse();
    fclose(fp);
    return result;
}
