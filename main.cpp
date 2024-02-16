#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{
String c, s;

printf("\nIngrese cadena de caracteres con blancos al principio ");
strcrear(c);

scan(c);
fflush(stdin);
print(c);
printf("\n");

eliminarBlancosPrincipio (c, s);

print(s);


}
