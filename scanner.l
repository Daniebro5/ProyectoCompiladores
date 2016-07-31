%{
	#include <string.h>	
	#include <stdlib.h>	
	#include "parser.tab.h"
	
	int lines=1, chars=0, errors=0;

	void count_lb(char *str, int leng, int *c, int *l);
%}

 /* Digitos y numeros */
digit 		[0-9]
num		{digit}+
real		{digit}+\.{digit}+

 /* Letras e Identificadores */
letter 		[a-zA-Z]
id     		("_"|{letter})("_"|{letter}|{digit})*

 /* Operadores logicos y matemáticos */
logicop		("!"|"<"|">"|"=="|"&&"|"||")
mathop		("+"|"-"|"*"|"/"|"++"|"--")
attribution	("=")

 /* Espacios en Blanco */
horizontal	[" "\t]
linebreak	\n|\v\r

 /* Delimitadores y fin de linea */
dscope		"{"|"}"|"("|")"|"["|"]"
dstmt		[,;]

 /* Cadenas y Comentarios  */
comment		("//".*\n)
string		(\"[^\"]*\")

%option noyywrap
%option noinput
%option nounput


%%

 /*	palabras reservadas	*/
main	{ chars += yyleng; return (MAIN); }
if	{ chars += yyleng; return (IF); }
else	{ chars += yyleng; return (ELSE); }
do	{ chars += yyleng; return (DO); }
while	{ chars += yyleng; return (WHILE); }
for	{ chars += yyleng; return (FOR); }
break	{ chars += yyleng; return (BREAK); }
print 	{ chars += yyleng; return (PRINT); }
return	{ chars += yyleng; return (RETURN); }


 /*	comentario	*/
{comment} { lines++; }


 /*	tipos de datos	*/
int {
	chars += yyleng;
	return (INT_TYPE);
}

float {
	chars += yyleng;
	return (FLOAT_TYPE);
}


 /*	Identificador Inválido	*/
({num}|{real}){id} {
	printf("( %3d : %-3d ) id inválido: %s\n", lines, chars, yytext);
	chars += yyleng;
	errors++;
}


 /*	numeros	*/
{num} {
	yylval.integer = (int)atoi(yytext);
	chars += yyleng;
	return (INTEGER);
}

{real} {
	yylval.real = (float)atof(yytext);
	chars += yyleng;
	return (REAL);
}


 /*	Identificador	*/
{id} {
	yylval.lexeme = (char *)strdup(yytext);
	chars += yyleng;
	return (ID);
}


 /*	Operadores	*/
"+" |
"-" |
"*" |
"/" { chars++; return yytext[0]; }

"++" { chars+=yyleng; return MATH_INC; }
"--" { chars+=yyleng; return MATH_DEC; }

"<"  { chars+=yyleng; return LOG_LT; } /* menor que */
">"  { chars+=yyleng; return LOG_GT; } /* mayor que */
"==" { chars+=yyleng; return LOG_EQL; } /* comparador de igualdad */
"&&" { chars+=yyleng; return LOG_AND; } /* and lógico */
"||" { chars+=yyleng; return LOG_OR; } /* or lógico */
"!"  { chars+=yyleng; return LOG_NOT; } /* negación lógica */

{attribution} { chars++; return (yytext[0]); }

 /*	Delimitadores	*/
({dscope}|{dstmt}) { chars++; return (yytext[0]); }


 /*	Otros	*/
{string} { count_lb(yytext, yyleng, &chars, &lines); return (STRING); }

{horizontal} { chars++; }

{linebreak} {
	chars = 0;
	lines++;
}


 /*	Errores		*/
. {
	printf("( %3d : %-3d ) token no reconocido\n", lines, chars);
	chars++;
	errors++;
}

%%

// Contador de lineas
void count_lb(char *str, int leng, int *c, int *l) {
	int i;

	for(i=0; i<leng; i++) {
		(*c)++;
		if(str[i] == '\n') {
			(*l)++;
			*c = 0;
		}
	}
}
