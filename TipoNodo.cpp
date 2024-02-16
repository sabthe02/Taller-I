#include "TipoNodo.h"

void desplegarTipo (TipoNodo tipo) {
 switch (tipo) {
            case VALOR: printf("true o false");
            break;
            case OPERADOR: printf("AND, OR o NOT");
            break;
            case PARENTESIS: printf("( o )");
            break;
    }
}

TipoNodo darTipo (TipoNodo tipo) {

return tipo;

}
