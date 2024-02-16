#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{
String c;
ListaStrings L;

printf("\nIngrese cadena de caracteres con blancos al principio ");
strcrear(c);
scan(c);
printf("\n");
partirStrings(c, L);

DesplegarIter (L);


}
