#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;

//Mostrar por pantalla el booleano
void desplegarBoolean (boolean valor);

//Devolver booleano
boolean darBoolean (boolean valor);

#endif // BOOLEAN_H_INCLUDED
