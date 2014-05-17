/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     STRING = 259,
     PRINT = 260,
     VAR = 261,
     BLTIN = 262,
     UNDEF = 263,
     WHILE = 264,
     FOR = 265,
     IF = 266,
     ELSE = 267,
     FUNCTION = 268,
     PROCEDURE = 269,
     RETURN = 270,
     FUNC = 271,
     PROC = 272,
     READ = 273,
     ARG = 274,
     MODEQ = 275,
     DIVEQ = 276,
     MULEQ = 277,
     SUBEQ = 278,
     ADDEQ = 279,
     OR = 280,
     AND = 281,
     NE = 282,
     EQ = 283,
     LE = 284,
     LT = 285,
     GE = 286,
     GT = 287,
     DEC = 288,
     INC = 289,
     NOT = 290,
     UNARYMINUS = 291
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define STRING 259
#define PRINT 260
#define VAR 261
#define BLTIN 262
#define UNDEF 263
#define WHILE 264
#define FOR 265
#define IF 266
#define ELSE 267
#define FUNCTION 268
#define PROCEDURE 269
#define RETURN 270
#define FUNC 271
#define PROC 272
#define READ 273
#define ARG 274
#define MODEQ 275
#define DIVEQ 276
#define MULEQ 277
#define SUBEQ 278
#define ADDEQ 279
#define OR 280
#define AND 281
#define NE 282
#define EQ 283
#define LE 284
#define LT 285
#define GE 286
#define GT 287
#define DEC 288
#define INC 289
#define NOT 290
#define UNARYMINUS 291




/* Copy the first part of user declarations.  */
#line 1 "book/hoc.y"

