#ifndef TABLERO_H
#define	TABLERO_H
#define MAX 20

typedef struct
{
	int num; //valor de la casilla de una matriz
	int conexion; //indica si la casilla esta conectada
}tcasilla;

typedef struct 
{ 
	int nfilas; //numero de filas del tablero
	int ncolumnas; //numero de columnas del tablero
	int dimension; //dimension del tablero
	tcasilla tab[MAX][MAX]; //elementos de la matriz del tablero
} t_tablero;

typedef struct
{
	int ex1; //extremo 1 de la conexion
	int ex2; //extremo 2 de la conexion
}tconexion;


void leer_tablero (t_tablero *tablero);

void imprimir_tablero (t_tablero tablero);

void realizar_jugada(t_tablero *tablero, int *conex);

void leer_jugada(t_tablero tablero, tconexion *v);

int comprobar_jugada (tconexion *v, int conex);


#endif




