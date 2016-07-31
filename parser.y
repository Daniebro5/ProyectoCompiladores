%{	
	#include <stdio.h>
	#include "symboltable.h"

	extern int errors, lines, chars;

	// Archivo destino de la tabla de símbolos
	#define TABLE_FILE "symboltable"

	// mensajes
	#define ERROR 0
	#define WARNING 1
	#define NOTE 2

	// tipos para la tabla de símbolos
	#define KEY_TYPE -100

	FILE *yyin;
	char *filename;

	int yylex();
	void yyerror();
	int install(const char *lexeme, int type);
	void install_keywords(char* keywords[], int n);
	void install_id(char *name, int type);
	void print_table(table_t table);
	char *strbuild(int option, const char *str1, const char *str2);
	void print_cursor();
	void get_line(char *line);

	#define YYDEBUG 1
%}

%start program
%token MAIN
%token IF ELSE DO WHILE FOR BREAK PRINT RETURN
%token INT_TYPE FLOAT_TYPE
%token STRING INTEGER REAL
%token ID
%token MATH_INC MATH_DEC
%token LOG_EQL LOG_LT LOG_GT LOG_AND LOG_OR LOG_NOT

%union {
	char *lexeme;
	int integer;
	float real;
}

%type<lexeme> ID
%type<integer> INTEGER i_expr i_term i_factor l_expr l_factor
%type<real> REAL r_expr r_term r_factor

%left '+' '-'
%left '*' '/'
%left MATH_INC MATH_DEC
%left LOG_EQL LOG_LT LOG_GT LOG_AND LOG_OR
%right '='
%right LOG_NOT

%glr-parser

%%

 /*******************************************
 CUERPO GENERAL DEL PROGRAMA
 *******************************************/
program : MAIN '('')' '{' commands '}' program_end
        | error {yyerror("formato de main incorrecto", ERROR);} ;

program_end :  %empty
            | ID '('')' '{' commands '}' program_end
            | error {yyerror("formato de programa incorrecto", ERROR);};


 /*******************************************
 COMANDOS
 *******************************************/

commands: command_list;

command_list: '{' command_list '}'
            | command  command_list
            | %empty
            ;

command: cmd ';'
       | stmt
       | error { yyerror("statement error or missing ';'", ERROR); }
       ;
	
stmt: if_stmt
    | for_stmt
    | while_stmt 
    | dowhile_stmt
    ;

cmd: PRINT STRING
   | BREAK
   | RETURN
   | attrib
   | declaration
   ;

 /*******************************************
 IF ELSE
 *******************************************/
if_stmt: IF '(' l_expr ')' '{' commands '}' else_stmt;

else_stmt: %empty
         | ELSE '{' commands '}';


/*******************************************
 FOR
 *******************************************/
for_stmt: FOR '(' ffirst ';' l_expr ';' fthird ')' '{' commands '}';

ffirst: %empty
      | attrib_list;


fthird: %empty
      | cmd ',' fthird
      | cmd;


 /*******************************************
 WHILE
 *******************************************/
while_stmt: WHILE '(' l_expr ')' '{' commands '}';


 /*******************************************
 DO WHILE
 *******************************************/
dowhile_stmt: DO '{' commands '}' WHILE '(' l_expr ')' ';';


 /*******************************************
 DECLARACION
 *******************************************/
declaration: INT_TYPE ID {
	install_id($2, INT_TYPE);
}
| FLOAT_TYPE ID {
	install_id($2, FLOAT_TYPE);
}
;


 /*******************************************
 ATRIBUCION
 *******************************************/
attrib_list: attrib ',' attrib_list
           | attrib
           ;

attrib: i_attrib
| r_attrib
| ID MATH_INC {
	if(get_entry($1)) {
		set_value($1, get_value($1)+1);
	}
	else {
		char *str = (char *)strbuild(1, "declaration of '%s' not found", $1);
		yyerror(str, ERROR);
	}
}
| ID MATH_DEC {
	if(get_entry($1)) {
		set_value($1, get_value($1)-1);
	}
	else {
		char *str = (char *)strbuild(1, "declaration of '%s' not found", $1);
		yyerror(str, ERROR);
	}
}                      
| ID '=' ID {
	char *str;
	if(get_entry($1) != NULL) {
		// if there's entry gets its value
		if(get_entry($3) != NULL) {
			if(get_type($1) == get_type($3)) {
				set_value($1, get_value($3));
			}
			else {
				str = (char *)strbuild(0,
						(char *)strbuild(1, "incompatible data types between '%s' ", $1),
						(char *)strbuild(1, "and'%s'", $3)
						);
			}
		}
		else {
			str = (char *)strbuild(1, "declaration of '%s' not found", $1);
			yyerror(str, ERROR);
		}
	}
	else {
		str = (char *)strbuild(1, "declaration of '%s' not found", $1);
		yyerror(str, ERROR);
	}

}
| error { yyerror("invalid attribution format", ERROR); };

