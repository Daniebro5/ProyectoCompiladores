%{
#include <stdio.h>
FILE *archSal;


%}
%option noyywrap
%option yylineno 

omitir 		" "|\t
entero 		[0-9]|"-"[0-9]|"+"[0-9]   
car 		","|";"|":"|"!"|"&"|"$"  
agrup		"("|")"|"["|"]"|"{"|"}" 
float 		[0-9]*"."[0-9]+ 
booleano 	"True"|"False"|"true"|"false"
oper		"+"|"-"|"<"|">"|"="
reserv 		"if"|"for"|"else"|"return"|"bool"|"string"|"int"|"void"|"float"|"char"|"then"|"while"|"void"|"do"|"input"|"output"
iden 		[a-z]([a-z]|[0-9])*   
compar 		"<="|">="|"=="|"!="|"&&"|"||"|"!="
char 		"'".{1}"'"
cadena 		\"[^\n"]+\"
coms 		"//".*?    
comc 		"/*"[^"*/"]* 
%%

"#include"		fprintf(archSal,"ExpresionReservada ");
"<"[a-z]+".h>"		fprintf(archSal,"Libreria ");
{omitir}*       	;
{agrup}			fprintf(archSal,"Agrupador ");
{entero}		fprintf(archSal,"Entero ");
{float}			fprintf(archSal,"NumeroDecimal ");
{booleano}		fprintf(archSal,"Booleano ");
{reserv} 		fprintf(archSal,"Palabrareservada ");
{oper}			fprintf(archSal,"Operador ");
{car}  			fprintf(archSal,"CaracterEspecial ");
{compar}		fprintf(archSal,"Comparador ");
{iden} 			fprintf(archSal,"Identificador ");
{char}			fprintf(archSal,"Caracter ");
{cadena}		fprintf(archSal,"Cadena ");
\n			fprintf(archSal,"\n"); 
{coms}			fprintf(archSal,"Comentariolinea ");
{comc}		 	fprintf(archSal,"Comentariovariaslineas");
.			fprintf(archSal,"Erroren la linea: %d",yylineno);

%%

void main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    archSal=fopen("salida.txt","w");
    yylex();
    fclose(archSal);
 }
