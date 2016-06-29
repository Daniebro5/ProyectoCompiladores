%{
	 #include <stdio.h> 
    int yylex(void); 
    void yyerror(char *);
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
	INCLUDE LIBRERIA	{printf("Llamada a libreria ");}
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
int main(void) { 
    yyparse(); 
    return 0; 
} 
