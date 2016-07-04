%{
#include <stdlib.h> 
void yyerror(char *);
int funcion();
#include "sintactico.tab.h"
%}
caresp 		":"|"!"|"&"|"$"
compar 		"<="|">="|"=="|"!="|"&&"|"||"|"<"|">"
iden 		[a-z]([a-zA-Z]|[0-9])*
digito 		[0-9]|"-"[0-9]|"+"[0-9]
float 		[0-9]*"."[0-9]+
bool 		"True"|"False"|"true"|"false"
char 		"'"[a-zA-Z]{1}"'"
string 		\"[^\n"]+\"
coms 		"//".*?
comc 		"/*"[^"*/"]*
tdd		"boolean"|"string"|"int"|"char"|"float"|"String"

%%

" "|\t|\n			;
"#include" 			return INCLUDE;
"<"[a-z]+".h>" 			return LIBRERIA;
"if"      			return IF;
"for"      			return FOR;
"else"     			return ELSE;
"return"  			return RETURN;
{tdd}				return TIPODEDATO;
"void"    			return VOID;

"then"    			return THEN;
"while"   			return WHILE;
"do"      			return DO;
"input"   			return INPUT;
"output"  			return OUTPUT;
"="				return IGUAL;
{digito}|"+"{digito}	 	return ENTEROPOSITIVO;
"-"{digito}+			return ENTERONEGATIVO;
{float} 			return FLOTANTE;
{bool} 				return BOOLEANO;
{caresp}			return CARRESP;
{compar} 			return COMPAR;			
{iden} 				return IDENTIFICADOR;
{char}				return CARACTER;
{string} 			return CADENA;
"+"|"-"				return MASMENOS;
"*"|"/"				return DIMULTI;
";"					{return FinCommand;}
"{"					{return KEYOP;}
"}"					{return KEYCL;}
"("					{return ParetOP;}
")"					{return ParetCL;}
"["					{return BracketOP;}
"]"					{return BracketCL;}
","				return COMA;
.				yyerror("invalid character");
%%
int yywrap(void){
	return 1;
}
