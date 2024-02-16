#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{
String c, d, e, f;
ListaStrings L;

printf("\nIngrese cadena de caracteres con blancos al principio ");
strcrear(c);
scan(c);
printf("\n");

Crear (L);

partirStrings(c, L);
DesplegarIter(L);
printf("El largo de la lista es: %d", largoListaStrings(L));

//
//if (!esVacio(c)) {
//eliminarBlancosPrincipio(c, d);
//dividirString(d, e, f);
//Crear (L);
//InsBackIter(e, L);
//DesplegarIter(L);
//printf("El largo de la lista es: %d", largoListaStrings(L));
//
//}



}

