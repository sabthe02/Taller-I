#include "ListaStrings.h"

// Cambiar a requerimientos

//void Crear (Lista &L) {
//    L = NULL;
//}
//
//boolean Vacia(Lista L) {
//    boolean es = FALSE;
//    if (L == NULL)
//        es = TRUE;
//    return es;
//}
//
//
//Consulta Primero(Lista L) {
//    return L->info;
//}
//
//
//void Resto(Lista &L) {
//    Lista aux = L;
//    L = L->sig;
//    delete aux;
//}
//
//void InsFront(Lista &L, Consulta e) {
//    Lista aux = new nodo2;
//    aux->info = e;
//    aux->sig = L;
//    L = aux;
//}
//
//
//void DesplegarIter(Lista L)
//{
//    while (L != NULL)
//    {
//        desplegarConsulta (L->info);
//        L = L->sig;
//    }
//}
//
//void InsBackIter(Lista &L, Consulta c)
//{
//    Lista nuevo = new nodo2;
//    nuevo->info = c;
//    nuevo->sig = NULL;
//    if (L == NULL)
//        L = nuevo;
//    else {
//        Lista aux = L;
//        while (aux->sig != NULL)
//            aux = aux->sig;
//        aux->sig = nuevo;
//    }
//}
//
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
//void desplegarConsultaPorFecha(Lista L, fecha f){
//    if (L != NULL) {
//        if (darDia(seleccionarFecha(L->info)) >= darDia(f) && darMes(seleccionarFecha(L->info)) >= darMes(f) &&
//            darAnio(seleccionarFecha(L->info)) >= darAnio(f)){
//            desplegarConsulta(L->info);
//            desplegarConsultaPorFecha(L->sig, f);
//        } else desplegarConsultaPorFecha(L->sig, f);
//    }
//}
//
//void liberarMemoriaLista(Lista &L)
//{
//    while (L != NULL)
//    {
//        Lista lista = L;
//        L = L->sig;
//        delete lista;
//    }
//}