i_attrib: ID '=' i_expr {
	if(get_entry($1)) {
		// if they have the same type
		if(get_type($1) == INT_TYPE) {
			// does the attribution
			set_value($1, $3);
		}
		else {
			yyerror("incompatible data types", WARNING);
		}
	}
	else {
		char *str = (char *)strbuild(1, "declaration of '%s' not found", $1);
		yyerror(str, ERROR);
	}
};

r_attrib: ID '=' r_expr {
	if(get_entry($1)) {
		// if they have the same type
		if(get_type($1) == FLOAT_TYPE) {
			// does the attribution
			set_value($1, $3);
		}
		else {
			yyerror("incompatible data types", WARNING);
		}
	}
	else {
		char *str = (char *)strbuild(1, "declaration of '%s' not found", $1);
		yyerror(str, ERROR);
	}
};


 /*******************************************
 EXPRESIONES LOGICAS Y MATEMÁTICAS
 *******************************************/
l_expr: l_expr LOG_EQL l_factor { $$ = $1 == $3; }
      | l_expr LOG_AND l_factor { $$ = $1 && $3; }
      | l_expr LOG_OR l_factor { $$ = $1 || $3; }
      | l_expr LOG_GT l_factor { $$ = $1 > $3; }
      | l_expr LOG_LT l_factor { $$ = $1 < $3; }
      | LOG_NOT l_expr { $$ = !$2; }
      | l_factor
      ;

l_factor: '(' l_expr ')' { $$ = $2; }
| INTEGER { $$ = $1; }
| REAL { $$ = $1; }
| ID {            
	// si existe una entrada obtendremos su valor
	if(get_entry($1)) {
		$$ = (int) get_value($1);
	}
	else {
		char *str = (char *)strbuild(1, "declaration of '%s' not found", $1);
		yyerror(str, ERROR);
	}
};

i_expr: i_expr '+' i_term { $$ = $1 + $3; }
      | i_expr '-' i_term { $$ = $1 - $3; } 
      | i_term { $$ = $1; }
      ;

r_expr: r_expr '+' r_term { $$ = $1 + $3; } 
      | r_expr '-' r_term { $$ = $1 - $3; } 
      | r_term { $$ = $1; }
      ;

i_term: i_term '*' i_factor { $$ = $1 * $3; } 
      | i_term '/' i_factor { $$ = $1 / $3; } 
      | i_factor { $$ = $1; }
      ;

r_term: r_term '*' r_factor { $$ = $1 * $3; } 
      | r_term '/' r_factor { $$ = $1 / $3; } 
      | r_factor { $$ = $1; }
      ;

i_factor: '(' i_expr ')' { $$ = $2; }
        | INTEGER { $$ = $1; }
        ;

r_factor: '(' r_expr ')' { $$ = $2; }
        | REAL { $$ = $1; }
        ;

%%

int main( int argc, char **argv )
{
	char* keywords[] = {"main", "if", "else", "do", "while", "for", "break", "print",
						"return", "int", "float"};

	// revisa si hay más archivos que se deban leer 
	++argv, --argc;
	if ( argc > 0 ) {
		filename = strdup(argv[0]);
		yyin = fopen( argv[0], "r" );
	}
	else {
		filename = strdup("stdin");
		yyin = stdin;
	}

	// inicializa la tabla de simbolos
	init_table();

	// instala las palabras reservadas en la primera fila
	install_keywords(keywords, 11);

	// ejecuta el analizador
	yyparse();

	if(errors==0) {
		printf("Analisis finalizado correctamente.\n");
	}
	else {
		printf("Se han encontrado: %d errores\n", errors);
	}

	// Imprime la tabla de simbolos generada
	print_table(table);

	return 0;
}

