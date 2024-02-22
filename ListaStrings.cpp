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

int PosicionListaString (String s, ListaStrings L) {
int posicion = 1;
boolean encontre = FALSE;

while (L!= NULL && !encontre) {
    if (streq(s,L->palabra)) {
        encontre = TRUE;
    }
    else {
    posicion++;
    L = L -> sig;
    }
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

if (!esVacio(s)) {
eliminarBlancosPrincipio (s, s2);
dividirString(s2, p, r);
InsBackIter(p, L);
partirStrings(r, L->sig);
}

}
//
//String obtenerPalabraDeListaStrings (int posicion, ListaStrings L) {
//
//String p;
//strcrear(p);
//boolean encontre = FALSE;
//
//while (L!=NULL && !encontre) {
//    if ((PosicionListaString(L->palabra,L)) == posicion) {
//        if (streq(, L->palabra)) {
//        encontre = TRUE;
//        }
//    }
//    else {
//        L = L -> sig;
//    }
//    p = L->palabra;
//}
//return p;
//
//}

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
                                desplegarNodosArbolOrden(ar);
                                insertarNodoEnlista(e, LE);
                                }
                                else {
                                    crearArbol(ar);
                                    insertarValorArbol ((transformarStringABoolean ("false")), ar);
                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                    desplegarNodosArbolOrden(ar);
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

}


//
//void registrarConsulta (Lista &L, Consulta c)
//{
//    boolean agregada = FALSE;
//
//    Lista aux;
//    Lista aux2;
//    Lista aux3;
//
//    if (L == NULL){
//         InsFront(L, c);}
//
//    else {
//
//          aux2 = L;
//          aux3 = L;
//
//          aux = new nodo2;
//          aux->info = c;
//
//          while (aux2 != NULL && !agregada)
//           {if (MenorFecha (seleccionarFecha (aux2->info), seleccionarFecha (aux->info)) == TRUE && MenorFecha (seleccionarFecha (L->info), seleccionarFecha (aux->info)) == TRUE)
//                     {aux->sig = aux2;
//                      aux2 = aux;
//                      L = aux2;
//                      agregada = TRUE;
//                      }
//            // insfront
//
//            else if (MenorFecha (seleccionarFecha (aux2->info), seleccionarFecha (aux->info)) == TRUE && MenorFecha (seleccionarFecha (L->info), seleccionarFecha (aux->info)) == FALSE)
//                  {L->sig = aux;
//                   aux->sig = aux2;
//                    agregada = TRUE;}
//
//            else aux2 = aux2->sig;
//           }
//
//          if (agregada == FALSE)
//            {
//
//            while (aux3->sig != NULL)
//            {aux3 = aux3->sig;}
//
//            aux3->sig = new nodo2;
//            aux3->sig->info = c;
//            aux3->sig->sig = NULL;
//            }
//
//            //InsBackIter
//        }
//}
//
//void cantidadConsultasportratamiento (Lista L, int &tratamiento, int &protesis, int &saludable)
//{
//
//    if (L != NULL)
//    {
//        switch (seleccionarEvaluacion (L->info))
//        {
//            case EN_TRATAMIENTO: tratamiento++;
//            break;
//            case NECESITA_PROTESIS: protesis++;
//            break;
//            case SALUDABLE: saludable++;
//            break;
//        }
//
//        cantidadConsultasportratamiento (L->sig,tratamiento,protesis,saludable);
//    }
//}
//
//
//int cantidadConsultasporfecha (Lista L, fecha f)
//{
//    if (L == NULL)
//        return 0;
//    else {
//          if (darDia (seleccionarFecha (L->info)) == darDia (f) && darMes (seleccionarFecha (L->info)) == darMes (f) && darAnio (seleccionarFecha (L->info)) == darAnio (f))
//          {return 1 + cantidadConsultasporfecha (L->sig, f);}
//          else return cantidadConsultasporfecha (L->sig, f);
//         }
//}
//
//
//void desplegarporcedula (Lista L, long int cedula)
//{
//    if (L != NULL)
//    {
//        if (seleccionarCedulaConsulta (L->info) == cedula)
//        {
//        desplegarConsulta (L->info);
//        desplegarporcedula (L->sig, cedula);
//        }
//        else
//            {desplegarporcedula (L->sig, cedula);}
//    }
//}
//
//
//int ContarCedulas(long int e, Lista L) {
//    int cant = 0;
//    while (L != NULL) {
//        if (seleccionarCedulaConsulta (L->info) == e)
//            cant++;
//        L = L->sig;
//    }
//    return cant;
//}
//
//
//
//void mayorcantidadconsultas (Lista L, long int &cedula, int &mayor)
//{
//    Lista aux = L;
//    Lista aux2 = L;
//    int conteo = 0;
//
//    cedula = seleccionarCedulaConsulta (L->info);
//    mayor = ContarCedulas (seleccionarCedulaConsulta (L->info) , aux);
//
//    L = L->sig;
//
//    while (L != NULL)
//    {
//     if (seleccionarCedulaConsulta (L->info) == cedula)
//     {L = L->sig;}
//
//     else
//    {
//     aux = aux2;
//
//     conteo = ContarCedulas (seleccionarCedulaConsulta (L->info), aux);
//
//     if (conteo > mayor)
//     {
//         cedula = seleccionarCedulaConsulta (L->info);
//         mayor = conteo;
//         L = L->sig;
//     }
//     else
//     {
//         L = L->sig;
//     }
//
//
//    }
//
//
//}
//}
//
//void eliminarConsulta(Lista &L, long int cedula){
//    if (L != NULL)
//    {
//        if (cedula == seleccionarCedulaConsulta(L->info))
//        {
//            Lista aux = L;
//            L = L -> sig;
//            delete aux;
//            eliminarConsulta(L, cedula);
//        }
//        else
//            eliminarConsulta(L -> sig, cedula);
//    }
//
//}
//
