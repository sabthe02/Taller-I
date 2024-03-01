#ifndef ARBOLEXPRE_H_INCLUDED
#define ARBOLEXPRE_H_INCLUDED

#include "ValorNodo.h"


typedef struct nodoA 	{ValorNodo info;
                        nodoA *hizq;
                        nodoA *hder;
                        } NodoA;

typedef NodoA *ArbolExpre;


//Crear un árbol
void crearArbol (ArbolExpre &a);

// Saber si el árbol está vacío
boolean ArbolEsVacio (ArbolExpre a);

// Devolver raiz
//Precondición: Árbol no vacío
ValorNodo darRaiz (ArbolExpre a);

// Procedimiento para subir a memoria los nodos según su índice
// Solo sirve para insertar desde archivo porque tiene que venir con el indice seteado, no sirve si el indice no esta definido
//Precondición: el valor no existía previamente en el árbol
// Precondición: El índice de ValorNodo tiene que estar asignado
void insertarValorEnOrden (ValorNodo valor, ArbolExpre &a);

// Insertar valor atómico
// Precondición: Valor a insertar convertido a booleano
void insertarValorArbol (boolean v, ArbolExpre &a);

// Insertar operador a nodo
// Precondición: String "AND" u "OR" convertido a 'A' u 'O'
void insertarOperador (char o, ValorNodo &valor);

// Insertar paréntesis a nodo
void insertarParentesisNodo (char p, ValorNodo &valor);

// Asignar índice a nodo (cuando se bajará a archivo)
void asignarIndiceNodo (int indice, ValorNodo &valor);

// liberar memoria arbol
void liberarMemoriaArbol(ArbolExpre &a);

// Listar todos los nodos del árbol en pantalla, recorriéndolo en órden
void desplegarNodosArbolOrden (ArbolExpre a);

//asigna al árbol un nuevo nodo de tipo ValorNodo (no importando qué tiene adentro)
void insertarValorNodoArbol(ValorNodo vn, ArbolExpre &a);

//Copia un árbol a otro
void copiarArbolAOtro(ArbolExpre b, ArbolExpre &a);

//carga Paréntesis cierre o apertura a árbol
void cargarParentesis(ArbolExpre &a, char parentesis);

// carga Operador (NOT) a árbol
// cargar un arbol en hder, en el min cargar parentesis (hizq), en max cargar parentesis (hder)
void cargarOperadorNOT(ArbolExpre &a, ArbolExpre ar, char operador);

// carga Operador (AND u OR) a árbol
// ar copiar a otro arbol como hizq,
// arb copiar a otro como hder, en el min cargar parentesis (hizq), en max cargar parentesis (hder)
void cargarOperadorAndOr(ArbolExpre &a, ArbolExpre ar, ArbolExpre arb, char operador);

//carga paréntesis en el hijo más izquierdo
void InsertarParentesisEnMinimo(char parentesis, ArbolExpre &a);

//carga paréntesis en el hizo más derecho
void InsertarParentesisEnMaximo(char parentesis, ArbolExpre &a);

//evaluar expresión
// si en raiz hay un boolean, entonces retornar valor del boolean. PASO BASE,
// sino, si en raiz hay un NOT, evaluo con ! y llamada recursiva a evaluarExpresion(arbol->hder)
// sino si en raiz hay AND u OR, llamada recursiva a evaluarExpresion(arbol->hizq), conecto con || u &&, y luego llamada recursiva a evaluar con evaluarExpresion(arbol->hder)
boolean evaluarExpresion(ArbolExpre a);

//enumerar nodos del árbol
// precondición: Inizializar índice en 0
void enumerarNodos(int &indice, ArbolExpre &a);


#endif // ARBOLEXPRE_H_INCLUDED
