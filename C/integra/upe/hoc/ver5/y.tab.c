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
     VAR = 259,
     CONST = 260,
     BLTIN = 261,
     UNDEF = 262,
     PRINT = 263,
     WHILE = 264,
     IF = 265,
     ELSE = 266,
     FOR = 267,
     CMD = 268,
     MOD_ASGN = 269,
     MUL_ASGN = 270,
     DIV_ASGN = 271,
     SUB_ASGN = 272,
     ADD_ASGN = 273,
     UNPLUS = 274,
     OR = 275,
     AND = 276,
     LE = 277,
     GE = 278,
     NE = 279,
     EQ = 280,
     LT = 281,
     GT = 282,
     DECR = 283,
     INCR = 284,
     NOT = 285,
     UNMINUS = 286
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define VAR 259
#define CONST 260
#define BLTIN 261
#define UNDEF 262
#define PRINT 263
#define WHILE 264
#define IF 265
#define ELSE 266
#define FOR 267
#define CMD 268
#define MOD_ASGN 269
#define MUL_ASGN 270
#define DIV_ASGN 271
#define SUB_ASGN 272
#define ADD_ASGN 273
#define UNPLUS 274
#define OR 275
#define AND 276
#define LE 277
#define GE 278
#define NE 279
#define EQ 280
#define LT 281
#define GT 282
#define DECR 283
#define INCR 284
#define NOT 285
#define UNMINUS 286




/* Copy the first part of user declarations.  */
#line 1 "hoc.y"

# include "hoc.h"

