#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;
typedef char *String;

// crear un String nulo
void strcrear (String &s);

// libera la memoria ocupada por un String
void strdestruir (String &s);

//Devolver largo de un String
int strlar (String s);

//Imprimir un String
void print (String s);

//leer un String desde teclado
void scan (String &s);

// Determinar si un String es menor a otro
boolean strmen (String s1, String s2);

//Determinar si dos Strings son iguales
boolean streq (String s1, String s2);

//Copiar un String a otro
void strcop (String &s1,String s2);

// Concatenar un String detrás de otro
void strcon (String &s1, String s2);

// Intercambiar dos Strings
void strswp (String &s1,String &s2);

#endif // STRING_H_INCLUDED
