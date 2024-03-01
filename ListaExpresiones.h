#ifndef LISTAEXPRESIONES_H_INCLUDED
#define LISTAEXPRESIONES_H_INCLUDED

#include "Expresion.h"


typedef struct nodoL {Expresion expre;
                        nodoL *sig;
                        } NodoL;

typedef NodoL *ListaExpresiones;

//Crea una lista
void crearLista (ListaExpresiones &LE);
//
//Verifica si la lista esta vacia
boolean VaciaExpre(ListaExpresiones LE);

////Dada una lista y una expresi�n, agrega dicha expresi�n al final de la lista.
void insertarNodoEnlista (Expresion e, ListaExpresiones &LE);
//
//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
int largoListaExpresiones (ListaExpresiones LE);
//
////Dada una lista y un n�mero de lista, despliega la expresi�n en ese lugar.
void desplegarPorNumero (ListaExpresiones LE, int numero);
//
//Dado un ID, revisa si existe en ListaExpresiones
boolean PerteneceAListaExpreConID (int Id, ListaExpresiones LE);

//Dado un ID, devuelve la Expresi�n correspondiente de ListaExpresiones
Expresion darExpresionConID (int Id, ListaExpresiones LE);

// liberar memoria lista
void liberarMemoriaListaE (ListaExpresiones &LE);

//*Dada una lista y una expresion, devuelve TRUE si dicha expresi�n pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIterExpre(ListaExpresiones LE, Expresion e);
//


#endif // LISTAEXPRESIONES_H_INCLUDED
