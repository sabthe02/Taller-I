#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{

ListaStrings L;
boolean b = TRUE;
ValorNodo V, V2, V3, V4, V5;
char a = 'A';
char o = 'O';
char n = 'N';
char p = '(';
char p2 = ')';
int indice;
ArbolExpre ar;
ListaExpresiones LE;
Expresion e;
String s, q;

printf("\nIngrese comando: ");
strcrear(s);
scan(s);
Crear(L);
crearLista(LE);

partirStrings(s, L);

if (!Vacia(L)){
        if (PerteneceIter("atomic", L)) {
            if (PosicionListaString("atomic", L) == 1) {
                if (largoListaStrings(L) != 2) {
                    printf("\nCantidad de parámetros incorrecta, deben ser 2");
                }
                else {
                        if (((PerteneceIter("true", L)) && (PosicionListaString("true", L) == 2)) || ((PerteneceIter("false", L)) && (PosicionListaString("false", L) == 2))) {
                            if ((PerteneceIter("true", L)) && (PosicionListaString("true", L) == 2)) {
                                crearArbol(ar);
                                insertarValorArbol ((transformarStringABoolean ("true")), ar);
                                asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                insertarNodoEnlista(e, LE);
                                }
                                else {
                                    crearArbol(ar);
                                    insertarValorArbol ((transformarStringABoolean ("false")), ar);
                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                    insertarNodoEnlista(e, LE);
                                }

                        }
                        else {
                            printf("\nDebe ingresar 'true' o 'false' como segunda palabra");
                        }
                }
            }
            else {
                printf("\nLa palabra 'atomic' debe ir en primer lugar y en segundo 'true' o 'false'");
            }
        }
else {
    printf("\nNo se ha ingresado ningún comando");
 }
desplegarPorNumero (LE, 1); // a modo de testeo con 1

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