#include <string.h>
#include "hoc.h"
#define	code2(c1,c2)	code(c1); code(c2)
#define	code3(c1,c2,c3)	code(c1); code(c2); code(c3)


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 7 "book/hoc.y"
typedef union YYSTYPE {
	Symbol	*sym;	/* symbol table pointer */
	Inst	*inst;	/* machine instruction */
	int	narg;	/* number of arguments */
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 170 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 182 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  18
/* YYNRULES -- Number of rules. */
#define YYNRULES  81
/* YYNRULES -- Number of states. */
#define YYNSTATES  163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      45,    46,    36,    34,    50,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    20,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    39,    40,
      41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    19,    23,    27,
      31,    35,    39,    43,    47,    51,    55,    59,    63,    67,
      71,    75,    77,    79,    82,    88,    91,    98,   109,   116,
     126,   130,   132,   134,   136,   138,   139,   140,   141,   144,
     147,   149,   151,   153,   155,   161,   166,   171,   175,   179,
     183,   187,   191,   195,   199,   202,   206,   210,   214,   218,
     222,   226,   230,   234,   237,   240,   243,   246,   249,   251,
     253,   257,   261,   262,   269,   270,   277,   279,   281,   283,
     284,   286
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      52,     0,    -1,    -1,    52,    44,    -1,    52,    64,    44,
      -1,    52,    53,    44,    -1,    52,    54,    44,    -1,    52,
      62,    44,    -1,    52,     1,    44,    -1,     6,    20,    62,
      -1,     6,    25,    62,    -1,     6,    24,    62,    -1,     6,
      23,    62,    -1,     6,    22,    62,    -1,     6,    21,    62,
      -1,    19,    20,    62,    -1,    19,    25,    62,    -1,    19,
      24,    62,    -1,    19,    23,    62,    -1,    19,    22,    62,
      -1,    19,    21,    62,    -1,    62,    -1,    15,    -1,    15,
      62,    -1,    14,    59,    45,    68,    46,    -1,     5,    63,
      -1,    56,    45,    55,    46,    54,    60,    -1,    57,    45,
      55,    47,    55,    47,    55,    46,    54,    60,    -1,    58,
      45,    55,    46,    54,    60,    -1,    58,    45,    55,    46,
      54,    60,    12,    54,    60,    -1,    48,    61,    49,    -1,
      62,    -1,     9,    -1,    10,    -1,    11,    -1,    -1,    -1,
      -1,    61,    44,    -1,    61,    54,    -1,     3,    -1,     6,
      -1,    19,    -1,    53,    -1,    13,    59,    45,    68,    46,
      -1,    18,    45,     6,    46,    -1,     7,    45,    62,    46,
      -1,    45,    62,    46,    -1,    62,    34,    62,    -1,    62,
      35,    62,    -1,    62,    36,    62,    -1,    62,    37,    62,
      -1,    62,    38,    62,    -1,    62,    43,    62,    -1,    35,
      62,    -1,    62,    33,    62,    -1,    62,    32,    62,    -1,
      62,    31,    62,    -1,    62,    30,    62,    -1,    62,    29,
      62,    -1,    62,    28,    62,    -1,    62,    27,    62,    -1,
      62,    26,    62,    -1,    41,    62,    -1,    40,     6,    -1,
      39,     6,    -1,     6,    40,    -1,     6,    39,    -1,    62,
      -1,     4,    -1,    63,    50,    62,    -1,    63,    50,     4,
      -1,    -1,    16,    67,    65,    45,    46,    54,    -1,    -1,
      17,    67,    66,    45,    46,    54,    -1,     6,    -1,    13,
      -1,    14,    -1,    -1,    62,    -1,    68,    50,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    28,    28,    29,    30,    31,    32,    33,    34,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    49,    50,    51,    53,    55,    56,    59,    64,    67,
      71,    73,    75,    77,    79,    81,    83,    85,    86,    87,
      89,    90,    91,    92,    93,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   119,   120,
     121,   122,   124,   124,   126,   126,   129,   130,   131,   133,
     134,   135
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STRING", "PRINT", "VAR",
  "BLTIN", "UNDEF", "WHILE", "FOR", "IF", "ELSE", "FUNCTION", "PROCEDURE",
  "RETURN", "FUNC", "PROC", "READ", "ARG", "'='", "MODEQ", "DIVEQ",
  "MULEQ", "SUBEQ", "ADDEQ", "OR", "AND", "NE", "EQ", "LE", "LT", "GE",
  "GT", "'+'", "'-'", "'*'", "'/'", "'%'", "DEC", "INC", "NOT",
  "UNARYMINUS", "'^'", "'\\n'", "'('", "')'", "';'", "'{'", "'}'", "','",
  "$accept", "list", "asgn", "stmt", "cond", "while", "for", "if", "begin",
  "end", "stmtlist", "expr", "prlist", "defn", "@1", "@2", "procname",
  "arglist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,    43,    45,    42,    47,    37,   288,
     289,   290,   291,    94,    10,    40,    41,    59,   123,   125,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    51,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    56,    57,    58,    59,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    63,    65,    64,    66,    64,    67,    67,    67,    68,
      68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     5,     2,     6,    10,     6,     9,
       3,     1,     1,     1,     1,     0,     0,     0,     2,     2,
       1,     1,     1,     1,     5,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     0,     6,     0,     6,     1,     1,     1,     0,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     1,     0,    40,     0,    41,     0,    32,    33,
      34,    35,    35,    22,     0,     0,     0,    42,     0,     0,
       0,     0,     3,     0,    37,    43,     0,     0,     0,     0,
       0,     0,     8,    69,    43,    68,    25,     0,     0,     0,
       0,     0,     0,    67,    66,     0,     0,     0,    23,    76,
      77,    78,    72,    74,     0,     0,     0,     0,     0,     0,
       0,    54,    65,    64,    63,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     4,     0,     9,
      14,    13,    12,    11,    10,     0,    79,    79,     0,     0,
       0,    15,    20,    19,    18,    17,    16,    47,    38,    30,
      39,    21,     0,    31,     0,     0,    62,    61,    60,    59,
      58,    57,    56,    55,    48,    49,    50,    51,    52,    53,
      71,    70,    46,    80,     0,     0,     0,     0,    45,     0,
       0,     0,    44,     0,    24,     0,     0,    36,     0,    36,
      81,    73,    75,    26,     0,    28,     0,     0,     0,    36,
      36,    29,    27
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    34,    26,   112,    27,    28,    29,    46,   153,
      66,   111,    36,    31,    98,    99,    52,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const short int yypact[] =
{
    -132,   106,  -132,   -43,  -132,   210,   -15,   -42,  -132,  -132,
    -132,  -132,  -132,   258,    13,    13,   -34,    10,   258,    -4,
       8,   258,  -132,   258,  -132,   -23,   -21,    -3,    -2,     5,
     100,     4,  -132,  -132,  -132,   252,     1,   258,   258,   258,
     258,   258,   258,  -132,  -132,   258,    16,    17,   252,  -132,
    -132,  -132,  -132,  -132,    57,   258,   258,   258,   258,   258,
     258,    22,  -132,  -132,    22,   278,   152,  -132,  -132,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,  -132,  -132,   218,   252,
     252,   252,   252,   252,   252,   299,   258,   258,    21,    44,
      45,   252,   252,   252,   252,   252,   252,  -132,  -132,  -132,
    -132,   252,    48,   252,    20,    51,   319,   335,   204,   204,
     204,   204,   204,   204,     9,     9,    22,    22,    22,    22,
    -132,   252,  -132,   252,     3,    14,    52,    54,  -132,   170,
     258,   170,  -132,   258,  -132,   170,   170,  -132,    43,  -132,
     252,  -132,  -132,  -132,   258,    89,    56,   170,   170,  -132,
    -132,  -132,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -132,  -132,   102,   -53,   -55,  -132,  -132,  -132,    96,  -131,
    -132,    -1,  -132,  -132,  -132,  -132,    95,    55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      30,    32,    62,    45,    35,    37,    38,    39,    40,    41,
      42,    54,    48,   110,    63,   114,   115,    61,   155,    49,
      64,    67,    65,    68,    43,    44,    50,    51,   161,   162,
      55,    56,    57,    58,    59,    60,    89,    90,    91,    92,
      93,    94,    69,    70,    95,    82,    83,    84,    87,   142,
      71,    88,    85,   143,   101,   102,   103,   104,   105,   106,
     144,    96,    97,   100,   143,    85,   136,   140,   113,   113,
     113,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   148,   147,   131,   149,   137,
     154,   138,   151,   152,   139,   133,   133,   141,   145,   156,
     146,   157,   158,    25,   159,   160,     2,     3,    47,     4,
      53,     5,     6,     7,     0,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   113,
       0,    18,   150,    85,    86,    19,    20,    21,     0,     0,
      22,    23,   135,   113,    24,     4,     0,     5,     6,     7,
       0,     8,     9,    10,     0,    11,    12,    13,     0,     0,
      16,    17,     0,     4,     0,     5,     6,     7,     0,     8,
       9,    10,     0,    11,    12,    13,     0,    18,    16,    17,
       0,    19,    20,    21,     0,     0,   108,    23,     0,     0,
      24,   109,     0,     0,     0,    18,     0,     0,     0,    19,
      20,    21,     0,     4,    33,    23,     6,     7,    24,     0,
       0,     4,   130,    11,     6,     7,     0,     0,    16,    17,
       0,    11,     0,     0,     0,     0,    16,    17,    80,    81,
      82,    83,    84,     0,     0,    18,     0,    85,     0,    19,
      20,    21,     0,    18,     0,    23,     0,    19,    20,    21,
       0,     4,     0,    23,     6,     7,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,    16,    17,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,    18,     0,    85,     0,    19,    20,    21,
       0,     0,     0,    23,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,    85,     0,     0,   107,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,     0,     0,   132,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,    85
};

static const short int yycheck[] =
{
       1,    44,     6,    45,     5,    20,    21,    22,    23,    24,
      25,    45,    13,    66,     6,    70,    71,    18,   149,     6,
      21,    44,    23,    44,    39,    40,    13,    14,   159,   160,
      20,    21,    22,    23,    24,    25,    37,    38,    39,    40,
      41,    42,    45,    45,    45,    36,    37,    38,    44,    46,
      45,    50,    43,    50,    55,    56,    57,    58,    59,    60,
      46,    45,    45,     6,    50,    43,    45,    47,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   140,   139,    88,   141,    45,
      47,    46,   145,   146,    46,    96,    97,    46,    46,   154,
      46,    12,    46,     1,   157,   158,     0,     1,    12,     3,
      15,     5,     6,     7,    -1,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   140,
      -1,    35,   143,    43,    44,    39,    40,    41,    -1,    -1,
      44,    45,    97,   154,    48,     3,    -1,     5,     6,     7,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      18,    19,    -1,     3,    -1,     5,     6,     7,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    35,    18,    19,
      -1,    39,    40,    41,    -1,    -1,    44,    45,    -1,    -1,
      48,    49,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
      40,    41,    -1,     3,     4,    45,     6,     7,    48,    -1,
      -1,     3,     4,    13,     6,     7,    -1,    -1,    18,    19,
      -1,    13,    -1,    -1,    -1,    -1,    18,    19,    34,    35,
      36,    37,    38,    -1,    -1,    35,    -1,    43,    -1,    39,
      40,    41,    -1,    35,    -1,    45,    -1,    39,    40,    41,
      -1,     3,    -1,    45,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    -1,    -1,    18,    19,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    35,    -1,    43,    -1,    39,    40,    41,
      -1,    -1,    -1,    45,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    46,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    43,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    52,     0,     1,     3,     5,     6,     7,     9,    10,
      11,    13,    14,    15,    16,    17,    18,    19,    35,    39,
      40,    41,    44,    45,    48,    53,    54,    56,    57,    58,
      62,    64,    44,     4,    53,    62,    63,    20,    21,    22,
      23,    24,    25,    39,    40,    45,    59,    59,    62,     6,
      13,    14,    67,    67,    45,    20,    21,    22,    23,    24,
      25,    62,     6,     6,    62,    62,    61,    44,    44,    45,
      45,    45,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    43,    44,    44,    50,    62,
      62,    62,    62,    62,    62,    62,    45,    45,    65,    66,
       6,    62,    62,    62,    62,    62,    62,    46,    44,    49,
      54,    62,    55,    62,    55,    55,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
       4,    62,    46,    62,    68,    68,    45,    45,    46,    46,
      47,    46,    46,    50,    46,    46,    46,    54,    55,    54,
      62,    54,    54,    60,    47,    60,    55,    12,    46,    54,
      54,    60,    60
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 5:
#line 31 "book/hoc.y"
    { code2(xpop, STOP); return 1; }
    break;

  case 6:
#line 32 "book/hoc.y"
    { code(STOP); return 1; }
    break;

  case 7:
#line 33 "book/hoc.y"
    { code2(printtop, STOP); return 1; }
    break;

  case 8:
#line 34 "book/hoc.y"
    { yyerrok; }
    break;

  case 9:
#line 36 "book/hoc.y"
    { code3(varpush,(Inst)(yyvsp[-2].sym),assign); (yyval.inst)=(yyvsp[0].inst); }
    break;

  case 10:
#line 37 "book/hoc.y"
    { code3(varpush,(Inst)(yyvsp[-2].sym),addeq); (yyval.inst)=(yyvsp[0].inst); }
    break;

  case 11:
#line 38 "book/hoc.y"
    { code3(varpush,(Inst)(yyvsp[-2].sym),subeq); (yyval.inst)=(yyvsp[0].inst); }
    break;

  case 12:
#line 39 "book/hoc.y"
    { code3(varpush,(Inst)(yyvsp[-2].sym),muleq); (yyval.inst)=(yyvsp[0].inst); }
    break;

  case 13:
#line 40 "book/hoc.y"
    { code3(varpush,(Inst)(yyvsp[-2].sym),diveq); (yyval.inst)=(yyvsp[0].inst); }
    break;

  case 14:
#line 41 "book/hoc.y"
    { code3(varpush,(Inst)(yyvsp[-2].sym),modeq); (yyval.inst)=(yyvsp[0].inst); }
    break;

  case 15:
#line 42 "book/hoc.y"
    { defnonly("$"); code2(argassign,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst);}
    break;

  case 16:
#line 43 "book/hoc.y"
    { defnonly("$"); code2(argaddeq,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst);}
    break;

  case 17:
#line 44 "book/hoc.y"
    { defnonly("$"); code2(argsubeq,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst);}
    break;

  case 18:
#line 45 "book/hoc.y"
    { defnonly("$"); code2(argmuleq,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst);}
    break;

  case 19:
#line 46 "book/hoc.y"
    { defnonly("$"); code2(argdiveq,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst);}
    break;

  case 20:
#line 47 "book/hoc.y"
    { defnonly("$"); code2(argmodeq,(Inst)(yyvsp[-2].narg)); (yyval.inst)=(yyvsp[0].inst);}
    break;

  case 21:
#line 49 "book/hoc.y"
    { code(xpop); }
    break;

  case 22:
#line 50 "book/hoc.y"
    { defnonly("return"); code(procret); }
    break;

  case 23:
#line 52 "book/hoc.y"
    { defnonly("return"); (yyval.inst)=(yyvsp[0].inst); code(funcret); }
    break;

  case 24:
#line 54 "book/hoc.y"
    { (yyval.inst) = (yyvsp[-3].inst); code3(call, (Inst)(yyvsp[-4].sym), (Inst)(yyvsp[-1].narg)); }
    break;

  case 25:
#line 55 "book/hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); }
    break;

  case 26:
#line 56 "book/hoc.y"
    {
		((yyvsp[-5].inst))[1] = (Inst)(yyvsp[-1].inst);	/* body of loop */
		((yyvsp[-5].inst))[2] = (Inst)(yyvsp[0].inst); }
    break;

  case 27:
#line 59 "book/hoc.y"
    {
		((yyvsp[-9].inst))[1] = (Inst)(yyvsp[-5].inst);	/* condition */
		((yyvsp[-9].inst))[2] = (Inst)(yyvsp[-3].inst);	/* post loop */
		((yyvsp[-9].inst))[3] = (Inst)(yyvsp[-1].inst);	/* body of loop */
		((yyvsp[-9].inst))[4] = (Inst)(yyvsp[0].inst); }
    break;

  case 28:
#line 64 "book/hoc.y"
    {	/* else-less if */
		((yyvsp[-5].inst))[1] = (Inst)(yyvsp[-1].inst);	/* thenpart */
		((yyvsp[-5].inst))[3] = (Inst)(yyvsp[0].inst); }
    break;

  case 29:
#line 67 "book/hoc.y"
    {	/* if with else */
		((yyvsp[-8].inst))[1] = (Inst)(yyvsp[-4].inst);	/* thenpart */
		((yyvsp[-8].inst))[2] = (Inst)(yyvsp[-1].inst);	/* elsepart */
		((yyvsp[-8].inst))[3] = (Inst)(yyvsp[0].inst); }
    break;

  case 30:
#line 71 "book/hoc.y"
    { (yyval.inst) = (yyvsp[-1].inst); }
    break;

  case 31:
#line 73 "book/hoc.y"
    { code(STOP); }
    break;

  case 32:
#line 75 "book/hoc.y"
    { (yyval.inst) = code3(whilecode,STOP,STOP); }
    break;

  case 33:
#line 77 "book/hoc.y"
    { (yyval.inst) = code(forcode); code3(STOP,STOP,STOP); code(STOP); }
    break;

  case 34:
#line 79 "book/hoc.y"
    { (yyval.inst) = code(ifcode); code3(STOP,STOP,STOP); }
    break;

  case 35:
#line 81 "book/hoc.y"
    { (yyval.inst) = progp; }
    break;

  case 36:
#line 83 "book/hoc.y"
    { code(STOP); (yyval.inst) = progp; }
    break;

  case 37:
#line 85 "book/hoc.y"
    { (yyval.inst) = progp; }
    break;

  case 40:
#line 89 "book/hoc.y"
    { (yyval.inst) = code2(constpush, (Inst)(yyvsp[0].sym)); }
    break;

  case 41:
#line 90 "book/hoc.y"
    { (yyval.inst) = code3(varpush, (Inst)(yyvsp[0].sym), eval); }
    break;

  case 42:
#line 91 "book/hoc.y"
    { defnonly("$"); (yyval.inst) = code2(arg, (Inst)(yyvsp[0].narg)); }
    break;

  case 44:
#line 94 "book/hoc.y"
    { (yyval.inst) = (yyvsp[-3].inst); code3(call,(Inst)(yyvsp[-4].sym),(Inst)(yyvsp[-1].narg)); }
    break;

  case 45:
#line 95 "book/hoc.y"
    { (yyval.inst) = code2(varread, (Inst)(yyvsp[-1].sym)); }
    break;

  case 46:
#line 96 "book/hoc.y"
    { (yyval.inst)=(yyvsp[-1].inst); code2(bltin, (Inst)(yyvsp[-3].sym)->u.ptr); }
    break;

  case 47:
#line 97 "book/hoc.y"
    { (yyval.inst) = (yyvsp[-1].inst); }
    break;

  case 48:
#line 98 "book/hoc.y"
    { code(add); }
    break;

  case 49:
#line 99 "book/hoc.y"
    { code(sub); }
    break;

  case 50:
#line 100 "book/hoc.y"
    { code(mul); }
    break;

  case 51:
#line 101 "book/hoc.y"
    { code(divop); }
    break;

  case 52:
#line 102 "book/hoc.y"
    { code(mod); }
    break;

  case 53:
#line 103 "book/hoc.y"
    { code (power); }
    break;

  case 54:
#line 104 "book/hoc.y"
    { (yyval.inst)=(yyvsp[0].inst); code(negate); }
    break;

  case 55:
#line 105 "book/hoc.y"
    { code(gt); }
    break;

  case 56:
#line 106 "book/hoc.y"
    { code(ge); }
    break;

  case 57:
#line 107 "book/hoc.y"
    { code(lt); }
    break;

  case 58:
#line 108 "book/hoc.y"
    { code(le); }
    break;

  case 59:
#line 109 "book/hoc.y"
    { code(eq); }
    break;

  case 60:
#line 110 "book/hoc.y"
    { code(ne); }
    break;

  case 61:
#line 111 "book/hoc.y"
    { code(and); }
    break;

  case 62:
#line 112 "book/hoc.y"
    { code(or); }
    break;

  case 63:
#line 113 "book/hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code(not); }
    break;

  case 64:
#line 114 "book/hoc.y"
    { (yyval.inst) = code2(preinc,(Inst)(yyvsp[0].sym)); }
    break;

  case 65:
#line 115 "book/hoc.y"
    { (yyval.inst) = code2(predec,(Inst)(yyvsp[0].sym)); }
    break;

  case 66:
#line 116 "book/hoc.y"
    { (yyval.inst) = code2(postinc,(Inst)(yyvsp[-1].sym)); }
    break;

  case 67:
#line 117 "book/hoc.y"
    { (yyval.inst) = code2(postdec,(Inst)(yyvsp[-1].sym)); }
    break;

  case 68:
#line 119 "book/hoc.y"
    { code(prexpr); }
    break;

  case 69:
#line 120 "book/hoc.y"
    { (yyval.inst) = code2(prstr, (Inst)(yyvsp[0].sym)); }
    break;

  case 70:
#line 121 "book/hoc.y"
    { code(prexpr); }
    break;

  case 71:
#line 122 "book/hoc.y"
    { code2(prstr, (Inst)(yyvsp[0].sym)); }
    break;

  case 72:
#line 124 "book/hoc.y"
    { (yyvsp[0].sym)->type=FUNCTION; indef=1; }
    break;

  case 73:
#line 125 "book/hoc.y"
    { code(procret); define((yyvsp[-4].sym)); indef=0; }
    break;

  case 74:
#line 126 "book/hoc.y"
    { (yyvsp[0].sym)->type=PROCEDURE; indef=1; }
    break;

  case 75:
#line 127 "book/hoc.y"
    { code(procret); define((yyvsp[-4].sym)); indef=0; }
    break;

  case 79:
#line 133 "book/hoc.y"
    { (yyval.narg) = 0; }
    break;

  case 80:
#line 134 "book/hoc.y"
    { (yyval.narg) = 1; }
    break;

  case 81:
#line 135 "book/hoc.y"
    { (yyval.narg) = (yyvsp[-2].narg) + 1; }
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1721 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 137 "book/hoc.y"

	/* end of grammar */
#include <stdio.h>
#include <ctype.h>
char	*progname;
int	lineno = 1;
#include <signal.h>
#include <setjmp.h>
#include <errno.h>
jmp_buf	begin;
int	indef;
char	*infile;	/* input file name */
FILE	*fin;		/* input file pointer */
char	**gargv;	/* global argument list */
extern	errno;
int	gargc;

int c = '\n';	/* global for use by warning() */

int	backslash(int), follow(int, int, int);
void	defnonly(char*), run(void);
void	warning(char*, char*);

yylex(void)		/* hoc6 */
{
	while ((c=getc(fin)) == ' ' || c == '\t')
		;
	if (c == EOF)
		return 0;
	if (c == '\\') {
		c = getc(fin);
		if (c == '\n') {
			lineno++;
			return yylex();
		}
	}
	if (c == '#') {		/* comment */
		while ((c=getc(fin)) != '\n' && c != EOF)
			;
		if (c == '\n')
			lineno++;
		return c;
	}
	if (c == '.' || isdigit(c)) {	/* number */
		double d;
		ungetc(c, fin);
		fscanf(fin, "%lf", &d);
		yylval.sym = install("", NUMBER, d);
		return NUMBER;
	}
	if (isalpha(c) || c == '_') {
		Symbol *s;
		char sbuf[100], *p = sbuf;
		do {
			if (p >= sbuf + sizeof(sbuf) - 1) {
				*p = '\0';
				execerror("name too long", sbuf);
			}
			*p++ = c;
		} while ((c=getc(fin)) != EOF && (isalnum(c) || c == '_'));
		ungetc(c, fin);
		*p = '\0';
		if ((s=lookup(sbuf)) == 0)
			s = install(sbuf, UNDEF, 0.0);
		yylval.sym = s;
		return s->type == UNDEF ? VAR : s->type;
	}
	if (c == '$') {	/* argument? */
		int n = 0;
		while (isdigit(c=getc(fin)))
			n = 10 * n + c - '0';
		ungetc(c, fin);
		if (n == 0)
			execerror("strange $...", (char *)0);
		yylval.narg = n;
		return ARG;
	}
	if (c == '"') {	/* quoted string */
		char sbuf[100], *p;
		for (p = sbuf; (c=getc(fin)) != '"'; p++) {
			if (c == '\n' || c == EOF)
				execerror("missing quote", "");
			if (p >= sbuf + sizeof(sbuf) - 1) {
				*p = '\0';
				execerror("string too long", sbuf);
			}
			*p = backslash(c);
		}
		*p = 0;
		yylval.sym = (Symbol *)emalloc(strlen(sbuf)+1);
		strcpy((char*)yylval.sym, sbuf);
		return STRING;
	}
	switch (c) {
	case '+':	return follow('+', INC, follow('=', ADDEQ, '+'));
	case '-':	return follow('-', DEC, follow('=', SUBEQ, '-'));
	case '*':	return follow('=', MULEQ, '*');
	case '/':	return follow('=', DIVEQ, '/');
	case '%':	return follow('=', MODEQ, '%');
	case '>':	return follow('=', GE, GT);
	case '<':	return follow('=', LE, LT);
	case '=':	return follow('=', EQ, '=');
	case '!':	return follow('=', NE, NOT);
	case '|':	return follow('|', OR, '|');
	case '&':	return follow('&', AND, '&');
	case '\n':	lineno++; return '\n';
	default:	return c;
	}
}

backslash(int c)	/* get next char with \'s interpreted */
{
	static char transtab[] = "b\bf\fn\nr\rt\t";
	if (c != '\\')
		return c;
	c = getc(fin);
	if (islower(c) && strchr(transtab, c))
		return strchr(transtab, c)[1];
	return c;
}

follow(int expect, int ifyes, int ifno)	/* look ahead for >=, etc. */
{
	int c = getc(fin);

	if (c == expect)
		return ifyes;
	ungetc(c, fin);
	return ifno;
}

void
yyerror(char* s)	/* report compile-time error */
{
/*rob
	warning(s, (char *)0);
	longjmp(begin, 0);
rob*/
	execerror(s, (char *)0);
}

void
execerror(char* s, char* t)	/* recover from run-time error */
{
	warning(s, t);
	fseek(fin, 0L, 2);		/* flush rest of file */
	longjmp(begin, 0);
}

void
fpecatch(void)	/* catch floating point exceptions */
{
	execerror("floating point exception", (char *) 0);
}

void
intcatch(void)	/* catch interrupts */
{
	execerror("interrupt", (char *) 0);
}

void
run(void)	/* execute until EOF */
{
	setjmp(begin);
	signal(SIGINT, intcatch);
	signal(SIGFPE, fpecatch);
	for (initcode(); yyparse(); initcode())
		execute(progbase);
}

int
main(int argc, char* argv[])	/* hoc6 */
{
	static int first = 1;
#ifdef YYDEBUG
	extern int yydebug;
	yydebug=3;
#endif
	progname = argv[0];
	init();
	if (argc == 1) {	/* fake an argument list */
		static char *stdinonly[] = { "-" };

		gargv = stdinonly;
		gargc = 1;
	} else if (first) {	/* for interrupts */
		first = 0;
		gargv = argv+1;
		gargc = argc-1;
	}
	while (moreinput())
		run();
	signal(SIGINT, SIG_IGN);
	return 0;
}

moreinput(void)
{
	if (gargc-- <= 0)
		return 0;
	if (fin && fin != stdin)
		fclose(fin);
	infile = *gargv++;
	lineno = 1;
	if (strcmp(infile, "-") == 0) {
		fin = stdin;
		infile = 0;
	} else if ((fin=fopen(infile, "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", progname, infile);
		return moreinput();
	}
	return 1;
}

void
warning(char *s, char *t)	/* print warning message */
{
	fprintf(stderr, "%s: %s", progname, s);
	if (t)
		fprintf(stderr, " %s", t);
	if (infile)
		fprintf(stderr, " in %s", infile);
	fprintf(stderr, " near line %d\n", lineno);
	while (c != '\n' && c != EOF)
		if((c = getc(fin)) == '\n')	/* flush rest of input line */
			lineno++;
		else if (c == EOF && errno == EINTR) {
			clearerr(stdin);	/* ick! */
			errno = 0;
		}
}

void
defnonly(char *s)	/* warn if illegal definition */
{
	if (!indef)
		execerror(s, "used outside definition");
}


