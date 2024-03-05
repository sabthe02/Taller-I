#include "String.h"

void strcrear (String &s) {

s = new char [1];
s[0] = '\0';


}

void strdestruir (String &s) {
delete []s;
s = NULL;

}

int strlar (String s)
{
 int i = 0;
 while (s[i] != '\0')
i++;
 return i;
}

void print (String s)
{
 int i = 0;
 while (s[i]!= '\0')
{
 printf ("%c", s[i]);
 i++;
}
}

void scan (String &s){
    String aux = new char[MAX];
    int i=0;
    char c;
    fflush (stdin);
    scanf ("%c", &c);

    while (c!= '\n' && i < MAX-1) {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strdestruir (aux);
}


boolean streq (String s1, String s2)
{
 int i = 0;
 boolean iguales = TRUE;
while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
{
 if (s1[i] != s2[i])
 iguales = FALSE;
 i++;
}
 if ((s1[i] != '\0') || (s2[i] != '\0'))
 iguales = FALSE;
return iguales;
}

void strcop (String &s1,String s2){
int i = 0;
int largo = strlar(s2) + 1;
delete [] s1;
s1 = new char[largo];

while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
}
s1[i] = '\0';
}


int transformarANatural (String s) {

int num;
num = atoi(s);
return num;

}

boolean esNatural (String s) {
boolean es;
int num;
num = atoi(s);

if (num == 0) {
    es = FALSE;
}
else {
    es = TRUE;
}
return es;

}
boolean transformarStringABoolean (String s) {
boolean Bool;

if (streq(s, "true")) {
    Bool = TRUE;
}
else {
    if (streq(s, "false")) {
        Bool = FALSE;
    }
}
return Bool;

}

char transformarStringOperadorAChar (String s) {
char c;
if (streq(s, "AND")) {
    c = 'A';
}
    else {
        if (streq(s, "OR")) {
            c = 'O';
        }

        else {
            if (streq(s, "NOT")) {
                    c = 'N';
            }
        }
    }
return c;
}




boolean esVacio (String s) {
boolean es;

if (strlar(s) == 0) {
    es = TRUE;
}
else {
    es = FALSE;
}
return es;

}

void eliminarBlancosPrincipio (String s, String &sb) {

int i = 0;
int j = 0;
boolean encontre = FALSE;

int largo = strlar(s) + 1;

sb = new char[largo];

while (s[i] != '\0') {
    while (!encontre) {
        if (s[i] ==' ') {
            i++;
        }
        else {
        encontre = TRUE;
        }
    }
        sb[j] = s[i];
        j++;
        i++;

}
sb[j] = '\0';


}

void dividirString (String s, String &primero, String &resto) {

int i = 0;
int j = 0;
boolean fin = FALSE;

int largo = strlar(s) + 1;

primero = new char[largo];
resto = new char[largo];


while (s[i] != '\0' && !fin) {

    if (s[i] == ' ') {
        fin = TRUE;
    }
    else {
    primero[i] = s[i];
    i++;
    }
}
primero[i] = '\0';

while (s[i] != '\0') {
    resto[j] = s[i];
    i++;
    j++;
}
resto[j] = '\0';

}

void dividirStringDeArchivo (String s, String &primero, String &resto) {

int i = 0;
int j = 0;
boolean fin = FALSE;

int largo = strlar(s) + 1;

primero = new char[largo];
resto = new char[largo];


while (s[i] != '\0' && !fin) {

    if (s[i] == '.') {
        fin = TRUE;
    }
    else {
    primero[i] = s[i];
    i++;
    }
}
primero[i] = '\0';

while (s[i] != '\0') {
    resto[j] = s[i];
    i++;
    j++;
}
resto[j] = '\0';
}

boolean esAlfabetico (String s) {

boolean es = TRUE;
int i = 0;

if (!esVacio(s)) {

while (es && (s[i] != '\0'))
{
 if (!((s[i] >=  'a' && s[i] <= 'z') || ((s[i] >=  'A' && s[i] <= 'Z')))) {
    es = FALSE;
    }
    else{
        i++;
    }
}
 if ((s[i] != '\0')){
    es = FALSE;
    }
}
else {
    es = FALSE;
}

return es;
}

boolean tieneExtension (String s) {
boolean tiene;

if (streq(s,".dat")) {
    tiene = TRUE;
}
else {
    tiene = FALSE;
}
return tiene;
}


boolean esNombreArchivo (String s){
boolean es = TRUE;
int largo = strlar(s);
String p, r;
strcrear(p);
strcrear(r);

 if (!esVacio(s)) {

dividirStringDeArchivo(s, p, r);
    if (esVacio (r) || esVacio (p)) {
        es = FALSE;
    }
    else {
        if ((!tieneExtension(r)) || (!esAlfabetico(p))){
                es = FALSE;
            }
    }
}

else {
    es = FALSE;
}

return es;

strdestruir(p);
strdestruir(r);

}

