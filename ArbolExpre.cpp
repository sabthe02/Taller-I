#include "ArbolExpre.h"

void crearArbol (ArbolExpre &a) {

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
        a =NULL;
    }
}

void desplegarNodosArbolOrden(ArbolExpre a)
{
    if (a != NULL)
    {
        desplegarNodosArbolOrden(a->hizq);
        desplegarDatoNodoArbol(a->info);
        desplegarNodosArbolOrden(a->hder);
    }
}


ValorNodo Maximo (ArbolExpre a) {

if (a->hder==NULL) {
    return a->info;
}
else {
    return Maximo(a->hder);
}
}


ValorNodo Minimo (ArbolExpre a) {
    if (a -> hizq == NULL)   {
            return (a->info);
    }
    else {
         return Minimo (a -> hizq); }
}


void insertarValorNodoArbol(ValorNodo vn, ArbolExpre &a){
    if(a==NULL) {
        a=new NodoA;
          a->info = vn;
          a->hder=NULL;
          a->hizq=NULL;
          }
}

void copiarArbolAOtro(ArbolExpre b, ArbolExpre &a){

if(b != NULL)
    {
        insertarValorNodoArbol(darRaiz(b),a);
        copiarArbolAOtro(b->hizq, a->hizq);
        copiarArbolAOtro(b->hder, a->hder);

    }
}



void cargarOperadorNOT(ArbolExpre &a, ArbolExpre ar, char operador)
{
    a = new NodoA;
    insertarOperadorNodo(operador, a->info);
    a->hizq = NULL;
    a->hder = NULL;
    copiarArbolAOtro(ar, a->hder);
    InsertarParentesisEnMinimo('(',a);
    InsertarParentesisEnMaximo(')',a);
}


void cargarOperadorAndOr(ArbolExpre &a, ArbolExpre ar, ArbolExpre arb, char operador) {

    a = new NodoA;
    insertarOperadorNodo(operador, a->info);
    a->hizq = NULL;
    a->hder = NULL;
    copiarArbolAOtro(ar, a->hizq);
    copiarArbolAOtro(arb, a->hder);
    InsertarParentesisEnMinimo('(',a);
    InsertarParentesisEnMaximo(')',a);

}



void InsertarParentesisEnMinimo(char parentesis, ArbolExpre &a){
   if (a->hizq == NULL)
   {
       a->hizq = new NodoA;
      insertarParentesisNodo(parentesis, a->hizq->info);
      a->hizq->hizq = NULL;
      a->hizq->hder = NULL;
   }
   else
   {
       InsertarParentesisEnMinimo(parentesis, a->hizq);
   }
}


void InsertarParentesisEnMaximo(char parentesis, ArbolExpre &a) {
       if (a->hder == NULL) {
            a->hder = new NodoA;
           insertarParentesisNodo(parentesis, a->hder->info);
            a->hder->hizq = NULL;
            a->hder->hder = NULL;
       }
       else {
           InsertarParentesisEnMaximo(parentesis, a->hder);
       }
}

boolean evaluarExpresion(ArbolExpre a){
    if (darDiscriminante (a->info) == VALOR){
        return darBooleanoArbol(a->info);
    }
        else {
            if (darDiscriminante (a->info) == OPERADOR) {
                    if (darOperadorArbol(a->info) == 'N') {
                        return transformarBoolEnBoolean(!(evaluarExpresion(a->hder)));
                    }

                       else {
                            if (darOperadorArbol(a->info) == 'A'){
                                return transformarBoolEnBoolean((evaluarExpresion(a->hizq) && evaluarExpresion(a->hder)));
                            }

                            else {
                                if (darOperadorArbol(a->info) == 'O'){
                                        return transformarBoolEnBoolean((evaluarExpresion(a->hizq) || evaluarExpresion(a->hder)));
                                }
                            }
                        }
            }
        }
}

void enumerarNodos(int &indice, ArbolExpre &a) {
if (a->hizq != NULL){
        enumerarNodos (indice, a->hizq);
    }
    indice++;
    asignarIndiceNodo(indice, a->info);

    if (a->hder !=NULL) {
        enumerarNodos(indice, a->hder);
    }

}



