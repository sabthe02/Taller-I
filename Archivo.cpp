#include "Archivo.h"



boolean ExisteArchivo (String nombrearchivo){

boolean existeArchivo = TRUE;
FILE * f = fopen (nombrearchivo, "rb");
if (f == NULL)
existeArchivo = FALSE;
else
fclose (f);
return existeArchivo;
}


void bajarValorNodo (ValorNodo v, FILE *f) {

    fwrite (&v.indice, sizeof(int), 1, f);
    fwrite (&v.discriminante, sizeof(TipoNodo), 1, f);
    switch (darTipo(v.discriminante)) {
        case VALOR: fwrite(&v.dato.valor, sizeof(boolean), 1, f);
        break;
        case OPERADOR: fwrite(&v.dato.operador, sizeof(char), 1, f);
        break;
        case PARENTESIS: fwrite(&v.dato.parentesis, sizeof(char), 1, f);
        break;
    }
}

void levantarValorNodo (ValorNodo &v, FILE *f) {

fread(&v.indice, sizeof(int), 1, f);
fread(&v.discriminante, sizeof(TipoNodo), 1, f);
switch (darTipo(v.discriminante)) {
        case VALOR: fread(&v.dato.valor, sizeof(boolean), 1, f);
        break;
        case OPERADOR: fread(&v.dato.operador, sizeof(char), 1, f);
        break;
        case PARENTESIS: fread(&v.dato.parentesis, sizeof(char), 1, f);
        break;
    }
}


void BajarArbolExpre (ArbolExpre a, FILE *f) {

if (a != NULL) {

bajarValorNodo(a->info, f);
BajarArbolExpre (a->hizq, f);
BajarArbolExpre (a->hder, f);
}

}

void LevantarArbolExpre (ArbolExpre &a, String nombrearchivo) {
FILE *f = fopen(nombrearchivo, "rb");
ValorNodo buffer;
crearArbol(a);

levantarValorNodo (buffer, f);
while (!feof(f)) {
    insertarValorEnOrden(buffer, a);
    levantarValorNodo(buffer, f);

}

fclose (f);

}



