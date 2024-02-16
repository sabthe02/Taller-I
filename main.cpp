#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{
String c, d;
int i;
ListaStrings L;

printf("\nIngrese cadena de caracteres con blancos al principio ");
strcrear(c);
scan(c);
printf("\n");

Crear (L);

partirStrings(c, L);
DesplegarIter(L);
printf("\nEl largo de la lista es: %d", largoListaStrings(L));

printf("\nIngrese palabra que se quiere devoler ");
strcrear(d);
scan(d);
printf("\nIngrese posicion ");
scanf("%d", &i);
printf("\n");
print(obtenerPalabraDeListaStrings (d, i, L));


}

