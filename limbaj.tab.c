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
#line 7 "limbaj.y"

#include <iostream>
#include "SymTable.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;

#line 83 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS_MK = 3,                   /* CLASS_MK  */
  YYSYMBOL_MAIN_MK = 4,                    /* MAIN_MK  */
  YYSYMBOL_PRINT = 5,                      /* PRINT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_EQ = 8,                         /* EQ  */
  YYSYMBOL_NEQ = 9,                        /* NEQ  */
  YYSYMBOL_LE = 10,                        /* LE  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_NR = 14,                        /* NR  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_TRU = 21,                       /* TRU  */
  YYSYMBOL_FLS = 22,                       /* FLS  */
  YYSYMBOL_INT_CONST = 23,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 24,               /* FLOAT_CONST  */
  YYSYMBOL_STRING_CONST = 25,              /* STRING_CONST  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_TYPE = 27,                      /* TYPE  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_progr = 41,                     /* progr  */
  YYSYMBOL_top_level = 42,                 /* top_level  */
  YYSYMBOL_top_level_decl = 43,            /* top_level_decl  */
  YYSYMBOL_list_var = 44,                  /* list_var  */
  YYSYMBOL_var = 45,                       /* var  */
  YYSYMBOL_func = 46,                      /* func  */
  YYSYMBOL_opt_param_list = 47,            /* opt_param_list  */
  YYSYMBOL_param_list = 48,                /* param_list  */
  YYSYMBOL_param = 49,                     /* param  */
  YYSYMBOL_class = 50,                     /* class  */
  YYSYMBOL_class_list = 51,                /* class_list  */
  YYSYMBOL_field = 52,                     /* field  */
  YYSYMBOL_method = 53,                    /* method  */
  YYSYMBOL_main = 54,                      /* main  */
  YYSYMBOL_main_code_block = 55,           /* main_code_block  */
  YYSYMBOL_code_block_no_definitions = 56, /* code_block_no_definitions  */
  YYSYMBOL_code_block = 57,                /* code_block  */
  YYSYMBOL_print_statement = 58,           /* print_statement  */
  YYSYMBOL_if_else_st = 59,                /* if_else_st  */
  YYSYMBOL_if_st = 60,                     /* if_st  */
  YYSYMBOL_func_call = 61,                 /* func_call  */
  YYSYMBOL_class_element = 62,             /* class_element  */
  YYSYMBOL_method_call = 63,               /* method_call  */
  YYSYMBOL_while_loop = 64,                /* while_loop  */
  YYSYMBOL_assign_statement = 65,          /* assign_statement  */
  YYSYMBOL_expression_or_logic = 66,       /* expression_or_logic  */
  YYSYMBOL_return_val = 67,                /* return_val  */
  YYSYMBOL_return_nothing = 68,            /* return_nothing  */
  YYSYMBOL_var_definition = 69,            /* var_definition  */
  YYSYMBOL_any_value = 70,                 /* any_value  */
  YYSYMBOL_any_value_no_bool_const = 71,   /* any_value_no_bool_const  */
  YYSYMBOL_any_not_const = 72,             /* any_not_const  */
  YYSYMBOL_form_expression = 73,           /* form_expression  */
  YYSYMBOL_logic_expression = 74,          /* logic_expression  */
  YYSYMBOL_logic_bool_operator = 75,       /* logic_bool_operator  */
  YYSYMBOL_bool_operator = 76,             /* bool_operator  */
  YYSYMBOL_expression = 77,                /* expression  */
  YYSYMBOL_call_param_list = 78            /* call_param_list  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      35,    36,    30,    28,    33,    29,    39,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    51,    52,    55,    56,    57,    59,    60,
      63,    64,    67,    68,    71,    72,    75,    76,    79,    80,
      83,    86,    87,    88,    89,    92,    93,    96,    97,   100,
     103,   104,   105,   106,   107,   108,   109,   110,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   138,
     139,   142,   145,   148,   151,   152,   155,   158,   161,   162,
     166,   167,   171,   172,   175,   178,   181,   182,   183,   184,
     185,   186,   187,   188,   191,   192,   193,   194,   195,   196,
     199,   200,   201,   202,   205,   206,   210,   211,   212,   213,
     214,   215,   216,   219,   220,   221,   222,   225,   226,   227,
     228,   229,   230,   231,   232,   235,   236,   237,   238,   239,
     240,   243,   244,   245,   246,   247
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
  "\"end of file\"", "error", "\"invalid token\"", "CLASS_MK", "MAIN_MK",
  "PRINT", "RETURN", "ASSIGN", "EQ", "NEQ", "LE", "GE", "LT", "GT", "NR",
  "NOT", "AND", "OR", "IF", "WHILE", "ELSE", "TRU", "FLS", "INT_CONST",
  "FLOAT_CONST", "STRING_CONST", "ID", "TYPE", "'+'", "'-'", "'*'", "'/'",
  "'%'", "','", "';'", "'('", "')'", "'{'", "'}'", "'.'", "$accept",
  "progr", "top_level", "top_level_decl", "list_var", "var", "func",
  "opt_param_list", "param_list", "param", "class", "class_list", "field",
  "method", "main", "main_code_block", "code_block_no_definitions",
  "code_block", "print_statement", "if_else_st", "if_st", "func_call",
  "class_element", "method_call", "while_loop", "assign_statement",
  "expression_or_logic", "return_val", "return_nothing", "var_definition",
  "any_value", "any_value_no_bool_const", "any_not_const",
  "form_expression", "logic_expression", "logic_bool_operator",
  "bool_operator", "expression", "call_param_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-126)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,     8,    20,  -129,   -15,   -21,   -12,     1,  -129,  -129,
    -129,  -129,  -129,     3,   115,   130,     9,   205,    41,   -25,
      43,    60,    63,     2,    44,    67,   115,   115,    76,     0,
      79,   115,    80,    92,     6,  -129,     6,  -129,    95,   100,
     -23,  -129,  -129,   282,   321,   321,   321,   321,   106,  -129,
     115,  -129,  -129,   115,   321,   321,   115,  -129,   115,   110,
    -129,   120,   140,   155,   114,  -129,   156,   162,   165,   -25,
     169,  -129,  -129,   176,    35,  -129,   180,  -129,  -129,   336,
     369,  -129,  -129,   321,   234,   186,   121,   190,  -129,  -129,
     233,   196,    75,   194,   202,  -129,  -129,  -129,  -129,   217,
    -129,  -129,  -129,  -129,   229,     6,   236,     6,     6,  -129,
    -129,  -129,  -129,    26,    26,    26,    26,    26,  -129,   148,
     321,   144,   298,   200,  -129,  -129,   240,   377,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,   133,   241,   245,   321,
     321,  -129,  -129,   167,  -129,   167,   248,   252,    37,    37,
    -129,  -129,  -129,   255,    47,  -129,    26,  -129,    53,    53,
    -129,  -129,   397,    -1,    92,  -129,   239,   258,   167,   167,
     261,   265,   167,   269,   275,   277,   167,   274,   278,   279,
      47,  -129,  -129,  -129,  -129,   283,   377,   276,   285,    53,
      53,   288,   289,    53,   294,   303,   306,   308,  -129,  -129,
    -129,  -129,  -129,    35,  -129,   180,  -129,  -129,   314,    53,
    -129,  -129,   167,   167,  -129,   167,  -129,  -129,  -129,   316,
     167,   167,   321,   331,    53,  -129,  -129,    53,    53,  -129,
      53,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
     315,   322,   318,   324,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,    53,   325,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     0,     0,     4,     7,
       6,     5,     2,     0,    30,     8,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    30,     0,     0,
       0,    30,     0,     0,    14,    11,    14,    10,     0,     0,
       0,    21,    22,     0,     0,     0,     0,   121,     0,    29,
      30,    31,    32,    30,     0,   121,    30,    35,    30,     8,
       9,     0,     0,     0,    15,    16,     0,    26,    25,     0,
       0,    88,    89,     0,    87,    84,    86,    85,   120,     0,
       0,   101,   102,     0,     0,     0,    95,     0,    69,    71,
      95,   124,    95,     0,    64,    65,    37,    33,    68,     0,
      34,    36,    19,    18,     0,     0,     0,    14,    14,    23,
      24,    20,    60,     0,     0,     0,     0,     0,    59,    87,
       0,    84,    86,    85,   100,    98,     0,    95,   108,   109,
     111,   112,   107,   110,   113,   114,     0,     0,     0,   121,
     121,    63,    66,    48,    17,    48,     0,     0,   115,   116,
     118,   117,   119,     0,     0,    94,     0,    97,    38,    38,
     123,   122,    74,     0,     0,    75,     0,     0,    48,    48,
       0,     0,    48,     0,     0,     0,    48,     0,     0,     0,
      99,   103,   104,   106,   105,     0,     0,     0,     0,    38,
      38,     0,     0,    38,     0,     0,     0,     0,    79,    80,
      82,    83,    73,    81,    76,    78,    77,    72,     0,    38,
      49,    50,    48,    48,    53,    48,    58,    57,    55,     0,
      48,    48,     0,    62,    38,    39,    40,    38,    38,    43,
      38,    46,    47,    67,    13,    56,    51,    52,    54,    12,
       0,     0,     0,     0,    45,    41,    42,    44,    28,    27,
      96,    38,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,    -4,   357,  -129,   -31,  -129,   264,
    -129,  -129,   304,   305,  -129,    -5,   -19,   -85,    66,   111,
     271,   -14,   334,    59,   299,   344,   329,  -128,    30,  -129,
    -129,  -129,  -129,   249,   -26,  -129,  -129,   463,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,    16,   165,    10,    63,    64,    65,
      11,    40,    41,    42,    12,    24,   187,   166,   167,   168,
     169,    75,    29,    77,   172,   173,    88,   174,   175,   176,
     207,    78,   124,    84,    91,   185,   136,    86,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    38,    39,    18,    99,    66,    46,    54,     3,    46,
      69,    13,    28,    28,    15,    70,    14,    28,    85,    87,
      89,    51,    52,     4,     5,    59,    57,    17,    89,    60,
     195,   195,    61,    62,    47,    55,    28,    47,    48,    28,
      19,    48,    28,    35,    28,    96,     6,     7,    97,    71,
      72,   100,    74,   101,   125,   181,   182,   126,    20,   162,
     177,   195,   195,   183,   184,   195,   121,   115,   116,   117,
      47,    21,    22,    30,    48,    37,   146,   147,    43,    23,
      25,   195,    49,   210,   211,    30,    30,   214,   160,   161,
      30,   218,    25,    25,   153,    44,   195,    25,    45,   195,
     195,    50,   195,   113,   114,   115,   116,   117,   140,    30,
      53,  -125,    30,    56,    58,    30,    25,    30,    59,    25,
      20,    67,    25,   195,    25,    26,    68,   236,   237,   170,
     238,   170,    94,    21,    22,   240,   241,    26,    26,   123,
     197,    23,    26,    33,   191,   191,   102,   105,   204,   113,
     114,   115,   116,   117,   170,   170,    71,    72,   170,    74,
      18,    26,   170,    33,    26,    34,   103,    26,   156,    26,
     225,   226,    20,   162,   229,   191,   191,   -90,   -90,   191,
     -90,   -93,   -93,    47,   -93,    21,    22,    48,   196,   196,
     235,   104,   106,   163,   164,   191,   242,   107,   170,   170,
     108,   170,   171,   111,   171,   244,   170,   170,   245,   246,
     191,   247,   112,   191,   191,    55,   191,   192,   192,   196,
     196,   206,   137,   196,   188,   188,   138,   171,   171,   139,
     141,   171,   252,   -91,   -91,   171,   -91,   191,    33,   196,
      36,    48,   128,   129,   130,   131,   132,   133,   192,   192,
     134,   135,   192,   142,   196,   188,   188,   196,   196,   188,
     196,   113,   114,   115,   116,   117,   143,   -70,   192,   189,
     189,   171,   171,   145,   171,   188,   154,   208,   158,   171,
     171,   196,   159,   192,   178,    27,   192,   192,   179,   192,
     188,   180,   209,   188,   188,   212,   188,    27,    27,   213,
     189,   189,    27,   215,   189,    71,    72,    73,    74,   216,
     192,   217,   219,    31,   223,   220,   221,   188,   222,   224,
     189,    27,   227,   228,    27,    31,    31,    27,   230,    27,
      31,   -92,   -92,    55,   -92,   189,    80,   231,   189,   189,
     232,   189,    81,    82,    71,    72,   233,    74,   234,    31,
     239,   243,    31,   248,   250,    31,    83,    31,    32,     9,
     249,   251,   189,   253,   113,   114,   115,   116,   117,   144,
      32,    32,   118,   109,   110,    32,     0,    76,    76,    76,
      76,    76,    95,    98,    80,   157,     0,     0,    76,    76,
      81,    82,    71,    72,    32,   119,     0,    32,     0,     0,
      32,     0,    32,     0,   120,   113,   114,   115,   116,   117,
       0,     0,     0,   155,   122,     0,     0,    76,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   190,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    76,    76,
      76,    76,     0,     0,    76,     0,     0,   193,   193,     0,
     190,   190,     0,     0,   190,     0,     0,     0,     0,     0,
      76,     0,     0,    76,    76,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,   193,   193,
      76,     0,   193,     0,     0,   190,   205,     0,   190,   190,
       0,   190,   194,   194,     0,     0,    79,     0,   193,    90,
      92,     0,     0,     0,     0,     0,     0,    90,    92,     0,
       0,     0,   190,   193,     0,     0,   193,   193,     0,   193,
       0,     0,     0,   194,   194,     0,     0,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
     193,     0,     0,   194,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
       0,   194,   194,     0,   194,     0,   148,   149,   150,   151,
     152,     0,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,     0,     0,     0,     0,
       0,     0,    92,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186
};

static const yytype_int16 yycheck[] =
{
      14,    26,    27,     7,    55,    36,     7,     7,     0,     7,
      33,    26,    26,    27,    26,    38,    37,    31,    44,    45,
      46,    26,    27,     3,     4,    26,    31,    26,    54,    33,
     158,   159,    26,    27,    35,    35,    50,    35,    39,    53,
      37,    39,    56,    34,    58,    50,    26,    27,    53,    23,
      24,    56,    26,    58,    80,     8,     9,    83,     5,     6,
     145,   189,   190,    16,    17,   193,    80,    30,    31,    32,
      35,    18,    19,    14,    39,    34,   107,   108,    35,    26,
      14,   209,    38,   168,   169,    26,    27,   172,   139,   140,
      31,   176,    26,    27,   120,    35,   224,    31,    35,   227,
     228,    34,   230,    28,    29,    30,    31,    32,    33,    50,
      34,    36,    53,    34,    34,    56,    50,    58,    26,    53,
       5,    26,    56,   251,    58,    14,    26,   212,   213,   143,
     215,   145,    26,    18,    19,   220,   221,    26,    27,    80,
     159,    26,    31,    33,   158,   159,    26,    33,   162,    28,
      29,    30,    31,    32,   168,   169,    23,    24,   172,    26,
     164,    50,   176,    33,    53,    35,    26,    56,    35,    58,
     189,   190,     5,     6,   193,   189,   190,    33,    34,   193,
      36,    33,    34,    35,    36,    18,    19,    39,   158,   159,
     209,    36,    36,    26,    27,   209,   222,    35,   212,   213,
      35,   215,   143,    34,   145,   224,   220,   221,   227,   228,
     224,   230,    36,   227,   228,    35,   230,   158,   159,   189,
     190,   162,    36,   193,   158,   159,    36,   168,   169,    33,
      36,   172,   251,    33,    34,   176,    36,   251,    33,   209,
      35,    39,     8,     9,    10,    11,    12,    13,   189,   190,
      16,    17,   193,    36,   224,   189,   190,   227,   228,   193,
     230,    28,    29,    30,    31,    32,    37,    34,   209,   158,
     159,   212,   213,    37,   215,   209,    36,    38,    37,   220,
     221,   251,    37,   224,    36,    14,   227,   228,    36,   230,
     224,    36,    34,   227,   228,    34,   230,    26,    27,    34,
     189,   190,    31,    34,   193,    23,    24,    25,    26,    34,
     251,    34,    38,    14,    38,    37,    37,   251,    35,    34,
     209,    50,    34,    34,    53,    26,    27,    56,    34,    58,
      31,    33,    34,    35,    36,   224,    15,    34,   227,   228,
      34,   230,    21,    22,    23,    24,    38,    26,    34,    50,
      34,    20,    53,    38,    36,    56,    35,    58,    14,     2,
      38,    37,   251,    38,    28,    29,    30,    31,    32,   105,
      26,    27,    36,    69,    69,    31,    -1,    43,    44,    45,
      46,    47,    48,    54,    15,   136,    -1,    -1,    54,    55,
      21,    22,    23,    24,    50,    26,    -1,    53,    -1,    -1,
      56,    -1,    58,    -1,    35,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    36,    80,    -1,    -1,    83,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,    -1,    -1,   120,    -1,    -1,   158,   159,    -1,
     189,   190,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     156,    -1,   193,    -1,    -1,   224,   162,    -1,   227,   228,
      -1,   230,   158,   159,    -1,    -1,    43,    -1,   209,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,   251,   224,    -1,    -1,   227,   228,    -1,   230,
      -1,    -1,    -1,   189,   190,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
     251,    -1,    -1,   209,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,   227,   228,    -1,   230,    -1,   113,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,     4,    26,    27,    43,    45,
      46,    50,    54,    26,    37,    26,    44,    26,    44,    37,
       5,    18,    19,    26,    55,    58,    59,    60,    61,    62,
      63,    64,    65,    33,    35,    34,    35,    34,    26,    27,
      51,    52,    53,    35,    35,    35,     7,    35,    39,    38,
      34,    55,    55,    34,     7,    35,    34,    55,    34,    26,
      44,    26,    27,    47,    48,    49,    47,    26,    26,    33,
      38,    23,    24,    25,    26,    61,    62,    63,    71,    77,
      15,    21,    22,    35,    73,    74,    77,    74,    66,    74,
      77,    74,    77,    78,    26,    62,    55,    55,    66,    78,
      55,    55,    26,    26,    36,    33,    36,    35,    35,    52,
      53,    34,    36,    28,    29,    30,    31,    32,    36,    26,
      35,    61,    62,    63,    72,    74,    74,    77,     8,     9,
      10,    11,    12,    13,    16,    17,    76,    36,    36,    33,
      33,    36,    36,    37,    49,    37,    47,    47,    77,    77,
      77,    77,    77,    74,    36,    36,    35,    73,    37,    37,
      78,    78,     6,    26,    27,    45,    57,    58,    59,    60,
      61,    63,    64,    65,    67,    68,    69,    57,    36,    36,
      36,     8,     9,    16,    17,    75,    77,    56,    58,    59,
      60,    61,    63,    64,    65,    67,    68,    56,    21,    22,
      23,    24,    25,    26,    61,    62,    63,    70,    38,    34,
      57,    57,    34,    34,    57,    34,    34,    34,    57,    38,
      37,    37,    35,    38,    34,    56,    56,    34,    34,    56,
      34,    34,    34,    38,    34,    56,    57,    57,    57,    34,
      57,    57,    74,    20,    56,    56,    56,    56,    38,    38,
      36,    37,    56,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    60,    61,    62,    62,    63,    64,    65,    65,
      66,    66,    67,    67,    68,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     3,
       3,     3,     9,     9,     0,     1,     1,     3,     2,     2,
       6,     1,     1,     3,     3,     2,     2,     8,     8,     4,
       0,     2,     2,     3,     3,     2,     3,     3,     0,     2,
       2,     3,     3,     2,     3,     3,     2,     2,     0,     2,
       2,     3,     3,     2,     3,     2,     3,     2,     2,     4,
       4,    11,     7,     4,     3,     3,     4,     7,     3,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     7,     3,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     0,     3,     3,     1,     1
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
  case 2: /* progr: top_level main  */
#line 48 "limbaj.y"
                       {if (errorCount == 0) cout<< "The program is correct!" << endl;}
#line 1388 "limbaj.tab.c"
    break;


#line 1392 "limbaj.tab.c"

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

#line 250 "limbaj.y"

void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     const string global="global";
     current = new SymTable(global);
     yyparse();
     //cout << "Variables:" <<endl;
     //current->printVars();
     delete current;
} 
