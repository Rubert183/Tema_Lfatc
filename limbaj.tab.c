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
#line 24 "limbaj.y"

#include <iostream>
#include "SymTable.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
string currentType;
IdInfo *currentIdInfo;
int errorCount = 0;

#line 85 "limbaj.tab.c"

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
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_type_or_class = 46,             /* type_or_class  */
  YYSYMBOL_var = 47,                       /* var  */
  YYSYMBOL_func = 48,                      /* func  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_opt_param_list = 51,            /* opt_param_list  */
  YYSYMBOL_param_list = 52,                /* param_list  */
  YYSYMBOL_param = 53,                     /* param  */
  YYSYMBOL_class = 54,                     /* class  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_class_list = 57,                /* class_list  */
  YYSYMBOL_field = 58,                     /* field  */
  YYSYMBOL_method = 59,                    /* method  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_main = 61,                      /* main  */
  YYSYMBOL_main_code_block = 62,           /* main_code_block  */
  YYSYMBOL_code_block_no_definitions = 63, /* code_block_no_definitions  */
  YYSYMBOL_code_block = 64,                /* code_block  */
  YYSYMBOL_print_statement = 65,           /* print_statement  */
  YYSYMBOL_if_else_st = 66,                /* if_else_st  */
  YYSYMBOL_if_st = 67,                     /* if_st  */
  YYSYMBOL_call = 68,                      /* call  */
  YYSYMBOL_while_loop = 69,                /* while_loop  */
  YYSYMBOL_assign_statement = 70,          /* assign_statement  */
  YYSYMBOL_expression_or_logic = 71,       /* expression_or_logic  */
  YYSYMBOL_return_val = 72,                /* return_val  */
  YYSYMBOL_return_nothing = 73,            /* return_nothing  */
  YYSYMBOL_var_definition = 74,            /* var_definition  */
  YYSYMBOL_any_value = 75,                 /* any_value  */
  YYSYMBOL_any_value_no_bool_const = 76,   /* any_value_no_bool_const  */
  YYSYMBOL_logic_expression = 77,          /* logic_expression  */
  YYSYMBOL_logic_and = 78,                 /* logic_and  */
  YYSYMBOL_logic_not = 79,                 /* logic_not  */
  YYSYMBOL_logic_atom = 80,                /* logic_atom  */
  YYSYMBOL_expression_comparisom = 81,     /* expression_comparisom  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_call_param_list = 83,           /* call_param_list  */
  YYSYMBOL_class_element = 84              /* class_element  */
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
#define YYLAST   432

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

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
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    76,    77,    80,    81,    82,    85,    85,
      99,   115,   116,   125,   128,   145,   128,   150,   151,   154,
     155,   158,   175,   192,   175,   195,   196,   197,   198,   201,
     218,   218,   241,   244,   245,   246,   247,   248,   249,   250,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   276,
     277,   280,   283,   287,   314,   352,   355,   368,   369,   372,
     373,   376,   379,   382,   383,   384,   385,   386,   387,   390,
     391,   392,   396,   402,   406,   411,   415,   420,   424,   430,
     431,   499,   500,   503,   504,   505,   506,   507,   508,   511,
     512,   534,   556,   592,   614,   637,   642,   645,   650,   655,
     660,   669,   680
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
  "progr", "top_level", "top_level_decl", "list_var", "$@1",
  "type_or_class", "var", "func", "$@2", "$@3", "opt_param_list",
  "param_list", "param", "class", "$@4", "$@5", "class_list", "field",
  "method", "$@6", "main", "main_code_block", "code_block_no_definitions",
  "code_block", "print_statement", "if_else_st", "if_st", "call",
  "while_loop", "assign_statement", "expression_or_logic", "return_val",
  "return_nothing", "var_definition", "any_value",
  "any_value_no_bool_const", "logic_expression", "logic_and", "logic_not",
  "logic_atom", "expression_comparisom", "expression", "call_param_list",
  "class_element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -88,     6,    14,   -88,   -14,   -21,   -88,   -88,   -88,    16,
     -88,   -88,   -88,   -88,   -88,    72,    -3,    11,    23,    36,
      43,    48,    50,    41,    31,    72,    72,    58,    72,    59,
      -4,    67,    70,   -88,    30,   246,    86,    86,    86,   -88,
      72,   -88,   -88,    72,   -88,    72,    86,    87,    89,    30,
     100,    25,   -88,   -88,   -88,   -88,    91,    27,   -88,   -88,
     165,    90,    86,   -88,   -88,    86,   -13,   114,   -88,   -88,
     400,   -10,   -12,   288,   106,   -88,   -88,   -88,   -88,   126,
     400,   109,   115,   -88,   121,   123,   117,   -88,   116,    30,
     -88,   -88,   254,    27,    27,    27,    27,    27,   -88,   -88,
      -9,   371,    86,   125,    86,   -88,   -88,   -88,   -88,   -88,
     -88,    27,   127,    86,    86,   -88,    86,   -88,   128,    30,
     132,   -88,   -88,   135,   -88,   105,   105,   -88,   -88,   -88,
     -88,   114,    49,   -88,   366,    49,   -88,   -88,   134,    76,
     -88,    30,   -88,   327,   133,   138,    49,    49,   140,    49,
     141,   143,   145,   142,   -88,     3,    89,   -88,   148,   155,
      76,    76,   156,    76,   164,   168,   169,    76,   163,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,    90,   186,    49,   -88,
     -88,    49,   -88,    49,   -88,   -88,   -88,   -88,    49,   -88,
     -88,    76,   -88,    76,   -88,   -88,   -88,   172,   176,   -88,
     -88,   -88,   182,   -88,   -88,   -88,    76,    49,   -88,   179,
     183,   -88,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    12,    11,     4,     0,
       7,     6,     5,     2,    22,    33,     8,     0,     0,     0,
       0,     0,   111,     0,     0,    33,    33,     0,    33,     0,
       0,     0,     0,    13,     0,     0,     0,     0,   106,    32,
      33,    34,    35,    33,    37,    33,     0,     0,     0,    17,
       0,     0,    25,    26,    81,    82,     0,     0,    79,   105,
       0,    80,     0,    91,    92,     0,     0,    84,    86,    88,
       0,     0,   110,   109,     0,    39,    36,    38,    66,    68,
      67,   112,     8,     9,     0,     0,    18,    19,    29,     0,
      23,    60,     0,     0,     0,     0,     0,     0,    59,    87,
       0,     0,     0,     0,     0,    94,    95,    97,    98,    93,
      96,     0,     0,   106,   106,    63,   106,    21,     0,     0,
       0,    27,    28,     0,    99,   100,   101,   103,   102,   104,
      89,    83,    40,    85,    90,    40,   108,   107,     0,    49,
      20,    17,    24,    71,     0,     0,    40,    40,     0,    40,
       0,     0,     0,     0,    64,   111,     0,    72,     0,     0,
      49,    49,     0,    49,     0,     0,     0,    49,     0,    75,
      76,    77,    78,    70,    73,    69,    74,    62,    40,    41,
      42,    40,    44,    40,    47,    48,    65,    15,    40,    50,
      51,    49,    53,    49,    58,    57,    55,     0,     0,    46,
      43,    45,     0,    56,    52,    54,    49,    40,    16,     0,
       0,    31,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   170,   -88,    -1,   221,   -88,   -88,
     -88,    83,   -88,   110,   -88,   -88,   -88,   -88,   150,   152,
     -88,   -88,   113,    73,   180,    -6,    21,    44,   -15,    71,
     200,   -88,   -87,   171,   -88,   -88,   -88,   -22,   151,   -60,
     -88,   -88,   198,     9,   211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,    17,    31,   156,   157,    11,    32,
     202,    85,    86,    87,    12,    18,   123,    51,    52,    53,
     120,    13,    23,   144,   158,   145,   146,   147,    58,   149,
     150,    78,   151,   152,   167,   175,    59,    72,    67,    68,
      69,   111,    70,    74,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,     9,    99,    46,   102,   102,     3,   102,   102,    24,
      27,    27,    14,    27,    66,    71,    15,     4,     5,    24,
      24,   113,    24,   103,    79,    27,   112,   130,    27,   -12,
      27,   -10,   -14,    50,    24,    47,    25,    24,    38,    24,
       6,     7,    16,   100,   133,    33,    25,    25,    84,    25,
      54,    55,   165,    22,    19,   143,     6,     7,    89,    26,
      34,    25,    57,    90,    25,    40,    25,    20,    21,    26,
      26,    35,    26,   165,   165,    22,   165,    19,    36,    39,
     165,    19,   143,    37,    26,    38,    28,    26,    50,    26,
      20,    21,    43,    45,    20,    21,    28,    28,    22,    28,
      48,    62,   155,     7,   165,    49,   165,    63,    64,    54,
      55,    28,    22,    81,    28,    82,    28,   148,    84,   165,
     148,    65,   136,   137,   162,   138,    88,    91,   174,    47,
     104,   148,   148,   159,   148,    95,    96,    97,    41,    42,
      84,    44,   115,   102,   116,   162,   162,   117,   162,   -10,
     119,   -30,   162,    75,   159,   159,    76,   159,    77,   118,
     160,   159,   132,   148,   135,   139,   148,   141,   148,   142,
     154,   177,   178,   148,   181,   183,   162,   184,   162,   185,
     186,   160,   160,   161,   160,   159,   187,   159,   160,   188,
     191,   162,   148,    93,    94,    95,    96,    97,   193,   197,
     159,    98,   194,   195,   161,   161,   198,   161,   153,   206,
     163,   161,   160,   207,   160,    29,   208,   211,    83,   179,
     180,   212,   182,    10,   168,    29,    29,   160,    29,   140,
       0,   163,   163,    60,   163,   161,    73,   161,   163,   121,
      29,   122,     0,    29,    80,    29,    61,    61,    61,    61,
     161,   199,     0,   131,   200,    92,   201,    61,     0,     0,
       0,   203,   163,   101,   163,     0,     0,     0,    61,    54,
      55,    56,    22,    61,     0,     0,    61,   163,     0,     0,
     210,    57,    93,    94,    95,    96,    97,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   105,   106,   107,   108,
     109,   110,     0,     0,    61,    61,    61,    61,    61,   134,
     166,    73,    73,    61,    73,    61,    93,    94,    95,    96,
      97,   114,    61,     0,    61,    61,     0,    61,     0,     0,
       0,   166,   166,     0,   166,     0,     0,     0,   166,   164,
     189,   190,     0,   192,     0,     0,     0,   196,   169,   170,
     171,   172,   173,    22,   176,     0,     0,     0,     0,     0,
     164,   164,   166,   164,   166,     0,     0,   164,     0,     0,
       0,   204,     0,   205,     0,     0,     0,   166,     0,   105,
     106,   107,   108,   109,   110,     0,   209,     0,     0,     0,
       0,   164,     0,   164,    93,    94,    95,    96,    97,    93,
      94,    95,    96,    97,     0,     0,   164,   124,   105,   106,
     107,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97
};

