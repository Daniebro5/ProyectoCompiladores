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
#line 1 "sintactico.y" /* yacc.c:339  */

	 #include <stdio.h>
	#include <stdlib.h> 
    int yylex(void); 
    void yyerror(char *);
extern FILE *yyin;
extern int linea;
 FILE *archSal;

#line 76 "sintactico.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "sintactico.tab.h".  */
#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
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
    INCLUDE = 258,
    IGUAL = 259,
    LIBRERIA = 260,
    TIPODEDATO = 261,
    IF = 262,
    FOR = 263,
    ELSE = 264,
    RETURN = 265,
    TIPODEDATOBOOL = 266,
    TIPODEDATOSTRING = 267,
    TIPODEDATOENTERO = 268,
    VOID = 269,
    TIPODEDATOFLOTANTE = 270,
    TIPODEDATOCHAR = 271,
    THEN = 272,
    WHILE = 273,
    DO = 274,
    INPUT = 275,
    OUTPUT = 276,
    ENTEROPOSITIVO = 277,
    ENTERONEGATIVO = 278,
    FLOTANTE = 279,
    BOOLEANO = 280,
    CARRESP = 281,
    COMPAR = 282,
    IDENTIFICADOR = 283,
    CARACTER = 284,
    CADENA = 285,
    MASMENOS = 286,
    DIMULTI = 287,
    COMA = 288,
    KEYOP = 289,
    KEYCL = 290,
    ParetOP = 291,
    ParetCL = 292,
    BracketOP = 293,
    BracketCL = 294,
    FinCommand = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 168 "sintactico.tab.c" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    57,    59,    61,    66,    67,    68,    72,
      77,    79,    81,    83,    85,    87,    89,    91,    96,    97,
      98,    99,   103,   104,   108,   109,   110,   111,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     133,   134,   138,   142,   146,   145,   152,   153,   157,   158,
     159,   160,   161,   165,   166,   167,   168,   172,   178,   179,
     182,   183,   186,   187,   190,   191
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCLUDE", "IGUAL", "LIBRERIA",
  "TIPODEDATO", "IF", "FOR", "ELSE", "RETURN", "TIPODEDATOBOOL",
  "TIPODEDATOSTRING", "TIPODEDATOENTERO", "VOID", "TIPODEDATOFLOTANTE",
  "TIPODEDATOCHAR", "THEN", "WHILE", "DO", "INPUT", "OUTPUT",
  "ENTEROPOSITIVO", "ENTERONEGATIVO", "FLOTANTE", "BOOLEANO", "CARRESP",
  "COMPAR", "IDENTIFICADOR", "CARACTER", "CADENA", "MASMENOS", "DIMULTI",
  "COMA", "KEYOP", "KEYCL", "ParetOP", "ParetCL", "BracketOP", "BracketCL",
  "FinCommand", "$accept", "programa", "declaracionG",
  "declaracionLibreria", "declaracionVariable", "declaracionFuncion",
  "parametroFuncion", "definicionFuncion", "bloque", "llamadaIf",
  "llamadaWhile", "llamadaDoWhile", "llamadaFuncion", "$@1",
  "parametroLlamada", "condicion", "valor", "usoVariable", "enteros",
  "operacion", "usoAux1", "usoAux2", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      62,     5,    -1,     2,     3,    43,    62,   -73,   -73,   -73,
      62,   -73,     0,    42,    23,   -73,   -73,   -73,    82,    15,
      45,   -73,    36,    16,   -73,   -73,    29,    30,    35,    41,
      50,    63,   -15,    61,    60,    68,   -11,    72,   -73,   -73,
     -73,   -73,   -73,    49,    44,   -73,    14,    74,   -73,    44,
     -73,    21,    94,    84,    77,    79,    83,    13,    44,    81,
      44,    44,    44,    44,    44,    44,   -73,   -73,    85,    44,
     -73,   -73,     4,    55,    55,    44,    64,    64,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,    86,   -73,    87,   -73,   -73,
      88,   -73,   -73,    91,    89,   -73,   -73,    92,    90,    93,
     -73,     1,   -73,    95,    96,   -73,   -73,    73,    97,    64,
      99,   105,   -73,   -73,   -73,    64,    98,    64,   -73,   -73,
      44,   -73,    44,   100,   -73,   -73,   -73,   102,   104,    55,
     106,   116,   -73,   103,   107,   101,   108,   109,    44,   -73,
     110,   112,   -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     6,     7,     8,
       3,     9,     0,     0,     0,     1,     4,     5,     0,     0,
       0,    16,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    10,
      15,    14,    12,    22,     0,    19,     0,     0,    11,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    32,     0,
      28,    29,    30,    31,    33,     0,    18,    17,     0,     0,
      20,    23,     0,     0,     0,     0,     0,     0,    38,    25,
      34,    35,    36,    37,    39,     0,    27,     0,    54,    48,
      62,    55,    56,    50,     0,    63,    53,     0,     0,     0,
      62,     0,    57,     0,    46,    24,    26,     0,     0,     0,
       0,     0,    60,    61,    64,     0,     0,     0,    52,    51,
       0,    49,     0,     0,    65,    44,    47,     0,     0,     0,
       0,    40,    42,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    45,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,    54,   -73,   -73,    18,   -73,   -18,   -73,   -49,   -73,
     -73,   -73,   -72,   -73,    24,   -71,   -73,   -73,   124,   -73,
     -70,    34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    58,     9,    33,    10,    59,    60,
      61,    62,    63,   130,   103,    94,    95,    64,    96,   115,
      97,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    93,    93,    98,    18,    37,   101,   104,    18,    78,
      11,    80,    81,    82,    83,    84,    85,    76,     8,    44,
      87,    31,    31,    49,     8,    45,    99,    12,     8,    50,
      13,    14,   112,   113,    71,   118,    19,   119,    20,   121,
      21,   114,    20,    15,    21,   101,    22,   104,    65,    77,
      53,    54,    32,    36,    66,    69,     3,    93,   133,    23,
      16,    70,    55,    56,    17,     1,    35,    34,     2,    38,
      39,   127,    57,   128,     3,    40,     4,    24,    25,    88,
      89,    41,    52,    90,    91,    92,    24,    25,    88,   141,
      42,    43,   100,    91,    92,    24,    25,    88,    46,    47,
      31,    90,    91,    92,    24,    25,    26,    27,    48,    51,
      28,    29,    72,    73,    67,    74,    79,    75,   107,   109,
      86,   105,   106,   123,    77,   135,   108,   110,   111,   117,
       0,   120,   116,   122,   134,   138,   129,   131,   125,   132,
     136,   126,    30,   137,     0,     0,   140,   143,   139,   124,
     142
};

