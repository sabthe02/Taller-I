#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "ListaExpresiones.h"
#include "ListaStrings.h"

//Saber si existe un archivo
boolean ExisteArchivo (String nombrearchivo);

// ValorNodo
//Bajar el estructurado ValorNodo a Archivo
// Precondición: El archivo viene abierto para escritura.
void bajarValorNodo (ValorNodo v, FILE *f);

// Levantar el estructurado ValorNodo a memoria
// Precondición: El archivo viene abierto para escritura.
void levantarValorNodo (ValorNodo &v, FILE *f);

// ArbolExpre
////Baja árbol a un archivo en preorden
////Precondición: El archivo viene abierto para escritura
void BajarArbolExpre (ArbolExpre a, FILE *f);
//
////Levanta árbol a memoria (órden)
void LevantarArbolExpre (ArbolExpre &a, String nombrearchivo);

////Bajar lista a un archivo
//void Bajar_Consultas (Lista L , String nomArchConsultas);
//
////Levantar lista a memoria
//void Levantar_Consultas (Lista &L, String nomArchConsultas);
//
////Baja ABB a un archivo
////Precondición: El archivo viene abierto para escritura
//void BajarPacientes (ABB a, FILE *f);
//
////Levanta ABB a memoria
//void LevantarPacientes (ABB &a, String nomArchPacientes);
//

#endif // ARCHIVO_H_INCLUDED
