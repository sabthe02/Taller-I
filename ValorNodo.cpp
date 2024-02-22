#include "ValorNodo.h"


void desplegarOperador (ValorNodo valor) {
switch(valor.dato.operador) {
    case 'A': printf(" AND ");
    break;
    case 'O': printf(" OR ");
    break;
    case 'N': printf("NOT ");
    break;
}
}

void desplegarParentesis (ValorNodo valor) {
switch(valor.dato.parentesis) {
    case '(': printf("(");
    break;
    case ')': printf(")");
    break;
}
}


void desplegarDatoNodoArbol (ValorNodo valor) {
    switch(darTipo(valor.discriminante)) {
        case VALOR: desplegarBoolean(valor.dato.valor);
        break;
        case OPERADOR: desplegarOperador(valor);
        break;
        case PARENTESIS: desplegarParentesis(valor);
        break;
    }
}


int darIndiceNodoArbol (ValorNodo valor) {
    return valor.indice;
}

TipoNodo darDiscriminante (ValorNodo valor) {
    return valor.discriminante;
}

boolean darBooleanoArbol (ValorNodo valor) {
return valor.dato.valor;
}

char darOperadorArbol (ValorNodo valor) {
    return valor.dato.operador;
}

char darParentesisArbol (ValorNodo valor) {
    return valor.dato.parentesis;
}

void insertarValorNodo (boolean v, ValorNodo &valor) {


switch(v) {
        case TRUE:  valor.dato.valor = TRUE;
                    valor.discriminante = VALOR;
        break;
        case FALSE: valor.dato.valor = FALSE;
                    valor.discriminante = VALOR;
        break;
    }

}

void insertarOperadorNodo (char o, ValorNodo &valor) {

switch(o) {
        case 'O':   valor.dato.operador = 'O';
                    valor.discriminante = OPERADOR;
        break;
        case 'A':   valor.dato.operador = 'A';
                    valor.discriminante = OPERADOR;
        break;
        case 'N':   valor.dato.operador = 'N';
                    valor.discriminante = OPERADOR;
    }

}


void insertarParentesisNodo (char p, ValorNodo &valor) {
    switch(p) {
        case '(':   valor.dato.operador = '(';
                    valor.discriminante = PARENTESIS;
        break;
        case ')':   valor.dato.operador = ')';
                    valor.discriminante = PARENTESIS;
        break;
    }
}

void asignarIndiceNodo (int indice, ValorNodo &valor) {

valor.indice = indice;

}

