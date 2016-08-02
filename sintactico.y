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
%left <tipo>TIPODEDATO
%token IF
%token FOR
%token ELSE
%token RETURN
%left <voi>VOID
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
%token <identificador>IDENTIFICADOR
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
%union{
char* tipo;
char* identificador;
char* voi;
}
%%

programa:
	declaracionG			
	|definicionFuncion	{fprintf(archSal,"DefinicionFuncion\n"); }		
	|declaracionG programa		
	|definicionFuncion programa	{fprintf(archSal,"DefinicionFuncion\n");  }

	;



declaracionG:
	declaracionLibreria	{fprintf(archSal,"DeclaracionLibreria\n");}
	|declaracionVariable	{fprintf(archSal,"DeclaracionVariable1\n");}
	|declaracionFuncion	{fprintf(archSal,"DeclaracionFuncion\n");}	
	;

declaracionLibreria:
	INCLUDE LIBRERIA	
	;


declaracionVariable:		
	TIPODEDATO IDENTIFICADOR IGUAL valor FinCommand	 		{fprintf(archSal1,"%s,%s \n",$1,$2);}
	|TIPODEDATO IDENTIFICADOR IGUAL IDENTIFICADOR FinCommand 		{fprintf(archSal1,"%s,%s \n",$1,$2);}
	|TIPODEDATO IDENTIFICADOR FinCommand 					{fprintf(archSal1,"%s,%s \n",$1,$2);}
	|TIPODEDATO IDENTIFICADOR BracketOP ENTEROPOSITIVO BracketCL FinCommand {fprintf(archSal1,"%s,%s \n",$1,$2);}
	;			
  
declaracionFuncion:
	TIPODEDATO IDENTIFICADOR ParetOP parametroFuncion ParetCL FinCommand {fprintf(archSal1,"%s,%s \n",$1,$2);}
	|TIPODEDATO IDENTIFICADOR ParetOP ParetCL FinCommand	{fprintf(archSal1,"%s,%s \n",$1,$2);}
	|VOID IDENTIFICADOR ParetOP parametroFuncion ParetCL FinCommand {fprintf(archSal1,"%s,%s \n",$1,$2);}
	|VOID IDENTIFICADOR ParetOP ParetCL FinCommand  {fprintf(archSal1,"%s,%s \n",$1,$2);}
	;

definicionFuncion:
	TIPODEDATO IDENTIFICADOR ParetOP parametroFuncion ParetCL KEYOP bloque KEYCL 
	|TIPODEDATO IDENTIFICADOR ParetOP ParetCL KEYOP bloque KEYCL			
	|VOID IDENTIFICADOR ParetOP parametroFuncion ParetCL KEYOP bloque KEYCL  	
	|VOID IDENTIFICADOR ParetOP ParetCL KEYOP bloque KEYCL			
	;

parametroFuncion:
	TIPODEDATO IDENTIFICADOR				//{fprintf(archSal1,"\n");}
	|TIPODEDATO IDENTIFICADOR COMA parametroFuncion
	;



bloque:
	llamadaIf			
	|llamadaWhile			
	|llamadaDoWhile			
	|llamadaFuncion			
	|declaracionVariable 		{fprintf(archSal,"DeclaracionVariable2\n");}	
	|usoVariable		{fprintf(archSal,"DeclaracionVariable3\n");}		
	|llamadaIf bloque			
	|llamadaWhile bloque			
	|llamadaDoWhile	bloque		
	|llamadaFuncion	bloque		
	|declaracionVariable bloque	{fprintf(archSal,"DeclaracionVariable2\n");}		
	|usoVariable bloque			
	;

llamadaIf:
	IF ParetOP condicion ParetCL KEYOP bloque KEYCL			{fprintf(archSal,"DeclaracionIF\n");}	
	|IF ParetOP condicion ParetCL KEYOP bloque KEYCL ELSE KEYOP bloque KEYCL {fprintf(archSal,"DeclaracionIF\n");}		
	;

llamadaWhile:
	WHILE ParetOP condicion ParetCL KEYOP bloque KEYCL	{fprintf(archSal,"DeclaracionWHILE\n");}				
	;

llamadaDoWhile:
	DO KEYOP bloque KEYCL WHILE ParetOP condicion ParetCL FinCommand	{fprintf(archSal,"DeclaracionDoWhile\n");}		
	;
llamadaFuncion:
	IDENTIFICADOR ParetOP parametroLlamada ParetCL FinCommand	{fprintf(archSal,"LlamadaFuncion\n");}	
	|IDENTIFICADOR ParetOP ParetCL FinCommand			{fprintf(archSal,"LlamadaFuncion\n");}	
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
	|FLOTANTE 	
	|CARACTER 
	|CADENA		
	;

usoVariable:
	IDENTIFICADOR IGUAL usoAux2 	//{fprintf(archSal1,"%s \n",yytext);}	
	;

enteros:
	ENTEROPOSITIVO	
	|ENTERONEGATIVO	
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
   		fprintf(stderr, "Error en la Linea: %d\n",linea+1); 
	} 
	void main(void) { 
		yyin=fopen("entrada.txt","r");
		archSal=fopen("salidaSintactica.txt","w");
		archSal1=fopen("tabladeSimbolos.csv","w");
	    	yyparse();  
		fclose(archSal);
	} 
