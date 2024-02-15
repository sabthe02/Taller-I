#ifndef LISTAEXPRESIONES_H_INCLUDED
#define LISTAEXPRESIONES_H_INCLUDED

#include "Expresion.h"

// cambiar a requerimiento
typedef struct nodoB {
                        Consulta info;
                        nodoB *sig;
                     } nodo2;

typedef nodo2 *Lista;

//Crea una lista
void Crear (Lista &L);

//Verifica si la lista esta vacia
boolean Vacia(Lista L);

/* Precondición: lista NO vacía */
Consulta Primero(Lista L);

/* Precondición: lista NO vacía */
void Resto(Lista &L);

void InsFront(Lista &L, Consulta e);

//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
Consulta LargoIter(Lista L);

//Dada una lista, despliega sus valores por pantalla.
void DesplegarIter(Lista L);

//Dada una lista, devuelve su último elemento
// Precondición: L no está vacía
Consulta UltimoIter(Lista L);

/*Dada una lista y un número entero, devuelve la cantidad de veces que dicho
entero aparece en la lista.*/
Consulta ContarIter(int e, Lista L);

/*Dada una lista y un número entero, devuelve TRUE si dicho entero
pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIter(Lista L, int e);

/*Dada una lista y dos números enteros, sustituye cada ocurrencia del
primer entero en la lista por el segundo entero.*/
void SustituirIter(Lista &L, int e1, int e2);

/*Dada una lista, devuelve el mayor entero almacenado en ella*/
// Precondición: L no está vacía
Consulta MaximoIter(Lista L);

/*Dada una lista, devuelve otras dos nuevas listas, una de ellas
conteniendo todos los valores pares de la lista original, y la otra conteniendo todos los valores
impares de la lista original (se permite usar la operación básica InsFront para esta parte).
No se debe modificar la lista original.*/
void ParesImparesIter(Lista L, Lista &P, Lista &I);

//Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackIter(Lista &L, Consulta c);

//Registrar la realización de una nueva consulta hecha por un paciente.
// Se debe verificar previamente que la cédula de dicho paciente exista en el sistema y que la fecha de la nueva consulta sea válida
// e igual o posterior a la fecha de la última consulta registrada hasta el momento en el sistema.
void registrarConsulta (Lista &L, Consulta c);

//-----
// Obtener la cantidad de consultas de cada tipo
void cantidadConsultasportratamiento (Lista L, int &tratamiento, int &protesis, int &saludable);

// Dada una fecha, obtener la cantidad de consultas que fueron realizadas en dicha fecha: ")
int cantidadConsultasporfecha (Lista L, fecha f);

// desplegar consultas por cedula
void desplegarporcedula (Lista L, long int cedula);

// Obtener la cedula del paciente que ha realizado la mayor cantidad de consultas hasta el momento, junto con la cantidad de consultas correspondiente
//PRECONDICION - inicializar variables
void mayorcantidadconsultas (Lista L, long int &cedula, int &mayor);

/*Dada una lista y un número de cedula, devuelve la cantidad de veces que dicho
cedula aparece en la lista.*/
int ContarCedulas (long int e, Lista L);

//elimina consulta
void eliminarConsulta(Lista &L, long int cedula);

//desplegar consulta por fecha
//PRECONDICIÓN: la cédula debe existir
void desplegarConsultaPorFecha(Lista L, fecha f);

// liberar memoria lista
void liberarMemoriaLista(Lista &L);

#endif // LISTAEXPRESIONES_H_INCLUDED
