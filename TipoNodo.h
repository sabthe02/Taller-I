#ifndef TIPONODO_H_INCLUDED
#define TIPONODO_H_INCLUDED

#include <stdio.h>

typedef enum {VALOR, OPERADOR, PARENTESIS} TipoNodo;

//Mostrar por pantalla el tipo del nodo
void desplegarTipo (TipoNodo tipo);

//Devolver tipo del Nodo
TipoNodo darTipo (TipoNodo tipo);

#endif // TIPONODO_H_INCLUDED
