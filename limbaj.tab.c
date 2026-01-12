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
#line 10 "limbaj.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include "SymTable.h"
#include "Expr.h"
#include "Ast.h"

using namespace std;

struct CallParams {
    vector<string>* types;
    vector<ASTNode*>* asts;
};

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
string currentType;
IdInfo *currentIdInfo;
int errorCount = 0;

#line 99 "limbaj.tab.c"

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
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
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
  YYSYMBOL_func_body = 50,                 /* func_body  */
  YYSYMBOL_opt_param_list = 51,            /* opt_param_list  */
  YYSYMBOL_param_list = 52,                /* param_list  */
  YYSYMBOL_param = 53,                     /* param  */
  YYSYMBOL_class = 54,                     /* class  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_class_list = 56,                /* class_list  */
  YYSYMBOL_field = 57,                     /* field  */
  YYSYMBOL_method = 58,                    /* method  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_method_body = 60,               /* method_body  */
  YYSYMBOL_main = 61,                      /* main  */
  YYSYMBOL_main_code_block = 62,           /* main_code_block  */
  YYSYMBOL_code_block_no_definitions = 63, /* code_block_no_definitions  */
  YYSYMBOL_return_statement = 64,          /* return_statement  */
  YYSYMBOL_code_block = 65,                /* code_block  */
  YYSYMBOL_print_statement = 66,           /* print_statement  */
  YYSYMBOL_if_else_st = 67,                /* if_else_st  */
  YYSYMBOL_if_st = 68,                     /* if_st  */
  YYSYMBOL_call_statement = 69,            /* call_statement  */
  YYSYMBOL_while_loop = 70,                /* while_loop  */
  YYSYMBOL_assign_statement = 71,          /* assign_statement  */
  YYSYMBOL_return_val = 72,                /* return_val  */
  YYSYMBOL_var_definition = 73,            /* var_definition  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_call_params = 75,               /* call_params  */
  YYSYMBOL_call = 76,                      /* call  */
  YYSYMBOL_class_element = 77              /* class_element  */
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
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

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
      33,    34,    30,    28,    35,    29,    39,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
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
       0,    96,    96,   130,   133,   141,   142,   143,   146,   146,
     160,   176,   177,   186,   189,   189,   216,   219,   220,   223,
     224,   227,   244,   244,   284,   287,   293,   296,   304,   321,
     321,   349,   352,   357,   360,   361,   362,   363,   364,   365,
     368,   371,   372,   373,   374,   375,   376,   377,   380,   383,
     386,   387,   388,   389,   390,   391,   392,   393,   396,   405,
     425,   444,   453,   471,   493,   502,   506,   507,   521,   531,
     541,   551,   561,   571,   575,   579,   583,   587,   591,   595,
     599,   603,   607,   608,   609,   610,   611,   612,   613,   617,
     623,   630,   642,   672,   708,   761,   773,   807
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
  "'%'", "'('", "')'", "','", "';'", "'{'", "'}'", "'.'", "$accept",
  "progr", "top_level", "top_level_decl", "list_var", "$@1",
  "type_or_class", "var", "func", "$@2", "func_body", "opt_param_list",
  "param_list", "param", "class", "$@3", "class_list", "field", "method",
  "$@4", "method_body", "main", "main_code_block",
  "code_block_no_definitions", "return_statement", "code_block",
  "print_statement", "if_else_st", "if_st", "call_statement", "while_loop",
  "assign_statement", "return_val", "var_definition", "expression",
  "call_params", "call", "class_element", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -130,     7,    19,  -130,     3,   -21,  -130,  -130,  -130,     5,
    -130,  -130,  -130,  -130,  -130,  -130,     2,   -19,    10,    15,
      48,   -15,  -130,    16,    -6,    22,    58,    62,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,    18,     1,    76,    16,    77,
      55,  -130,  -130,   306,   306,   306,   306,  -130,    79,   306,
      83,    71,  -130,    88,    98,    99,  -130,   100,    16,   101,
     306,  -130,  -130,  -130,  -130,  -130,   306,   306,   197,    96,
      97,   207,   234,   169,   104,   106,   159,   107,  -130,   105,
      16,   108,  -130,  -130,  -130,  -130,  -130,   244,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   116,   119,   125,   306,  -130,   306,  -130,   306,  -130,
    -130,    16,  -130,   117,   117,    20,    20,    20,    20,    69,
     281,    81,    81,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
     109,   110,   126,   299,   129,    66,    68,  -130,  -130,  -130,
     306,    -1,    76,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,   137,  -130,   128,   154,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,   271,  -130,  -130,   146,   155,   299,  -130,
    -130,    70,  -130
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    12,    11,     4,     0,
       7,     6,     5,     2,    22,    33,     8,     0,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    95,    32,    39,
      34,    35,    36,    37,    38,     0,     0,     0,    17,     0,
       0,    24,    25,     0,     0,     0,    89,    61,     0,     0,
       0,     8,     9,     0,     0,    18,    19,    28,     0,     0,
       0,    84,    85,    86,    87,    88,     0,     0,     0,    82,
      83,     0,     0,    91,     0,    97,     0,    96,    21,     0,
       0,     0,    26,    27,    23,    75,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    92,    89,    63,    89,    49,
      20,    17,    66,    80,    81,    78,    79,    76,    77,    74,
      73,    67,    68,    69,    70,    71,    58,    40,    40,    90,
       0,     0,     0,    16,     0,     0,     0,    94,    93,    15,
       0,    95,     0,    65,    57,    56,    50,    51,    52,    53,
      54,     0,    55,     0,    60,    47,    46,    41,    42,    43,
      44,    45,    62,    64,    48,    49,     0,     0,    31,    40,
      30,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,   147,  -130,    -2,   190,  -130,  -130,
    -130,    85,  -130,   114,  -130,  -130,  -130,   144,   145,  -130,
    -130,  -130,  -130,  -125,  -129,    46,   -17,   -13,   -10,    -9,
      -8,    -7,  -130,  -130,   -30,   -80,   -18,   -14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,    17,    20,    53,   143,    11,    21,
     132,    54,    55,    56,    12,    18,    40,    41,    42,    81,
     167,    13,    19,   135,   155,   133,   156,   157,   158,   159,
     160,   161,   151,   152,    73,    74,    69,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    35,    29,   136,   144,    36,    30,     3,    49,    31,
      32,    33,    34,    68,    71,    72,    15,    22,    38,    76,
      24,    39,     4,     5,   129,   -12,   130,    43,   131,    14,
      85,    16,    46,    25,    26,   -14,    86,    87,   -10,   144,
      50,    27,     6,     7,   171,     6,     7,    23,    96,    97,
      98,    99,   100,    28,    47,    44,    39,    48,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    24,   140,    24,   140,    24,   140,    88,    89,    90,
      91,    92,    93,    37,    25,    26,    25,    26,    25,    26,
      58,    45,    27,    59,    27,    46,    27,    96,    97,    98,
      99,   100,    51,    57,   154,    75,   162,   -10,   172,    77,
     163,    98,    99,   100,    78,    35,   145,    35,    35,    36,
     146,    36,    36,   147,   148,   149,   150,    90,    91,    92,
      93,   142,    79,   -29,    80,    48,    50,    84,   105,   106,
     108,   111,   109,   137,   138,    96,    97,    98,    99,   100,
      35,   145,   126,    35,    36,   146,   127,    36,   147,   148,
     149,   150,   128,   153,   139,   165,   142,    88,    89,    90,
      91,    92,    93,   164,   166,    94,    95,    88,    89,    90,
      91,    92,    93,   169,    52,    94,    95,    96,    97,    98,
      99,   100,    10,   170,   110,   107,   134,    96,    97,    98,
      99,   100,    82,    83,   104,    88,    89,    90,    91,    92,
      93,   168,     0,    94,    95,    88,    89,    90,    91,    92,
      93,     0,     0,    94,    95,    96,    97,    98,    99,   100,
       0,   101,     0,     0,     0,    96,    97,    98,    99,   100,
       0,   102,    88,    89,    90,    91,    92,    93,     0,     0,
      94,    95,    88,    89,    90,    91,    92,    93,     0,     0,
      94,    95,    96,    97,    98,    99,   100,     0,   103,     0,
       0,     0,    96,    97,    98,    99,   100,     0,   112,    88,
      89,    90,    91,    92,    93,     0,     0,    94,    95,    88,
      89,    90,    91,    92,    93,     0,     0,    94,     0,    96,
      97,    98,    99,   100,    24,   140,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,    25,    26,     0,
       0,    60,     0,     0,     0,   141,     7,    61,    62,    63,
      64,    65,    27,     0,     0,    66,     0,     0,     0,    67
};

