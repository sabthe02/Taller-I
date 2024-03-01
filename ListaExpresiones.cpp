#include "ListaExpresiones.h"

void crearLista  (ListaExpresiones &LE) {
    LE = NULL;
}

boolean VaciaExpre(ListaExpresiones LE) {
    boolean es = FALSE;
    if (LE == NULL)
        es = TRUE;
    return es;
}



void insertarNodoEnlista (Expresion e, ListaExpresiones &LE)
{
    if (LE == NULL)
    {
        LE = new NodoL;
        LE -> expre = e;
        LE -> sig = NULL;
    }
    else
        insertarNodoEnlista(e,LE->sig);
}

int largoListaExpresiones (ListaExpresiones LE) {
int contador = 0;

while (LE!= NULL) {
        contador++;
        LE = LE -> sig;
}

return contador;

}

void desplegarPorNumero (ListaExpresiones LE, int numero){
    if (LE != NULL){
        if (seleccionarNumeroExpresion (LE->expre) == numero) {
        desplegarExpresion(LE->expre);
        }
        else {
            desplegarPorNumero (LE->sig, numero);
        }
    }
}

void liberarMemoriaListaE (ListaExpresiones &LE) {
ArbolExpre ar;
    while (LE != NULL)
    {
        ListaExpresiones lista = LE;
        ar = seleccionarArbolExpre(LE->expre);
        liberarMemoriaArbol(ar);
        LE = LE->sig;
        delete lista;
        LE = NULL;
    }
}



boolean PerteneceIterExpre (ListaExpresiones LE, Expresion e) {

boolean pertenece = FALSE;

while (LE!=NULL && !pertenece) {
    if (seleccionarArbolExpre(e) == seleccionarArbolExpre(LE -> expre)) {
        pertenece = TRUE;
    }
    else {
        LE = LE -> sig;
    }
}
return pertenece;

}

boolean PerteneceAListaExpreConID (int Id, ListaExpresiones LE) {

boolean encontre = FALSE;

while (LE!=NULL && !encontre) {
    if (seleccionarNumeroExpresion (LE->expre) == Id) {
        if (PerteneceIterExpre(LE, LE->expre)) {
        encontre = TRUE;
        }
    }
    else {
        LE = LE -> sig;
    }
}
return encontre;

}

Expresion darExpresionConID (int Id, ListaExpresiones LE) {

boolean encontre = FALSE;

while (LE!=NULL && !encontre) {
    if (seleccionarNumeroExpresion (LE->expre) == Id) {
        if (PerteneceIterExpre(LE, LE->expre)) {
        encontre = TRUE;
        return LE->expre;
        }
    }
    else {
        LE = LE -> sig;
    }
}

}
