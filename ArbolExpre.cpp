#include "ArbolExpre.h"


void crearArbol (ArbolExpre &a) {

a = NULL;

}

boolean ArbolEsVacio (ArbolExpre a) {
boolean es;

if (a == NULL) {
    es = TRUE;
}
else {
    es = FALSE;
}
return es;
}

ValorNodo darRaiz (ArbolExpre a) {
return a->info;

}

ArbolExpre HijoIzq (ArbolExpre a) {

return a->hizq;

}


ArbolExpre HijoDer (ArbolExpre a) {

return a->hder;
}

void insertarValorEnOrden (ValorNodo valor, ArbolExpre &a) {

if (a == NULL) {
    a = new NodoA;
    a->info = valor;
    a->hizq = NULL;
    a->hder = NULL;
    }
    else {
        if (darIndiceNodoArbol(valor)< darIndiceNodoArbol(a->info)) {
            insertarValorEnOrden (valor, a->hizq);
        }
        else {
            insertarValorEnOrden (valor, a->hder);
        }
    }

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


void desplegarNodosArbolOrden (ArbolExpre a) {
 if (a != NULL) {
    desplegarNodosArbolOrden (a->hizq);
    desplegarDatoNodoArbol (a->info);
    desplegarNodosArbolOrden (a->hder);
 }
}


//void insertarValor (ArbolExpre &a, ValorNodo valor {
//
//if (a == NULL) {
//    a = new NodoA;
//    a->info = valor;
//    a->hizq = NULL;
//    a->hder = NULL;
//    }
//    else {
//        if (seleccionarCedulaPaciente(valor)< seleccionarCedulaPaciente(a->info)) {
//            Insert (a->hizq, valor);
//        }
//        else {
//            Insert (a->hder, valor);
//        }
//    }
//
//}
//
//
//
//boolean existe (ABB a, long int cedula) {
//if (a == NULL) {
//    return FALSE;
//}
//else {
//    if (cedula == seleccionarCedulaPaciente(a->info)) {
//        return TRUE;
//    }
//    else {
//            if (cedula < seleccionarCedulaPaciente(a->info)) {
//                return existe (a->hizq, cedula);
//            }
//            else {
//                return existe (a->hder, cedula);
//            }
//    }
//}
//
//
//}
//
//paciente Minimo (ABB a) {
//    if (a -> hizq == NULL)   {
//            return (a->info);
//    }
//    else {
//         return Minimo (a -> hizq); }
//
//    }
//
//void Borrar_Minimo (ABB &a) {
//    ABB aux;
//    if (a -> hizq == NULL) {
//            aux = a -> hder;
//            delete a;
//            a = aux;
//    }
//    else
//    {
//        Borrar_Minimo (a -> hizq);
//    }
//}
//
//void eliminarConCedula (long int cedula, ABB &a) {
//
//    ABB aux;
//    if (cedula == seleccionarCedulaPaciente(a -> info)) {
//        if (a -> hder == NULL) {
//            aux = a -> hizq;
//            delete a;
//            a = aux;
//        }
//        else {
//                if (a -> hizq == NULL) {
//                    aux = a -> hder;
//                    delete a;
//                    a = aux;
//                }
//                    else {
//                        a -> info = Minimo (a -> hder);
//                        Borrar_Minimo (a -> hder);
//                    }
//        }
//    }
//    else {
//            if (cedula < seleccionarCedulaPaciente(a -> info))   {
//                eliminarConCedula (cedula, a -> hizq);
//            }
//            else  {
//                eliminarConCedula (cedula, a -> hder);
//            }
//    }
//
//}
//

//
//
//}
//
//void listarPacientesSinConsultas (ABB a) {
//
//if (a !=NULL) {
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
//void sumarConsultaAlABB (ABB &a, long int ced)
//{
//if (a != NULL )
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
//int obtenerPacientesConCantidadDeConsultas (ABB a, int CaConsultas) {
//if (a == NULL) {
//    return 0;
//}
//else {
//    if (CaConsultas <= seleccionarCantConsultas(a->info))
//        {return 1+ obtenerPacientesConCantidadDeConsultas (a->hizq, CaConsultas) + obtenerPacientesConCantidadDeConsultas(a->hder, CaConsultas);}
//    else {return obtenerPacientesConCantidadDeConsultas (a->hizq, CaConsultas) + obtenerPacientesConCantidadDeConsultas(a->hder, CaConsultas);}
//}
//
//}
//
