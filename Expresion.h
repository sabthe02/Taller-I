#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include "ArbolExpre.h"

typedef struct 	{int numero;
                ArbolExpre arbol;
                } Expresion;


void asignarNumeroExpresion (Expresion &e, int num);

int seleccionarNumeroExpresion (Expresion e);

ArbolExpre seleccionarArbolExpre (Expresion e);

//
//void desplegarExpresion (Expresion e);
//
//void cargarExpresion (Expresion &e);


//
//int seleccionarCantConsultas (paciente p);
//
//Lista seleccionarConsultas (paciente p);
//
////Precondición: Paciente existe
//void sumarConsulta (paciente &p);

#endif // EXPRESION_H_INCLUDED
