/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    VOID = 266,
    THEN = 267,
    WHILE = 268,
    DO = 269,
    INPUT = 270,
    OUTPUT = 271,
    ENTEROPOSITIVO = 272,
    ENTERONEGATIVO = 273,
    FLOTANTE = 274,
    BOOLEANO = 275,
    CARRESP = 276,
    COMPAR = 277,
    IDENTIFICADOR = 278,
    CARACTER = 279,
    CADENA = 280,
    MASMENOS = 281,
    DIMULTI = 282,
    COMA = 283,
    KEYOP = 284,
    KEYCL = 285,
    ParetOP = 286,
    ParetCL = 287,
    BracketOP = 288,
    BracketCL = 289,
    FinCommand = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "sintactico.y" /* yacc.c:1909  */

char* tipo;
char* identificador;
char* voi;

#line 96 "sintactico.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */
