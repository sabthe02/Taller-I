#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{
boolean b = TRUE;
ValorNodo V, V2, V3, V4, V5;
char a = 'A';
char o = 'O';
char n = 'N';
char p = '(';
char p2 = ')';
int indice;
ArbolExpre ar;

String nombrearchivo = "test.dat";

insertarParentesisNodo(p, V);
asignarIndiceNodo(1, V);
insertarOperadorNodo(n, V3);
asignarIndiceNodo(2, V3);
insertarValorNodo(b, V2);
asignarIndiceNodo(3, V2);
insertarParentesisNodo(p2,V5);
asignarIndiceNodo(4, V5);


crearArbol(ar);
insertarValorEnOrden(V, ar);
insertarValorEnOrden(V3, ar);
insertarValorEnOrden(V2, ar);
insertarValorEnOrden(V5, ar);
desplegarNodosArbolOrden(ar);

FILE *f = fopen(nombrearchivo, "wb");

BajarArbolExpre(ar, f);

fclose(f);


LevantarArbolExpre(ar, nombrearchivo);


desplegarNodosArbolOrden(ar);

//desplegarDatoNodoArbol(V);
//printf(" Indice: %d", darIndiceNodoArbol(V));
//desplegarDatoNodoArbol(V3);
//printf(" Indice: %d", darIndiceNodoArbol(V3));
//desplegarDatoNodoArbol(V2);
//printf(" Indice: %d", darIndiceNodoArbol(V2));
//desplegarDatoNodoArbol(V5);
//printf(" Indice: %d", darIndiceNodoArbol(V5));
}

