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
		declaracionG			{fprintf(archSal,"1\n");}
		|definicionFuncion		{fprintf(archSal,"2\n");}
		|declaracionG programa		{fprintf(archSal,"3\n");}
		|definicionFuncion programa	{fprintf(archSal,"4\n");}
		;

declaracionG:
	declaracionLibreria		
	|declaracionVariable		
	|declaracionFuncion		
	;

declaracionLibreria:
	INCLUDE LIBRERIA	{fprintf(archSal,"Librería\n");}
	;

declaracionVariable:
	TIPODEDATO IDENTIFICADOR IGUAL BOOLEANO FinCommand 			{fprintf(archSal,"DeclaracionBooleano\n");}	
	|TIPODEDATOSTRING IDENTIFICADOR IGUAL CADENA FinCommand			{fprintf(archSal,"DeclaracionesCadena\n");}
	|TIPODEDATO IDENTIFICADOR IGUAL enteros FinCommand		{fprintf(archSal,"DeclaracionesEntero\n");}
	|TIPODEDATO IDENTIFICADOR IGUAL FLOTANTE FinCommand		{fprintf(archSal,"DeclaracionesFlotante\n");}
	|TIPODEDATO IDENTIFICADOR IGUAL CARACTER FinCommand			{fprintf(archSal,"DeclaracionesCaracter\n");}
	|TIPODEDATO IDENTIFICADOR IGUAL IDENTIFICADOR FinCommand		{fprintf(archSal,"DeclaracionConIDs\n");}
	|TIPODEDATO IDENTIFICADOR FinCommand 					{fprintf(archSal,"DeclaracionSinInicializacion\n");}
	|TIPODEDATO IDENTIFICADOR BracketOP ENTEROPOSITIVO BracketCL FinCommand	{fprintf(archSal,"Declaracionvector\n");}
	;			
  
declaracionFuncion:
	TIPODEDATO IDENTIFICADOR ParetOP parametroFuncion ParetCL FinCommand 	{fprintf(archSal,"DeclaracionFuncionpara\n");}
	|TIPODEDATO IDENTIFICADOR ParetOP ParetCL FinCommand			{fprintf(archSal,"DeclaracionFuncion\n");}
	|VOID IDENTIFICADOR ParetOP parametroFuncion ParetCL FinCommand 	{fprintf(archSal,"DeclaracionFuncionvoidpara\n");}
	|VOID IDENTIFICADOR ParetOP ParetCL FinCommand				{fprintf(archSal,"DeclaracionFuncionvoid\n");}
	;

parametroFuncion:
	TIPODEDATO IDENTIFICADOR	{fprintf(archSal,"9\n");}
	|TIPODEDATO IDENTIFICADOR COMA parametroFuncion	{fprintf(archSal,"10\n");}
	;

definicionFuncion:
	TIPODEDATO IDENTIFICADOR ParetOP parametroFuncion ParetCL KEYOP bloque KEYCL	{fprintf(archSal,"DefinicionFuncionpara\n");}
	|TIPODEDATO IDENTIFICADOR ParetOP ParetCL KEYOP bloque KEYCL			{fprintf(archSal,"DefinicionFuncion\n");}
	|VOID IDENTIFICADOR ParetOP parametroFuncion ParetCL KEYOP bloque KEYCL  	{fprintf(archSal,"DefiFuncionvoidpara\n");}
	|VOID IDENTIFICADOR ParetOP ParetCL KEYOP bloque KEYCL			{fprintf(archSal,"DefinicionFuncionvoid\n");}
	;
	



bloque:
	llamadaIf			{fprintf(archSal,"15\n");}
	|llamadaWhile			{fprintf(archSal,"16\n");}
	|llamadaDoWhile			{fprintf(archSal,"17\n");}
	|llamadaFuncion			{fprintf(archSal,"18\n");}
	|declaracionVariable 		{fprintf(archSal,"19\n");}
	|usoVariable			{fprintf(archSal,"20\n");}
	|llamadaIf bloque			{fprintf(archSal,"15\n");}
	|llamadaWhile bloque			{fprintf(archSal,"16\n");}
	|llamadaDoWhile	bloque		{fprintf(archSal,"17\n");}
	|llamadaFuncion	bloque		{fprintf(archSal,"18\n");}
	|declaracionVariable bloque		{fprintf(archSal,"19\n");}
	|usoVariable bloque			{fprintf(archSal,"20\n");}
	;

llamadaIf:
	IF ParetOP condicion ParetCL KEYOP bloque KEYCL				{fprintf(archSal,"llamadaIF\n");}
	|IF ParetOP condicion ParetCL KEYOP bloque KEYCL ELSE KEYOP bloque KEYCL	{fprintf(archSal,"llamadaIF\n");}
	;

llamadaWhile:
	WHILE ParetOP condicion ParetCL KEYOP bloque KEYCL				{fprintf(archSal,"llamadaWhile\n");}
	;

llamadaDoWhile:
	DO KEYOP bloque KEYCL WHILE ParetOP condicion ParetCL FinCommand		{fprintf(archSal,"llamadaDoWhile\n");}
	;
llamadaFuncion:
	IDENTIFICADOR ParetOP parametroLlamada ParetCL FinCommand	{fprintf(archSal,"llamadaFuncionCon\n");}
	IDENTIFICADOR ParetOP ParetCL FinCommand			{fprintf(archSal,"llamadaFuncionSin\n");}
	;

parametroLlamada:
	usoAux1					{fprintf(archSal,"21\n");}
	|usoAux1 COMA parametroLlamada		{fprintf(archSal,"22\n");}
	;

condicion:      
	BOOLEANO				{fprintf(archSal,"23\n");}
	|usoAux1 COMPAR usoAux1			{fprintf(archSal,"24\n");}
	|llamadaFuncion				{fprintf(archSal,"25\n");}
	|llamadaFuncion COMPAR usoAux1		{fprintf(archSal,"26\n");}
	|llamadaFuncion COMPAR llamadaFuncion	{fprintf(archSal,"27\n");}
	;

valor:		
	enteros		{fprintf(archSal,"28\n");}
	|FLOTANTE	{fprintf(archSal,"29\n");}
	|CARACTER	{fprintf(archSal,"30\n");}
	|CADENA		{fprintf(archSal,"31\n");}
	;

usoVariable:
	IDENTIFICADOR IGUAL usoAux2		{fprintf(archSal,"32\n");}
	;



enteros:
	ENTEROPOSITIVO		{fprintf(archSal,"38\n");}
	|ENTERONEGATIVO		{fprintf(archSal,"39\n");}
	;
operacion:
	MASMENOS		{fprintf(archSal,"40\n");}
	|DIMULTI		{fprintf(archSal,"41\n");}
	;
usoAux1:
	IDENTIFICADOR		{fprintf(archSal,"42\n");}
	|valor			{fprintf(archSal,"43\n");}
	;
usoAux2:
	usoAux1 FinCommand		{fprintf(archSal,"44\n");}
	|usoAux1 operacion usoAux2	{fprintf(archSal,"45\n");}
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
