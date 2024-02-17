#ifndef VALORNODO_H_INCLUDED
#define VALORNODO_H_INCLUDED

#include "TipoNodo.h"
#include "Boolean.h"


typedef struct {int indice;
TipoNodo discriminante;
				union 	{boolean valor;
						char operador;
						char parentesis;
						} dato;
			}ValorNodo;


// Desplegar operador
void desplegarOperador (ValorNodo valor);

// Desplegar parentesis
void desplegarParentesis (ValorNodo valor);

//Desplegar dato Nodo Arbol
void desplegarDatoNodoArbol (ValorNodo valor);

// Selectora indice
int darIndiceNodoArbol (ValorNodo valor);

// Selectora discriminante
TipoNodo darDiscriminante (ValorNodo valor);

// Selectora Valor Booleano
boolean darBooleanoArbol (ValorNodo valor);

// Selectora Operador
char darOperadorArbol (ValorNodo valor);

// Selectora Parentesis
char darParentesisArbol (ValorNodo valor);

// Insertar valor atómico a nodo
// Precondición: Valor a insertar convertido a booleano
void insertarValorNodo (boolean v, ValorNodo &valor);

// Insertar operador a nodo
// Precondición: String "AND" u "OR" convertido a 'A' u 'O'
void insertarOperadorNodo (char o, ValorNodo &valor);

// Insertar paréntesis a nodo
void insertarParentesisNodo (char p, ValorNodo &valor);

// Asignar índice a nodo (cuando se bajará a archivo)
void asignarIndiceNodo (int indice, ValorNodo &valor);

#endif // VALORNODO_H_INCLUDED
