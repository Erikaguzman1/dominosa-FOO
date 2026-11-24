#include <stdio.h>
#include "tablero.h"
#include "ficha.h"
#define TRUE 1
#define FALSE 0
#define NORTE 1
#define SUR 2
#define ESTE 3
#define OESTE 4
#define NO_CONECTADA 0

int fichaValida(t_tablero *tablero, t_ficha f1, t_ficha f2)
{
    /* Mira si esta fuera del tablero y si son contiguas */
	if (f1.fila < 0 || f1.fila >= tablero->nfilas || f1.columna < 0 || f1.columna >= tablero->ncolumnas) 
        return FALSE;
    else if (f2.fila < 0 || f2.fila >= tablero->nfilas || f2.columna < 0 || f2.columna >= tablero->ncolumnas)
        return FALSE;
	else if((f2.columna-f1.columna==1 || f1.columna-f2.columna==1) && f1.fila==f2.fila)
		return TRUE;
	else if ((f2.fila-f1.fila==1 || f1.fila-f2.fila==1) && f1.columna==f2.columna)
		return TRUE;
	else 
		return FALSE;
}

void leer_fichas (t_ficha *f1, t_ficha *f2)
{
	/* Pide una posición y pasa la letra al numero equivalente de la matriz */
	char letra1, letra2;
	printf("\n\nCasillas a conectar/desconectar (ej:A0B0):");
	scanf(" %c%d%c%d", &letra1, &f1->columna, &letra2, &f2->columna);
	
	if (letra1 <= 'z' && letra1 >= 'a' )
		f1->fila = letra1 - 'a';

	else
		f1->fila = letra1 - 'A';

	if (letra2 <= 'z' && letra2 >= 'a' )
		f2->fila = letra2 - 'a';

	else
		f2->fila = letra2 - 'A';
}


void conexion_fichas (t_tablero *tablero, t_ficha f1, t_ficha f2, int *conex)
{	
	int eliminar;
	eliminar=eliminar_conexion(tablero, f1, f2, conex);

	/*primero mira si las casillas estan conectadas, y si es asi deshace las conexiones*/
    if(tablero->tab[f1.fila][f1.columna].conexion!=NO_CONECTADA)
	{
		switch(tablero->tab[f1.fila][f1.columna].conexion)
		{
			case NORTE: tablero->tab[f1.fila-1][f1.columna].conexion=NO_CONECTADA;
						break;

			case SUR: tablero->tab[f1.fila+1][f1.columna].conexion=NO_CONECTADA;
                        break;

			case ESTE: tablero->tab[f1.fila][f1.columna+1].conexion=NO_CONECTADA;
                        break;

			case OESTE: tablero->tab[f1.fila][f1.columna-1].conexion=NO_CONECTADA;
                        break;
    	}
        *conex=*conex-1;
	}

	if(tablero->tab[f2.fila][f2.columna].conexion!=NO_CONECTADA)
	{
		switch(tablero->tab[f2.fila][f2.columna].conexion)
		{
			case NORTE: tablero->tab[f2.fila-1][f2.columna].conexion=NO_CONECTADA;
						break;

			case SUR: tablero->tab[f2.fila+1][f2.columna].conexion=NO_CONECTADA;
                        break;

			case ESTE: tablero->tab[f2.fila][f2.columna+1].conexion=NO_CONECTADA;
                        break;

			case OESTE: tablero->tab[f2.fila][f2.columna-1].conexion=NO_CONECTADA;
                        break;
		}
        *conex=*conex-1;
	}

	if (eliminar == FALSE)
	{
		/*conecta las dos casillas*/
		if (f2.fila<f1.fila)
		{
			tablero->tab[f1.fila][f1.columna].conexion=NORTE;
			tablero->tab[f2.fila][f2.columna].conexion=SUR;
		
		}
		else if (f1.fila<f2.fila)
		{
			tablero->tab[f1.fila][f1.columna].conexion=SUR;
			tablero->tab[f2.fila][f2.columna].conexion=NORTE;
		}		

		if (f2.columna<f1.columna)
		{
			tablero->tab[f1.fila][f1.columna].conexion=OESTE;
			tablero->tab[f2.fila][f2.columna].conexion=ESTE;
		}
		else if (f1.columna<f2.columna)
		{
			tablero->tab[f1.fila][f1.columna].conexion=ESTE;
			tablero->tab[f2.fila][f2.columna].conexion=OESTE;
		}
		*conex=*conex+1;
	}

	if (eliminar == TRUE)
	{
		tablero->tab[f1.fila][f1.columna].conexion=NO_CONECTADA;
		tablero->tab[f2.fila][f2.columna].conexion= NO_CONECTADA;
	}
}

int eliminar_conexion(t_tablero *tablero, t_ficha f1, t_ficha f2, int *conex)
{
    /*sirve para eliminar una conexion y no crear otra*/
	if (f2.fila<f1.fila && tablero->tab[f1.fila][f1.columna].conexion == NORTE && tablero->tab[f2.fila][f2.columna].conexion == SUR)
        return TRUE;

    else if (f1.fila<f2.fila && tablero->tab[f1.fila][f1.columna].conexion == SUR && tablero->tab[f2.fila][f2.columna].conexion == NORTE)
        return TRUE;

    else if (f2.columna<f1.columna && tablero->tab[f1.fila][f1.columna].conexion == OESTE && tablero->tab[f2.fila][f2.columna].conexion == ESTE)
        return TRUE;

    else if (f1.columna<f2.columna && tablero->tab[f1.fila][f1.columna].conexion == ESTE && tablero->tab[f2.fila][f2.columna].conexion == OESTE)
		return TRUE;
	 
    else
        return FALSE;
	
	
}

