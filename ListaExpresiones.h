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

//Obtiene el primer elemento de la lista
///* Precondición: lista NO vacía */
Expresion PrimeroExpre(ListaExpresiones LE);

// Obtiene el resto de la lista
///* Precondición: lista NO vacía */
void RestoExpre(ListaExpresiones &LE);


////Dada una lista y una expresión, agrega dicha expresión al final de la lista.
void insertarNodoEnlista (Expresion e, ListaExpresiones &LE);
//
//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
int largoListaExpresiones (ListaExpresiones LE);
//
////Dada una lista y un número de lista, despliega la expresión en ese lugar.
void desplegarPorNumero (ListaExpresiones LE, int numero);
//




//
// Dada una lista, insertar al principio de la lista un nuevo estructurado
//void InsFrontExpre(Expresion e, Lista &L);

////Dada una lista, devuelve su último elemento
//// Precondición: L no está vacía
//Expresion mayorIndiceLista (ListaExpresion L);
//

// liberar memoria lista
void liberarMemoriaListaE (ListaExpresiones &LE);

///*Dada una lista y una expresion, devuelve TRUE si dicha expresión pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIterExpre(ListaExpresiones LE, Expresion e);
//
///*Dada una lista y dos números enteros, sustituye cada ocurrencia del
//primer entero en la lista por el segundo entero.*/
//void SustituirIter(Lista &L, int e1, int e2);
//
///*Dada una lista, devuelve el mayor entero almacenado en ella*/
//// Precondición: L no está vacía
//Consulta MaximoIter(Lista L);
//
///*Dada una lista, devuelve otras dos nuevas listas, una de ellas
//conteniendo todos los valores pares de la lista original, y la otra conteniendo todos los valores
//impares de la lista original (se permite usar la operación básica InsFront para esta parte).
//No se debe modificar la lista original.*/
//void ParesImparesIter(Lista L, Lista &P, Lista &I);
//
////Registrar la realización de una nueva consulta hecha por un paciente.
//// Se debe verificar previamente que la cédula de dicho paciente exista en el sistema y que la fecha de la nueva consulta sea válida
//// e igual o posterior a la fecha de la última consulta registrada hasta el momento en el sistema.
//void registrarConsulta (Lista &L, Consulta c);
//
////-----
//// Obtener la cantidad de consultas de cada tipo
//void cantidadConsultasportratamiento (Lista L, int &tratamiento, int &protesis, int &saludable);
//
//// Dada una fecha, obtener la cantidad de consultas que fueron realizadas en dicha fecha: ")
//int cantidadConsultasporfecha (Lista L, fecha f);
//
//// desplegar consultas por cedula
//void desplegarporcedula (Lista L, long int cedula);

////desplegar consulta por fecha
////PRECONDICIÓN: la cédula debe existir
//void desplegarConsultaPorFecha(Lista L, fecha f);
//

#endif // LISTAEXPRESIONES_H_INCLUDED
