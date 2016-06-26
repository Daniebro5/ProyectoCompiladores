%{

#include <stdio.h>
#include <stdlib.h>
FILE *archSal;
void yyerror(char *);
#include "proyecto.tab.h"

%}

%option noyywrap
%option yylineno 

reservadas 		"if"|"for"|"else"|"return"|"bool"|"string"|"int"|"void"|"float"|"char"|"then"|"while"|"void"|"do"|"input"|"output"
caresp 		","|";"|":"|"!"|"&"|"$"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"<"|">"|"="
compar 		"<="|">="|"=="|"!="|"&&"|"||"
iden 		[a-z]([a-zA-Z]|[0-9])* 
entero 		[0-9]|"-"[0-9]|"+"[0-9]
float 		[0-9]*"."[0-9]+
bool 	"True"|"False"|"true"|"false"
char 		"'"[a-zA-Z]{1}"'"
string 		\"[^\n"]+\"
omitir 		" "|\t
coms 		"//".*?    
comc 		"/*"[^"*/"]* 
%%

"#include"		{fprintf(archSal,"ExpresionReservada "); return INCLUDE;}
"<"[a-z]+".h>"		{fprintf(archSal,"Libreria "); return LIBRERIA;}
{omitir}*       	{;}
{entero}		{fprintf(archSal,"Entero "); return ENTERO;}
{float}			{fprintf(archSal,"NumeroDecimal "); return FLOTANTE;}
{bool}			{fprintf(archSal,"Booleano "); return BOOLEANO;}
{reservadas} 		{fprintf(archSal,"PR ");}
{caresp}  		{fprintf(archSal,"CE ");}
{iden} 			{fprintf(archSal,"Identificador "); return IDENTIFICADOR;}
{char}			{fprintf(archSal,"Caracter ");}
{string}		{fprintf(archSal,"Cadena "); return CADENA;}
\n			{fprintf(archSal,"\n");} 
{coms}			{fprintf(archSal,"Comentariolinea ");}
{comc}		 	{fprintf(archSal,"Comentariovariaslineas");}
.			{fprintf(archSal,"Error en la linea: %d",yylineno);}

%%

void main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    archSal=fopen("salidaLexica.txt","w");
    yylex();
    fclose(archSal);
 }
