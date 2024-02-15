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
    int i=0; char c;
    fflush (stdin);
    scanf ("%c", &c);

    while (c!= '\n' && i < MAX-1) {
        aux[i] = c;
        i++; scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strdestruir (aux);
}


boolean strmen (String s1, String s2)
{
 int i = 0;
 boolean encontre = FALSE;
 boolean menor = FALSE;

 while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
{
 if (s1[i] != s2[i])
 encontre = TRUE;

 if (s1[i] < s2[i])
 menor = TRUE;
 i++;
}
 if ((!encontre) && (s2[i]!='\0'))
 menor = TRUE;

 return menor;
}

boolean streq (String s1, String s2)
{
  boolean iguales;

  if (s1 == s2) {
    iguales = TRUE;
  }
  else {
    iguales = FALSE;
  }


return iguales;
}

void strcop (String &s1,String s2)
{
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

void strcon (String &s1, String s2)
{
 String s3;
 int i = 0;
 int j = 0;
 s3 = new char [strlar(s1)+strlar(s2)+1];

 while (i < (strlar(s1)+strlar(s2)))
{
    while(s1[i] != '\0')
    {
        s3[i] = s1[i];
        i++;
    }
    s3[i] = s2[j];
    j++;
    i++;
    }
 s3[i] = '\0';

 strcop (s1, s3);
 strdestruir (s3);


}

void strswp (String &s1,String &s2)
{
 String aux;

 aux = s1;
 s1 = s2;
 s2 = aux;

}
