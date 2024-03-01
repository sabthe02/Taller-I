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

////Dada una lista y una expresión, agrega dicha expresión al final de la lista.
void insertarNodoEnlista (Expresion e, ListaExpresiones &LE);
//
//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
int largoListaExpresiones (ListaExpresiones LE);
//
////Dada una lista y un número de lista, despliega la expresión en ese lugar.
void desplegarPorNumero (ListaExpresiones LE, int numero);
//
//Dado un ID, revisa si existe en ListaExpresiones
boolean PerteneceAListaExpreConID (int Id, ListaExpresiones LE);

//Dado un ID, devuelve la Expresión correspondiente de ListaExpresiones
Expresion darExpresionConID (int Id, ListaExpresiones LE);

// liberar memoria lista
void liberarMemoriaListaE (ListaExpresiones &LE);

//*Dada una lista y una expresion, devuelve TRUE si dicha expresión pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIterExpre(ListaExpresiones LE, Expresion e);
//


#endif // LISTAEXPRESIONES_H_INCLUDED
