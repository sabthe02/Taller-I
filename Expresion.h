#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include "ArbolExpre.h"

typedef struct 	{int numero;
                ArbolExpre arbol;
                } Expresion;


void asignarNumeroExpresion (Expresion &e, int num);

void asignarArbolExpresion (Expresion &e, ArbolExpre ar);

int seleccionarNumeroExpresion (Expresion e);

ArbolExpre seleccionarArbolExpre (Expresion e);

void crearExpresion(ArbolExpre a, int indice, Expresion &expre);
/*precondicion: e no es vacio*/
void desplegarExpresion (Expresion e);

//// Implementar
//void crearExpresion (ArbolExpre arbol, int indice, Expresion &expre);


#endif // EXPRESION_H_INCLUDED
