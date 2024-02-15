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

/* Precondici�n: lista NO vac�a */
Consulta Primero(Lista L);

/* Precondici�n: lista NO vac�a */
void Resto(Lista &L);

void InsFront(Lista &L, Consulta e);

//Dada una lista, devuelve su largo (la cantidad de elementos de la lista)
Consulta LargoIter(Lista L);

//Dada una lista, despliega sus valores por pantalla.
void DesplegarIter(Lista L);

//Dada una lista, devuelve su �ltimo elemento
// Precondici�n: L no est� vac�a
Consulta UltimoIter(Lista L);

/*Dada una lista y un n�mero entero, devuelve la cantidad de veces que dicho
entero aparece en la lista.*/
Consulta ContarIter(int e, Lista L);

/*Dada una lista y un n�mero entero, devuelve TRUE si dicho entero
pertenece a la lista y FALSE en caso contrario.*/
boolean PerteneceIter(Lista L, int e);

/*Dada una lista y dos n�meros enteros, sustituye cada ocurrencia del
primer entero en la lista por el segundo entero.*/
void SustituirIter(Lista &L, int e1, int e2);

/*Dada una lista, devuelve el mayor entero almacenado en ella*/
// Precondici�n: L no est� vac�a
Consulta MaximoIter(Lista L);

/*Dada una lista, devuelve otras dos nuevas listas, una de ellas
conteniendo todos los valores pares de la lista original, y la otra conteniendo todos los valores
impares de la lista original (se permite usar la operaci�n b�sica InsFront para esta parte).
No se debe modificar la lista original.*/
void ParesImparesIter(Lista L, Lista &P, Lista &I);

//Dada una lista y un n�mero entero, agrega dicho entero al final de la lista.
void InsBackIter(Lista &L, Consulta c);

//Registrar la realizaci�n de una nueva consulta hecha por un paciente.
// Se debe verificar previamente que la c�dula de dicho paciente exista en el sistema y que la fecha de la nueva consulta sea v�lida
// e igual o posterior a la fecha de la �ltima consulta registrada hasta el momento en el sistema.
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

/*Dada una lista y un n�mero de cedula, devuelve la cantidad de veces que dicho
cedula aparece en la lista.*/
int ContarCedulas (long int e, Lista L);

//elimina consulta
void eliminarConsulta(Lista &L, long int cedula);

//desplegar consulta por fecha
//PRECONDICI�N: la c�dula debe existir
void desplegarConsultaPorFecha(Lista L, fecha f);

// liberar memoria lista
void liberarMemoriaLista(Lista &L);

#endif // LISTAEXPRESIONES_H_INCLUDED
