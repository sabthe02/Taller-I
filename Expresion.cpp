#include "Expresion.h"

void asignarNumeroExpresion (Expresion &e, int num) {

e.numero = num;

}

void asignarArbolExpresion (Expresion &e, ArbolExpre ar) {
e.arbol = ar;

}

int seleccionarNumeroExpresion (Expresion e) {
return e.numero;
}



ArbolExpre seleccionarArbolExpre (Expresion e) {
return e.arbol;
}

void crearExpresion(ArbolExpre a, int indice, Expresion &expre){
    expre.numero = indice;
    expre.arbol = a;
}


void desplegarExpresion (Expresion e) {
   int id;
   ArbolExpre arbol;
   arbol = seleccionarArbolExpre(e);
   asignarArbolExpresion (e, arbol);
    id = seleccionarNumeroExpresion(e);
    printf("\nexpresion %d: ", id);
    desplegarNodosArbolOrden (arbol);
}