static const yytype_int16 yycheck[] =
{
       2,    19,    19,   128,   133,    19,    19,     0,     7,    19,
      19,    19,    19,    43,    44,    45,    37,    36,    33,    49,
       5,    23,     3,     4,   104,    26,   106,    33,   108,    26,
      60,    26,    33,    18,    19,    33,    66,    67,    36,   168,
      39,    26,    26,    27,   169,    26,    27,    37,    28,    29,
      30,    31,    32,    38,    36,    33,    58,    39,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     5,     6,     5,     6,     5,     6,     8,     9,    10,
      11,    12,    13,    35,    18,    19,    18,    19,    18,    19,
      35,    33,    26,    38,    26,    33,    26,    28,    29,    30,
      31,    32,    26,    26,    38,    26,    38,    36,    38,    26,
     140,    30,    31,    32,    26,   133,   133,   135,   136,   133,
     133,   135,   136,   133,   133,   133,   133,    10,    11,    12,
      13,   133,    34,    33,    35,    39,    39,    36,    34,    33,
      33,    33,    37,    34,    34,    28,    29,    30,    31,    32,
     168,   168,    36,   171,   168,   168,    37,   171,   168,   168,
     168,   168,    37,    34,    38,    37,   168,     8,     9,    10,
      11,    12,    13,    36,    20,    16,    17,     8,     9,    10,
      11,    12,    13,    37,    37,    16,    17,    28,    29,    30,
      31,    32,     2,    38,    80,    36,   111,    28,    29,    30,
      31,    32,    58,    58,    35,     8,     9,    10,    11,    12,
      13,   165,    -1,    16,    17,     8,     9,    10,    11,    12,
      13,    -1,    -1,    16,    17,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      -1,    34,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    17,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    17,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    -1,    34,     8,
       9,    10,    11,    12,    13,    -1,    -1,    16,    17,     8,
       9,    10,    11,    12,    13,    -1,    -1,    16,    -1,    28,
      29,    30,    31,    32,     5,     6,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    18,    19,    -1,
      -1,    15,    -1,    -1,    -1,    26,    27,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,    42,     0,     3,     4,    26,    27,    43,    46,
      47,    48,    54,    61,    26,    37,    26,    44,    55,    62,
      45,    49,    36,    37,     5,    18,    19,    26,    38,    66,
      67,    68,    69,    70,    71,    76,    77,    35,    33,    46,
      56,    57,    58,    33,    33,    33,    33,    36,    39,     7,
      39,    26,    44,    46,    51,    52,    53,    26,    35,    38,
      15,    21,    22,    23,    24,    25,    29,    33,    74,    76,
      77,    74,    74,    74,    75,    26,    74,    26,    26,    34,
      35,    59,    57,    58,    36,    74,    74,    74,     8,     9,
      10,    11,    12,    13,    16,    17,    28,    29,    30,    31,
      32,    34,    34,    34,    35,    34,    33,    36,    33,    37,
      53,    33,    34,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    36,    37,    37,    75,
      75,    75,    50,    65,    51,    63,    63,    34,    34,    38,
       6,    26,    46,    47,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    34,    38,    64,    66,    67,    68,    69,
      70,    71,    38,    74,    36,    37,    20,    60,    65,    37,
      38,    63,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    45,    44,
      44,    46,    46,    47,    49,    48,    50,    51,    51,    52,
      52,    53,    55,    54,    56,    56,    56,    56,    57,    59,
      58,    60,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     0,     4,
       1,     1,     1,     3,     0,     9,     1,     0,     1,     1,
       3,     2,     0,     7,     1,     1,     3,     3,     2,     0,
       9,     1,     4,     0,     2,     2,     2,     2,     2,     2,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     5,    11,
       7,     2,     7,     4,     2,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     4,     6,     6,     1,     3,     3
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
#line 96 "limbaj.y"
                       {
            if (errorCount == 0) {
                cout << "The program is correct!" << endl;
                SymTable* global_scope = current;
                std::vector<ASTNode*>* definitions = (yyvsp[-1].ast_list);
                std::vector<ASTNode*>* main_instrs = (yyvsp[0].ast_list);
                
                if (definitions) {
                    for (ASTNode* def : *definitions) {
                        if (def) {
                            def->setDefinitionsList(definitions);
                        }
                    }
                }

                if (main_instrs) {
                    for (ASTNode* instr : *main_instrs) {
                        if (instr) {
                            try {
                                if (definitions) {
                                    instr->setDefinitionsList(definitions);
                                }
                                instr->eval(*global_scope);
                            } catch (const std::exception& e) {
                                cout << "Runtime error: " << e.what() << endl;
                                exit(1);
                            }
                        }
                    }
                }
            }
        }
#line 1344 "limbaj.tab.c"
    break;

  case 3: /* top_level: %empty  */
#line 130 "limbaj.y"
            {
            (yyval.ast_list) = new vector<ASTNode*>();
        }
#line 1352 "limbaj.tab.c"
    break;

  case 4: /* top_level: top_level top_level_decl  */
#line 133 "limbaj.y"
                                     {
            if ((yyvsp[0].ast)) {
                (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast));
            }
            (yyval.ast_list) = (yyvsp[-1].ast_list);
        }
