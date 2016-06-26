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

%%
EXP:
	INCLUDE LIBRERIA	{fprintf(archSal,"Llamada a libreria ");}
	;

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