static const yytype_int16 yycheck[] =
{
      15,     2,    62,     7,    17,    17,     0,    17,    17,    15,
      25,    26,    26,    28,    36,    37,    37,     3,     4,    25,
      26,    33,    28,    36,    46,    40,    36,    36,    43,    26,
      45,    34,    35,    34,    40,    39,    15,    43,    35,    45,
      26,    27,    26,    65,   104,    34,    25,    26,    49,    28,
      23,    24,   139,    26,     5,     6,    26,    27,    33,    15,
      37,    40,    35,    38,    43,    34,    45,    18,    19,    25,
      26,    35,    28,   160,   161,    26,   163,     5,    35,    38,
     167,     5,     6,    35,    40,    35,    15,    43,    89,    45,
      18,    19,    34,    34,    18,    19,    25,    26,    26,    28,
      33,    15,    26,    27,   191,    35,   193,    21,    22,    23,
      24,    40,    26,    26,    43,    26,    45,   132,   119,   206,
     135,    35,   113,   114,   139,   116,    26,    36,   143,    39,
      16,   146,   147,   139,   149,    30,    31,    32,    25,    26,
     141,    28,    36,    17,    35,   160,   161,    26,   163,    34,
      33,    35,   167,    40,   160,   161,    43,   163,    45,    36,
     139,   167,    37,   178,    37,    37,   181,    35,   183,    34,
      36,    38,    34,   188,    34,    34,   191,    34,   193,    34,
      38,   160,   161,   139,   163,   191,    38,   193,   167,    34,
      34,   206,   207,    28,    29,    30,    31,    32,    34,    36,
     206,    36,    34,    34,   160,   161,    20,   163,   135,    37,
     139,   167,   191,    37,   193,    15,    34,    38,    48,   146,
     147,    38,   149,     2,   141,    25,    26,   206,    28,   119,
      -1,   160,   161,    35,   163,   191,    38,   193,   167,    89,
      40,    89,    -1,    43,    46,    45,    35,    36,    37,    38,
     206,   178,    -1,   102,   181,    57,   183,    46,    -1,    -1,
      -1,   188,   191,    65,   193,    -1,    -1,    -1,    57,    23,
      24,    25,    26,    62,    -1,    -1,    65,   206,    -1,    -1,
     207,    35,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    93,    94,    95,    96,    97,     8,     9,    10,    11,
      12,    13,    -1,    -1,    93,    94,    95,    96,    97,   111,
     139,   113,   114,   102,   116,   104,    28,    29,    30,    31,
      32,    33,   111,    -1,   113,   114,    -1,   116,    -1,    -1,
      -1,   160,   161,    -1,   163,    -1,    -1,    -1,   167,   139,
     160,   161,    -1,   163,    -1,    -1,    -1,   167,    21,    22,
      23,    24,    25,    26,   143,    -1,    -1,    -1,    -1,    -1,
     160,   161,   191,   163,   193,    -1,    -1,   167,    -1,    -1,
      -1,   191,    -1,   193,    -1,    -1,    -1,   206,    -1,     8,
       9,    10,    11,    12,    13,    -1,   206,    -1,    -1,    -1,
      -1,   191,    -1,   193,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    -1,    -1,   206,    36,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,     4,    26,    27,    43,    46,
      47,    48,    54,    61,    26,    37,    26,    44,    55,     5,
      18,    19,    26,    62,    65,    66,    67,    68,    69,    70,
      84,    45,    49,    34,    37,    35,    35,    35,    35,    38,
      34,    62,    62,    34,    62,    34,     7,    39,    33,    35,
      46,    57,    58,    59,    23,    24,    25,    35,    68,    76,
      82,    84,    15,    21,    22,    35,    77,    78,    79,    80,
      82,    77,    77,    82,    83,    62,    62,    62,    71,    77,
      82,    26,    26,    44,    46,    51,    52,    53,    26,    33,
      38,    36,    82,    28,    29,    30,    31,    32,    36,    79,
      77,    82,    17,    36,    16,     8,     9,    10,    11,    12,
      13,    81,    36,    33,    33,    36,    35,    26,    36,    33,
      60,    58,    59,    56,    36,    82,    82,    82,    82,    82,
      36,    78,    37,    79,    82,    37,    83,    83,    83,    37,
      53,    35,    34,     6,    63,    65,    66,    67,    68,    69,
      70,    72,    73,    63,    36,    26,    46,    47,    64,    65,
      66,    67,    68,    69,    70,    72,    73,    74,    51,    21,
      22,    23,    24,    25,    68,    75,    84,    38,    34,    63,
      63,    34,    63,    34,    34,    34,    38,    38,    34,    64,
      64,    34,    64,    34,    34,    34,    64,    36,    20,    63,
      63,    63,    50,    63,    64,    64,    37,    37,    34,    64,
      63,    38,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    45,    44,
      44,    46,    46,    47,    49,    50,    48,    51,    51,    52,
      52,    53,    55,    56,    54,    57,    57,    57,    57,    58,
      60,    59,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    67,    68,    68,    69,    70,    71,    71,    72,
      72,    73,    74,    75,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     0,     4,
       1,     1,     1,     3,     0,     0,    11,     0,     1,     1,
       3,     2,     0,     0,     8,     1,     1,     3,     3,     2,
       0,     9,     4,     0,     2,     2,     3,     2,     3,     3,
       0,     2,     2,     3,     2,     3,     3,     2,     2,     0,
       2,     2,     3,     2,     3,     2,     3,     2,     2,     4,
       4,    11,     7,     4,     6,     7,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     0,     3,     3,     1,
       1,     1,     3
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
#line 73 "limbaj.y"
                       {if (errorCount == 0) cout<< "The program is correct!" << endl;}
#line 1348 "limbaj.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 85 "limbaj.y"
              {
             if(current->existsClass(*(yyvsp[0].strVal))){
                 cout << "Variable " << *(yyvsp[0].strVal) << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else if(current->existsFunction(*(yyvsp[0].strVal))){
                    cout << "Variable " << *(yyvsp[0].strVal) << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsVar_current(*(yyvsp[0].strVal))){
                    cout << "Redeclared variable " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                    errorCount++;
             } else {
                    current->addVar(currentType, *(yyvsp[0].strVal));
             }
         }
#line 1367 "limbaj.tab.c"
    break;

  case 10: /* list_var: ID  */
#line 99 "limbaj.y"
              {
             if(current->existsClass(*(yyvsp[0].strVal))){
                 cout << "Variable " << *(yyvsp[0].strVal) << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else if(current->existsFunction(*(yyvsp[0].strVal))){
                    cout << "Variable " << *(yyvsp[0].strVal) << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsVar_current(*(yyvsp[0].strVal))){
                    cout << "Redeclared variable " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                    errorCount++;
             } else {
                    current->addVar(currentType, *(yyvsp[0].strVal));
             }
         }
#line 1386 "limbaj.tab.c"
    break;

  case 11: /* type_or_class: TYPE  */
#line 115 "limbaj.y"
                     {currentType=*(yyvsp[0].strVal);}
#line 1392 "limbaj.tab.c"
    break;

  case 12: /* type_or_class: ID  */
#line 116 "limbaj.y"
                   {
                if(!current->existsClass(*(yyvsp[0].strVal))){
                 cout << "Undeclared class " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                 errorCount++;
                }
                currentType=*(yyvsp[0].strVal);
              }
#line 1404 "limbaj.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 128 "limbaj.y"
                       {
             if(current->existsClass(*(yyvsp[0].strVal))){
                 cout << "Function " << *(yyvsp[0].strVal) << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else if(current->existsVar_current(*(yyvsp[0].strVal))){
                    cout << "Function " << *(yyvsp[0].strVal) << " has the name of a variable at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsFunction(*(yyvsp[0].strVal))){
                        cout << "Redeclared function " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                        errorCount++;
             } else {
                        current->addFunction(currentType, *(yyvsp[0].strVal));
                        SymTable* funcScope = new SymTable(*(yyvsp[0].strVal), current);
                        currentIdInfo=current->getFunction(*(yyvsp[0].strVal));
                        currentIdInfo->function_scope = funcScope;
                        current = current->getFunctionScope(*(yyvsp[0].strVal));
             }
         }
#line 1427 "limbaj.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 145 "limbaj.y"
                                                     { 
            current=current->getParent();
         }
#line 1435 "limbaj.tab.c"
    break;

  case 21: /* param: type_or_class ID  */
#line 158 "limbaj.y"
                         {
             if(current->existsClass(*(yyvsp[0].strVal))){
                 cout << "Parameter " << *(yyvsp[0].strVal) << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else if(current->existsFunction_current(*(yyvsp[0].strVal))){
                    cout << "Parameter " << *(yyvsp[0].strVal) << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsVar_current(*(yyvsp[0].strVal))){
                    cout << "Redeclared Parameter " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                    errorCount++;
             } else {
                        currentIdInfo->add_param(currentType,*(yyvsp[0].strVal));
                        current->addVar(currentType, *(yyvsp[0].strVal));
             }
         }
#line 1455 "limbaj.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 175 "limbaj.y"
                    {
        string className = *(yyvsp[0].strVal);
        if(current->existsVar(className)){
            cout << "Class " << className << " has the name of a variable at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsFunction(className)){
            cout << "Class " << className << " has the name of a function at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsClass(className)){
            cout << "Redeclared class " << className << " at line " << yylineno << endl;
            errorCount++;
        } else {
            current->addClass(className);
            SymTable* classScope = new SymTable(className, current);
            current->getClass(className)->class_scope = classScope;
            current = classScope;
        }
      }
#line 1478 "limbaj.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 192 "limbaj.y"
                           {current=current->getParent();}
#line 1484 "limbaj.tab.c"
    break;

  case 29: /* field: type_or_class ID  */
#line 201 "limbaj.y"
                         {
        string fieldName = *(yyvsp[0].strVal);
        if(current->existsClass(fieldName)){
            cout << "Field " << fieldName << " has the name of a class at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsFunction_current(fieldName)){
            cout << "Field " << fieldName << " has the name of a function at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsVar_current(fieldName)){
            cout << "Redeclared field " << fieldName << " at line " << yylineno << endl;
            errorCount++;
        } else {
            current->addVar(currentType, fieldName); 
        }
    }
#line 1504 "limbaj.tab.c"
    break;

  case 30: /* $@6: %empty  */
#line 218 "limbaj.y"
                          {
    string methodName = *(yyvsp[0].strVal);
    if(current->existsClass(methodName)){
        cout << "Method " << methodName << " has the name of a class at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsVar_current(methodName)){
        cout << "Method " << methodName << " has the name of a variable at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsFunction_current(methodName)){
        cout << "Redeclared method " << methodName << " at line " << yylineno << endl;
        errorCount++;
    } else {
        current->addFunction(currentType, methodName);
        SymTable* methodScope = new SymTable(methodName, current);
        currentIdInfo = current->getFunction(methodName);
        currentIdInfo->function_scope = methodScope;
        current = methodScope;
    }
    }
#line 1528 "limbaj.tab.c"
    break;

  case 31: /* method: type_or_class ID $@6 '(' opt_param_list ')' '{' code_block '}'  */
#line 236 "limbaj.y"
                                                {
        current = current->getParent();
    }
#line 1536 "limbaj.tab.c"
    break;

  case 63: /* call: ID '(' call_param_list ')'  */
#line 288 "limbaj.y"
{
    IdInfo* f = current->getFunction(*(yyvsp[-3].strVal));
    if(!f){
        cout << "Undefined function " << *(yyvsp[-3].strVal)
             << " at line " << yylineno << endl;
        errorCount++;
        (yyval.expr) = makeExpr("");
    } else {
        if(f->params.size() != (yyvsp[-1].types)->size()){
            cout << "Function " << *(yyvsp[-3].strVal)
                 << " called with wrong number of parameters at line "
                 << yylineno << endl;
            errorCount++;
        } else {
            for(size_t i = 0; i < (yyvsp[-1].types)->size(); i++){
                if(f->params[i].first!= (*(yyvsp[-1].types))[i]){
                    cout << "Type mismatch for parameter "
                         << i+1 << " in function " << *(yyvsp[-3].strVal)
                         << " at line " << yylineno << endl;
                    errorCount++;
                }
            }
        }
        (yyval.expr) = makeExpr(f->type);
    }
}
#line 1567 "limbaj.tab.c"
    break;

  case 64: /* call: class_element '.' ID '(' call_param_list ')'  */
#line 315 "limbaj.y"
{
    IdInfo* typeInfo = current->getClass(*(yyvsp[-5].expr)->type);
    if(!typeInfo){
        cout << "Type " << *(yyvsp[-5].expr)->type
             << " is not a class at line " << yylineno << endl;
        errorCount++;
        (yyval.expr) = makeExpr("");
    } else {
        SymTable* classScope = typeInfo->class_scope;
        IdInfo* m = classScope->getFunction(*(yyvsp[-3].strVal));
        if(!m){
            cout << "Undefined method " << *(yyvsp[-3].strVal)
                 << " at line " << yylineno << endl;
            errorCount++;
            (yyval.expr) = makeExpr("");
        } else {
            if(m->params.size() != (yyvsp[-1].types)->size()){
                cout << "Method " << *(yyvsp[-3].strVal)
                     << " called with wrong number of parameters at line "
                     << yylineno << endl;
                errorCount++;
            } else {
                for(size_t i = 0; i < (yyvsp[-1].types)->size(); i++){
                    if(m->params[i].first != (*(yyvsp[-1].types))[i]){
                        cout << "Type mismatch for parameter "
                             << i+1 << " in method " << *(yyvsp[-3].strVal)
                             << " at line " << yylineno << endl;
                        errorCount++;
                    }
                }
            }
            (yyval.expr) = makeExpr(m->type);
        }
    }
}
#line 1607 "limbaj.tab.c"
    break;

  case 66: /* assign_statement: class_element ASSIGN expression_or_logic  */
#line 356 "limbaj.y"
                 {
                    if(*(yyvsp[0].expr)->type!=""){
                        if (*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) {
                            if(*(yyvsp[-2].expr)->type!="")
                                cout << "Cannot assign type "<< *(yyvsp[0].expr)->type << " to type "<< *(yyvsp[-2].expr)->type << " at line "<< yylineno << endl;
                            errorCount++;
                        }
                    }
                 }
#line 1621 "limbaj.tab.c"
    break;

  case 81: /* any_value_no_bool_const: INT_CONST  */
#line 392 "limbaj.y"
                                    {
                            (yyval.expr) = makeExpr("int");
                            (yyval.expr)->i=(yyvsp[0].intVal);
                        }
#line 1630 "limbaj.tab.c"
    break;

  case 82: /* any_value_no_bool_const: FLOAT_CONST  */
#line 396 "limbaj.y"
                                      {
                            (yyval.expr) = makeExpr("float");
                            (yyval.expr)->f=(yyvsp[0].floatVal);
                        }
#line 1639 "limbaj.tab.c"
    break;

  case 83: /* logic_expression: logic_expression OR logic_and  */
#line 402 "limbaj.y"
                                                 {
                    (yyval.expr) = makeExpr("bool");
                    (yyval.expr)->b = (yyvsp[-2].expr)->b || (yyvsp[0].expr)->b;
                 }
#line 1648 "limbaj.tab.c"
    break;

  case 84: /* logic_expression: logic_and  */
#line 406 "limbaj.y"
                             {
                    (yyval.expr) = (yyvsp[0].expr); 
                 }
#line 1656 "limbaj.tab.c"
    break;

  case 85: /* logic_and: logic_and AND logic_not  */
#line 411 "limbaj.y"
                                    {
            (yyval.expr) = makeExpr("bool");
            (yyval.expr)->b = (yyvsp[-2].expr)->b && (yyvsp[0].expr)->b;
            }
#line 1665 "limbaj.tab.c"
    break;

  case 86: /* logic_and: logic_not  */
#line 415 "limbaj.y"
                      {
            (yyval.expr) = (yyvsp[0].expr); 
          }
#line 1673 "limbaj.tab.c"
    break;

  case 87: /* logic_not: NOT logic_not  */
#line 420 "limbaj.y"
                          {
            (yyval.expr) = makeExpr("bool");
            (yyval.expr)->b = !(yyvsp[0].expr)->b;
            }
#line 1682 "limbaj.tab.c"
    break;

  case 88: /* logic_not: logic_atom  */
#line 424 "limbaj.y"
                       {
            (yyval.expr) = (yyvsp[0].expr); 
          }
#line 1690 "limbaj.tab.c"
    break;

  case 89: /* logic_atom: '(' logic_expression ')'  */
#line 430 "limbaj.y"
                               { (yyval.expr) = (yyvsp[-1].expr); }
#line 1696 "limbaj.tab.c"
    break;

  case 90: /* logic_atom: expression expression_comparisom expression  */
#line 431 "limbaj.y"
                                                  {
        if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
            if(*(yyvsp[-2].expr)->type!="")
                cout << "Invalid comparisom of type " << *(yyvsp[-2].expr)->type << " and type " <<*(yyvsp[0].expr)->type<<" called at line " << yylineno << endl;
            (yyval.expr)=makeExpr("");
            errorCount++;
        } else {
            if(*(yyvsp[-2].expr)->type=="int" || *(yyvsp[0].expr)->type=="float"){
                (yyval.expr)=makeExpr("bool");
                switch((yyvsp[-1].expr_comp_op)){
                    case 1:{
                        if(*(yyvsp[-2].expr)->type=="int"){
                            (yyval.expr)->b= (yyvsp[-2].expr)->i < (yyvsp[0].expr)->i;
                        } else {
                            (yyval.expr)->b= (yyvsp[-2].expr)->f < (yyvsp[0].expr)->f;
                        }
                        break;
                    }
                    case 2:{
                        if(*(yyvsp[-2].expr)->type=="int"){
                            (yyval.expr)->b= (yyvsp[-2].expr)->i == (yyvsp[0].expr)->i;
                        } else {
                            (yyval.expr)->b= (yyvsp[-2].expr)->f == (yyvsp[0].expr)->f;
                        }
                        break;
                    }
                    case 3:{
                        if(*(yyvsp[-2].expr)->type=="int"){
                            (yyval.expr)->b= (yyvsp[-2].expr)->i != (yyvsp[0].expr)->i;
                        } else {
                            (yyval.expr)->b= (yyvsp[-2].expr)->f != (yyvsp[0].expr)->f;
                        }
                        break;
                    }
                    case 4:{
                        if(*(yyvsp[-2].expr)->type=="int"){
                            (yyval.expr)->b= (yyvsp[-2].expr)->i > (yyvsp[0].expr)->i;
                        } else {
                            (yyval.expr)->b= (yyvsp[-2].expr)->f > (yyvsp[0].expr)->f;
                        }
                        break;
                    }
                    case 5:{
                        if(*(yyvsp[-2].expr)->type=="int"){
                            (yyval.expr)->b= (yyvsp[-2].expr)->i <= (yyvsp[0].expr)->i;
                        } else {
                            (yyval.expr)->b= (yyvsp[-2].expr)->f <= (yyvsp[0].expr)->f;
                        }
                        break;
                    }
                    case 6:{
                        if(*(yyvsp[-2].expr)->type=="int"){
                            (yyval.expr)->b= (yyvsp[-2].expr)->i >= (yyvsp[0].expr)->i;
                        } else {
                            (yyval.expr)->b= (yyvsp[-2].expr)->f >= (yyvsp[0].expr)->f;
                        }
                        break;
                    }
                    default:{break;}
                }
            }
            else{
                cout << "Invalid comparisom of elements of the type " << *(yyvsp[-2].expr)->type <<" called at line " << yylineno << endl;
                (yyval.expr)=makeExpr("");
                errorCount++;
            }
        }
    }
#line 1769 "limbaj.tab.c"
    break;

  case 91: /* logic_atom: TRU  */
#line 499 "limbaj.y"
          {(yyval.expr)=makeExpr("bool"); (yyval.expr)->b=true;}
#line 1775 "limbaj.tab.c"
    break;

  case 92: /* logic_atom: FLS  */
#line 500 "limbaj.y"
          {(yyval.expr)=makeExpr("bool"); (yyval.expr)->b=false;}
#line 1781 "limbaj.tab.c"
    break;

  case 93: /* expression_comparisom: LT  */
#line 503 "limbaj.y"
                           {(yyval.expr_comp_op)=1;}
#line 1787 "limbaj.tab.c"
    break;

  case 94: /* expression_comparisom: EQ  */
#line 504 "limbaj.y"
                           {(yyval.expr_comp_op)=2;}
#line 1793 "limbaj.tab.c"
    break;

  case 95: /* expression_comparisom: NEQ  */
#line 505 "limbaj.y"
                            {(yyval.expr_comp_op)=3;}
#line 1799 "limbaj.tab.c"
    break;

  case 96: /* expression_comparisom: GT  */
#line 506 "limbaj.y"
                           {(yyval.expr_comp_op)=4;}
#line 1805 "limbaj.tab.c"
    break;

  case 97: /* expression_comparisom: LE  */
#line 507 "limbaj.y"
                           {(yyval.expr_comp_op)=5;}
#line 1811 "limbaj.tab.c"
    break;

  case 98: /* expression_comparisom: GE  */
#line 508 "limbaj.y"
                           {(yyval.expr_comp_op)=6;}
#line 1817 "limbaj.tab.c"
    break;

  case 99: /* expression: '(' expression ')'  */
#line 511 "limbaj.y"
                                {(yyval.expr)=(yyvsp[-1].expr);}
#line 1823 "limbaj.tab.c"
    break;

  case 100: /* expression: expression '+' expression  */
#line 512 "limbaj.y"
                                       {
            if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
                cout << "Tried to make an addition on a " << *(yyvsp[-2].expr)->type <<" with a "<<*(yyvsp[0].expr)->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
                if(*(yyvsp[-2].expr)->type=="int"){
                    (yyval.expr)=makeExpr("int");
                    (yyval.expr)->i=(yyvsp[-2].expr)->i+(yyvsp[0].expr)->i;
                }
                else{
                    (yyval.expr)=makeExpr("float");
                    (yyval.expr)->f=(yyvsp[-2].expr)->f+(yyvsp[0].expr)->f;
                }
            }
            else{
                 if(*(yyvsp[-2].expr)->type!="")
                    cout << "Invalid add operation for the type " << *(yyvsp[-2].expr)->type << " called at line " << yylineno << endl;
                 (yyval.expr)=makeExpr("");
                 errorCount++;
            }
           }
#line 1850 "limbaj.tab.c"
    break;

  case 101: /* expression: expression '-' expression  */
#line 534 "limbaj.y"
                                       {
            if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
                cout << "Tried to substract from a " << *(yyvsp[-2].expr)->type <<" with a "<<*(yyvsp[0].expr)->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
                if(*(yyvsp[-2].expr)->type=="int"){
                    (yyval.expr)=makeExpr("int");
                    (yyval.expr)->i=(yyvsp[-2].expr)->i-(yyvsp[0].expr)->i;
                }
                else{
                    (yyval.expr)=makeExpr("float");
                    (yyval.expr)->f=(yyvsp[-2].expr)->f-(yyvsp[0].expr)->f;
                }
            }
            else{
                 if(*(yyvsp[-2].expr)->type!="")
                    cout << "Invalid substract operation for the type " << *(yyvsp[-2].expr)->type << " called at line " << yylineno << endl;
                (yyval.expr)=makeExpr("");
                 errorCount++;
            }
           }
#line 1877 "limbaj.tab.c"
    break;

  case 102: /* expression: expression '/' expression  */
#line 556 "limbaj.y"
                                      {
            if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
                cout << "Tried to divide a " << *(yyvsp[-2].expr)->type <<" with a "<<*(yyvsp[0].expr)->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
                if(*(yyvsp[-2].expr)->type=="int"){
                    if((yyvsp[0].expr)->i!=0){
                        (yyval.expr)=makeExpr("int");
                        (yyval.expr)->i=(yyvsp[-2].expr)->i/(yyvsp[0].expr)->i;
                    }
                    else{
                        cout << "Tried to divide with a 0 at line " << yylineno << endl;
                        (yyval.expr)=makeExpr("");
                        errorCount++;
                    }
                }
                else{
                    if((yyvsp[0].expr)->f!=0.0){
                        (yyval.expr)=makeExpr("float");
                        (yyval.expr)->f=(yyvsp[-2].expr)->f/(yyvsp[0].expr)->f;
                    }
                    else{
                        cout << "Tried to divide with a 0 at line " << yylineno << endl;
                        (yyval.expr)=makeExpr("");
                        errorCount++;
                    }
                }
            }
            else{
                 if(*(yyvsp[-2].expr)->type!="")
                    cout << "Invalid div operation for the type " << *(yyvsp[-2].expr)->type << " called at line " << yylineno << endl;
                 (yyval.expr)=makeExpr("");
                 errorCount++;
            }
           }
#line 1918 "limbaj.tab.c"
    break;

  case 103: /* expression: expression '*' expression  */
#line 592 "limbaj.y"
                                      {
            if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
                cout << "Tried to mutiply a " << *(yyvsp[-2].expr)->type <<" with a "<<*(yyvsp[0].expr)->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
                if(*(yyvsp[-2].expr)->type=="int"){
                    (yyval.expr)=makeExpr("int");
                    (yyval.expr)->i=(yyvsp[-2].expr)->i*(yyvsp[0].expr)->i;
                }
                else{
                    (yyval.expr)=makeExpr("float");
                    (yyval.expr)->i=(yyvsp[-2].expr)->f*(yyvsp[0].expr)->f;
                }
            }
            else{
                 if(*(yyvsp[-2].expr)->type!="")
                    cout << "Invalid multiply operation for the type " << *(yyvsp[-2].expr)->type << " called at line " << yylineno << endl;
                 (yyval.expr)=makeExpr("");
                 errorCount++;
            }
           }
