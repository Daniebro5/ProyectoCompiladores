%{
#include <stdio.h>
#include <stdlib.h>
FILE *archSal;
void yyerror(char *);
#include "proyecto.tab.h"
%}
%option noyywrap
%option yylineno
if "if"
for "for"
else "else"
return "return"
bool "bool"
string "string"
int "int"
void "void"
float "float"
char "char"
then "then"
while "while"
void "void"
do "do"
input "input"
output "output"
caresp ","|";"|":"|"!"|"&"|"$"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"<"|">"|"="
compar "<="|">="|"=="|"!="|"&&"|"||"
iden [a-z]([a-zA-Z]|[0-9])*
entero [0-9]|"-"[0-9]|"+"[0-9]
float [0-9]*"."[0-9]+
bool "True"|"False"|"true"|"false"
char "'"[a-zA-Z]{1}"'"
string \"[^\n"]+\"
omitir " "|\t
coms "//".*?
comc "/*"[^"*/"]*
%%
"#include" {fprintf(archSal,"ExpresionReservada "); return INCLUDE;}
"<"[a-z]+".h>" {fprintf(archSal,"Libreria "); return LIBRERIA;}
{omitir}* {;}
{if}      {fprint(archSal,"if"); return IF;}}
{for}      {fprint(archSal,"for"); return FOR;}
{else}      {fprint(archSal,"if"); return ELSE;}
{return}      {fprint(archSal,"if"); return RETURN;}
{bool}      {fprint(archSal,"bool"); return TIPODEDATOBOOL;}
{string}      {fprint(archSal,"string"); return TIPODEDATOSTRING;}
{int}      {fprint(archSal,"int"); return TIPODEDATOENTERO;}
{void}      {fprint(archSal,"void"); return TIPODEDATOVOID;}
{float}      {fprint(archSal,"float"); return TIPODEDATOFLOTANTE;}
{char}      {fprint(archSal,"char"); return TIPODEDATOCHAR;}
{then}      {fprint(archSal,"then"); return THEN;}
{while}      {fprint(archSal,"while"); return WHILE;}
{void}      {fprint(archSal,"void"); return VOID;}
{do}      {fprint(archSal,"do"); return DO;}
{input}      {fprint(archSal,"input"); return INPUT;}
{output}      {fprint(archSal,"output"); return OUTPUT;}
{entero} {fprintf(archSal,"Entero "); return ENTERO;}
{float} {fprintf(archSal,"NumeroDecimal "); return FLOTANTE;}
{bool} {fprintf(archSal,"Booleano "); return BOOLEANO;}
{caresp} {fprintf(archSal,"CE ");return CARRESP;}
{compar} {fprintf(archSal,"COMPAR ");return COMPAR;			}
{iden} {fprintf(archSal,"Identificador "); return IDENTIFICADOR;}
{char} {fprintf(archSal,"Caracter ");}
{string} {fprintf(archSal,"Cadena "); return CADENA;}
\n {fprintf(archSal,"\n");}
{coms} {fprintf(archSal,"Comentariolinea ");}
{comc} {fprintf(archSal,"Comentariovariaslineas");}
. {fprintf(archSal,"Error en la linea: %d",yylineno);}
%%
void main(int argc,char *argv[]){
yyin=fopen(argv[1],"r");
archSal=fopen("salidaLexica.txt","w");
yylex();
fclose(archSal);
}