# define PROMPT                printf ("hoc>")
# define code2(c1, c2)         code (c1); code (c2)
# define code3(c1, c2, c3)     code (c1); code (c2); code (c3)


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
#line 9 "hoc.y"
typedef union YYSTYPE {
    Symbol *sym;            /* symbol table pointer */
    Inst   *inst;           /* machine instruction */
    char   *cmd;            /* passed on to shell */
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 161 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 173 "y.tab.c"

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
#define YYLAST   294

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  12
/* YYNRULES -- Number of rules. */
#define YYNRULES  56
/* YYNRULES -- Number of states. */
#define YYNSTATES  107

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      43,    44,    31,    30,     2,    29,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    14,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    34,    35,    36,    37,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    19,    23,    27,
      29,    33,    37,    41,    45,    49,    53,    56,    59,    63,
      65,    68,    73,    81,    86,    91,    95,    99,   101,   103,
     105,   106,   107,   110,   113,   115,   117,   119,   121,   126,
     129,   132,   136,   140,   144,   148,   152,   156,   160,   164,
     168,   172,   176,   180,   184,   188,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      46,     0,    -1,    -1,    46,    39,    -1,    46,    47,    39,
      -1,    46,    48,    39,    -1,    46,    49,    39,    -1,    46,
      56,    39,    -1,    46,     1,    39,    -1,    13,    -1,     4,
      14,    56,    -1,     4,    19,    56,    -1,     4,    18,    56,
      -1,     4,    17,    56,    -1,     4,    16,    56,    -1,     4,
      15,    56,    -1,    35,     4,    -1,    34,     4,    -1,     5,
      40,    56,    -1,    56,    -1,     8,    56,    -1,    52,    50,
      49,    54,    -1,    52,    50,    49,    54,    11,    49,    54,
      -1,    51,    50,    49,    54,    -1,    53,    50,    49,    54,
      -1,    41,    55,    42,    -1,    43,    56,    44,    -1,     9,
      -1,    10,    -1,    12,    -1,    -1,    -1,    55,    39,    -1,
      55,    49,    -1,     3,    -1,     5,    -1,     4,    -1,    48,
      -1,     6,    43,    56,    44,    -1,    30,    56,    -1,    29,
      56,    -1,    56,    30,    56,    -1,    56,    29,    56,    -1,
      56,    31,    56,    -1,    56,    32,    56,    -1,    56,    33,
      56,    -1,    56,    38,    56,    -1,    56,    28,    56,    -1,
      56,    24,    56,    -1,    56,    27,    56,    -1,    56,    23,
      56,    -1,    56,    26,    56,    -1,    56,    25,    56,    -1,
      56,    21,    56,    -1,    56,    22,    56,    -1,    36,    56,
      -1,    43,    56,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    27,    27,    28,    29,    30,    31,    32,    33,    36,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    50,
      51,    52,    56,    62,    67,    72,    75,    78,    81,    84,
      87,    90,    91,    92,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VAR", "CONST", "BLTIN",
  "UNDEF", "PRINT", "WHILE", "IF", "ELSE", "FOR", "CMD", "'='", "MOD_ASGN",
  "MUL_ASGN", "DIV_ASGN", "SUB_ASGN", "ADD_ASGN", "UNPLUS", "OR", "AND",
  "LE", "GE", "NE", "EQ", "LT", "GT", "'-'", "'+'", "'*'", "'/'", "'%'",
  "DECR", "INCR", "NOT", "UNMINUS", "'^'", "'\\n'", "\"=\"", "'{'", "'}'",
  "'('", "')'", "$accept", "list", "command", "asgn", "stmt", "cond",
  "while", "if", "for", "end", "stmtlist", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    61,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    45,
      43,    42,    47,    37,   283,   284,   285,   286,    94,    10,
     287,   123,   125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    46,    46,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    49,    49,    49,    49,    50,    51,    52,    53,
      54,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       2,     4,     7,     4,     4,     3,     3,     1,     1,     1,
       0,     0,     2,     2,     1,     1,     1,     1,     4,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     0,     1,     0,    34,    36,    35,     0,     0,    27,
      28,    29,     9,     0,     0,     0,     0,     0,     3,    31,
       0,     0,    37,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    20,    40,
      39,    17,    16,    55,     0,     0,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,    10,    15,
      14,    13,    12,    11,    18,     0,    32,    25,    33,    19,
      56,     0,    30,    30,    30,    53,    54,    50,    48,    52,
      51,    49,    47,    42,    41,    43,    44,    45,    46,    38,
      26,    23,    21,    24,     0,    30,    22
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     1,    21,    37,    23,    50,    24,    25,    26,   101,
      44,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -83
static const short int yypact[] =
{
     -83,    37,   -83,   -33,   -83,   275,   -29,   -26,   127,   -83,
     -83,   -83,   -83,   127,   127,    11,    14,   127,   -83,   -83,
     127,   -15,   -14,   -13,   -16,   -16,   -16,   198,   -83,   127,
     127,   127,   127,   127,   127,   127,   127,   -83,   217,    -2,
     217,   -83,   -83,    -2,    78,   116,   -83,   -83,   -83,   127,
      93,    93,    93,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   -83,   217,   217,
     217,   217,   217,   217,   217,   150,   -83,   -83,   -83,   217,
     -83,   174,   -83,   -83,   -83,   234,   250,    62,    62,    62,
      62,    62,    62,   -28,   -28,    -2,    -2,    -2,    -2,   -83,
     -83,   -83,    28,   -83,    93,   -83,   -83
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -83,   -83,   -83,    43,   -30,   -17,   -83,   -83,   -83,   -82,
     -83,    -1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      27,   102,   103,    63,    64,    65,    28,    38,    51,    52,
      66,    35,    39,    40,    78,    41,    43,    36,    42,    45,
      82,    83,    84,   106,    46,    47,    48,    49,    68,    69,
      70,    71,    72,    73,    74,    75,    66,     2,     3,   104,
       4,     5,     6,     7,    22,     8,     9,    10,    81,    11,
      12,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    13,    14,     0,     0,
       0,    15,    16,    17,   105,     0,    18,     0,    19,     0,
      20,     4,     5,     6,     7,     0,     8,     9,    10,     0,
      11,    61,    62,    63,    64,    65,     4,     5,     6,     7,
      66,     8,     9,    10,     0,    11,     0,    13,    14,     0,
       0,     0,    15,    16,    17,     0,     0,    76,     0,    19,
      77,    20,    13,    14,     0,     0,     0,    15,    16,    17,
       4,     5,     6,     7,    19,     0,    20,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,     0,     0,     0,    66,     0,    13,    14,     0,     0,
      80,    15,    16,    17,     0,     0,     0,     0,     0,     0,
      20,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,    99,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,   100,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,     0,    66,    67,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,    66,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,    66,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,    66,    29,
      30,    31,    32,    33,    34
};

static const yysigned_char yycheck[] =
{
       1,    83,    84,    31,    32,    33,    39,     8,    25,    26,
      38,    40,    13,    14,    44,     4,    17,    43,     4,    20,
      50,    51,    52,   105,    39,    39,    39,    43,    29,    30,
      31,    32,    33,    34,    35,    36,    38,     0,     1,    11,
       3,     4,     5,     6,     1,     8,     9,    10,    49,    12,
      13,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    29,    30,    -1,    -1,
      -1,    34,    35,    36,   104,    -1,    39,    -1,    41,    -1,
      43,     3,     4,     5,     6,    -1,     8,     9,    10,    -1,
      12,    29,    30,    31,    32,    33,     3,     4,     5,     6,
      38,     8,     9,    10,    -1,    12,    -1,    29,    30,    -1,
      -1,    -1,    34,    35,    36,    -1,    -1,    39,    -1,    41,
      42,    43,    29,    30,    -1,    -1,    -1,    34,    35,    36,
       3,     4,     5,     6,    41,    -1,    43,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    29,    30,    -1,    -1,
      44,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    14,
      15,    16,    17,    18,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    46,     0,     1,     3,     4,     5,     6,     8,     9,
      10,    12,    13,    29,    30,    34,    35,    36,    39,    41,
      43,    47,    48,    49,    51,    52,    53,    56,    39,    14,
      15,    16,    17,    18,    19,    40,    43,    48,    56,    56,
      56,     4,     4,    56,    55,    56,    39,    39,    39,    43,
      50,    50,    50,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    38,    39,    56,    56,
      56,    56,    56,    56,    56,    56,    39,    42,    49,    56,
      44,    56,    49,    49,    49,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    44,
      44,    54,    54,    54,    11,    49,    54
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
        case 3:
#line 28 "hoc.y"
    { PROMPT; }
    break;

  case 5:
#line 30 "hoc.y"
    { code(STOP); return 1; }
    break;

  case 6:
#line 31 "hoc.y"
    { code(STOP); PROMPT; return 1; }
    break;

  case 7:
#line 32 "hoc.y"
    { code2(print, STOP); PROMPT; return 1; }
    break;

  case 8:
#line 33 "hoc.y"
    { yyerrok; PROMPT; }
    break;

  case 9:
#line 36 "hoc.y"
    { shell((yyvsp[0].cmd)); PROMPT; }
    break;

  case 10:
#line 39 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code3(varpush, (Inst)(yyvsp[-2].sym), assign); }
    break;

  case 11:
#line 40 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code3(varpush, (Inst)(yyvsp[-2].sym), add_assign); }
    break;

  case 12:
#line 41 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code3(varpush, (Inst)(yyvsp[-2].sym), sub_assign); }
    break;

  case 13:
#line 42 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code3(varpush, (Inst)(yyvsp[-2].sym), div_assign); }
    break;

  case 14:
#line 43 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code3(varpush, (Inst)(yyvsp[-2].sym), mul_assign); }
    break;

  case 15:
#line 44 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code3(varpush, (Inst)(yyvsp[-2].sym), mod_assign); }
    break;

  case 16:
#line 45 "hoc.y"
    { (yyval.inst) = (yyvsp[0].sym); code3(varpush, (Inst)(yyvsp[0].sym), incr); }
    break;

  case 17:
#line 46 "hoc.y"
    { (yyval.inst) = (yyvsp[0].sym); code3(varpush, (Inst)(yyvsp[0].sym), decr); }
    break;

  case 18:
#line 47 "hoc.y"
    { execerror ("won't assign to non-variable", (yyvsp[-2].sym)->name); }
    break;

  case 19:
#line 50 "hoc.y"
    { /*code(pop)*/; }
    break;

  case 20:
#line 51 "hoc.y"
    { code(print); (yyval.inst) = (yyvsp[0].inst); }
    break;

  case 21:
#line 52 "hoc.y"
    {                              /* simple (else-less) if */
                              ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);          /* pointer to if body */
                              ((yyvsp[-3].inst))[3] = (Inst)(yyvsp[0].inst);          /* end, if cond fails */
                            }
    break;

  case 22:
#line 57 "hoc.y"
    {
                              ((yyvsp[-6].inst))[1] = (Inst)(yyvsp[-4].inst);          /* pointer to if body */
                              ((yyvsp[-6].inst))[2] = (Inst)(yyvsp[-1].inst);          /* pointer to else body */
                              ((yyvsp[-6].inst))[3] = (Inst)(yyvsp[0].inst);          /* end, if cond fails */
                            }
    break;

  case 23:
#line 63 "hoc.y"
    {                              /* ($1)[0] has pointer to whilecode() */
                              ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);          /* pointer to body of loop */
                              ((yyvsp[-3].inst))[2] = (Inst)(yyvsp[0].inst);          /* end, if cond fails */
                            }
    break;

  case 24:
