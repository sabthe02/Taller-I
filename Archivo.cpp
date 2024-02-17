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
//
//void Bajar_String (String s, FILE * f){
//int i =0;
//
//while (s[i]!='\0' && (!feof(f))) {
//    fwrite(&s[i], sizeof(char),1, f);
//    i++;
//}
//fwrite(&s[i], sizeof(char),1, f);
//
//}
//
//void Levantar_String (String &s, FILE * f) {
//int i = 0;
//String aux;
//aux = new char [MAX];
//
//fread(&aux[i], sizeof(char), 1, f);
//
//while (aux[i]!='\0' && (!feof(f))) {
//    i++;
//    fread(&aux[i], sizeof(char), 1, f);
//}
//strcop(s, aux);
//delete []aux;
//}
//
//// ValorNodo
//
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

// ÁrbolExpre
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



//void Bajar_Consultas (Lista L , String nomArchConsultas) {
//FILE * f = fopen("Consultas.txt", "wb");
//while (L != NULL){
//    Bajar_Consulta (L -> info, f);
//    L = L -> sig;
//}
//fclose(f);
//}
//
//void Levantar_Consultas (Lista &L, String nomArchConsultas) {
//FILE * f = fopen("Consultas.txt", "rb");
//Consulta buffer;
//Crear (L);
//}
//