#line 1363 "limbaj.tab.c"
    break;

  case 5: /* top_level_decl: class  */
#line 141 "limbaj.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 1369 "limbaj.tab.c"
    break;

  case 6: /* top_level_decl: func  */
#line 142 "limbaj.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 1375 "limbaj.tab.c"
    break;

  case 7: /* top_level_decl: var  */
#line 143 "limbaj.y"
                     { (yyval.ast) = nullptr; }
#line 1381 "limbaj.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 146 "limbaj.y"
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
#line 1400 "limbaj.tab.c"
    break;

  case 10: /* list_var: ID  */
#line 160 "limbaj.y"
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
#line 1419 "limbaj.tab.c"
    break;

  case 11: /* type_or_class: TYPE  */
#line 176 "limbaj.y"
                     {currentType=*(yyvsp[0].strVal);}
#line 1425 "limbaj.tab.c"
    break;

  case 12: /* type_or_class: ID  */
#line 177 "limbaj.y"
                   {
                if(!current->existsClass(*(yyvsp[0].strVal))){
                 cout << "Undeclared class " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                 errorCount++;
                }
                currentType=*(yyvsp[0].strVal);
              }
#line 1437 "limbaj.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 189 "limbaj.y"
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
                        currentIdInfo = current->getFunction(*(yyvsp[0].strVal));
                        current = current->getFunctionScope(*(yyvsp[0].strVal));
             }
         }
#line 1458 "limbaj.tab.c"
    break;

  case 15: /* func: type_or_class ID $@2 '(' opt_param_list ')' '{' func_body '}'  */
#line 204 "limbaj.y"
                                                    {
            string func_name = *(yyvsp[-7].strVal);
            SymTable* func_scope = current->getFunctionScope(func_name);
            current=current->getParent();
            if (errorCount == 0 && (yyvsp[-1].ast_list)) {
                (yyval.ast) = new ASTFunctionDef(func_name, *(yyvsp[-1].ast_list), func_scope);
            } else {
                (yyval.ast) = nullptr;
            }
         }
#line 1473 "limbaj.tab.c"
    break;

  case 16: /* func_body: code_block  */
#line 216 "limbaj.y"
                       { (yyval.ast_list) = (yyvsp[0].ast_list); }
#line 1479 "limbaj.tab.c"
    break;

  case 21: /* param: type_or_class ID  */
#line 227 "limbaj.y"
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
#line 1499 "limbaj.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 244 "limbaj.y"
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
            /*current->addClass(className);
            SymTable* classScope = new SymTable(className, current);
            current->getClass(className)->class_scope = classScope;
            current = classScope;*/
            current->addClass(className);
            current = current->getClassScope(className);
        }
      }
#line 1524 "limbaj.tab.c"
    break;

  case 23: /* class: CLASS_MK ID $@3 '{' class_list '}' ';'  */
#line 263 "limbaj.y"
                               {
            string className = *(yyvsp[-5].strVal);
            SymTable* class_scope = current->getClassScope(className);
            current=current->getParent();
            if (errorCount == 0 && class_scope) {
                ASTClassDef* class_def = new ASTClassDef(className, class_scope);
                if ((yyvsp[-2].ast_list)) {
                    for (ASTNode* method_node : *(yyvsp[-2].ast_list)) {
                        ASTFunctionDef* method_def = dynamic_cast<ASTFunctionDef*>(method_node);
                        if (method_def) {
                            class_def->addMethod(method_def->getName(), method_def);
                        }
                    }
                }
                (yyval.ast) = class_def;
            } else {
                (yyval.ast) = nullptr;
            }
        }
#line 1548 "limbaj.tab.c"
    break;

  case 24: /* class_list: field  */
#line 284 "limbaj.y"
                   {
            (yyval.ast_list) = new vector<ASTNode*>();
        }
#line 1556 "limbaj.tab.c"
    break;

  case 25: /* class_list: method  */
#line 287 "limbaj.y"
                    {
            (yyval.ast_list) = new vector<ASTNode*>();
            if ((yyvsp[0].ast)) {
                (yyval.ast_list)->push_back((yyvsp[0].ast));
            }
        }
#line 1567 "limbaj.tab.c"
    break;

  case 26: /* class_list: class_list ',' field  */
#line 293 "limbaj.y"
                                  {
            (yyval.ast_list) = (yyvsp[-2].ast_list);
        }
#line 1575 "limbaj.tab.c"
    break;

  case 27: /* class_list: class_list ',' method  */
#line 296 "limbaj.y"
                                   {
            if ((yyvsp[0].ast)) {
                (yyvsp[-2].ast_list)->push_back((yyvsp[0].ast));
            }
            (yyval.ast_list) = (yyvsp[-2].ast_list);
        }
#line 1586 "limbaj.tab.c"
    break;

  case 28: /* field: type_or_class ID  */
