#ifndef ARBOLEXPRE_H_INCLUDED
#define ARBOLEXPRE_H_INCLUDED

#include "ValorNodo.h"


typedef struct nodoA 	{ValorNodo info;
                        nodoA *hizq;
                        nodoA *hder;
                        } NodoA;

typedef NodoA *ArbolExpre;


//Crear un �rbol
void crearArbol (ArbolExpre &a);

// Saber si el �rbol est� vac�o
boolean ArbolEsVacio (ArbolExpre a);

// Devolver raiz
//Precondici�n: �rbol no vac�o
ValorNodo darRaiz (ArbolExpre a);

// Procedimiento para subir a memoria los nodos seg�n su �ndice
// Solo sirve para insertar desde archivo porque tiene que venir con el indice seteado, no sirve si el indice no esta definido
//Precondici�n: el valor no exist�a previamente en el �rbol
// Precondici�n: El �ndice de ValorNodo tiene que estar asignado
void insertarValorEnOrden (ValorNodo valor, ArbolExpre &a);

// Insertar valor at�mico
// Precondici�n: Valor a insertar convertido a booleano
void insertarValorArbol (boolean v, ArbolExpre &a);

// Insertar operador a nodo
// Precondici�n: String "AND" u "OR" convertido a 'A' u 'O'
void insertarOperador (char o, ValorNodo &valor);

// Insertar par�ntesis a nodo
void insertarParentesisNodo (char p, ValorNodo &valor);

// Asignar �ndice a nodo (cuando se bajar� a archivo)
void asignarIndiceNodo (int indice, ValorNodo &valor);

// liberar memoria arbol
void liberarMemoriaArbol(ArbolExpre &a);

// Listar todos los nodos del �rbol en pantalla, recorri�ndolo en �rden
void desplegarNodosArbolOrden (ArbolExpre a);

//asigna al �rbol un nuevo nodo de tipo ValorNodo (no importando qu� tiene adentro)
void insertarValorNodoArbol(ValorNodo vn, ArbolExpre &a);

//Copia un �rbol a otro
void copiarArbolAOtro(ArbolExpre b, ArbolExpre &a);

//carga Par�ntesis cierre o apertura a �rbol
void cargarParentesis(ArbolExpre &a, char parentesis);

// carga Operador (NOT) a �rbol
// cargar un arbol en hder, en el min cargar parentesis (hizq), en max cargar parentesis (hder)
void cargarOperadorNOT(ArbolExpre &a, ArbolExpre ar, char operador);

// carga Operador (AND u OR) a �rbol
// ar copiar a otro arbol como hizq,
// arb copiar a otro como hder, en el min cargar parentesis (hizq), en max cargar parentesis (hder)
void cargarOperadorAndOr(ArbolExpre &a, ArbolExpre ar, ArbolExpre arb, char operador);

//carga par�ntesis en el hijo m�s izquierdo
void InsertarParentesisEnMinimo(char parentesis, ArbolExpre &a);

//carga par�ntesis en el hizo m�s derecho
void InsertarParentesisEnMaximo(char parentesis, ArbolExpre &a);

//evaluar expresi�n
// si en raiz hay un boolean, entonces retornar valor del boolean. PASO BASE,
// sino, si en raiz hay un NOT, evaluo con ! y llamada recursiva a evaluarExpresion(arbol->hder)
// sino si en raiz hay AND u OR, llamada recursiva a evaluarExpresion(arbol->hizq), conecto con || u &&, y luego llamada recursiva a evaluar con evaluarExpresion(arbol->hder)
boolean evaluarExpresion(ArbolExpre a);

//enumerar nodos del �rbol
// precondici�n: Inizializar �ndice en 0
void enumerarNodos(int &indice, ArbolExpre &a);


#endif // ARBOLEXPRE_H_INCLUDED
