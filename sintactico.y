%{
	 #include <stdio.h>
	#include <stdlib.h> 
    int yylex(void); 
    void yyerror(char *);
extern FILE *yyin;
extern int linea;
extern char *yytext;

 FILE *archSal;
   FILE *archSal1;
%}

%token INCLUDE
%token IGUAL
%token LIBRERIA
%token TIPODEDATO
%token IF
%token FOR
%token ELSE
%token RETURN
%token TIPODEDATOBOOL
%token TIPODEDATOSTRING
%token TIPODEDATOENTERO
%token VOID
%token TIPODEDATOFLOTANTE
%token TIPODEDATOCHAR
%token THEN
%token WHILE
%token DO
%token INPUT
%token OUTPUT
%token ENTEROPOSITIVO
%token ENTERONEGATIVO
%token FLOTANTE
%token BOOLEANO
%token CARRESP
%token COMPAR
%token IDENTIFICADOR
%token CARACTER 
%token CADENA
%token MASMENOS
%token DIMULTI
%token COMA
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
	declaracionG			
	|definicionFuncion		
	|declaracionG programa		
	|definicionFuncion programa	
	;

declaracionG:
	declaracionLibreria	{fprintf(archSal,"DeclaracionLibreria\n");}
	|declaracionVariable	{fprintf(archSal,"DeclaracionVariable\n");}
	|declaracionFuncion	{fprintf(archSal,"DeclaracionFuncion\n");}	
	;

declaracionLibreria:
	INCLUDE LIBRERIA
	;

tipoDeDato:
		TIPODEDATOBOOL {fprintf(archSal1,"%s,",yytext );}
		|TIPODEDATOSTRING {fprintf(archSal1,"%s,",yytext );}
		|TIPODEDATOENTERO {fprintf(archSal1,"entero,");} 
		|TIPODEDATOFLOTANTE {fprintf(archSal1,"%s,",yytext );}
		|TIPODEDATOCHAR {fprintf(archSal1,"%s,",yytext );}
		;


declaracionVariable:
	 				
	tipoDeDato IDENTIFICADOR IGUAL valor FinCommand	
	|tipoDeDato IDENTIFICADOR IGUAL IDENTIFICADOR FinCommand
	|tipoDeDato IDENTIFICADOR FinCommand 
	|tipoDeDato IDENTIFICADOR BracketOP ENTEROPOSITIVO BracketCL FinCommand
	;			
  
declaracionFuncion:
	TIPODEDATO IDENTIFICADOR ParetOP parametroFuncion ParetCL FinCommand
	|TIPODEDATO IDENTIFICADOR ParetOP ParetCL FinCommand
	|VOID IDENTIFICADOR ParetOP parametroFuncion ParetCL FinCommand
	|VOID IDENTIFICADOR ParetOP ParetCL FinCommand
	;

parametroFuncion:
	TIPODEDATO IDENTIFICADOR
	|TIPODEDATO IDENTIFICADOR COMA parametroFuncion
	;

definicionFuncion:
	TIPODEDATO IDENTIFICADOR ParetOP parametroFuncion ParetCL KEYOP bloque KEYCL
	|TIPODEDATO IDENTIFICADOR ParetOP ParetCL KEYOP bloque KEYCL			
	|VOID IDENTIFICADOR ParetOP parametroFuncion ParetCL KEYOP bloque KEYCL  	
	|VOID IDENTIFICADOR ParetOP ParetCL KEYOP bloque KEYCL			
	;

bloque:
	llamadaIf			
	|llamadaWhile			
	|llamadaDoWhile			
	|llamadaFuncion			
	|declaracionVariable 		
	|usoVariable			
	|llamadaIf bloque			
	|llamadaWhile bloque			
	|llamadaDoWhile	bloque		
	|llamadaFuncion	bloque		
	|declaracionVariable bloque		
	|usoVariable bloque			
	;

llamadaIf:
	IF ParetOP condicion ParetCL KEYOP bloque KEYCL				
	|IF ParetOP condicion ParetCL KEYOP bloque KEYCL ELSE KEYOP bloque KEYCL	
	;

llamadaWhile:
	WHILE ParetOP condicion ParetCL KEYOP bloque KEYCL				
	;

llamadaDoWhile:
	DO KEYOP bloque KEYCL WHILE ParetOP condicion ParetCL FinCommand		
	;
llamadaFuncion:
	IDENTIFICADOR ParetOP parametroLlamada ParetCL FinCommand	
	|IDENTIFICADOR ParetOP ParetCL FinCommand			
	;

parametroLlamada:
	usoAux1					
	|usoAux1 COMA parametroLlamada		
	;

condicion:      
	BOOLEANO				
	|usoAux1 COMPAR usoAux1			
	|llamadaFuncion				
	|llamadaFuncion COMPAR usoAux1		
	|llamadaFuncion COMPAR llamadaFuncion	
	;

valor:		
	enteros		
	|FLOTANTE {fprintf(archSal1,"%s \n",yytext );}	
	|CARACTER {fprintf(archSal1,"%s \n",yytext );}	
	|CADENA	{fprintf(archSal1,"%s \n",yytext );}	
	;

usoVariable:
	IDENTIFICADOR IGUAL usoAux2		
	;

enteros:
	ENTEROPOSITIVO	{fprintf(archSal1,"%s \n",yytext); }	
	|ENTERONEGATIVO	{fprintf(archSal1,"%s \n",yytext); }	
	;
operacion:
	MASMENOS		
	|DIMULTI
	
	;
usoAux1:
	IDENTIFICADOR		
	|valor			
	;
usoAux2:
	usoAux1 FinCommand		
	|usoAux1 operacion usoAux2	
	;


%%
	void yyerror(char *s) { 
   		fprintf(stderr, "Linea: %d, %s",linea+1,s); 
	} 
	void main(void) { 
		yyin=fopen("entrada.txt","r");
		archSal=fopen("salidaSintactica.txt","w");
		archSal1=fopen("tabladeSimbolos.csv","w");
	    	yyparse();  
		fclose(archSal);
	} 