#line 304 "limbaj.y"
                         {
        string fieldName = *(yyvsp[0].strVal);
        if(current->existsClass(fieldName)){
            cout << "Field " << fieldName << " has the name of a class at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsFunction_current(fieldName)){
            cout << "Field " << fieldName << " has the name of a method at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsVar_current(fieldName)){
            cout << "Redeclared field " << fieldName << " at line " << yylineno << endl;
            errorCount++;
        } else {
            current->addVar(currentType, fieldName); 
        }
    }
#line 1606 "limbaj.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 321 "limbaj.y"
                          {
    string methodName = *(yyvsp[0].strVal);
    if(current->existsClass(methodName)){
        cout << "Method " << methodName << " has the name of a class at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsVar_current(methodName)){
        cout << "Method " << methodName << " has the name of a field at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsFunction_current(methodName)){
        cout << "Redeclared method " << methodName << " at line " << yylineno << endl;
        errorCount++;
    } else {
        current->addFunction(currentType, methodName);
        currentIdInfo = current->getFunction(methodName);
        current = current->getFunctionScope(methodName);
    }
    }
#line 1628 "limbaj.tab.c"
    break;

  case 30: /* method: type_or_class ID $@4 '(' opt_param_list ')' '{' method_body '}'  */
#line 337 "limbaj.y"
                                                 {
        string methodName = *(yyvsp[-7].strVal);
        SymTable* method_scope = current->getFunctionScope(methodName);
        current = current->getParent();
        if (errorCount == 0 && method_scope && (yyvsp[-1].ast_list)) {
            (yyval.ast) = new ASTFunctionDef(methodName, *(yyvsp[-1].ast_list), method_scope);
        } else {
            (yyval.ast) = nullptr;
        }
    }
#line 1643 "limbaj.tab.c"
    break;

  case 31: /* method_body: code_block  */
#line 349 "limbaj.y"
                         { (yyval.ast_list) = (yyvsp[0].ast_list); }
#line 1649 "limbaj.tab.c"
    break;

  case 32: /* main: MAIN_MK '{' main_code_block '}'  */
#line 352 "limbaj.y"
                                       {
            (yyval.ast_list) = (yyvsp[-1].ast_list);
        }
#line 1657 "limbaj.tab.c"
    break;

  case 33: /* main_code_block: %empty  */
#line 357 "limbaj.y"
                  {
            (yyval.ast_list) = new vector<ASTNode*>();
        }
#line 1665 "limbaj.tab.c"
    break;

  case 34: /* main_code_block: main_code_block if_else_st  */
