%{
#include <stdlib.h> 
void yyerror(char *);
int funcion();
#include "sintactico.tab.h"
%}
caresp 		","|":"|"!"|"&"|"$"|"+"|"-"|"<"|">"
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

" "|\t|\n			;
"#include" 			return INCLUDE;
"<"[a-z]+".h>" 			return LIBRERIA;
"if"      			return IF;
"for"      			return FOR;
"else"     			return ELSE;
"return"  			return RETURN;
"boolean"  			return TIPODEDATOBOOL;
"string"  			return TIPODEDATOSTRING;
"int"     			return TIPODEDATOENTERO;
"void"    			return TIPODEDATOVOID;
"float"   			return TIPODEDATOFLOTANTE;
"char"    			return TIPODEDATOCHAR;
"then"    			return THEN;
"while"   			return WHILE;
"do"      			return DO;
"input"   			return INPUT;
"output"  			return OUTPUT;
"="				return IGUAL;
[0-9]|"-"[0-9]|"+"[0-9] 	return ENTERO;
{float} 			return FLOTANTE;
{bool} 				return BOOLEANO;
{caresp}			return CARRESP;
{compar} 			return COMPAR;			
{iden} 				return IDENTIFICADOR;
{char}				return CARACTER;
{string} 			return CADENA;
";"					{return FinCommand;}
"{"					{return KEYOP;}
"}"					{return KEYCL;}
"("					{return ParetOP;}
")"					{return ParetCL;}
"["					{return BracketOP;}
"]"					{return BracketCL;}
.				yyerror("invalid character");
%%
int yywrap(void){
	return 1;
}