#line 68 "hoc.y"
    {
                              ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);          /* pointer to body of loop */
                              ((yyvsp[-3].inst))[2] = (Inst)(yyvsp[0].inst);          /* pointer to next stmt after for(..) loop */
                            }
    break;

  case 25:
#line 72 "hoc.y"
    { (yyval.inst) = (yyvsp[-1].inst); }
    break;

  case 26:
#line 75 "hoc.y"
    { code(STOP); (yyval.inst) = (yyvsp[-1].inst); }
    break;

  case 27:
#line 78 "hoc.y"
    { (yyval.inst) = code3 (whilecode, STOP, STOP); }
    break;

  case 28:
#line 81 "hoc.y"
    { (yyval.inst) = code(ifcode); code3(STOP, STOP, STOP); }
    break;

  case 29:
#line 84 "hoc.y"
    { (yyval.inst) = code(forcode, STOP, STOP); }
    break;

  case 30:
#line 87 "hoc.y"
    { code(STOP); (yyval.inst) = progp; }
    break;

  case 31:
#line 90 "hoc.y"
    { (yyval.inst) = progp; }
    break;

  case 34:
#line 95 "hoc.y"
    { (yyval.inst) = code2(constpush, (Inst)(yyvsp[0].sym)); }
    break;

  case 35:
