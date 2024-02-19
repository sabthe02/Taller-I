#ifndef ARBOLEXPRE_H_INCLUDED
#define ARBOLEXPRE_H_INCLUDED

#include "ValorNodo.h"


typedef struct nodoA 	{ValorNodo info;
                        nodoA *hizq;
                        nodoA *hder;
                        } NodoA;

typedef NodoA *ArbolExpre;


//Crear un árbol
void crearArbol (ArbolExpre &a);

// Saber si el árbol está vacío
boolean ArbolEsVacio (ArbolExpre a);

// Devolver raiz
//Precondición: Árbol no vacío
ValorNodo darRaiz (ArbolExpre a);

// Obtener subárbol izquierdo
//Precondición: Árbol no vacío
ArbolExpre HijoIzq (ArbolExpre a);

// Obtener subárbol derecho
//Precondición: Árbol no vacío
ArbolExpre HijoDer (ArbolExpre a);

// Dados dos árboles y un valor, devolver un nuevo árbol, colocando el valor como raíz y los dos árboles como subárboles
//Precondición: el valor no existía previamente en el árbol
// Precondición: El índice de ValorNodo tiene que estar asignado
// Procedimiento para subir a memoria los nodos según su índice.
void insertarValorEnOrden (ValorNodo valor, ArbolExpre &a);

// Insertar valor atómico
// Precondición: Valor a insertar convertido a booleano
void insertarValorArbol (boolean v, ArbolExpre &a);

// Insertar operador a nodo
// Precondición: String "AND" u "OR" convertido a 'A' u 'O'
void insertarOperador (char o, ValorNodo &valor);

// Insertar paréntesis a nodo
void insertarParentesisNodo (char p, ValorNodo &valor);

// Asignar índice a nodo (cuando se bajará a archivo)
void asignarIndiceNodo (int indice, ValorNodo &valor);

// liberar memoria arbol
void liberarMemoriaArbol(ArbolExpre &a);

// Listar todos los nodos del árbol en pantalla, recorriéndolo en órden
void desplegarNodosArbolOrden (ArbolExpre a);

////Revisa si existe el índice en el árbol
//boolean existeEnArbol (ArbolExpre a, int indice);
//
////Determina nodo con menor índice
//ValorNodo Minimo (ArbolExpre a);
//
////Borra del árbol nodo con menor índice
//void Borrar_Minimo (ArbolExpre &a);
//
////Dado el índice, eliminar dicho nodo del sistema.
//// Precondición, índice existe en el sistema.
//void eliminarConIndice (int indice, ArbolExpre &a);
//

//
//// Listar aquellos pacientes registrados en el sistema que aún no han realizado ninguna consulta al dentista.
//// Los datos de cada paciente (cédula, nombre, apellido, teléfono y cantidad de consultas realizadas hasta el momento)
////deben listarse todos en una misma línea.
//void listarPacientesSinConsultas (ABB a);
//
////Sumarle una consulta al paciente con la cédula que realizó una consulta
//void sumarConsultaAlABB (ABB &a, long int ced);
//
//// Dada una cantidad de consultas, obtener la cantidad de pacientes registrados en el sistema que han realizado al menos dicha cantidad de consultas
////hasta el momento.
//int obtenerPacientesConCantidadDeConsultas (ABB a, int CaConsultas);
//


#endif // ARBOLEXPRE_H_INCLUDED
