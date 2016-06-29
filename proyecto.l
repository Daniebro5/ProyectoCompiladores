%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *);
#include "proyecto.tab.h"
static void comment(void);
static int check_type(void);¿
void count();
void _remove();

extern int yyparse();
int yylineno;

FILE *beamerFile;
FILE *yyin;
void yyerror(const char *s);
void beamerParseFile();
void parseFile();
void parse(FILE *filename,int type);
void createBeamerFile();
%}

caresp 		","|";"|":"|"!"|"&"|"$"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"<"|">"|"="
compar 		"<="|">="|"=="|"!="|"&&"|"||"
iden 		[a-z]([a-zA-Z]|[0-9])*
entero 		[0-9]|"-"[0-9]|"+"[0-9]
float 		[0-9]*"."[0-9]+
bool 		"True"|"False"|"true"|"false"
char 		"'"[a-zA-Z]{1}"'"
string 		\"[^\n"]+\"
coms 		"//".*?
comc 		"/*"[^"*/"]*
%%
"#include" 		return INCLUDE;
"<"[a-z]+".h>" 		return LIBRERIA;
[ \t\v\n\f]		;
"if"      		return IF;
"for"      		return FOR;
"else"     		return ELSE;
"return"  		return RETURN;
"bool"  		return TIPODEDATOBOOL;
"string"  		return TIPODEDATOSTRING;
"int"     		return TIPODEDATOENTERO;
"void"    		return TIPODEDATOVOID;
"float"   		return TIPODEDATOFLOTANTE;
"char"    		return TIPODEDATOCHAR;
"then"    		return THEN;
"while"   		return WHILE;
"void"   		return VOID;
"do"      		return DO;
"input"   		return INPUT;
"output"  		return OUTPUT;
{entero} 		return ENTERO;
{float} 		return FLOTANTE;
{bool} 			return BOOLEANO;
{caresp}		return CARRESP;
{compar} 		return COMPAR;			}
{iden} 			return IDENTIFICADOR;
{char}			return CARACTER 
{string} 		return CADENA;
\n			;
{coms} 			;
{comc} 			;
.			yyerror("invalid character");
%%

void yyerror(const char *s){
	int column=0;
	fflush(stdout);
	printf("\n%*s\n%*s in line: %d\n", column, "^", column, s, yylineno);
}

void beamerParseFile(FILE *filename){
		yyin = filename;
		yyparse();
}

void parseFile(FILE *filename){
		yyin = filename;
		yyparse();


}

void parse(FILE *filename,int type) {

	
    parseFile(filename);
  
}