#line 96 "hoc.y"
    { (yyval.inst) = code3(varpush, (Inst)(yyvsp[0].sym), eval); }
    break;

  case 36:
#line 97 "hoc.y"
    { (yyval.inst) = code3(varpush, (Inst)(yyvsp[0].sym), eval); }
    break;

  case 38:
#line 99 "hoc.y"
    { (yyval.inst) = (yyvsp[-1].inst); code2(bltin, (Inst)(yyvsp[-3].sym)->u.ptr); }
    break;

  case 39:
#line 100 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); }
    break;

  case 40:
#line 101 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code(neg); }
    break;

  case 41:
#line 102 "hoc.y"
    { code(add); }
    break;

  case 42:
#line 103 "hoc.y"
    { code(sub); }
    break;

  case 43:
#line 104 "hoc.y"
    { code(mul); }
    break;

  case 44:
#line 105 "hoc.y"
    { code(dvd); }
    break;

  case 45:
#line 106 "hoc.y"
    { code(mod); }
    break;

  case 46:
#line 107 "hoc.y"
    { code(power); }
    break;

  case 47:
#line 108 "hoc.y"
    { code(gt); }
    break;

  case 48:
#line 109 "hoc.y"
    { code(ge); }
    break;

  case 49:
#line 110 "hoc.y"
    { code(lt); }
    break;

  case 50:
#line 111 "hoc.y"
    { code(le); }
    break;

  case 51:
#line 112 "hoc.y"
    { code(eq); }
    break;

  case 52:
#line 113 "hoc.y"
    { code(ne); }
    break;

  case 53:
#line 114 "hoc.y"
    { code(or); }
    break;

  case 54:
#line 115 "hoc.y"
    { code(and); }
    break;

  case 55:
#line 116 "hoc.y"
    { (yyval.inst) = (yyvsp[0].inst); code(not); }
    break;

  case 56:
#line 117 "hoc.y"
    { (yyval.inst) = (yyvsp[-1].inst); }
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1550 "y.tab.c"

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


#line 119 "hoc.y"

     /* end of grammar */

# include <stdio.h>
# include <ctype.h>
# include <signal.h>
# include <setjmp.h>

char *progname;
int lineno = 1;
jmp_buf begin;
int TRACE_ON = 0;

int
main (int argc, char **argv)
{
    void catch_fpe(), bannar (), init ();
    progname = argv[0];
    int showBannar = 1, i = 0, k = 0;
    unsigned char c = 0;

    /** parse command line arguments */
    if (argc > 1)
    {
        for (i = 1; i < argc; i++)      /* for each arg */
        {
            k = 0;
            while (c = *(argv[i]+k))         /* walk over the characters */
            {
                switch (c)
                {
                     case '-': break;     /* ignore */
                     case 'q':            /* quite, no bannar */
                               showBannar = 0;
                               break;
                     case 't':            /* trace the execution */
                               TRACE_ON = 1;
                               break;
                     default: 
                               printf ("Invalid option %c\n", c);
                               break;
                }
                ++k;
            }
        }
    }

    if (showBannar) bannar();
    init ();
    setjmp (begin);
    signal (SIGFPE, catch_fpe);
    

    /* parse now returns after each 
     * stmt or expr instead of token i */

    for (initcode (); yyparse (); initcode ())
        execute (prog);
    return 0;
}