static const yytype_int16 yycheck[] =
{
      49,    73,    74,    74,     4,    23,    76,    77,     4,    58,
       5,    60,    61,    62,    63,    64,    65,     4,     0,    34,
      69,     6,     6,    34,     6,    40,    75,    28,    10,    40,
      28,    28,    31,    32,    52,   107,    36,   107,    38,   109,
      40,    40,    38,     0,    40,   115,     4,   117,    34,    36,
       6,     7,    37,    37,    40,    34,    12,   129,   129,    36,
       6,    40,    18,    19,    10,     3,    30,    22,     6,    40,
      40,   120,    28,   122,    12,    40,    14,    22,    23,    24,
      25,    40,    33,    28,    29,    30,    22,    23,    24,   138,
      40,    28,    28,    29,    30,    22,    23,    24,    37,    39,
       6,    28,    29,    30,    22,    23,    24,    25,    40,    37,
      28,    29,    28,    36,    40,    36,    35,    34,    27,    27,
      35,    35,    35,    18,    36,     9,    37,    37,    35,    33,
      -1,    34,    37,    34,    28,    34,    36,    35,    40,    35,
      37,   117,    18,    36,    -1,    -1,    37,    35,    40,   115,
      40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    12,    14,    42,    43,    44,    45,    46,
      48,     5,    28,    28,    28,     0,    42,    42,     4,    36,
      38,    40,     4,    36,    22,    23,    24,    25,    28,    29,
      59,     6,    37,    47,    22,    30,    37,    47,    40,    40,
      40,    40,    40,    28,    34,    40,    37,    39,    40,    34,
      40,    37,    33,     6,     7,    18,    19,    28,    45,    49,
      50,    51,    52,    53,    58,    34,    40,    40,    49,    34,
      40,    47,    28,    36,    36,    34,     4,    36,    49,    35,
      49,    49,    49,    49,    49,    49,    35,    49,    24,    25,
      28,    29,    30,    53,    56,    57,    59,    61,    56,    49,
      28,    61,    62,    55,    61,    35,    35,    27,    37,    27,
      37,    35,    31,    32,    40,    60,    37,    33,    53,    61,
      34,    61,    34,    18,    62,    40,    55,    49,    49,    36,
      54,    35,    35,    56,    28,     9,    37,    36,    34,    40,
      37,    49,    40,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    43,    43,    43,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      46,    46,    47,    47,    48,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      50,    50,    51,    52,    54,    53,    55,    55,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       5,     5,     5,     5,     5,     5,     3,     6,     6,     5,
       6,     5,     2,     4,     8,     7,     8,     7,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       7,    11,     7,     9,     0,    10,     1,     3,     1,     3,
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     3
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
#line 56 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"1\n");}
#line 1346 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"2\n");}
#line 1352 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"3\n");}
#line 1358 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"4\n");}
#line 1364 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 73 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"Librería\n");}
#line 1370 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionBooleano\n");}
#line 1376 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionesCadena\n");}
#line 1382 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionesEntero\n");}
#line 1388 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionesFlotante\n");}
#line 1394 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 86 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionesCaracter\n");}
#line 1400 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionConIDs\n");}
#line 1406 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 90 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionSinInicializacion\n");}
#line 1412 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"Declaracionvector\n");}
#line 1418 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionFuncionpara\n");}
#line 1424 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionFuncion\n");}
#line 1430 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionFuncionvoidpara\n");}
#line 1436 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DeclaracionFuncionvoid\n");}
#line 1442 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 103 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"9\n");}
#line 1448 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 104 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"10\n");}
#line 1454 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 108 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DefinicionFuncionpara\n");}
#line 1460 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 109 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DefinicionFuncion\n");}
#line 1466 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DefiFuncionvoidpara\n");}
#line 1472 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 111 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"DefinicionFuncionvoid\n");}
#line 1478 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 118 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"15\n");}
#line 1484 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"16\n");}
#line 1490 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"17\n");}
#line 1496 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 121 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"18\n");}
#line 1502 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 122 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"19\n");}
#line 1508 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 123 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"20\n");}
#line 1514 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 124 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"15\n");}
#line 1520 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 125 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"16\n");}
#line 1526 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 126 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"17\n");}
#line 1532 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 127 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"18\n");}
#line 1538 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 128 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"19\n");}
#line 1544 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 129 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"20\n");}
#line 1550 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 133 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"llamadaIF\n");}
#line 1556 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 134 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"llamadaIF\n");}
#line 1562 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 138 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"llamadaWhile\n");}
#line 1568 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 142 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"llamadaDoWhile\n");}
#line 1574 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 146 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"llamadaFuncionConParametro\n");}
#line 1580 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 148 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"llamadaFuncionSin\n");}
#line 1586 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 152 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"21\n");}
#line 1592 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 153 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"22\n");}
#line 1598 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 157 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"23\n");}
#line 1604 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 158 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"24\n");}
#line 1610 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 159 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"25\n");}
#line 1616 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 160 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"26\n");}
#line 1622 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 161 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"27\n");}
#line 1628 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 165 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"28\n");}
#line 1634 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 166 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"29\n");}
#line 1640 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 167 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"30\n");}
#line 1646 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 168 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"31\n");}
#line 1652 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 172 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"32\n");}
#line 1658 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 178 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"38\n");}
#line 1664 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 179 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"39\n");}
#line 1670 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 182 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"40\n");}
#line 1676 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 183 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"41\n");}
#line 1682 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 186 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"42\n");}
#line 1688 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 187 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"43\n");}
#line 1694 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 190 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"44\n");}
#line 1700 "sintactico.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 191 "sintactico.y" /* yacc.c:1646  */
    {fprintf(archSal,"45\n");}
#line 1706 "sintactico.tab.c" /* yacc.c:1646  */
    break;


#line 1710 "sintactico.tab.c" /* yacc.c:1646  */
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
#line 195 "sintactico.y" /* yacc.c:1906  */

void yyerror(char *s) { 
   fprintf(stderr, "Linea: %d, %s",linea+1,s); 
} 
void main(void) { 
	yyin=fopen("entrada.txt","r");
	archSal=fopen("salidaSintactica.txt","w");
    	yyparse();  
	fclose(archSal);
} 
