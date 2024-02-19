#include "Expresion.h"

//
//void desplegarExpresion (Expresion p) {
//printf("\n Cedula: %ld ", p.cedula);
//printf("Nombre: ");
//print(p.nombre);
//printf(" Apellido: ");
//print(p.apellido);
//printf(" Telefono: %ld ", p.telefono);
//printf("Cantidad de consultas: %d ", p.cantConsultas);
//}
//
//void cargarExpresion (Expresion &e) {
//printf("\nIngresar cedula del paciente: ");
//scanf("%ld",&p.cedula);
//fflush(stdin);
//printf("\nIngrese nombre del paciente: ");
//strcrear(p.nombre);
//scan (p.nombre);
//printf("\nIngrese apellido del paciente: ");
//strcrear(p.apellido);
//scan (p.apellido);
//printf("\nIngrese telefono del paciente: ");
//scanf("%ld", &p.telefono);
//p.cantConsultas = 0;
//}
//
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
