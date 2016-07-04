
%{
	#include <stdlib.h> 
	void yyerror(char *);
	int funcion();
	#include "sintactico.tab.h"
	int linea=0;
	
%}

caresp 		":"|"!"|"&"|"$"
compar 		"<="|">="|"=="|"!="|"&&"|"||"|"<"|">"
iden 		[a-z]([a-zA-Z]|[0-9])*
digito 		[0-9]
float 		[0-9]*"."[0-9]+
bool 		"True"|"False"|"true"|"false"
char 		"'"[a-zA-Z]{1}"'"
string 		\"[^\n"]+\"
coms 		"//".*?
comc 		"/*"[^"*/"]*


%%

"#include" 			return INCLUDE;
"<"[a-z]+".h>" 			return LIBRERIA;
"if"      			return IF;
"for"      			return FOR;
"else"     			return ELSE;
"return"  			return RETURN;
"int"				return TIPODEDATOENTERO;
"boolean"			return TIPODEDATOBOOL;
"string"			return TIPODEDATOSTRING;
"char"				return TIPODEDATOCHAR;
"float"				return TIPODEDATOFLOTANTE;
"String"			return TIPODEDATOSTRING;
"void"    			return VOID;
"then"    			return THEN;
"while"   			return WHILE;
"do"      			return DO;
"input"   			return INPUT;
"output"  			return OUTPUT;
{iden} 				{return IDENTIFICADOR;}
"="				return IGUAL;
{digito}+|"+"{digito}+	 	return ENTEROPOSITIVO;
"-"{digito}+			return ENTERONEGATIVO;
{float} 			return FLOTANTE;
{bool} 				return BOOLEANO;
{caresp}			return CARRESP;
{compar} 			return COMPAR;			
{char}				return CARACTER;
{string} 			return CADENA;
"+"|"-"				return MASMENOS;
"*"|"/"				return DIMULTI;
";"				return FinCommand;
"{"				return KEYOP;
"}"				return KEYCL;
"("				return ParetOP;
")"				return ParetCL;
"["				return BracketOP;
"]"				return BracketCL;
","				return COMA;
" "|\t				;
\n				{linea++;};
.				yyerror("invalid character");
%%

	int yywrap(void){
		return 1;
	}
