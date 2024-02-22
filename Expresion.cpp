#include "Expresion.h"

void desplegarExpresion (Expresion e) {
   int id;
   ArbolExpre arbol;
    id = seleccionarNumeroExpresion(e);
    arbol = seleccionarArbolExpre(e);
    printf("\nexpresion %d: ", id);
    desplegarNodosArbolOrden (arbol);
}


int seleccionarNumeroExpresion (Expresion e) {
return e.numero;
}

void asignarNumeroExpresion (Expresion &e, int num) {

e.numero = num;

}


ArbolExpre seleccionarArbolExpre (Expresion e) {
return e.arbol;
}


//
//int seleccionarCantConsultas (paciente p) {
//return p.cantConsultas;
//}
//
//void sumarConsulta (paciente &p) {
//p.cantConsultas = p.cantConsultas + 1;
//}
