#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "ListaExpresiones.h"
#include "ListaStrings.h"


//Saber si existe un archivo
boolean ExisteArchivo (String nombrearchivo);
//
////Bajar String a archivo
//void Bajar_String (String s, FILE * f);
//
////Levantar String a memoria
//void Levantar_String (String &s, FILE * f);
//
//// Expresion
//
////Bajar Expresion a un archivo
//void bajarEvaluacion (String nombrearchivo, file *f);
////
//////Levantar Expresión a memoria
//void levantarEvaluacion (String &nombrearchivo, file *f);
//
////Bajar lista a un archivo
//void Bajar_Consultas (Lista L , String nomArchConsultas);
//
////Levantar lista a memoria
//void Levantar_Consultas (Lista &L, String nomArchConsultas);
//
////PACIENTES
//// Escribe en el archivo los datos del paciente p.
//// Precondición: El archivo viene abierto para escritura.
//void BajarPaciente (paciente p, FILE * f);
//
//// Levanta Paciente de memoria
//// Precondición: El archivo viene abierto para escritura
//void LevantarPaciente (paciente &p, FILE * f);
//
////Baja ABB a un archivo
////Precondición: El archivo viene abierto para escritura
//void BajarPacientes (ABB a, FILE *f);
//
////Levanta ABB a memoria
//void LevantarPacientes (ABB &a, String nomArchPacientes);
//

#endif // ARCHIVO_H_INCLUDED
