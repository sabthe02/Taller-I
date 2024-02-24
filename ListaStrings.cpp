#include "ListaStrings.h"


void Crear (ListaStrings &L) {
    L = NULL;
}

boolean Vacia(ListaStrings L) {
    boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}


String Primero(ListaStrings L) {
    return L->palabra;
}


void Resto(ListaStrings &L) {
    ListaStrings aux = L;
    L = L->sig;
    delete aux;
}

void InsBackIter(String s, ListaStrings &L)
{
    ListaStrings nuevo = new NodoS;
    nuevo->palabra = s;
    nuevo->sig = NULL;
    if (L == NULL)
        L = nuevo;
    else {
        ListaStrings aux = L;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}

void InsFront(String s, ListaStrings &L) {
    ListaStrings aux = new NodoS;
    aux->palabra = s;
    aux->sig = L;
    L = aux;
}

int largoListaStrings (ListaStrings L) {
int contador = 0;

while (L!= NULL) {
        contador++;
        L = L -> sig;
}

return contador;

}

void DesplegarIter(ListaStrings L)
{
    while (L != NULL)
    {
        print (L->palabra);
        printf(" ");
        L = L->sig;
    }
}

int PosicionListaString (String s, ListaStrings L) { // ver si anda bien
int posicion = 0;
boolean encontre = FALSE;

while (L!= NULL && !encontre) {
    if (streq(s,L->palabra)) {
        encontre = TRUE;
    }
    else {

    L = L -> sig;
    }
    posicion++;
}
return posicion;
}


String UltimoIter (ListaStrings L) {

while ((L-> sig) != NULL) {
        L = L -> sig;
}

return L->palabra;
}


boolean PerteneceIter (String s, ListaStrings L) {

boolean pertenece = FALSE;

while (L!=NULL && !pertenece) {
    if (streq(s, L->palabra)) {
        pertenece = TRUE;
    }
    else {
        L = L -> sig;
    }
}
return pertenece;

}

void partirStrings (String s, ListaStrings &L) {
String s2, p, r;
strcrear(s2);
strcrear(p);
strcrear(r);

if (!esVacio(s)) {
eliminarBlancosPrincipio (s, s2);
dividirString(s2, p, r);
InsBackIter(p, L);
partirStrings(r, L->sig);
}

}

String darPalabraDeLista (String s, ListaStrings L) {
boolean encontre = FALSE;

while (L!= NULL && !encontre) {
    if (streq(s,L->palabra)) {
        encontre = TRUE;
        return L->palabra;
    }
    else {
    L = L -> sig;
    }
}
}

void vaciarListaStrings (ListaStrings &L) {

while (L != NULL)
    {
        ListaStrings lista = L;
        strdestruir(L->palabra);
        L = L->sig;
        delete lista;
    }
}



String darPalabraporPosicion (int posicion, ListaStrings L) { // no funciona, salvo la posición 1

boolean encontre = FALSE;

while (L!=NULL && !encontre) {
    if (PosicionListaString (L->palabra,L) == posicion) {
        if (PerteneceIter(L->palabra,L)) {
        encontre = TRUE;
        return L->palabra;
        }
    }
    else {
        L = L -> sig;
    }
}
}


void obtenerPalabraporPosicion (int posicion, ListaStrings L, String &s) { // no funciona, salvo la posición 1

boolean encontre = FALSE;

while (L!=NULL && !encontre) {
    if (PosicionListaString (L->palabra,L) == posicion) {
        if (PerteneceIter(L->palabra,L)) {
        encontre = TRUE;
        strcop(s, L->palabra);
        }
    }
    else {
        L = L -> sig;
    }
}
}



 void liberarMemoriaListaS(ListaStrings &L)
{
    while (L != NULL)
    {
        ListaStrings lista = L;
        L = L->sig;
        delete lista;
    }
}

void atomic (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {

            if (PosicionListaString("atomic", L) != 1) {
                   printf("\nLa palabra 'atomic' debe ir en primer lugar y en segundo 'true' o 'false'");
            }
            else {
                    if (largoListaStrings(L) != 2) {
                        printf("\nCantidad de parametros incorrecta, deben ser 2");
                    }
                    else {
                            if (((PerteneceIter("true", L)) && (PosicionListaString("true", L) == 2)) || ((PerteneceIter("false", L)) && (PosicionListaString("false", L) == 2))) {
                                if ((PerteneceIter("true", L)) && (PosicionListaString("true", L) == 2)) {
                                    insertarValorArbol ((transformarStringABoolean ("true")), ar);
                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                    asignarArbolExpresion(e, ar);
                                    insertarNodoEnlista(e, LE);
                                    desplegarPorNumero(LE, seleccionarNumeroExpresion(e));

                                    }
                                    else {
                                        insertarValorArbol ((transformarStringABoolean ("false")), ar);
                                        asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                        asignarArbolExpresion(e, ar);
                                        insertarNodoEnlista(e, LE);
                                        desplegarPorNumero (LE, seleccionarNumeroExpresion(e));
                                    }

                            }
                            else {
                                printf("\nDebe ingresar 'true' o 'false' como segunda palabra");
                            }
                }
            }

}

void compound (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
int Id1, Id2;
ArbolExpre a, a2;
String q;
crearArbol(a);

            if (PosicionListaString("compound", L) == 1) {
                if ((largoListaStrings(L) != 3) && (largoListaStrings(L) != 4) ) {
                    printf("\nCantidad de parámetros incorrecta, deben ser 3 o 4");
                }
                else {
                        if ((largoListaStrings(L) == 3) && (PerteneceIter("NOT", L)) && (PosicionListaString("NOT", L) != 2)) {
                            printf("\NOT debe ser la segunda palabra");
                        }
                        else {
//                                if ((largoListaStrings(L) == 3) && (PerteneceIter("NOT", L))) {
                                    if (!(esNatural(darPalabraporPosicion(3,L)))) { //
                                            printf("\nLa tercer palabra no es un natural");
                                    }
                                        else {
                                            Id1 = transformarANatural(darPalabraporPosicion(3, L));//
                                            if (!(PerteneceAListaExpreConID(Id1, LE))) {
                                                printf("\nNo existe la expresion correspondiente en Lista Expresiones");
                                                }
                                                else {
                                                    cargarOperadorNOT(a,(seleccionarArbolExpre (darExpresionConID(Id1,LE))),(transformarStringOperadorAChar(darPalabraDeLista("NOT", L))));
                                                    copiarArbolAOtro (seleccionarArbolExpre(darExpresionConID(Id1,LE)),a);
                                                    asignarArbolExpresion(e, a);
                                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                                    insertarNodoEnlista(e, LE);
                                                    desplegarPorNumero(LE, seleccionarNumeroExpresion(e));
                                                }

                                        }
//                                    }
                        }
                        if (((largoListaStrings(L) == 4) && (((PerteneceIter("AND", L)) || (PerteneceIter("OR", L)))) && (((PosicionListaString("AND", L) !=3) || (PosicionListaString("OR", L) !=3))))) {
                                printf("\n'AND' u 'OR' deben ser la tercer palabra");
                        }
                        else {
                            if ((largoListaStrings(L) == 4) && (((PerteneceIter("AND", L)) || (PerteneceIter("OR", L))))) {
                                    if (!(esNatural(darPalabraporPosicion(2, L))) && (!(esNatural(darPalabraporPosicion(4, L))))) {//
                                        printf("\nLa segunda y la cuarta palabra deben ser naturales");
                                        }

                                else {
                                        Id1 = transformarANatural((darPalabraporPosicion(2, L)));
                                        Id2 = transformarANatural((darPalabraporPosicion(4, L)));
                                        if ((!PerteneceAListaExpreConID(Id1, LE)) || (!PerteneceAListaExpreConID(Id2, LE))) {
                                                if ((!PerteneceAListaExpreConID(Id1, LE))) {
                                                     printf("\nNumero uno no pertenece a Lista de Expresiones");
                                                }
                                                else {
                                                    if ((!PerteneceAListaExpreConID(Id2, LE))) {
                                                         printf("\nNumero dos no pertenece a Lista de Expresiones");
                                                    }
                                                else {
                                                    if ((!(PerteneceAListaExpreConID(Id1, LE)))&& (!(PerteneceAListaExpreConID(Id2, LE)))) {
                                                        printf("\nNi numero uno ni numero dos pertenece a Lista Expresiones");
                                                    }
                                                }
                                            }

                                        }
                                            else {
                                                if (PosicionListaString("AND", L) == 3) {
                                                    cargarOperadorAndOr(a,(seleccionarArbolExpre (darExpresionConID(Id1,LE))),(seleccionarArbolExpre(darExpresionConID(Id2,LE))),(transformarStringOperadorAChar(darPalabraDeLista("AND", L))));
                                                }

                                                    else {
                                                        if (PosicionListaString("OR", L) == 3) {
                                                            cargarOperadorAndOr(a,(seleccionarArbolExpre (darExpresionConID(Id1,LE))),(seleccionarArbolExpre(darExpresionConID(Id2,LE))),(transformarStringOperadorAChar(darPalabraDeLista("OR", L))));
                                                        }
                                                    }
                                                    copiarArbolAOtro (seleccionarArbolExpre(darExpresionConID(Id1,LE)),a);
                                                    asignarArbolExpresion(e, a);
                                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                                    insertarNodoEnlista(e, LE);
                                                    desplegarPorNumero(LE, seleccionarNumeroExpresion(e));
                                            }

                                    }
                                }

                            }
                        }

                    }

                else {
                    printf("\nLa palabra 'compound' debe ir en primer lugar");
                }
}

void show (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
int Id1;
            if (PosicionListaString("show", L) != 1) {
                   printf("\nLa palabra 'show' debe ir en primer lugar y luego el numero de la expresion a mostrar");
            }
            else {
                    if (largoListaStrings(L) != 2) {
                        printf("\nCantidad de parametros incorrecta, deben ser 2");
                    }
                    else {
                        if (!(esNatural(darPalabraporPosicion(2,L)))) { //
                            printf("\nEl numero no es un natural");
                        }
                        else {
                            Id1 = transformarANatural(darPalabraporPosicion(2, L)); //
                            if (!(PerteneceAListaExpreConID(Id1, LE))) {
                            printf("\nNo existe la expresion correspondiente en Lista Expresiones");
                          }
                          else {
                            desplegarPorNumero(LE, Id1);
                          }
                        }
                    }

            }
}

void evaluate (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
int Id1;
            if (PosicionListaString("evaluate", L) != 1) {
                   printf("\nLa palabra 'evaluate' debe ir en primer lugar y luego el numero de la expresion a mostrar");
            }
            else {
                    if (largoListaStrings(L) != 2) {
                        printf("\nCantidad de parametros incorrecta, deben ser 2");
                    }
                    else {
                        if (!(esNatural(darPalabraporPosicion(2,L)))) { //
                            printf("\nEl numero no es un natural");
                        }
                        else {
                            Id1 = transformarANatural(darPalabraporPosicion(2, L)); //
                            if (!(PerteneceAListaExpreConID(Id1, LE))) {
                            printf("\nNo existe la expresion correspondiente en Lista Expresiones");
                          }
                          else {
                            evaluarExpresion (seleccionarArbolExpre(e));
                            if (evaluarExpresion (seleccionarArbolExpre(e))) {
                                printf("La expresion vale true");
                            }
                            else {
                                printf("La expresion vale false");
                            }
                          }
                        }
                    }

            }
}

