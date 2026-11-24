#ifndef FICHA_H
#define	FICHA_H

typedef struct 
{
	int fila; //fila de la ficha
	int columna;  //columna de la ficha
}t_ficha;

int fichaValida(t_tablero *tablero, t_ficha f1, t_ficha f2);

void leer_fichas (t_ficha *f1, t_ficha *f2);

void conexion_fichas (t_tablero *tablero, t_ficha f1, t_ficha f2, int *conex);

int eliminar_conexion (t_tablero *tablero, t_ficha f1, t_ficha f2, int *conex);

#endif
