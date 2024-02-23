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


String obtenerPalabraporPosicion (int posicion, ListaStrings L) {

boolean encontre = FALSE;

while (L!=NULL && !encontre) {

    if ((PosicionListaString(L->palabra,L)) == posicion) {
//        if (streq(darPalabraDeLista(L->palabra,L), L->palabra)) {
        encontre = TRUE;
        return L->palabra;
//        }
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
                                    boolean test = transformarStringABoolean ("true");
                                    insertarValorArbol (test, ar);
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
                                if ((largoListaStrings(L) == 3) && (PerteneceIter("NOT", L))) {
                                    if (!(esNatural(obtenerPalabraporPosicion(3, L)))) {
                                            printf("\nEl tercer numero no es un natural");
                                    }
                                        else {
                                            Id1 = transformarANatural((obtenerPalabraporPosicion(3, L)));
                                            if (!(PerteneceAListaExpreConID(Id1, LE))) {
                                                printf("\nNo existe la expresion correspondiente en Lista Expresiones");
                                                }
                                                else {
                                                    copiarArbolAOtro (seleccionarArbolExpre (darExpresionConID(Id1,LE)),a);
//                                                    cargarOperadorNOT(ar,a,//?? de dónde sacar el operador (char)?) // falta el procedimiento
                                                    // se supone que este procedimiento ya te carga los paréntesis y el operador (?)
                                                    asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                                    insertarNodoEnlista(e, LE);
                                                    desplegarPorNumero(LE, seleccionarNumeroExpresion(e));
                                                }

                                        }
                                    }
                        }
                        if (((largoListaStrings(L) == 4) && ((PerteneceIter("AND", L)) || (PerteneceIter("OR", L)))) && ((PosicionListaString("AND", L) !=3) || (PosicionListaString("AND", L) !=3))) {
                                printf("\n'AND' u 'OR' deben ser la tercer palabra");
                        }
                        else {
                            if ((!(esNatural(obtenerPalabraporPosicion(2, L)))) && (!(esNatural(obtenerPalabraporPosicion(4, L))))) {
                                    printf("\nLa segunda y la cuarta palabra deben ser naturales");
                            }
                                else {
                                    Id1 = transformarANatural((obtenerPalabraporPosicion(2, L)));
                                    Id2 = transformarANatural((obtenerPalabraporPosicion(4, L)));
                                    if ((!(PerteneceAListaExpreConID(Id1, LE)))|| (!(PerteneceAListaExpreConID(Id2, LE)))) {
                                        printf("\nNo existe la expresion correspondiente a al menos uno de los numeros");
                                    }
                                        else {
//                                          copiarArbolAOtro (seleccionarArbolExpre (darExpresionConID(Id1,LE)),a);
//                                          copiarArbolAOtro  (seleccionarArbolExpre (darExpresionConID(Id2,LE)),a2);
                                            crearArbol(ar);
//                                            cargarOperadorAndOr(ar,a,//?? de dónde sacar el operador (char)?) // falta el procedimiento
//                                            // se supone que este procedimiento ya te carga los paréntesis y el operador (?)
                                            asignarNumeroExpresion (e, largoListaExpresiones(LE)+1);
                                            insertarNodoEnlista(e, LE);
                                            desplegarNodosArbolOrden(ar); // a modo de prueba
//                                          desplegarPorNumero(LE, 1); // no funciona
                                        }

                                }
                        }

                    }
                }
                else {
                    printf("\nLa palabra 'compound' debe ir en primer lugar");
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
