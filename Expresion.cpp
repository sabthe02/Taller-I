#include "Expresion.h"

// Cambiar a contenido
void desplegarPaciente (paciente p) {
printf("\n Cedula: %ld ", p.cedula);
printf("Nombre: ");
print(p.nombre);
printf(" Apellido: ");
print(p.apellido);
printf(" Telefono: %ld ", p.telefono);
printf("Cantidad de consultas: %d ", p.cantConsultas);
}

void cargarPaciente (paciente &p) {
printf("\nIngresar cedula del paciente: ");
scanf("%ld",&p.cedula);
fflush(stdin);
printf("\nIngrese nombre del paciente: ");
strcrear(p.nombre);
scan (p.nombre);
printf("\nIngrese apellido del paciente: ");
strcrear(p.apellido);
scan (p.apellido);
printf("\nIngrese telefono del paciente: ");
scanf("%ld", &p.telefono);
p.cantConsultas = 0;
}

long int seleccionarCedulaPaciente (paciente p) {
return p.cedula;
}

String seleccionarNombre (paciente p) {
return p.nombre;
}

String seleccionarApellido (paciente p) {
return p.apellido;
}

long int seleccionarTelefono (paciente p) {
return p.telefono;
}

int seleccionarCantConsultas (paciente p) {
return p.cantConsultas;
}

void sumarConsulta (paciente &p) {
p.cantConsultas = p.cantConsultas + 1;
}
