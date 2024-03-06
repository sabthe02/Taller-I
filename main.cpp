#include "ListaExpresiones.h"
#include "ListaStrings.h"
#include "Archivo.h"

int main()
{

ListaStrings L;
ArbolExpre ar;
ListaExpresiones LE;
Expresion e;
String s, q;
boolean es = FALSE;
Crear(L);
crearLista(LE);
crearArbol(ar);
strcrear(q);

do {

printf("\nIngrese comando: ");
strcrear(s);
scan(s);

partirStrings(s, L);


if (!Vacia(L)){
        if (PerteneceIter("atomic", L))  {
            atomic(L, LE, e, ar);
        }
        else
            if (PerteneceIter("compound", L)) {
                compound (L, LE, e, ar);
            }
            else
                if (PerteneceIter("show", L)) {
                    show (L, LE, e, ar);
                }
                else
                    if (PerteneceIter("evaluate", L)) {
                        evaluate (L, LE, e, ar);
                    }
                    else
                        if (PerteneceIter("save", L)) {
                            save (L, LE, e, ar);
                        }
                        else
                        if (PerteneceIter("load", L)) {
                            load (L, LE, e, ar);
                        }
                        else
                            if (PerteneceIter("exit", L)) {
                                exit (L, LE, e, ar);
                                es = esExit(L);
                            }
                    else {
                    printf("\nPor favor ingrese un comando valido (atomic, compound, show, evaluate, save, load, exit)");
                    }

if (!es) {
    vaciarListaStrings(L);
    printf("\n");
    }
}

else {
    printf("\nNo se ha ingresado ningun comando \n");
 }

} while(!es);
vaciarListaStrings(L);

}


