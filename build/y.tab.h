/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_Y_TAB_H_INCLUDED
# define YY_YY_BUILD_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER_LITERAL = 259,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 260,           /* FLOAT_LITERAL  */
    PROGRAM = 261,                 /* PROGRAM  */
    BEGIN_ = 262,                  /* BEGIN_  */
    END = 263,                     /* END  */
    DECLARE = 264,                 /* DECLARE  */
    AS = 265,                      /* AS  */
    INTEGER_TYPE = 266,            /* INTEGER_TYPE  */
    FLOAT_TYPE = 267,              /* FLOAT_TYPE  */
    FOR = 268,                     /* FOR  */
    TO = 269,                      /* TO  */
    DOWNTO = 270,                  /* DOWNTO  */
    ENDFOR = 271,                  /* ENDFOR  */
    IF = 272,                      /* IF  */
    THEN = 273,                    /* THEN  */
    ELSE = 274,                    /* ELSE  */
    ENDIF = 275,                   /* ENDIF  */
    PRINT = 276,                   /* PRINT  */
    ASSIGN = 277,                  /* ASSIGN  */
    SEMICOLON = 278,               /* SEMICOLON  */
    COMMA = 279,                   /* COMMA  */
    LPAREN = 280,                  /* LPAREN  */
    RPAREN = 281,                  /* RPAREN  */
    LBRACKET = 282,                /* LBRACKET  */
    RBRACKET = 283,                /* RBRACKET  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    MULTIPLY = 286,                /* MULTIPLY  */
    DIVIDE = 287,                  /* DIVIDE  */
    GE = 288,                      /* GE  */
    LE = 289,                      /* LE  */
    GT = 290,                      /* GT  */
    LT = 291,                      /* LT  */
    EQ = 292,                      /* EQ  */
    NE = 293,                      /* NE  */
    UMINUS = 294                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTEGER_LITERAL 259
#define FLOAT_LITERAL 260
#define PROGRAM 261
#define BEGIN_ 262
#define END 263
#define DECLARE 264
#define AS 265
#define INTEGER_TYPE 266
#define FLOAT_TYPE 267
#define FOR 268
#define TO 269
#define DOWNTO 270
#define ENDFOR 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define PRINT 276
#define ASSIGN 277
#define SEMICOLON 278
#define COMMA 279
#define LPAREN 280
#define RPAREN 281
#define LBRACKET 282
#define RBRACKET 283
#define PLUS 284
#define MINUS 285
#define MULTIPLY 286
#define DIVIDE 287
#define GE 288
#define LE 289
#define GT 290
#define LT 291
#define EQ 292
#define NE 293
#define UMINUS 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "src/parser.y"

    int intval;
    float floatval;
    char* strval;
    struct {
        char* addr;
        char* type;
    } expr;
    struct {
        char* text;
        int is_array;
        int array_size;
    } id_attr;

#line 160 "build/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_Y_TAB_H_INCLUDED  */
