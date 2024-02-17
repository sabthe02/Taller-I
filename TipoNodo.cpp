#include "TipoNodo.h"

void desplegarTipo (TipoNodo tipo) {
 switch (tipo) {
            case VALOR: printf("VALOR");
            break;
            case OPERADOR: printf("OPERADOR");
            break;
            case PARENTESIS: printf("PARENTESIS");
            break;
    }
}

TipoNodo darTipo (TipoNodo tipo) {

return tipo;

}
