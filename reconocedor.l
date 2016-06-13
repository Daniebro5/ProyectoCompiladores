%{

#include <stdio.h>
FILE *archSal;

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

"#include"		fprintf(archSal,"ExpresionReservada ");
"<"[a-z]+".h>"		fprintf(archSal,"Libreria ");
{omitir}*       	;
{entero}		fprintf(archSal,"Entero ");
{float}			fprintf(archSal,"NumeroDecimal ");
{bool}			fprintf(archSal,"Booleano ");
{reservadas} 		fprintf(archSal,"PR ");
{caresp}  		fprintf(archSal,"CE ");
{iden} 			fprintf(archSal,"Identificador ");
{char}			fprintf(archSal,"Caracter ");
{string}		fprintf(archSal,"Cadena ");
\n			fprintf(archSal,"\n"); 
{coms}			fprintf(archSal,"Comentariolinea ");
{comc}		 	fprintf(archSal,"Comentariovariaslineas");
.			fprintf(archSal,"Error en la linea: %d",yylineno);

%%

void main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    archSal=fopen("salida.txt","w");
    yylex();
    fclose(archSal);
 }
