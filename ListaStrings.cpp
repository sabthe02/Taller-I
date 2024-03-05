#include "ListaStrings.h"
#include "Errores.h"

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

int PosicionListaString (String s, ListaStrings L) {
int posicion = 1;
boolean encontre = FALSE;

while (L!= NULL && !encontre) {
    if (streq(s,L->palabra)) {
        encontre = TRUE;
    }
    else {

    L = L -> sig;
    posicion++;
    }

}
return posicion;
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

while (!esVacio(s)) {
    eliminarBlancosPrincipio (s, s2);
    dividirString(s2, p, r);
    InsBackIter(p, L);
    strcop(s,r);

}
strdestruir(s2);
// No destruyo p y r porque no me anda el programa si no!

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



String darPalabraporPosicion (int posicion, ListaStrings L) {

int aux = 1;

while (aux != posicion) {
    L = L->sig;
    aux++;
}
return L->palabra;
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
int comando = 1;
errores codigo;
            if (PosicionListaString("atomic", L) != 1) {
                    codigo = COMANDOENLUGAREQUIVOCADO;
                    error (codigo,comando, L);
            }
            else {
                    if (largoListaStrings(L) != 2) {
                            codigo = CANTIDADDEPARAMETROSINCORRECTA;
                            error (codigo,comando, L);
                    }
                    else {
                            if ((streq(darPalabraporPosicion(2,L), "true")) || ((streq(darPalabraporPosicion(2,L), "false")))) {
                                if ((streq(darPalabraporPosicion(2,L), "true"))) {
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
                                codigo = PALABRAEQUIVOCADA;
                                error (codigo,comando, L);
                            }
                }
            }

}

void compound (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
int Id1, Id2;
ArbolExpre a, a2;
String q;
crearArbol(a);
int comando = 2;
errores codigo;

            if (PosicionListaString("compound", L) == 1) {
                if ((largoListaStrings(L) != 3) && (largoListaStrings(L) != 4) ) {
                    codigo = CANTIDADDEPARAMETROSINCORRECTA;
                    error (codigo, comando, L);

                }
                else {
                        if ((largoListaStrings(L) == 3) && (!(PerteneceIter("NOT", L)))) {
                            codigo = NOCONTIENEFORMATO;
                            error(codigo, comando, L);
                            }
                            else {
                                if ((largoListaStrings(L) == 3) && (PerteneceIter("NOT", L)) && (PosicionListaString("NOT", L) != 2)) {
                                    codigo = PALABRAENLUGAREQUIVOCADO;
                                    error (codigo, comando, L);
                                }
                                else {
                                        if ((largoListaStrings(L) == 3) && (PerteneceIter("NOT", L))) {
                                            if (!(esNatural(darPalabraporPosicion(3,L)))) {
                                                    codigo = PALABRADEBESERNATURAL;
                                                    error (codigo, comando, L);
                                            }
                                                else {
                                                    Id1 = transformarANatural(darPalabraporPosicion(3, L));
                                                    if (!(PerteneceAListaExpreConID(Id1, LE))) {
                                                        codigo = NOEXISTEENLISTAEXPRESIONES;
                                                        error(codigo, comando, L);
                                                        }
                                                        else {
                                                            cargarOperadorNOT(a,(seleccionarArbolExpre (darExpresionConID(Id1,LE))),(transformarStringOperadorAChar(darPalabraDeLista("NOT", L))));
                                                            asignarArbolExpresion(e, a);
                                                            asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                                            insertarNodoEnlista(e, LE);
                                                            desplegarPorNumero(LE, seleccionarNumeroExpresion(e));
                                                        }

                                                }

                                        }
                                }
                            }
                            if ((largoListaStrings(L) == 4) && ((!(PerteneceIter("AND", L)) && (!(PerteneceIter("OR", L)))))) {
                                codigo = NOCONTIENEFORMATO;
                                error(codigo, comando, L);
                            }
                            else {
                                if (((largoListaStrings(L) == 4) && (((PerteneceIter("AND", L)) || (PerteneceIter("OR", L)))) && (((PosicionListaString("AND", L) !=3) && (PosicionListaString("OR", L) !=3))))) {
                                        codigo = PALABRAENLUGAREQUIVOCADO;
                                        error (codigo, comando, L);
                                }
                                else {
                                        if ((largoListaStrings(L) == 4) && (!(streq(darPalabraporPosicion(3,L), "AND"))) && (!(streq(darPalabraporPosicion(3,L), "OR")))) {
                                                codigo = PALABRAEQUIVOCADA;
                                                error (codigo, comando, L);
                                            }

                                        if ((largoListaStrings(L) == 4) && ((streq(darPalabraporPosicion(3,L),"AND")) || (streq(darPalabraporPosicion(3,L),"OR")))) {
                                                if (!(esNatural(darPalabraporPosicion(2, L)))) {
                                                    codigo = PALABRADEBESERNATURAL;
                                                    error (codigo, comando, L);
                                                    }

                                                if (!(esNatural(darPalabraporPosicion(4, L)))) {
                                                    codigo = CUARTAPALABRADEBESERNATURAL;
                                                    error (codigo, comando, L);
                                                    }

                                                    else {
                                                            if ((esNatural(darPalabraporPosicion(2, L)) && (esNatural(darPalabraporPosicion(4, L))))) {
                                                                Id1 = transformarANatural((darPalabraporPosicion(2, L)));
                                                                Id2 = transformarANatural((darPalabraporPosicion(4, L)));
                                                                if ((!PerteneceAListaExpreConID(Id1, LE)) || (!PerteneceAListaExpreConID(Id2, LE))) {
                                                                        if ((!PerteneceAListaExpreConID(Id1, LE))) {
                                                                            codigo = NOEXISTEENLISTAEXPRESIONESPRIMERO;
                                                                            error(codigo, comando, L);
                                                                        }

                                                                        if ((!PerteneceAListaExpreConID(Id2, LE))) {
                                                                                codigo = NOEXISTEENLISTAEXPRESIONESSEGUNDO;
                                                                                error(codigo, comando, L);
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

                }
            }
                else {
                    codigo = COMANDOENLUGAREQUIVOCADO;
                    error (codigo,comando, L);
                }

}

void show (ListaStrings L, ListaExpresiones LE, Expresion e, ArbolExpre ar) {
int Id1;
int comando = 3;
errores codigo;
            if (PosicionListaString("show", L) != 1) {
                    codigo = COMANDOENLUGAREQUIVOCADO;
                    error(codigo, comando, L);
            }
            else {
                    if (largoListaStrings(L) != 2) {
                            codigo = CANTIDADDEPARAMETROSINCORRECTA;
                            error (codigo,comando, L);
                    }
                    else {
                        if (!(esNatural(darPalabraporPosicion(2,L)))) {
                            codigo = PALABRADEBESERNATURAL;
                            error (codigo, comando, L);
                        }
                        else {
                            Id1 = transformarANatural(darPalabraporPosicion(2, L));
                            if (!(PerteneceAListaExpreConID(Id1, LE))) {
                            codigo = NOEXISTEENLISTAEXPRESIONES;
                            error(codigo, comando, L);
                          }
                          else {
                            desplegarPorNumero(LE, Id1);
                          }
                        }
                    }

            }
}

void evaluate (ListaStrings L, ListaExpresiones LE, Expresion e, ArbolExpre ar) {
int Id1;
int comando = 4;
errores codigo;
            if (PosicionListaString("evaluate", L) != 1) {
                codigo = COMANDOENLUGAREQUIVOCADO;
                error(codigo, comando, L);
            }
            else {

                    if (largoListaStrings(L) != 2) {
                            codigo = CANTIDADDEPARAMETROSINCORRECTA;
                            error (codigo,comando, L);
                    }
                    else {
                        if (!(esNatural(darPalabraporPosicion(2,L)))) {
                            codigo = PALABRADEBESERNATURAL;
                            error (codigo, comando, L);
                        }
                        else {
                            Id1 = transformarANatural(darPalabraporPosicion(2, L));
                            if (!(PerteneceAListaExpreConID(Id1, LE))) {
                            codigo = NOEXISTEENLISTAEXPRESIONES;
                            error(codigo, comando, L);
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

void save (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
int Id1;
int indice = 0;
String entrada;
String p, r;
int comando = 5;
errores codigo;
            if (PosicionListaString("save", L) != 1) {
                codigo = COMANDOENLUGAREQUIVOCADO;
                error(codigo, comando, L);
            }
            else {
                    if (largoListaStrings(L) != 3) {
                        codigo = CANTIDADDEPARAMETROSINCORRECTA;
                        error (codigo,comando, L);
                    }
                    else {
                        if (!(esNatural(darPalabraporPosicion(2,L)))) {
                            codigo = PALABRADEBESERNATURAL;
                            error (codigo, comando, L);
                        }
                        else {
                            if (!esNombreArchivo(darPalabraporPosicion(3,L))) {
                                    dividirStringDeArchivo (darPalabraporPosicion(3,L), p, r);
                                    if (!(esAlfabetico(p))) {
                                        codigo = PALABRANOALFABETICA;
                                        error(codigo, comando, L);
                                    }
                                    if (!(tieneExtension(r))) {
                                        codigo = ARCHIVONODAT;
                                        error(codigo, comando, L);
                                    }
                            }
                            else {
                                Id1 = transformarANatural(darPalabraporPosicion(2, L));
                                if (!(PerteneceAListaExpreConID(Id1, LE))) {
                                    codigo = NOEXISTEENLISTAEXPRESIONES;
                                    error(codigo, comando, L);
                                }
                                else {
                                        if (!ExisteArchivo(darPalabraporPosicion(3,L))) {
                                            ar = seleccionarArbolExpre(darExpresionConID(Id1,LE));
                                            enumerarNodos(indice, ar);
                                            FILE * f = fopen (darPalabraporPosicion(3,L), "wb");
                                            BajarArbolExpre(seleccionarArbolExpre(darExpresionConID(Id1,LE)), f);
                                            fclose(f);
                                            printf("expresion %d respaldada correctamente en ", Id1);
                                            print(darPalabraporPosicion(3,L));
                                        }
                                        else {
                                            printf("\nArchivo ya existe, desea sobreescribirlo? S = si, N = no \n");
                                            strcrear(entrada);
                                            scan (entrada);

                                            while (!(streq(entrada,"S")) && !(streq(entrada, "N"))){
                                               printf("\nSolo se admite 'S' o 'N' como respuesta\n");
                                               scan (entrada);
                                            }
                                            if (streq(entrada,"S")) {
                                                ar = seleccionarArbolExpre(darExpresionConID(Id1,LE));
                                                enumerarNodos(indice, ar);
                                                FILE * f = fopen (darPalabraporPosicion(3,L), "wb");
                                                BajarArbolExpre(seleccionarArbolExpre(darExpresionConID(Id1,LE)), f);
                                                fclose(f);
                                                printf("expresion %d respaldada correctamente en ", Id1);
                                                print(darPalabraporPosicion(3,L));
                                            }
                                            else {
                                                printf("\nNo guardado ");
                                            }
                                            strdestruir(entrada);
                                        }
                                }
                            }
                          }
                        }
                    }

}

void load (ListaStrings L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
String p, r;
int comando = 6;
errores codigo;
    if (PosicionListaString("load", L) != 1) {
                    codigo = COMANDOENLUGAREQUIVOCADO;
                    error(codigo, comando, L);
            }
            else {
                    if (largoListaStrings(L) != 2) {
                            codigo = CANTIDADDEPARAMETROSINCORRECTA;
                            error (codigo,comando, L);
                    }
                    else {
                            if (!esNombreArchivo(darPalabraporPosicion(2,L))) {
                                    dividirStringDeArchivo (darPalabraporPosicion(2,L), p, r);
                                    if (!(esAlfabetico(p))) {
                                        codigo = PALABRANOALFABETICA;
                                        error(codigo, comando, L);
                                    }
                                    if (!(tieneExtension(r))) {
                                        codigo = ARCHIVONODAT;
                                        error(codigo, comando, L);
                                    }
                            }
                            else {
                                if (!(ExisteArchivo(darPalabraporPosicion(2,L)))) {
                                        codigo = NOEXISTEARCHIVO;
                                        error(codigo, comando, L);
                                }
                                else {
                                    LevantarArbolExpre(ar, darPalabraporPosicion(2,L));
                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                    asignarArbolExpresion(e, ar);
                                    insertarNodoEnlista(e, LE);
                                    desplegarPorNumero(LE, seleccionarNumeroExpresion(e));
                                }
                            }
                    }

            }

}

void exit (ListaStrings &L, ListaExpresiones &LE, Expresion &e, ArbolExpre &ar) {
int comando = 7;
errores codigo;
    if (PosicionListaString("exit", L) != 1) {
            codigo = COMANDOENLUGAREQUIVOCADO;
            error(codigo, comando, L);
            }
            else {
                    if (largoListaStrings(L) != 1) {
                        codigo = CANTIDADDEPARAMETROSINCORRECTA;
                        error(codigo, comando, L);
                    }
                    else {
                          liberarMemoriaListaE(LE);
                            printf("hasta la proxima");
                        }
                    }
}


boolean esExit (ListaStrings L) {
boolean es = FALSE;

    if (PosicionListaString("exit", L) == 1) {
                    if (largoListaStrings(L) == 1) {
                          es = TRUE;
                        }
    }

return es;
}


