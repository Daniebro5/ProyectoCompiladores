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

%token KEYOP
%token KEYCL

%token ParetOP
%token ParetCL

%token BracketOP
%token BracketCL
%token FinCommand

%start programa
%%

programa:
		declaracionG {fprintf(archSal,"DeclaracionesGlobales");}
		|funcion  {fprintf(archSal,"DeclaracionesdeFuncion");}
		|main		
				;

//declaracionG: TIPODEDATOENTERO IDENTIFICADOR IGUAL IDENTIFICADOR FinCommand	{fprintf(archSal,"declaracionEntero");};

//libreria: INCLUDE LIBRERIA FinCommand ;    																																																																	
funcion:
		IDENTIFICADOR ParetOP declaracionParametro ParetCL FinCommand
		| IDENTIFICADOR ParetOP declaracionParametro ParetCL "{" sentencia "}"
		;
declaracionG:
		declaracionLibreria
		|declaracionFuncion
		|declaracionVariable
		;
declaracionLibreria:
		INCLUDE LIBRERIA FinCommand					
		;
declaracionVariable:
		TIPODEDATOBOOL IDENTIFICADOR IGUAL BOOLEANO FinCommand 	
		|TIPODEDATOSTRING IDENTIFICADOR IGUAL CADENA FinCommand	
		|TIPODEDATOENTERO IDENTIFICADOR IGUAL ENTERO FinCommand	
		|TIPODEDATOFLOTANTE IDENTIFICADOR IGUAL FLOTANTE FinCommand	
		|TIPODEDATOCHAR IDENTIFICADOR IGUAL CARACTER FinCommand	
		|tipoDeDato IDENTIFICADOR IGUAL IDENTIFICADOR FinCommand	
		;
declaracionFuncion:
		TIPODEDATOBOOL IDENTIFICADOR ParetOP declaracionParametro ParetCL FinCommand 	
		|TIPODEDATOSTRING IDENTIFICADOR IGUAL CADENA ParetOP declaracionParametro ParetCL FinCommand	
		|TIPODEDATOENTERO IDENTIFICADOR IGUAL ENTERO ParetOP declaracionParametro ParetCL FinCommand	
		|TIPODEDATOFLOTANTE IDENTIFICADOR IGUAL FLOTANTE ParetOP declaracionParametro ParetCL FinCommand	
		|TIPODEDATOCHAR IDENTIFICADOR IGUAL CARACTER ParetOP declaracionParametro ParetCL FinCommand	
		|tipoDeDato IDENTIFICADOR IGUAL IDENTIFICADOR ParetOP declaracionParametro ParetCL FinCommand	
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
		declaracionVariable		|funcion
		;
main:
		tipoDeDato "main" ParetOP declaracionParametro ParetCL "{" sentencia "}"
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
