%{
FILE *archSal;
int num_linea =0;
bool bandera = true;
%}

car ","|";"|":"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"<"|">"|"="|"!"|"&"|"$" 

%%

[0-9]|"-"[0-9]|"+"[0-9]		fprintf(archSal,"Integer ",yytext);
[0-9]*"."[0-9]+			fprintf(archSal,"Float ",yytext);
"True"|"False"|"true"|"false"			fprintf(archSal,"bool ",yytext);
"if"|"else"|"return"|"bool"|"string"|"int"|"float"|"char"|"then"|"while"|"do"|"input"|"output"	fprintf(archSal,"Palabra reservada ",yytext);

car		{fprintf(archSal,"Caracter Especial ",yytext);}
 		
"<="|">="|"=="|"!="|"&&"|"||"			fprintf(archSal,"Operando Compuesto ",yytext);

[a-z]([a-z]|[0-9])* 		fprintf(archSal,"Identificador ",yytext);
"'".{1}"'"			fprintf(archSal,"char ",yytext);
\"[^\n"]+\"			fprintf(archSal,"string ",yytext);
\n				fprintf(archSal,"\n",yytext); ++num_linea;

"//".*?				fprintf(archSal,"Comentario linea ",yytext);

"/*"[^"*/"]*	 fprintf(archSal,"Comentario dos o mas lineas",yytext);
.		fprintf(archSal,"Error",yytext); bandera = false;

%%

main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    archSal=fopen("salida.txt","w");
    yylex();
    fclose(archSal);
 }
