%{
	 #include <stdio.h>
	#include <stdlib.h> 
    int yylex(void); 
    void yyerror(char *);
extern FILE *yyin;
 FILE *archSal;
%}

%token INCLUDE
%token IGUAL
%token LIBRERIA
%token IF
%token FOR
%token ELSE
%token RETURN
%token TIPODEDATOBOOL
%token TIPODEDATOSTRING
%token TIPODEDATOENTERO
%token TIPODEDATOVOID
%token TIPODEDATOFLOTANTE
%token TIPODEDATOCHAR
%token THEN
%token WHILE
%token DO
%token INPUT
%token OUTPUT
%token ENTERO
%token FLOTANTE
%token BOOLEANO
%token CARRESP
%token COMPAR
%token IDENTIFICADOR
%token CARACTER 
%token CADENA


%start programa
%%


funcion:
		IDENTIFICADOR "(" declaracionParametro ")" ";"
		|tipoDeDato IDENTIFICADOR "(" declaracionParametro ")" "{" sentencia "}"
		|""
		;
declaracionG:
		declaracionLibreria
		|declaracionFuncion
		|declaracionVariable
		;
declaracionLibreria:
		INCLUDE LIBRERIA					{fprintf(archSal,"libreria la concha de tu hermana");}
		;
declaracionVariable:
		TIPODEDATOBOOL IDENTIFICADOR IGUAL BOOLEANO ";" 	{fprintf(archSal,"declaracionbooleano");}
		|TIPODEDATOSTRING IDENTIFICADOR IGUAL CADENA ";"	{fprintf(archSal,"declaracioncadena");}
		|TIPODEDATOENTERO IDENTIFICADOR IGUAL ENTERO ";"	{fprintf(archSal,"declaracionentero");}
		|TIPODEDATOFLOTANTE IDENTIFICADOR IGUAL FLOTANTE ";"	{fprintf(archSal,"declaracionflotante");}
		|TIPODEDATOCHAR IDENTIFICADOR IGUAL CARACTER ";"	{fprintf(archSal,"declaracioncaracter");}
		|tipoDeDato IDENTIFICADOR IGUAL IDENTIFICADOR ";"	{fprintf(archSal,"declaracionigualacion");}
		;
declaracionFuncion:
		TIPODEDATOBOOL IDENTIFICADOR "(" declaracionParametro ")" ";" 	{fprintf(archSal,"declaracionbooleano");}
		|TIPODEDATOSTRING IDENTIFICADOR IGUAL CADENA "(" declaracionParametro ")" ";"	{fprintf(archSal,"declaracioncadena");}
		|TIPODEDATOENTERO IDENTIFICADOR IGUAL ENTERO "(" declaracionParametro ")" ";"	{fprintf(archSal,"declaracionentero");}
		|TIPODEDATOFLOTANTE IDENTIFICADOR IGUAL FLOTANTE "(" declaracionParametro ")" ";"	{fprintf(archSal,"declaracionflotante");}
		|TIPODEDATOCHAR IDENTIFICADOR IGUAL CARACTER "(" declaracionParametro ")" ";"	{fprintf(archSal,"declaracioncaracter");}
		|tipoDeDato IDENTIFICADOR IGUAL IDENTIFICADOR "(" declaracionParametro ")" ";"	{fprintf(archSal,"declaracionigualacion");}
		;
declaracionParametro:
		tipoDeDato IDENTIFICADOR
		;
tipoDeDato:
		TIPODEDATOBOOL
		|TIPODEDATOSTRING
		|TIPODEDATOENTERO
		|TIPODEDATOFLOTANTE
		|TIPODEDATOCHAR
		;
sentencia:
		declaracionVariable
		|funcion
		;
main:
		tipoDeDato "main" "(" declaracionParametro ")" "{" sentencia "}"{fprintf(archSal,"main damier");}
		;
programa:
		declaracionG main funcion		{fprintf(archSal,"funciona :)");}
		;

%%
void yyerror(char *s) { 
    fprintf(stderr, "%s\n", s); 
} 
void main(void) { 
	yyin=fopen("entrada.txt","r");
	archSal=fopen("salidaSintactica.txt","w");
    	yyparse();  
	fclose(archSal);
} 