#line 1945 "limbaj.tab.c"
    break;

  case 104: /* expression: expression '%' expression  */
#line 614 "limbaj.y"
                                      {
            if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
                cout << "Tried to do a mod operation on a " << *(yyvsp[-2].expr)->type <<" with a "<<*(yyvsp[0].expr)->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*(yyvsp[-2].expr)->type=="int"){
                    if((yyvsp[0].expr)->i!=0){
                        (yyval.expr)=makeExpr("int");
                        (yyval.expr)->i=(yyvsp[-2].expr)->i%(yyvsp[0].expr)->i;
                    }
                    else{
                        cout << "Tried a mod operation with a 0 at line " << yylineno << endl;
                        (yyval.expr)=makeExpr("");
                        errorCount++;
                    }
            }
            else{
                 if(*(yyvsp[-2].expr)->type!="")
                    cout << "Invalid mod operation for the type " << *(yyvsp[-2].expr)->type << " called at line " << yylineno << endl;
                 (yyval.expr)=makeExpr("");
                 errorCount++;
            }
           }
#line 1973 "limbaj.tab.c"
    break;

  case 106: /* call_param_list: %empty  */
#line 642 "limbaj.y"
    {
        (yyval.types) = new vector<string>();
    }
#line 1981 "limbaj.tab.c"
    break;

  case 107: /* call_param_list: expression ',' call_param_list  */
