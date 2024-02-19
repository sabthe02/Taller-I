#ifndef ARBOLEXPRE_H_INCLUDED
#define ARBOLEXPRE_H_INCLUDED

#include "ValorNodo.h"


typedef struct nodoA 	{ValorNodo info;
                        nodoA *hizq;
                        nodoA *hder;
                        } NodoA;

typedef NodoA *ArbolExpre;


//Crear un �rbol
void crearArbol (ArbolExpre &a);

// Saber si el �rbol est� vac�o
boolean ArbolEsVacio (ArbolExpre a);

// Devolver raiz
//Precondici�n: �rbol no vac�o
ValorNodo darRaiz (ArbolExpre a);

// Obtener sub�rbol izquierdo
//Precondici�n: �rbol no vac�o
ArbolExpre HijoIzq (ArbolExpre a);

// Obtener sub�rbol derecho
//Precondici�n: �rbol no vac�o
ArbolExpre HijoDer (ArbolExpre a);

// Dados dos �rboles y un valor, devolver un nuevo �rbol, colocando el valor como ra�z y los dos �rboles como sub�rboles
//Precondici�n: el valor no exist�a previamente en el �rbol
// Precondici�n: El �ndice de ValorNodo tiene que estar asignado
// Procedimiento para subir a memoria los nodos seg�n su �ndice.
void insertarValorEnOrden (ValorNodo valor, ArbolExpre &a);

// Insertar valor at�mico
// Precondici�n: Valor a insertar convertido a booleano
void insertarValorArbol (boolean v, ArbolExpre &a);

// Insertar operador a nodo
// Precondici�n: String "AND" u "OR" convertido a 'A' u 'O'
void insertarOperador (char o, ValorNodo &valor);

// Insertar par�ntesis a nodo
void insertarParentesisNodo (char p, ValorNodo &valor);

// Asignar �ndice a nodo (cuando se bajar� a archivo)
void asignarIndiceNodo (int indice, ValorNodo &valor);

// liberar memoria arbol
void liberarMemoriaArbol(ArbolExpre &a);

// Listar todos los nodos del �rbol en pantalla, recorri�ndolo en �rden
void desplegarNodosArbolOrden (ArbolExpre a);

////Revisa si existe el �ndice en el �rbol
//boolean existeEnArbol (ArbolExpre a, int indice);
//
////Determina nodo con menor �ndice
//ValorNodo Minimo (ArbolExpre a);
//
////Borra del �rbol nodo con menor �ndice
//void Borrar_Minimo (ArbolExpre &a);
//
////Dado el �ndice, eliminar dicho nodo del sistema.
//// Precondici�n, �ndice existe en el sistema.
//void eliminarConIndice (int indice, ArbolExpre &a);
//

//
//// Listar aquellos pacientes registrados en el sistema que a�n no han realizado ninguna consulta al dentista.
//// Los datos de cada paciente (c�dula, nombre, apellido, tel�fono y cantidad de consultas realizadas hasta el momento)
////deben listarse todos en una misma l�nea.
//void listarPacientesSinConsultas (ABB a);
//
////Sumarle una consulta al paciente con la c�dula que realiz� una consulta
//void sumarConsultaAlABB (ABB &a, long int ced);
//
//// Dada una cantidad de consultas, obtener la cantidad de pacientes registrados en el sistema que han realizado al menos dicha cantidad de consultas
////hasta el momento.
//int obtenerPacientesConCantidadDeConsultas (ABB a, int CaConsultas);
//


#endif // ARBOLEXPRE_H_INCLUDED
