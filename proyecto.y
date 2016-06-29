%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
	FILE *archSal;
%}

%token ENTERO
%token IDENTIFICADOR
%token FLOTANTE
%token BOOLEANO
%token INCLUDE
%token LIBRERIA
%token CADENA
%token IF 
%token FOR 
%token ELSE 
%token return 
%token TIPODEDATOBOOL 
%token TIPODEDATOSTRING 
%token VOID
%token TIPODEDATOENTERO
%token TIPODEDATOFLOTANTE
%token TIPODEDATOCHAR
%token THEN 
%token WHILE
%token VOID 
%token DO
%token INPUT
%token OUTPUT
%token CARRESP
%token COMPAR
%token CHAR
%token COMS
%token COMC



%%
EXP:
	INCLUDE LIBRERIA	{fprintf(archSal,"Llamada a libreria ");}
	;
op:     '+'|'-'|'*'|'/';

oper:	IDENTIFICADOR op oper    
	|IDENTIFICADOR
	|ENTERO op
	|ENTERO
	|FLOTANTE op
	|FLOTANTE;
	
EXP1:   IDENTIFICADOR '=' oper  {fprintf(archSal,"Operacion ");}






%%

void yyerror(char *s) { 
    fprintf(archSal,stderr, "%s\n", s); 
} 
int main(void) { 
	archSal=fopen("salidaSintactica.txt","w");
	yyparse();
	fclose(archSal);
	return 0; 
}
