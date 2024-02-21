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

//-- -- -- -- -- -- -- -- -- -- -- --PUSH DESDE VS CODE(ALE)-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// void insertarValorArbol(boolean valor, ArbolExpre &a) // ATOMIC
// {
//     if (a == NULL)
//     {
//         a = new NodoA;
//         a->info = valor;
//         a->hizq = NULL;
//         a->hder = NULL;
//     }
// }

void copiarArbolAOtro(ArbolExpre ar, ArbolExpre &a)
{
    // si ar != null, copiar nodo
    // copiar info de ar->info a a->info
    // llamar copiarArbolAOtro(ar->hizq, a->hizq)
    // llamar copiarArbolAOtro(ar->hder, a->hder)
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
            return TRUE;
            else
            {
                return FALSE;
            }
        }
    } // si en raiz hay un boolean, entonces retorno valor del boolean. PASO BASE,
    // sino, si en raiz hay un NOT, evaluo con ! y llamada recursivs a evaluarExpresion(arbol->hder)
    // sino si en raiz hay AND u OR, llamada recursivs a evaluarExpresion(arbol->hizq), conecto con || u &&, y luego llamada recursiva a evaluar con evaluarExpresion(arbol->hder)
}

// void enumerarNodos(ArbolExpre &a) {}

void colocarParentesis(ArbolExpre &a)
{
    // colocar parentesis como hijo del ultimo hizq, y como hijo del ultompo hder
    // mientras hizq sea  != null, avanzo, sigo yendo a la izquierda
    // mientras hder sea  != null, avanzo, sigo yendo a la derecha
}

/*Para el compound, ejemplo COMPOUND 1 AND 2 
Busco en la lista la expre1, copio su árbol, busco en la lista la expre2 y copio su arbol, creo un nuevo árbol cuya raíz sea el AND, el hizq es el árbol copiado de expre1, y el hder es el árbol copiado de expre2. Creo la raíz, y se le engancha el árbol de 
/*