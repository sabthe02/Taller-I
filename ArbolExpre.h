#ifndef ARBOLEXPRE_H_INCLUDED
#define ARBOLEXPRE_H_INCLUDED

#include "ValorNodo.h"

// A cambiar

typedef struct nodoA    {paciente info;
                        nodoA *hizq;
                        nodoA *hder;
                        }nodo;
typedef nodo *ABB;

//Crear un �rbol
void Crear (ABB &a);

// Saber si el �rbol est� vac�o
boolean Vacio (ABB a);

// Devolver raiz
//Precondici�n: �rbol no vac�o
paciente darRaiz (ABB a);

// Obtener sub�rbol izquierdo
//Precondici�n: �rbol no vac�o
ABB HijoIzq (ABB a);

// Obtener sub�rbol derecho
//Precondici�n: �rbol no vac�o
ABB HijoDer (ABB a);

// Dados dos �rboles y un valor, devolver un nuevo �rbol, colocando el valor como ra�z y los dos �rboles como sub�rboles
//Precondici�n: el valor no exist�a previamente en el ABB
void Insert (ABB &a, paciente valor);

//Revisa si existe la c�dula del paciente en el ABB
boolean existe (ABB a, long int cedula);

//Determina paciente con menor c�dula
paciente Minimo (ABB a);

//Borra del ABB paciente con menor c�dula
void Borrar_Minimo (ABB &a);

//Dada la c�dula que identifica a un paciente, eliminar dicho paciente del sistema.
//Se debe verificar previamente que dicha c�dula exista en el sistema.
//Tambi�n se deben eliminar del sistema todas las consultas realizadas por dicho paciente.
// Precondici�n, c�dula del paciente existe en el sistema.
void eliminarConCedula (long int cedula, ABB &a);

// Listar todos los pacientes registrados en el sistema, ordenados por c�dula de identidad de menor a mayor.
//Los datos de cada paciente (c�dula, nombre, apellido, tel�fono y cantidad de consultas realizadas hasta el momento)
//deben listarse todos en una misma l�nea.
void listarPacientes (ABB a);

// Listar aquellos pacientes registrados en el sistema que a�n no han realizado ninguna consulta al dentista.
// Los datos de cada paciente (c�dula, nombre, apellido, tel�fono y cantidad de consultas realizadas hasta el momento)
//deben listarse todos en una misma l�nea.
void listarPacientesSinConsultas (ABB a);

//Sumarle una consulta al paciente con la c�dula que realiz� una consulta
void sumarConsultaAlABB (ABB &a, long int ced);

// Dada una cantidad de consultas, obtener la cantidad de pacientes registrados en el sistema que han realizado al menos dicha cantidad de consultas
//hasta el momento.
int obtenerPacientesConCantidadDeConsultas (ABB a, int CaConsultas);

// liberar memoria arbol
void liberarArbol(ABB &a);

#endif // ARBOLEXPRE_H_INCLUDED
