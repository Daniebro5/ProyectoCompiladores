%{
	 #include <stdio.h>
	#include <stdlib.h> 
    int yylex(void); 
    void yyerror(char *);
extern FILE *yyin;
 FILE *archSal;
%}

%token INCLUDE
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



%%
EXP:
	INCLUDE LIBRERIA	{fprintf(archSal,"Llamada a libreria ");}
	;
/*op:     '+'|'-'|'*'|'/';

oper:	IDENTIFICADOR op oper    
	|IDENTIFICADOR
	|ENTERO op
	|ENTERO
	|FLOTANTE op
	|FLOTANTE;
	
EXP1:   IDENTIFICADOR '=' oper  {fprintf(archSal,"Operacion ");}
;*/

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
