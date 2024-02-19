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
///* Precondici�n: lista NO vac�a */
Expresion PrimeroExpre(ListaExpresiones LE);

// Obtiene el resto de la lista
///* Precondici�n: lista NO vac�a */
void RestoExpre(ListaExpresiones &LE);


////Dada una lista y una expresi�n, agrega dicha expresi�n al final de la lista.
void insertarNodoEnlista (Expresion e, ListaExpresiones &LE);
//
//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
int largoListaExpresiones (ListaExpresiones LE);
//
////Dada una lista y un n�mero de lista, despliega la expresi�n en ese lugar.
void desplegarPorNumero (ListaExpresiones LE, int numero);
//




//
// Dada una lista, insertar al principio de la lista un nuevo estructurado
//void InsFrontExpre(Expresion e, Lista &L);

////Dada una lista, devuelve su �ltimo elemento
//// Precondici�n: L no est� vac�a
//Expresion mayorIndiceLista (ListaExpresion L);
//

// liberar memoria lista
void liberarMemoriaListaE (ListaExpresiones &LE);

///*Dada una lista y una expresion, devuelve TRUE si dicha expresi�n pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIterExpre(ListaExpresiones LE, Expresion e);
//
///*Dada una lista y dos n�meros enteros, sustituye cada ocurrencia del
//primer entero en la lista por el segundo entero.*/
//void SustituirIter(Lista &L, int e1, int e2);
//
///*Dada una lista, devuelve el mayor entero almacenado en ella*/
//// Precondici�n: L no est� vac�a
//Consulta MaximoIter(Lista L);
//
///*Dada una lista, devuelve otras dos nuevas listas, una de ellas
//conteniendo todos los valores pares de la lista original, y la otra conteniendo todos los valores
//impares de la lista original (se permite usar la operaci�n b�sica InsFront para esta parte).
//No se debe modificar la lista original.*/
//void ParesImparesIter(Lista L, Lista &P, Lista &I);
//
////Registrar la realizaci�n de una nueva consulta hecha por un paciente.
//// Se debe verificar previamente que la c�dula de dicho paciente exista en el sistema y que la fecha de la nueva consulta sea v�lida
//// e igual o posterior a la fecha de la �ltima consulta registrada hasta el momento en el sistema.
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
////PRECONDICI�N: la c�dula debe existir
//void desplegarConsultaPorFecha(Lista L, fecha f);
//

#endif // LISTAEXPRESIONES_H_INCLUDED