// Ingresa una declaracion al final de la tabla de simbolos
// 	si el id ya existe retorna un 0
int install(const char *lexeme, int type) {
	int success = 1;
	entry_t *e;

	e = (entry_t *)get_entry(lexeme);
	if(e == 0) {
		/* Empaqueta los datos y los ingresa
		 * en la tabla de simbolos
		 */
		put_entry((entry_t *)create_entry(type, lexeme, 0));
	}
	else {
		// Ya se colocó en la tabla
		success = 0;
	}
	return success;
}

// ingresa las palabras clave al inicio de la tabla
void install_keywords(char* keywords[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		install(keywords[i], KEY_TYPE);
	}
}

// imprime la tabla en un archivo
void print_table(table_t table) {
	FILE *f = fopen (TABLE_FILE, "w");
	int i;
	entry_t *cur;
	
	fprintf(f, "SYMBOL TABLE\n"
		"%d entries\n\n", table.t_size);

	fprintf(f, "+-------+---------+------------------------------+\n"); 
	fprintf(f, "|   -   |  TYPE   |        TOKEN = VALUE         |\n");
	fprintf(f, "+-------+---------+------------------------------+\n"); 

	for(i = 1, cur = table.t_head;
	    cur != NULL;
	    cur = cur->next, i++) {
		if(cur->type == INT_TYPE) {
			fprintf(f, "| %-5d | INTEGER |  %s = %d\n", i, cur->lexeme, (int) cur->value);
		} 
		else if(cur->type == FLOAT_TYPE) {
			fprintf(f, "| %-5d |  FLOAT  |  %s = %f\n", i, cur->lexeme, (float) cur->value);
		} 
		else if(cur->type == KEY_TYPE) {
			fprintf(f, "| %-5d | KEYWORD |  %s\n", i, cur->lexeme);
		}
	}

	fprintf(f, "+-------+---------+------------------------------+\n"); 
}

void yyerror(const char *msg, int type) {
	if(strcmp(msg, "syntax error") == 0) {
		printf("syntax error\n");
	}
	else {
		//se muestran los errores y la línea en la que se encuentran
		switch(type) {
			case ERROR:
				printf("%s:%d:%d: error: %s\n", filename, lines, chars, msg);
				break;

			case WARNING:
				printf("%s:%d:%d: warning: %s\n", filename, lines, chars, msg);
				break;

			case NOTE:
				printf("%s:%d:%d: note: %s\n", filename, lines, chars, msg);
				break;

			default:
				printf("%s:%d:%d: error: %s\n", filename, lines, chars, msg);
		}

		errors++;
		print_cursor();
	}
}

void install_id(char *name, int type) {
	// verifica si el id está en la tabla y si no está se lo agrega
	if(install(name, type)) {
		// se agrega en la tabla en la llamada del argumento del if
		
	}
	else {
		int t = get_type(name);
		char *str;
		if(t == type) {
			str = (char *)strbuild(1, "redeclaration of '%s'", name);
		}
		else {
			str = (char *)strbuild(1, "conflicting type for '%s'", name);
		}
		yyerror(str, NOTE);
	}
}

char *strbuild(int option, const char *str1, const char *str2) {
	char *full_str;

	if(option == 1) {
		int size;
		// asigna el tamaño de la cadena resultante
		size = snprintf(NULL, 0, str1, str2);
		full_str = (char *)malloc(size+1);

		// si hay un espacio lo inserta en la cadena
		if(full_str != NULL) {
			snprintf(full_str, size+1, str1, str2);
		}
		// o solo retorna el primer valor
		else {
			full_str = (char *)strdup(str1);
		}
	}
	else {
		// concatenacion
		full_str = (char *)malloc((strlen(str1) + strlen(str2)) * sizeof(char));
                if(full_str != NULL) {
			strcat(full_str, str1);
			strcat(full_str, str2);
		}
	}

	return full_str;
}

void print_cursor() {
	int i;
	char line[256];

	get_line(line);
	printf("%s", line);

	for(i=0; i<chars-1; i++) {
		if(line[i] == '\t') {
			printf("\t");
		}
		else {
			printf(" ");
		}
	}
	printf("^^\n");
}

void get_line(char *line) {
	int i;
	fpos_t position;

	// guarda la posicion actual en el archivo
	fgetpos(yyin, &position);
	rewind(yyin);
	for(i=0; i<lines; i++) {
		fgets(line, 256, yyin);
	}

	// recupera la posicion en el archivo
	fsetpos(yyin, &position);
}

