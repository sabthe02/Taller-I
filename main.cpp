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

insertarParentesisNodo(p, V);
desplegarDatoNodoArbol(V);

insertarOperadorNodo(n, V3);
desplegarDatoNodoArbol(V3);

insertarValorNodo(b, V2);
desplegarDatoNodoArbol(V2);


insertarParentesisNodo(p2,V5);
desplegarDatoNodoArbol(V5);

}