# ifndef _LEX_VER_

int
yylex (void)
{
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;
    if (c == EOF)
        return 0;

    /* 
     * a shell command? 
     */
    if (c == ':')
    {                 /* do not ungetc ':' */
        char buf[100];
        yylval.cmd = malloc (sizeof buf);
        fgets (yylval.cmd, sizeof buf, stdin);
        yylval.cmd [strlen(yylval.cmd)] = '\0';    /* overwrite '\n' */
        return CMD;
    }

    /**
     * Number:
     *       unlike earlier versions (consuming the number), 
     *       push it on the stack
     */
    if (c == '.' || isdigit (c))        
    {
        double d;
        ungetc (c, stdin);
        scanf ("%lf", &d);
        yylval.sym = install ("", NUMBER, d);
        return NUMBER;
    }

    /**
     * Variable
     */
    if (isalpha (c))
    {
        Symbol *s;
        char buf[100], *p = buf;

        do
        {
          *p++ = c;
        } while ((c=getchar()) != EOF && isalnum(c));
        ungetc (c, stdin);
        *p = '\0';

        if ((s = lookup (buf)) == 0)
            s = install (buf, UNDEF, 0.0);

        yylval.sym = s;
        return s->type == UNDEF ? VAR : s->type; 
    }
    

    /**
     * Operator
     */
    switch (c)
    {
        case '>':    return follow ('=', GE, GT);
        case '<':    return follow ('=', LE, LT);
        case '=':    return follow ('=', EQ, '=');
        case '!':    return follow ('=', NE, NOT);
        case '|':    return follow ('|', OR, '|');
        case '&':    return follow ('=', AND, '&');
        case '/':    return follow ('=', DIV_ASGN, '/');
        case '*':    return follow ('=', MUL_ASGN, '*');
        case '%':    return follow ('=', MOD_ASGN, '%');
        case '+':    if (ADD_ASGN == follow ('=', ADD_ASGN, '+'))   
                         return ADD_ASGN;
                     else
                         return follow ('+', INCR, '+');
        case '-':    if (SUB_ASGN == follow ('=', SUB_ASGN, '-'))
                         return SUB_ASGN;                           /* -= or */
                     else
                         return follow ('-', DECR, '-');            /* -- */
        case '\n':    lineno++; return '\n';
        default :   return c;
    }
}

int 
follow (int expect, int ifyes, int ifno)
{
    int c = getchar ();

    if (c == expect)
        return ifyes;
    ungetc (c, stdin);
    return ifno;
}
# endif

yyerror (char *s)
{
    warning (s, (char*) 0);
}

execerror (char *s, char *t)
{
    warning (s, t);
    longjmp (begin, 0);
}

warning (char *s, char *t)
{
    fprintf (stderr, "%s: %s", progname, s);
    if (t)
        fprintf (stderr, " %s", t);
    fprintf (stderr, " near line %d\n", lineno);
}


catch_fpe ()
{
    execerror ("floating point exception", (void *) 0);
}

void
bannar(void)
{

     puts ("    ****************************************************************   ");
     puts ("    * hoc: a calculator program from the book 'The Unix            * * ");
     puts ("    * Programming Environment'  -- Karnighan and Pike.             ****");
     puts ("    *                                                                 *");
# ifdef _LEX_VER_
     puts ("    * This is a 'lex' version of 'hoc'.\n                             *");
# endif
     puts ("    * supports:                                                       *");
     puts ("    * 1. Operators '+', '-', '*', '/'.                                *");
     puts ("    * 2. unary '-', '%' and unary '+' (exercise 8.2).                 *");
     puts ("    * 3. Varibale names 'a'...'z'                                     *"); 
     puts ("    * 4. Exponentiation operator '^', arbitrary variable names.       *");
     puts ("    * 5. prevent assignment to constants (8.5)                        *");
     puts ("    * 6. rand () and atan2 () (8.6),                                  *");
     puts ("    * 7. execute unix shell commands from within hoc (8.7)            *");
     puts ("    * 8. Full set of relational operators and control flow.           *");
     puts ("    *******************************************************************");
}

