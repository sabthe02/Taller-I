#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "String.h"
#include "ListaExpresiones.h"


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
String darPalabraporPosicion (int posicion, ListaStrings L); // no funciona

//obtener palabra dada una Lista y su posición
void obtenerPalabraporPosicion (int posicion, ListaStrings L, String &s);

// liberar memoria ListaString
void liberarMemoriaListaS(ListaStrings &L);

// Ejecuta comando atomic
void atomic (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

// Ejecuta comando compound
void compound (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

//Ejecuta comando show
void show (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);

//Ejecuta comando evaluate
void evaluate (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar);
////////////////////////////
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
//
//// Obtener la cedula del paciente que ha realizado la mayor cantidad de consultas hasta el momento, junto con la cantidad de consultas correspondiente
////PRECONDICION - inicializar variables
//void mayorcantidadconsultas (Lista L, long int &cedula, int &mayor);
//
///*Dada una lista y un número de cedula, devuelve la cantidad de veces que dicho
//cedula aparece en la lista.*/
//int ContarCedulas (long int e, Lista L);
//
////elimina consulta
//void eliminarConsulta(Lista &L, long int cedula);
//
////desplegar consulta por fecha
////PRECONDICIÓN: la cédula debe existir
//void desplegarConsultaPorFecha(Lista L, fecha f);
//


#endif // LISTASTRINGS_H_INCLUDED
