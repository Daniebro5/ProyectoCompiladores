# ProyectoCompiladores

Para el uso del programa solo son necesarios los archivos reconocedor.l y entrada.txt

En el Terminal ejecutaremos las siguientes instrucciones:
  flex reconocedor.l
  gcc lex.yy.c -lfl
  ./a.out entrada.txt

Con esto ya se tendrá el resultado en un archivo salida.txt que se encuentra en la misma carpeta 
que los archivos anteriormente citados
  
Se puede cambiar el texto de entrada por lo que sea, es importante ubicar ambos archivos en la misma carpeta
