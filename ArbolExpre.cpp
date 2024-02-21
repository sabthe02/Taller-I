#include "ArbolExpre.h"

typedef struct nodoA
{
    ValorNodo info;
    nodoA *hizq;
    nodoA *hder;
} NodoA;

typedef NodoA *ArbolExpre;

void crearArbol(ArbolExpre &a)
{

    a = NULL;
}

boolean ArbolEsVacio(ArbolExpre a)
{
    boolean es;

    if (a == NULL)
    {
        es = TRUE;
    }
    else
    {
        es = FALSE;
    }
    return es;
}

ValorNodo darRaiz(ArbolExpre a)
{
    return a->info;
}

ArbolExpre HijoIzq(ArbolExpre a)
{

    return a->hizq;
}

ArbolExpre HijoDer(ArbolExpre a)
{

    return a->hder;
}
// Solo sirve para insertar desde archivo porque tiene que venir con el �ndice seteado, no sirve si el �ndice no est� definido

void insertarValorEnOrden(ValorNodo valor, ArbolExpre &a)
{

    if (a == NULL)
    {
        a = new NodoA;
        a->info = valor;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if (darIndiceNodoArbol(valor) < darIndiceNodoArbol(a->info))
        {
            insertarValorEnOrden(valor, a->hizq);
        }
        else
        {
            insertarValorEnOrden(valor, a->hder);
        }
    }
}

void insertarValorArbol(boolean v, ArbolExpre &a)
{

    a = new NodoA;
    insertarValorNodo(v, a->info);
    a->hizq = NULL;
    a->hder = NULL;
}

void liberarMemoriaArbol(ArbolExpre &a)
{
    if (a != NULL)
    {
        liberarMemoriaArbol(a->hizq);
        liberarMemoriaArbol(a->hder);
        delete a;
    }
}

void desplegarNodosArbolOrden(ArbolExpre a)
{
    if (a != NULL)
    {
        desplegarNodosArbolOrden(a->hizq); // Se rompe ac�, no llega a hacerlo cuando viene de la lista, pero si lo ejecuto solo en el �rbol funciona
        desplegarDatoNodoArbol(a->info);
        desplegarNodosArbolOrden(a->hder);
    }
}

// boolean existe (ABB a, long int cedula) {
// if (a == NULL) {
//     return FALSE;
// }
// else {
//     if (cedula == seleccionarCedulaPaciente(a->info)) {
//         return TRUE;
//     }
//     else {
//             if (cedula < seleccionarCedulaPaciente(a->info)) {
//                 return existe (a->hizq, cedula);
//             }
//             else {
//                 return existe (a->hder, cedula);
//             }
//     }
// }
//
//
// }
//
// paciente Minimo (ABB a) {
//     if (a -> hizq == NULL)   {
//             return (a->info);
//     }
//     else {
//          return Minimo (a -> hizq); }
//
//     }
//
// void Borrar_Minimo (ABB &a) {
//     ABB aux;
//     if (a -> hizq == NULL) {
//             aux = a -> hder;
//             delete a;
//             a = aux;
//     }
//     else
//     {
//         Borrar_Minimo (a -> hizq);
//     }
// }
//
// void eliminarConCedula (long int cedula, ABB &a) {
//
//     ABB aux;
//     if (cedula == seleccionarCedulaPaciente(a -> info)) {
//         if (a -> hder == NULL) {
//             aux = a -> hizq;
//             delete a;
//             a = aux;
//         }
//         else {
//                 if (a -> hizq == NULL) {
//                     aux = a -> hder;
//                     delete a;
//                     a = aux;
//                 }
//                     else {
//                         a -> info = Minimo (a -> hder);
//                         Borrar_Minimo (a -> hder);
//                     }
//         }
//     }
//     else {
//             if (cedula < seleccionarCedulaPaciente(a -> info))   {
//                 eliminarConCedula (cedula, a -> hizq);
//             }
//             else  {
//                 eliminarConCedula (cedula, a -> hder);
//             }
//     }
//
// }
//

//
//
//}
//
// void listarPacientesSinConsultas (ABB a) {
//
// if (a !=NULL) {
//    if (seleccionarCantConsultas(a->info) == 0 ) {
//        listarPacientesSinConsultas (a->hizq);
//        desplegarPaciente (a->info);
//        listarPacientesSinConsultas (a->hder);
//    }
//    else {
//        listarPacientesSinConsultas (a->hizq);
//        listarPacientesSinConsultas (a->hder);
//    }
//
//}
//
//
//}
//
// void sumarConsultaAlABB (ABB &a, long int ced)
//{
// if (a != NULL )
//{
//    {
//         if (seleccionarCedulaPaciente (a->info) == ced)
//             sumarConsulta (a->info);
//         else
//            {if (ced < seleccionarCedulaPaciente (a->info))
//         sumarConsultaAlABB (a->hizq, ced);
//         else sumarConsultaAlABB (a->hder, ced);
//          }
//    }
//
//
//}
//}
//
//
// int obtenerPacientesConCantidadDeConsultas (ABB a, int CaConsultas) {
// if (a == NULL) {
//    return 0;
//}
// else {
//    if (CaConsultas <= seleccionarCantConsultas(a->info))
//        {return 1+ obtenerPacientesConCantidadDeConsultas (a->hizq, CaConsultas) + obtenerPacientesConCantidadDeConsultas(a->hder, CaConsultas);}
//    else {return obtenerPacientesConCantidadDeConsultas (a->hizq, CaConsultas) + obtenerPacientesConCantidadDeConsultas(a->hder, CaConsultas);}
//}
//
//}
//

//------------------------PUSH DESDE VS CODE (ALE)----------------------------------------

void insertarValorArbol(boolean valor, ArbolExpre &a) // ATOMIC
{
    if (a == NULL)
    {
        a = new NodoA;
        a->info = valor;
        a->hizq = NULL;
        a->hder = NULL;
    }
}

void copiarArbolAOtro(ArbolExpre ar, ArbolExpre &a)
{
}

//  Minimo (ABB a) {
//    if (a -> hizq == NULL)   {
//            return (a->info);
//    }
//    else {
//         return Minimo (a -> hizq); }

//  Maximo (ABB a) {
//    if (a -> hder == NULL)   {
//            return (a->info);
//    }
//    else {
//         return Maximo (a -> hder); }

void compound()
{
    while (hizq != NULL)
    {
    }
}

void cargarParentesis(ArbolExpre &a, char parentesis)
{
    if (a == NULL)
    {
        a = new NodoA;
        a->info = parentesis;
        a->hizq = NULL;
        a->hder = NULL;
    }
}

void cargarOperadorNOT(ArbolExpre &a, ArbolExpre ar, char operador)
{
    // cargar un arbol en hder, en el min cargar parentesis (hizq)
}

void cargarOperadorAndOr(ArbolExpre &a, ArbolExpre ar, ArbolExpre arb, char operador) {}
// ar copiar a otro arbol como hizq,
// arb copiar a otro como hder

boolean evaluarExpresion(ArbolExpre arbol)
{
    if (arbol->info == valor)
    {
        if (valor)
        {
            return true;
            else
            {
                return false;
            }
        }
    }
}

void enumerarNodos(ArbolExpre &a) {}

// void colocarParentesis(ArbolExpre &a) {}
