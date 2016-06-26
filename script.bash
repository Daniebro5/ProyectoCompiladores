#/bin/bash
flex proyecto.l
gcc lex.yy.c -lfl
./a.out entrada.txt
bison -d proyecto.y
flex proyecto.l
gcc -o proyecto lex.yy.c proyecto.tab.c
