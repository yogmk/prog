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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 9 "hoc.y"
typedef union YYSTYPE {
    Symbol *sym;            /* symbol table pointer */
    Inst   *inst;           /* machine instruction */
    char   *cmd;            /* passed on to shell */
} YYSTYPE;
/* Line 1403 of yacc.c.  */
#line 106 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