#line 646 "limbaj.y"
    {
        (yyval.types) = (yyvsp[0].types);
        (yyval.types)->insert((yyval.types)->begin(), *(yyvsp[-2].expr)->type);
    }
#line 1990 "limbaj.tab.c"
    break;

  case 108: /* call_param_list: logic_expression ',' call_param_list  */
#line 651 "limbaj.y"
    {
        (yyval.types) = (yyvsp[0].types);
        (yyval.types)->insert((yyval.types)->begin(), "bool");
    }
#line 1999 "limbaj.tab.c"
    break;

  case 109: /* call_param_list: expression  */
#line 656 "limbaj.y"
    {
        (yyval.types) = new vector<string>();
        (yyval.types)->push_back(*(yyvsp[0].expr)->type);
    }
#line 2008 "limbaj.tab.c"
    break;

  case 110: /* call_param_list: logic_expression  */
#line 661 "limbaj.y"
    {
        (yyval.types) = new vector<string>();
        (yyval.types)->push_back("bool");
    }
#line 2017 "limbaj.tab.c"
    break;

  case 111: /* class_element: ID  */
#line 670 "limbaj.y"
        {
            IdInfo* v = current->getVar(*(yyvsp[0].strVal));
            if(!v){
                cout << "Undefined variable " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                errorCount++;
                (yyval.expr) = makeExpr("");
            } else {
                (yyval.expr) = makeExpr(v->type);
            }
        }
