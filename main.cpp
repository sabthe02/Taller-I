#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{

ListaStrings L;
//boolean b = TRUE;
//ValorNodo V, V2, V3, V4, V5;
//char a = 'A';
//char o = 'O';
//char n = 'N';
//char p = '(';
//char p2 = ')';
//int indice;
ArbolExpre ar;
ListaExpresiones LE;
Expresion e;
String s, q;
Crear(L);
crearLista(LE);
crearArbol(ar);
strcrear(q);

while (!PerteneceIter("exit", L)) {

printf("\nIngrese comando: ");
strcrear(s);
scan(s);


partirStrings(s, L);


obtenerPalabraporPosicion(1, L,q);
printf("%d", PosicionListaString(q, L));
//printf("%d", largoListaStrings(L));
//desplegarBoolean(esNatural(darPalabraDeLista("2",L)));
print (q);

//DesplegarIter(L);


if (!Vacia(L)){
        if (PerteneceIter("atomic", L)) {
            atomic(L, LE, e, ar);
        }
//        else {
//                if (PerteneceIter("compound", L)) {
//                    compound (L, LE, e, ar);
//                }

////            // En el caso de  otros comandos
//
//            // Si no se ingresó ningún comando
                else {
                    printf("\nPor favor ingrese un comando valido (atomic, compound, evaluate, show, save, load, exit)");
                }
//        }
vaciarListaStrings(L);

}
// si no se ha ingresado nada
else {
    printf("\nNo se ha ingresado ningún comando");
 }

}

//
//String nombrearchivo = "test.dat";
//
//
//
//insertarParentesisNodo(p, V);
//asignarIndiceNodo(1, V);
//insertarOperadorNodo(n, V3);
//asignarIndiceNodo(2, V3);
//insertarValorNodo(b, V2);
//asignarIndiceNodo(3, V2);
//insertarParentesisNodo(p2,V5);
//asignarIndiceNodo(4, V5);
//
//
//crearArbol(ar);
//insertarValorEnOrden(V, ar);
//insertarValorEnOrden(V3, ar);
//insertarValorEnOrden(V2, ar);
//insertarValorEnOrden(V5, ar);
//desplegarNodosArbolOrden(ar);
//
//FILE *f = fopen(nombrearchivo, "wb");
//
//BajarArbolExpre(ar, f);
//
//fclose(f);
//
//
//LevantarArbolExpre(ar, nombrearchivo);
//
//
//desplegarNodosArbolOrden(ar);
//
////desplegarDatoNodoArbol(V);
////printf(" Indice: %d", darIndiceNodoArbol(V));
////desplegarDatoNodoArbol(V3);
////printf(" Indice: %d", darIndiceNodoArbol(V3));
////desplegarDatoNodoArbol(V2);
////printf(" Indice: %d", darIndiceNodoArbol(V2));
////desplegarDatoNodoArbol(V5);
////printf(" Indice: %d", darIndiceNodoArbol(V5));
}

