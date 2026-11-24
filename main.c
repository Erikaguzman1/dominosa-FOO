#include <stdio.h>
#include "fichero.h"
#include "tablero.h"
#define MAX 20

int main () {
    char fich[MAX];
    t_tablero tablero;
    int i=0, j=0, correcto;
    printf("Introduce un fichero: ");
    do {
    scanf("%s%*c", &(*fich));
    correcto=abrir_fichero(fich);
    if (correcto==ABRIR_FICHERO_OK) {
        printf("\nEl fichero es correcto");
        tablero.dimension=leer_int_fichero(fich);
        tablero.nfilas=leer_int_fichero(fich);
        tablero.ncolumnas=leer_int_fichero(fich);
    }
    else {
        printf("\nFichero no encontrado. \nVuelva a introducir un fichero: ");
    }
    } while (correcto!=ABRIR_FICHERO_OK);
   printf("\n%d %d %d ", tablero.dimension, tablero.nfilas, tablero.ncolumnas);
   
   for (i=0; i<tablero.nfilas; i++) {
       for (j=0; j<tablero.ncolumnas; j++) {
           tablero.tab[i][j].num=leer_int_fichero(fich);
       }
   }
   printf("\n");
   imprimir_tablero (tablero);
}
