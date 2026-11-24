#include <stdio.h>
#include "tablero.h"
#include "colores.h"
#include "fichero.h"
#include "ficha.h"
#define MAX 20
#define TRUE 1
#define FALSE 0
#define NORTE 1
#define SUR 2
#define ESTE 3
#define OESTE 4
#define NO_CONECTADA 0

void leer_tablero(t_tablero *tablero)
{
	printf("leer_tablero...\n");
	char fich[MAX];
    int i=0, j=0, correcto;
    printf("Introduce un fichero: ");
    do 
	{
		scanf("%s%*c", fich);
		correcto=abrir_fichero(fich);
		if (correcto==ABRIR_FICHERO_OK) 
		{
			printf("\nEl fichero es correcto");
			tablero->dimension=leer_int_fichero();
			tablero->nfilas=leer_int_fichero();
			tablero->ncolumnas=leer_int_fichero();
		}
		else printf("\nFichero no encontrado. \nVuelva a introducir un fichero: ");
    } while (correcto!=ABRIR_FICHERO_OK);
    
   printf("\n%d %d %d\n", tablero->dimension, tablero->nfilas, tablero->ncolumnas);
   
   for (i=0; i<tablero->nfilas; i++) 
   {
       for (j=0; j<tablero->ncolumnas; j++)
           tablero->tab[i][j].num=leer_int_fichero();
   }
   printf("\n");
}


void imprimir_tablero (t_tablero tablero)
{
	int i, j;
	for(i=0; i<tablero.ncolumnas; i++)
	{	printf_color_negrita();
		printf("   %d", i);
	}
			
	printf("\n +");
	
	for(i=0; i<tablero.ncolumnas; i++)
		printf("---+");
	
	printf("\n");
		
	printf_color_num(-1);
			
	for(j=0; j<tablero.nfilas; j++)
	{
		printf_color_negrita();
		printf("%c|", 'A'+j);
			
		for(i=0; i<tablero.ncolumnas; i++)
		{
			printf_color_num(-1);
			if(i>0)
			{
				if (tablero.tab[j][i].conexion==OESTE)
				{
					printf("███");
					printf_color_num(tablero.tab[j][i].num);
					printf("%d", tablero.tab[j][i].num);
				}
				else 
				{
					printf_color_num(tablero.tab[j][i].num);
					printf("   %d", tablero.tab[j][i].num);
				}
			}
			else
			{
				printf_color_num(tablero.tab[j][i].num);
				printf(" %d", tablero.tab[j][i].num);
			}
		}
		
		printf_color_negrita();
		printf("\n +");
			for(i=0; i<tablero.ncolumnas; i++)
			{
				if(i>0)
				{
					if (tablero.tab[j][i].conexion==SUR)
						printf(" █ +");
					else 
						printf("   +");
				}
				else 
				{
					if (tablero.tab[j][i].conexion==SUR)
						printf(" █ +");
					else 
						printf("   +");
				}
			}
		printf_color_num(-1);
		
		printf("\n");
	}
}

void realizar_jugada (t_tablero *tablero, int *conex)
{
	t_ficha f1, f2;
	int n;

	do{
		leer_fichas (&f1, &f2);
		
	}while(fichaValida(tablero, f1, f2) == FALSE);

				
	}while(n == 0);

	conexion_fichas(tablero, f1, f2, conex);

}

void leer_jugada(t_tablero tablero, tconexion *v)
{
	/*introduce cada conexion en una posicion del vector*/
	int i, j, pos=0;

	for(i=0; i<tablero.ncolumnas; i++)
	{
		for(j=0; j<tablero.nfilas; j++)
		{
			if(tablero.tab[i][j].conexion == SUR)
			{
				v[pos].ex1=tablero.tab[i+1][j].num;
				v[pos].ex2=tablero.tab[i][j].num;
				pos++;

			}

			else if (tablero.tab[i][j].conexion == ESTE)
			{
				v[pos].ex1=tablero.tab[i][j].num;
				v[pos].ex2=tablero.tab[i][j+1].num;
				pos++;
			}
		}
	}
} 

int comprobar_jugada (tconexion *v, int conex)
{
	/*devuelve si la partida se ha finalizando, comprobando las conexiones mirando si estas estan repetidas*/
	int i, j, finalizada=FALSE;
	for(i=0; i<conex; i++)
	{
		for(j=i+1; j<conex-1; j++)
		{
			if((v[i].ex1==v[j].ex1 && v[i].ex2==v[j].ex2) || (v[i].ex1==v[j].ex2 && v[i].ex2==v[j].ex1))
				finalizada=TRUE;;
		}
	}
	return finalizada;

}





