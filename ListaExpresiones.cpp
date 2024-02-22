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


Expresion PrimeroExpre(ListaExpresiones LE) {
    return LE->expre;
}


void RestoExpre(ListaExpresiones &LE) {
    ListaExpresiones aux = LE;
    LE = LE->sig;
    delete aux;
}
//
//void InsFrontExpre(Lista &L, Consulta e) {
//    Lista aux = new nodo2;
//    aux->info = e;
//    aux->sig = L;
//    L = aux;
//}
//
//

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
//        printf("\nexpresion %d: ", seleccionarNumeroExpresion(LE->expre));
//        desplegarNodosArbolOrden (seleccionarArbolExpre(LE->expre));
        desplegarExpresion(LE->expre);
        }
        else {
            desplegarPorNumero (LE->sig, numero);
        }
    }
}

void liberarMemoriaListaE (ListaExpresiones &LE) {
    while (LE != NULL)
    {
        ListaExpresiones lista = LE;
        LE = LE->sig;
        delete lista;
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