#line 2032 "limbaj.tab.c"
    break;

  case 112: /* class_element: class_element '.' ID  */
#line 681 "limbaj.y"
{
    SymTable* classScope = nullptr;
    IdInfo* typeInfo = current->getClass(*(yyvsp[-2].expr)->type);
    if(!typeInfo){
        cout << "Type " << *(yyvsp[-2].expr)->type << " is not a class at line " << yylineno << endl;
        errorCount++;
        (yyval.expr) = makeExpr("");
    } else {
        classScope = typeInfo->class_scope;
        if(!classScope){
            cout << "Class " << *(yyvsp[-2].expr)->type << " has no scope at line " << yylineno << endl;
            errorCount++;
            (yyval.expr) = makeExpr("");
        } else {
            // Mai întâi verificăm dacă e câmp
            IdInfo* field = classScope->getVar_current(*(yyvsp[0].strVal));
            if(field){
                (yyval.expr) = makeExpr(field->type);
            } else {
                // Dacă nu e câmp, verificăm dacă e funcție (metodă)
                IdInfo* method = classScope->getFunction(*(yyvsp[0].strVal));
                if(method){
                    (yyval.expr) = makeExpr(method->type);
                    (yyval.expr)->cur_scope = classScope; // marcăm că e un call
                } else {
                    cout << "Undefined class element or method " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                    errorCount++;
                    (yyval.expr) = makeExpr("");
                }
            }
        }
    }
}
#line 2070 "limbaj.tab.c"
    break;


#line 2074 "limbaj.tab.c"

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

#line 716 "limbaj.y"

void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     const string global="global";
     current = new SymTable(global);
     yyparse();
     delete current;
}