#line 360 "limbaj.y"
                                     { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1671 "limbaj.tab.c"
    break;

  case 35: /* main_code_block: main_code_block if_st  */
#line 361 "limbaj.y"
                                { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1677 "limbaj.tab.c"
    break;

  case 36: /* main_code_block: main_code_block call_statement  */
#line 362 "limbaj.y"
                                         { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1683 "limbaj.tab.c"
    break;

  case 37: /* main_code_block: main_code_block while_loop  */
#line 363 "limbaj.y"
                                     { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1689 "limbaj.tab.c"
    break;

  case 38: /* main_code_block: main_code_block assign_statement  */
#line 364 "limbaj.y"
                                           { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1695 "limbaj.tab.c"
    break;

  case 39: /* main_code_block: main_code_block print_statement  */
#line 365 "limbaj.y"
                                          { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1701 "limbaj.tab.c"
    break;

  case 40: /* code_block_no_definitions: %empty  */
#line 368 "limbaj.y"
                            {
            (yyval.ast_list) = new vector<ASTNode*>();
        }
#line 1709 "limbaj.tab.c"
    break;

  case 41: /* code_block_no_definitions: code_block_no_definitions if_else_st  */
#line 371 "limbaj.y"
                                               { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1715 "limbaj.tab.c"
    break;

  case 42: /* code_block_no_definitions: code_block_no_definitions if_st  */
#line 372 "limbaj.y"
                                          { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1721 "limbaj.tab.c"
    break;

  case 43: /* code_block_no_definitions: code_block_no_definitions call_statement  */
#line 373 "limbaj.y"
                                                   { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1727 "limbaj.tab.c"
    break;

  case 44: /* code_block_no_definitions: code_block_no_definitions while_loop  */
#line 374 "limbaj.y"
                                               { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1733 "limbaj.tab.c"
    break;

  case 45: /* code_block_no_definitions: code_block_no_definitions assign_statement  */
#line 375 "limbaj.y"
                                                     { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1739 "limbaj.tab.c"
    break;

  case 46: /* code_block_no_definitions: code_block_no_definitions print_statement  */
#line 376 "limbaj.y"
                                                    { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1745 "limbaj.tab.c"
    break;

  case 47: /* code_block_no_definitions: code_block_no_definitions return_statement  */
#line 377 "limbaj.y"
                                                     { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1751 "limbaj.tab.c"
    break;

  case 48: /* return_statement: return_val ';'  */
#line 380 "limbaj.y"
                                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 1757 "limbaj.tab.c"
    break;

  case 49: /* code_block: %empty  */
#line 383 "limbaj.y"
             {
            (yyval.ast_list) = new vector<ASTNode*>();
        }
#line 1765 "limbaj.tab.c"
    break;

  case 50: /* code_block: code_block if_else_st  */
#line 386 "limbaj.y"
                                { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1771 "limbaj.tab.c"
    break;

  case 51: /* code_block: code_block if_st  */
#line 387 "limbaj.y"
                           { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1777 "limbaj.tab.c"
    break;

  case 52: /* code_block: code_block call_statement  */
#line 388 "limbaj.y"
                                    { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1783 "limbaj.tab.c"
    break;

  case 53: /* code_block: code_block while_loop  */
#line 389 "limbaj.y"
                                { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1789 "limbaj.tab.c"
    break;

  case 54: /* code_block: code_block assign_statement  */
#line 390 "limbaj.y"
                                      { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1795 "limbaj.tab.c"
    break;

  case 55: /* code_block: code_block var_definition  */
#line 391 "limbaj.y"
                                    { (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1801 "limbaj.tab.c"
    break;

  case 56: /* code_block: code_block print_statement  */
#line 392 "limbaj.y"
                                     { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1807 "limbaj.tab.c"
    break;

  case 57: /* code_block: code_block return_statement  */
#line 393 "limbaj.y"
                                      { (yyvsp[-1].ast_list)->push_back((yyvsp[0].ast)); (yyval.ast_list) = (yyvsp[-1].ast_list); }
#line 1813 "limbaj.tab.c"
    break;

  case 58: /* print_statement: PRINT '(' expression ')' ';'  */
#line 396 "limbaj.y"
                                               {
            if ((yyvsp[-2].expr) && (yyvsp[-2].expr)->ast) {
                (yyval.ast) = new ASTPrint((yyvsp[-2].expr)->ast);
            } else {
                (yyval.ast) = new ASTOther();
            }
        }
#line 1825 "limbaj.tab.c"
    break;

  case 59: /* if_else_st: IF '(' expression ')' '{' code_block_no_definitions '}' ELSE '{' code_block_no_definitions '}'  */
#line 405 "limbaj.y"
                                                                                                            {
            if ((yyvsp[-8].expr) && (yyvsp[-8].expr)->ast && (yyvsp[-5].ast_list) && (yyvsp[-1].ast_list)) {
                if(*(yyvsp[-8].expr)->type!="bool"){
                    cout << "The condition of the if at line "<< yylineno << " needs to be a boolean expression"<<endl;
                    (yyval.ast) = new ASTOther();
                    errorCount++;
                }
                else{
                    ASTNode* cond = (yyvsp[-8].expr)->ast;
                    vector<ASTNode*> if_body = *(yyvsp[-5].ast_list);
                    vector<ASTNode*> else_body = *(yyvsp[-1].ast_list);
                    (yyval.ast) = new ASTIf(cond, if_body, else_body);
                }
                
            } else {
                (yyval.ast) = new ASTOther();
            }
        }
#line 1848 "limbaj.tab.c"
    break;

  case 60: /* if_st: IF '(' expression ')' '{' code_block_no_definitions '}'  */
#line 425 "limbaj.y"
                                                                {
            if ((yyvsp[-4].expr) && (yyvsp[-4].expr)->ast && (yyvsp[-1].ast_list)) {
                if(*(yyvsp[-4].expr)->type!="bool"){
                    cout << "The condition of the if at line "<< yylineno << " needs to be a boolean expression"<<endl;
                    (yyval.ast) = new ASTOther();
                    errorCount++;
                }
                else{
                    ASTNode* cond = (yyvsp[-4].expr)->ast;
                    vector<ASTNode*> body = *(yyvsp[-1].ast_list);
                    (yyval.ast) = new ASTIf(cond, body);
                }
                
            } else {
                (yyval.ast) = new ASTOther();
            }
        }
#line 1870 "limbaj.tab.c"
    break;

  case 61: /* call_statement: call ';'  */
#line 444 "limbaj.y"
                          {
    if ((yyvsp[-1].expr) && (yyvsp[-1].expr)->ast) {
        (yyval.ast) = (yyvsp[-1].expr)->ast;
    } else {
        (yyval.ast) = new ASTOther();
    }
}
#line 1882 "limbaj.tab.c"
    break;

  case 62: /* while_loop: WHILE '(' expression ')' '{' code_block_no_definitions '}'  */
#line 453 "limbaj.y"
                                                                        {
            if ((yyvsp[-4].expr) && (yyvsp[-4].expr)->ast && (yyvsp[-1].ast_list)) {
                if(*(yyvsp[-4].expr)->type!="bool"){
                    cout << "The condition of the while at line "<< yylineno << " needs to be a boolean expression"<<endl;
                    (yyval.ast) = new ASTOther();
                    errorCount++;
                }
                else{
                    ASTNode* cond = (yyvsp[-4].expr)->ast;
                    vector<ASTNode*> body = *(yyvsp[-1].ast_list);
                    (yyval.ast) = new ASTWhile(cond, body);
                }
            } else {
                (yyval.ast) = new ASTOther();
            }
        }
#line 1903 "limbaj.tab.c"
    break;

  case 63: /* assign_statement: class_element ASSIGN expression ';'  */
#line 472 "limbaj.y"
                 {
                    if((yyvsp[-3].expr) && (yyvsp[-1].expr) && *(yyvsp[-1].expr)->type!=""){
                        if (*(yyvsp[-3].expr)->type != *(yyvsp[-1].expr)->type) {
                            if(*(yyvsp[-3].expr)->type!="")
                                cout << "Cannot assign type "<< *(yyvsp[-1].expr)->type << " to type "<< *(yyvsp[-3].expr)->type << " at line "<< yylineno << endl;
                            errorCount++;
                        }
                    }
                    ASTNode* right_ast = nullptr;
                    if ((yyvsp[-1].expr) && (yyvsp[-1].expr)->ast) {
                        right_ast = (yyvsp[-1].expr)->ast;
                    }
                    
                    if ((yyvsp[-3].expr) && (yyvsp[-3].expr)->ast && right_ast) {
                        (yyval.ast) = new ASTAssign((yyvsp[-3].expr)->ast, right_ast);
                    } else {
                        (yyval.ast) = new ASTOther();
                    }
                 }
#line 1927 "limbaj.tab.c"
    break;

  case 64: /* return_val: RETURN expression  */
#line 493 "limbaj.y"
                               {
            if ((yyvsp[0].expr) && (yyvsp[0].expr)->ast) {
                (yyval.ast) = new ASTReturn((yyvsp[0].expr)->ast);
            } else {
                (yyval.ast) = new ASTReturn();
            }
        }
#line 1939 "limbaj.tab.c"
    break;

  case 66: /* expression: '(' expression ')'  */
#line 506 "limbaj.y"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 1945 "limbaj.tab.c"
    break;

  case 67: /* expression: expression '+' expression  */
#line 507 "limbaj.y"
                                {
        if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
            cout << "Invalid addition type mismatch at line " << yylineno << endl;
            errorCount++;
            (yyval.expr)=makeExpr("");
        } else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
            (yyval.expr)=makeExpr(*(yyvsp[-2].expr)->type);
            if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("+", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
        } else {
            cout << "Invalid add operation at line " << yylineno << endl;
            (yyval.expr)=makeExpr("");
            errorCount++;
        }
    }
#line 1964 "limbaj.tab.c"
    break;

  case 68: /* expression: expression '-' expression  */
#line 521 "limbaj.y"
                                {
        if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
            cout << "Type mismatch -" << endl; errorCount++; (yyval.expr)=makeExpr("");
        } else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
            (yyval.expr)=makeExpr(*(yyvsp[-2].expr)->type);
            if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("-", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
        } else {
            cout << "Invalid sub op" << endl; errorCount++; (yyval.expr)=makeExpr("");
        }
    }
#line 1979 "limbaj.tab.c"
    break;

  case 69: /* expression: expression '*' expression  */
#line 531 "limbaj.y"
                                {
        if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
            cout << "Type mismatch *" << endl; errorCount++; (yyval.expr)=makeExpr("");
        } else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
            (yyval.expr)=makeExpr(*(yyvsp[-2].expr)->type);
            if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("*", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
        } else {
            cout << "Invalid mul op" << endl; errorCount++; (yyval.expr)=makeExpr("");
        }
    }
#line 1994 "limbaj.tab.c"
    break;

  case 70: /* expression: expression '/' expression  */
#line 541 "limbaj.y"
                                {
        if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
            cout << "Type mismatch /" << endl; errorCount++; (yyval.expr)=makeExpr("");
        } else if(*(yyvsp[-2].expr)->type=="int"||*(yyvsp[-2].expr)->type=="float"){
            (yyval.expr)=makeExpr(*(yyvsp[-2].expr)->type);
            if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("/", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
        } else {
            cout << "Invalid div op" << endl; errorCount++; (yyval.expr)=makeExpr("");
        }
    }
#line 2009 "limbaj.tab.c"
    break;

  case 71: /* expression: expression '%' expression  */
#line 551 "limbaj.y"
                                {
        if(*(yyvsp[-2].expr)->type!=*(yyvsp[0].expr)->type){
            cout << "Type mismatch %" << endl; errorCount++; (yyval.expr)=makeExpr("");
        } else if(*(yyvsp[-2].expr)->type=="int"){
            (yyval.expr)=makeExpr("int");
            if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("%", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
        } else {
            cout << "Invalid mod op" << endl; errorCount++; (yyval.expr)=makeExpr("");
        }
    }
#line 2024 "limbaj.tab.c"
    break;

  case 72: /* expression: '-' expression  */
#line 561 "limbaj.y"
                               { 
        if (*(yyvsp[0].expr)->type == "int" || *(yyvsp[0].expr)->type == "float") {
            (yyval.expr) = makeExpr(*(yyvsp[0].expr)->type);
            if ((yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTUnaryOp("-", (yyvsp[0].expr)->ast);
        } else {
             cout << "Type mismatch for unary minus at line " << yylineno << endl;
             errorCount++;
             (yyval.expr) = makeExpr("");
        }
    }
#line 2039 "limbaj.tab.c"
    break;

  case 73: /* expression: expression OR expression  */
#line 571 "limbaj.y"
                               {
        (yyval.expr) = makeExpr("bool");
        if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("||", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
    }
#line 2048 "limbaj.tab.c"
    break;

  case 74: /* expression: expression AND expression  */
#line 575 "limbaj.y"
                                {
        (yyval.expr) = makeExpr("bool");
        if ((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("&&", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast);
    }
#line 2057 "limbaj.tab.c"
    break;

  case 75: /* expression: NOT expression  */
#line 579 "limbaj.y"
                     {
        (yyval.expr) = makeExpr("bool");
        if ((yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTUnaryOp("not", (yyvsp[0].expr)->ast);
    }
#line 2066 "limbaj.tab.c"
    break;

  case 76: /* expression: expression LT expression  */
#line 583 "limbaj.y"
                               {
        if(*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) { cout << "Type mismatch for operator '<' at line " << yylineno << endl; errorCount++; (yyval.expr)=makeExpr(""); }
        else { (yyval.expr)=makeExpr("bool"); if((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("<", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast); }
    }
#line 2075 "limbaj.tab.c"
    break;

  case 77: /* expression: expression GT expression  */
#line 587 "limbaj.y"
                               {
        if(*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) { cout << "Type mismatch for operator '>' at line " << yylineno << endl; errorCount++; (yyval.expr)=makeExpr(""); }
        else { (yyval.expr)=makeExpr("bool"); if((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp(">", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast); }
    }
#line 2084 "limbaj.tab.c"
    break;

  case 78: /* expression: expression LE expression  */
#line 591 "limbaj.y"
                               {
        if(*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) { cout << "Type mismatch for operator '<=' at line " << yylineno << endl;errorCount++; (yyval.expr)=makeExpr(""); }
        else { (yyval.expr)=makeExpr("bool"); if((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("<=", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast); }
    }
#line 2093 "limbaj.tab.c"
    break;

  case 79: /* expression: expression GE expression  */
#line 595 "limbaj.y"
                               {
        if(*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) { cout << "Type mismatch for operator '>=' at line " << yylineno << endl;errorCount++; (yyval.expr)=makeExpr(""); }
        else { (yyval.expr)=makeExpr("bool"); if((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp(">=", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast); }
    }
#line 2102 "limbaj.tab.c"
    break;

  case 80: /* expression: expression EQ expression  */
#line 599 "limbaj.y"
                               {
        if(*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) { cout << "Type mismatch for operator '==' at line " << yylineno << endl;errorCount++; (yyval.expr)=makeExpr(""); }
        else { (yyval.expr)=makeExpr("bool"); if((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("==", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast); }
    }
#line 2111 "limbaj.tab.c"
    break;

  case 81: /* expression: expression NEQ expression  */
#line 603 "limbaj.y"
                                {
        if(*(yyvsp[-2].expr)->type != *(yyvsp[0].expr)->type) { cout << "Type mismatch for operator '!=' at line " << yylineno << endl; errorCount++; (yyval.expr)=makeExpr(""); }
        else { (yyval.expr)=makeExpr("bool"); if((yyvsp[-2].expr)->ast && (yyvsp[0].expr)->ast) (yyval.expr)->ast = new ASTBinaryOp("!=", (yyvsp[-2].expr)->ast, (yyvsp[0].expr)->ast); }
    }
#line 2120 "limbaj.tab.c"
    break;

  case 82: /* expression: call  */
#line 607 "limbaj.y"
           { (yyval.expr) = (yyvsp[0].expr); }
#line 2126 "limbaj.tab.c"
    break;

  case 83: /* expression: class_element  */
#line 608 "limbaj.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2132 "limbaj.tab.c"
    break;

  case 84: /* expression: TRU  */
#line 609 "limbaj.y"
          { (yyval.expr) = makeExpr("bool", new ASTConstant(Value::makeBool(true))); }
#line 2138 "limbaj.tab.c"
    break;

  case 85: /* expression: FLS  */
#line 610 "limbaj.y"
          { (yyval.expr) = makeExpr("bool", new ASTConstant(Value::makeBool(false))); }
#line 2144 "limbaj.tab.c"
    break;

  case 86: /* expression: INT_CONST  */
#line 611 "limbaj.y"
                { (yyval.expr) = makeExpr("int", new ASTConstant(Value::makeInt((yyvsp[0].intVal)))); }
#line 2150 "limbaj.tab.c"
    break;

  case 87: /* expression: FLOAT_CONST  */
#line 612 "limbaj.y"
                  { (yyval.expr) = makeExpr("float", new ASTConstant(Value::makeFloat((yyvsp[0].floatVal)))); }
#line 2156 "limbaj.tab.c"
    break;

  case 88: /* expression: STRING_CONST  */
#line 613 "limbaj.y"
                   { (yyval.expr) = makeExpr("string", new ASTConstant(Value::makeString(*(yyvsp[0].strVal)))); }
#line 2162 "limbaj.tab.c"
    break;

  case 89: /* call_params: %empty  */
#line 617 "limbaj.y"
      {
        CallParams* cp = new CallParams();
        cp->types = new vector<string>();
        cp->asts = new vector<ASTNode*>();
        (yyval.call_params) = cp;
    }
#line 2173 "limbaj.tab.c"
    break;

  case 90: /* call_params: expression ',' call_params  */
#line 623 "limbaj.y"
                                 {
        (yyval.call_params) = (yyvsp[0].call_params);
        string param_type = (*(yyvsp[-2].expr)->type == "bool") ? "bool" : *(yyvsp[-2].expr)->type;
        (yyval.call_params)->types->insert((yyval.call_params)->types->begin(), param_type);
        if ((yyvsp[-2].expr) && (yyvsp[-2].expr)->ast) (yyval.call_params)->asts->insert((yyval.call_params)->asts->begin(), (yyvsp[-2].expr)->ast);
        else (yyval.call_params)->asts->insert((yyval.call_params)->asts->begin(), new ASTOther());
    }
#line 2185 "limbaj.tab.c"
    break;

  case 91: /* call_params: expression  */
#line 630 "limbaj.y"
                 {
        CallParams* cp = new CallParams();
        cp->types = new vector<string>();
        cp->asts = new vector<ASTNode*>();
        string param_type = (*(yyvsp[0].expr)->type == "bool") ? "bool" : *(yyvsp[0].expr)->type;
        cp->types->push_back(param_type);
        if ((yyvsp[0].expr) && (yyvsp[0].expr)->ast) cp->asts->push_back((yyvsp[0].expr)->ast);
        else cp->asts->push_back(new ASTOther());
        (yyval.call_params) = cp;
    }
#line 2200 "limbaj.tab.c"
    break;

  case 92: /* call: ID '(' call_params ')'  */
#line 642 "limbaj.y"
                              {
    IdInfo* f = current->getFunction(*(yyvsp[-3].strVal));
    Expr* expr_result = nullptr;
    if(!f){
        cout << "Undefined function " << *(yyvsp[-3].strVal) << " at line " << yylineno << endl;
        errorCount++;
        expr_result = makeExpr("");
        expr_result->ast = new ASTOther();
    } else {
        vector<string>* types = (yyvsp[-1].call_params)->types;
        vector<ASTNode*>* asts = (yyvsp[-1].call_params)->asts;
        if(f->params.size() != types->size()){
            cout << "Function " << *(yyvsp[-3].strVal) << " called with wrong params" << endl;
            errorCount++;
            expr_result = makeExpr("");
            expr_result->ast = new ASTOther();
        } else {
             for(size_t i = 0; i < types->size(); i++){
                if(f->params[i].first!= (*types)[i]){
                    cout << "Type mismatch for param " << i+1 << " in function " << *(yyvsp[-3].strVal) << endl;
                    errorCount++;
                }
            }
            expr_result = makeExpr(f->type);
            if (asts) expr_result->ast = new ASTFunctionCall(*(yyvsp[-3].strVal), *asts);
            else expr_result->ast = new ASTOther();
        }
    }
    (yyval.expr) = expr_result;
}
#line 2235 "limbaj.tab.c"
    break;

  case 93: /* call: class_element '.' ID '(' call_params ')'  */
#line 672 "limbaj.y"
                                           {
    IdInfo* typeInfo = current->getClass(*(yyvsp[-5].expr)->type);
    Expr* expr_result = nullptr;
    if(!typeInfo){
        cout << "Type " << *(yyvsp[-5].expr)->type << " is not a class at line " << yylineno << endl;
        errorCount++;
        expr_result = makeExpr("");
        expr_result->ast = new ASTOther();
    } else {
        SymTable* classScope = typeInfo->class_scope;
        IdInfo* m = classScope->getFunction(*(yyvsp[-3].strVal));
        if(!m){
            cout << "Undefined method " << *(yyvsp[-3].strVal) << endl;
            errorCount++;
            expr_result = makeExpr("");
            expr_result->ast = new ASTOther();
        } else {
             vector<string>* types = (yyvsp[-1].call_params)->types;
            vector<ASTNode*>* asts = (yyvsp[-1].call_params)->asts;
            if(m->params.size() != types->size()){
                cout << "Wrong number of params" << endl; errorCount++;
                expr_result = makeExpr(""); expr_result->ast = new ASTOther();
            } else {
                 for(size_t i = 0; i < types->size(); i++){
                    if(m->params[i].first != (*types)[i]){
                        cout << "Type mismatch param" << endl; errorCount++;
                    }
                }
                expr_result = makeExpr(m->type);
                if ((yyvsp[-5].expr)->ast && asts) expr_result->ast = new ASTMethodCall((yyvsp[-5].expr)->ast, *(yyvsp[-3].strVal), *asts);
                else expr_result->ast = new ASTOther();
            }
        }
    }
    (yyval.expr) = expr_result;
}
#line 2276 "limbaj.tab.c"
    break;

  case 94: /* call: call '.' ID '(' call_params ')'  */
#line 708 "limbaj.y"
                                  {
    // 1. Verificam daca rezultatul apelului anterior ($1) este o clasa
    IdInfo* typeInfo = current->getClass(*(yyvsp[-5].expr)->type);
    Expr* expr_result = nullptr;

    if(!typeInfo){
        cout << "Type " << *(yyvsp[-5].expr)->type << " returned by function is not a class at line " << yylineno << endl;
        errorCount++;
        expr_result = makeExpr("");
        expr_result->ast = new ASTOther();
    } else {
        SymTable* classScope = typeInfo->class_scope;
        // 2. Cautam metoda in scope-ul clasei returnate
        IdInfo* m = classScope->getFunction(*(yyvsp[-3].strVal));
        
        if(!m){
            cout << "Undefined method " << *(yyvsp[-3].strVal) << " in class " << *(yyvsp[-5].expr)->type << endl;
            errorCount++;
            expr_result = makeExpr("");
            expr_result->ast = new ASTOther();
        } else {
            vector<string>* types = (yyvsp[-1].call_params)->types;
            vector<ASTNode*>* asts = (yyvsp[-1].call_params)->asts;
            
            // 3. Validam parametrii
            if(m->params.size() != types->size()){
                cout << "Wrong number of params for method " << *(yyvsp[-3].strVal) << endl;
                errorCount++;
                expr_result = makeExpr(""); 
                expr_result->ast = new ASTOther();
            } else {
                 for(size_t i = 0; i < types->size(); i++){
                    if(m->params[i].first != (*types)[i]){
                        cout << "Type mismatch param " << i+1 << " in method " << *(yyvsp[-3].strVal) << endl;
                        errorCount++;
                    }
                }
                // 4. Succes! Cream ASTMethodCall
                expr_result = makeExpr(m->type);
                // Obiectul pe care apelam metoda este AST-ul apelului anterior ($1->ast)
                if ((yyvsp[-5].expr)->ast && asts) 
                    expr_result->ast = new ASTMethodCall((yyvsp[-5].expr)->ast, *(yyvsp[-3].strVal), *asts);
                else 
                    expr_result->ast = new ASTOther();
            }
        }
    }
    (yyval.expr) = expr_result;
}
#line 2330 "limbaj.tab.c"
    break;

  case 95: /* class_element: ID  */
#line 761 "limbaj.y"
         {
            IdInfo* v = current->getVar(*(yyvsp[0].strVal));
            if(!v){
                cout << "Undefined variable " << *(yyvsp[0].strVal) << " at line " << yylineno << endl;
                errorCount++;
                (yyval.expr) = makeExpr("");
                (yyval.expr)->ast = new ASTOther();
            } else {
                (yyval.expr) = makeExpr(v->type);
                (yyval.expr)->ast = new ASTId(*(yyvsp[0].strVal));
            }
        }
#line 2347 "limbaj.tab.c"
    break;

  case 96: /* class_element: class_element '.' ID  */
#line 773 "limbaj.y"
                           {
        SymTable* classScope = nullptr;
        IdInfo* typeInfo = current->getClass(*(yyvsp[-2].expr)->type);
        if(!typeInfo){
            cout << "Type " << *(yyvsp[-2].expr)->type << " is not a class at line " << yylineno << endl;
            errorCount++;
            (yyval.expr) = makeExpr("");
            (yyval.expr)->ast = new ASTOther();
        } else {
            classScope = typeInfo->class_scope;
            if(!classScope){
                cout << "Class scope error" << endl; errorCount++;
                (yyval.expr) = makeExpr(""); (yyval.expr)->ast = new ASTOther();
            } else {
                IdInfo* field = classScope->getVar_current(*(yyvsp[0].strVal));
                if(field){
                    (yyval.expr) = makeExpr(field->type);
                    if ((yyvsp[-2].expr)->ast) (yyval.expr)->ast = new ASTFieldAccess((yyvsp[-2].expr)->ast, *(yyvsp[0].strVal));
                    else (yyval.expr)->ast = new ASTOther();
                } else {
                    IdInfo* method = classScope->getFunction(*(yyvsp[0].strVal));
                    if(method){
                        (yyval.expr) = makeExpr(method->type);
                        //$$->cur_scope = classScope;
                        (yyval.expr)->ast = new ASTOther();
                    } else {
                        cout << "Undefined class element " << *(yyvsp[0].strVal) << endl;
                        errorCount++;
                        (yyval.expr) = makeExpr(""); (yyval.expr)->ast = new ASTOther();
                    }
                }
            }
        }
    }
#line 2386 "limbaj.tab.c"
    break;

  case 97: /* class_element: call '.' ID  */
#line 807 "limbaj.y"
                  {
        SymTable* classScope = nullptr;
        IdInfo* typeInfo = current->getClass(*(yyvsp[-2].expr)->type);
        
        if(!typeInfo){
            cout << "Type " << *(yyvsp[-2].expr)->type << " returned by function is not a class at line " << yylineno << endl;
            errorCount++;
            (yyval.expr) = makeExpr("");
            (yyval.expr)->ast = new ASTOther();
        } else {
            classScope = typeInfo->class_scope;
            if(!classScope){
                cout << "Class scope error" << endl; errorCount++;
                (yyval.expr) = makeExpr(""); (yyval.expr)->ast = new ASTOther();
            } else {
                IdInfo* field = classScope->getVar_current(*(yyvsp[0].strVal));
                if(field){
                    (yyval.expr) = makeExpr(field->type);
                    if ((yyvsp[-2].expr)->ast) (yyval.expr)->ast = new ASTFieldAccess((yyvsp[-2].expr)->ast, *(yyvsp[0].strVal));
                    else (yyval.expr)->ast = new ASTOther();
                } else {
                    IdInfo* method = classScope->getFunction(*(yyvsp[0].strVal));
                    if(method){
                        (yyval.expr) = makeExpr(method->type);
                        //$$->cur_scope = classScope; 
                        (yyval.expr)->ast = new ASTOther();
                    } else {
                        cout << "Undefined field " << *(yyvsp[0].strVal) << " in class returned by function" << endl;
                        errorCount++;
                        (yyval.expr) = makeExpr(""); (yyval.expr)->ast = new ASTOther();
                    }
                }
            }
        }
    }
#line 2426 "limbaj.tab.c"
    break;


#line 2430 "limbaj.tab.c"

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

#line 844 "limbaj.y"

void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     const string global="global";
     current = new SymTable(global);
     yyparse();
     SymTable::printAllTables("tables.txt");
     delete current;
}
