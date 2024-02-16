#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{
String c, s, st, st2;

printf("\nIngrese cadena de caracteres con blancos al principio ");
strcrear(c);
scan(c);

print(c);
printf("\n");

eliminarBlancosPrincipio (c, s);

print(s);

printf("\n");
dividirString (s, st, st2);
print(st);
printf("\n");
print(st2);

}
