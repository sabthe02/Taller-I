#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "String.h"
#include "ListaExpresiones.h"
#include "Archivo.h"

typedef struct nodoS {String palabra;
                nodoS *sig;
                }NodoS;

typedef NodoS *ListaStrings;


//Crea una lista
void Crear (ListaStrings &L);

//Verifica si la lista esta vacia
boolean Vacia(ListaStrings L);

// Devuelve la primer palabra de la lista
/* Precondición: lista NO vacía */
String Primero(ListaStrings L);

// Devuelve el resto de una lista
/* Precondición: lista NO vacía */
void Resto(ListaStrings &L);

//Dada una lista y un String, agrega dicho String al final de la lista.
void InsBackIter(String s, ListaStrings &L);

//Dada una lista, inserta un String al principio de la lista
void InsFront(String s, ListaStrings &L);

//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
int largoListaStrings(ListaStrings L);

//Dada una lista, despliega sus valores por pantalla.
void DesplegarIter(ListaStrings L);

/*Dada una lista y un String, determina en qué lugar de la lista se encuentra el String*/
//Precondición: String existe en la lista
int PosicionListaString (String s, ListaStrings L);

//Dada una lista, devuelve su último elemento
//Precondición: L no está vacía
String UltimoIter(ListaStrings L);

/*Dada una lista y un String, devuelve TRUE si dicho String
pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIter(String s,ListaStrings L);

// Partir Strings en palabras
//Precondición: Crear Lista en main
void partirStrings (String s, ListaStrings &L);

//Dado un String y una Lista de Strings, devuelve la palabra de la lista
//Precondición: La Palabra pertenece al String
String darPalabraDeLista (String s, ListaStrings L);

//Borra contenido y strings dinámicos de la lista
void vaciarListaStrings (ListaStrings &L);

// Dada su posición, obtener esa palabra de la Lista de Strings
//Precondicion: Palabra pertenece a la lista
// Precondición: La posición es una posición válida
String darPalabraporPosicion (int posicion, ListaStrings L);

// liberar memoria ListaString
void liberarMemoriaListaS(ListaStrings &L);

// Ejecuta comando atomic
void atomic (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

// Ejecuta comando compound
void compound (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

//Ejecuta comando show
void show (ListaStrings L, ListaExpresiones LE, Expresion e, ArbolExpre ar);

//Ejecuta comando evaluate
void evaluate (ListaStrings L, ListaExpresiones LE, Expresion e, ArbolExpre ar);

//Ejecuta comando save
void save (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

//Ejecuta comando load
void load (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

//Ejecuta comando exit
void exit (ListaStrings &L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar); ///// preguntar por cabezal y si procedimiento es correcto



#endif // LISTASTRINGS_H_INCLUDED
