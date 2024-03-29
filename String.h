#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdlib.h>
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

//Determinar si dos Strings son iguales
boolean streq (String s1, String s2);

//Copiar un String a otro
void strcop (String &s1,String s2);

// Transformar un String a un natural
int transformarANatural (String s);

// Determinar si un String es un natural
boolean esNatural (String s);

// Transformar un String a Boolean
boolean transformarStringABoolean (String s);

//Transformar AND u OR en 'A' u 'O'
char transformarStringOperadorAChar (String s);

// Determinar si un String es vac�o
boolean esVacio (String s);

// Copia hacia sb los caracteres de s,
//pero sin los blancos que puede tener al principio.
//Precondici�n: s no es vac�o
void eliminarBlancosPrincipio (String s, String &sb);

//Divide el string s en otros dos; en primero guarda
//la primera palabra del s y en el resto todo lo dem�s
// Precondici�n: s no es vac�o
void dividirString (String s, String &primero, String &resto);

//Divide el String nombre de un archivo con extensi�n en la parte del nombre y la extensi�n
void dividirStringDeArchivo (String s, String &primero, String &resto);

//Revisa si un string consiste solo en letras
boolean esAlfabetico(String s);

//Revisa si un String es igual a ".dat"
boolean tieneExtension (String s);

// Divide el String en dos y verifica si el nombre del archivo (la primer parte) es alfab�tico y la segunda parte termina en .dat
boolean esNombreArchivo (String s);


#endif // STRING_H_INCLUDED
