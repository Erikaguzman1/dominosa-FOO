#include <stdio.h>
#include "colores.h"
#include "tablero.h"
#include "fichero.h"
#define MAX 20
#define TRUE 1
#define FALSE 0
#define NORTE 1
#define SUR 2
#define ESTE 3
#define OESTE 4
#define NO_CONECTADA 0

int main ()
{	
	t_tablero tablero;
	int i, j, fin=FALSE;
	int conex=0, cmax;

	leer_tablero (&tablero);
	cmax=tablero.nfilas * tablero.ncolumnas / 2;
	tconexion v[cmax];
    
	for (i=0; i<tablero.ncolumnas; i++)
	{
		for (j=0; j<tablero.nfilas; j++)
			tablero.tab[j][i].conexion=NO_CONECTADA;
	}

	while (fin==FALSE) 
	{
		imprimir_tablero(tablero);
		printf("\nConexiones: %d de %d\n", conex, cmax);
		realizar_jugada(&tablero, &conex);
		

		if(conex==cmax)
		{
			leer_jugada(tablero, v);
			if(comprobar_jugada(v, conex)==TRUE)
			{
				imprimir_tablero(tablero);
				printf("\nConexiones: %d de %d\n", conex, cmax);
				printf("FELICIDADES! HAS RESUELTO ESTE DOMINOSA! B-)\n");
				fin=TRUE;
			}
		}
	};
}


