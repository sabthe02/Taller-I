#include "Errores.h"

void error (errores codigo, int comando, ListaStrings L) {
switch (codigo) {
    case COMANDOENLUGAREQUIVOCADO: switch (comando) {
                                                case 1: printf("\nLa palabra 'atomic' debe ir en primer lugar y en segundo 'true' o 'false'");
                                                break;
                                                case 2: printf("\nLa palabra 'compound' debe ir en primer lugar, seguido de 'NOT' y un numero natural o seguido de un numero natural, 'AND' u 'OR y otro numero natural");
                                                break;
                                                case 3: printf("\nLa palabra 'show' debe ir en primer lugar y luego el numero de la expresion a mostrar");
                                                break;
                                                case 4: printf("\nLa palabra 'evaluate' debe ir en primer lugar y luego el numero de la expresion a mostrar");
                                                break;
                                                case 5: printf("\nLa palabra 'save' debe ir en primer lugar, luego el numero de la expresion a guardar y en tercer lugar el nombre del archivo");
                                                break;
                                                case 6: printf("\nLa palabra 'load' debe ir en primer lugar y en segundo 'true' o 'false'");
                                                break;
                                                case 7: printf("\nLa palabra 'exit' debe ir en primer lugar");
                                                break;
                                                case 8: printf("\nLa palabra 'exit' debe ir en primer lugar");
                                                break;
                                    }
    break;
    case NOCONTIENEFORMATO: switch (comando) {
                                                case 2: if (largoListaStrings(L)==3) {
                                                            printf("\nFormato incorrecto, 'compound' debe ser seguido por 'NOT'");
                                                        }
                                                        else
                                                        if (largoListaStrings(L)==4) {
                                                            printf("\nFormato incorrecto, 'compound' debe ser seguido por un natural, luego 'AND' u 'OR' y otro natural");
                                                        }
                                                break;
                            }
    break;
    case PALABRAENLUGAREQUIVOCADO: switch (comando) {
                                                case 1: printf("\nLa palabra 'atomic' debe ir en primer lugar y en segundo 'true' o 'false'");
                                                break;
                                                case 2: if (PerteneceIter("NOT", L)) {
                                                            printf("\nNOT debe ser la segunda palabra");
                                                        }
                                                        else {
                                                            printf("\n'AND' u 'OR' deben ser la tercer palabra");
                                                        }
                                                break;
                                    }
    break;
    case CANTIDADDEPARAMETROSINCORRECTA: switch (comando) {
                                                case 1: printf("\nCantidad de parametros incorrecta, deben ser 2");
                                                break;
                                                case 2: printf("\nCantidad de parametros incorrecta, deben ser 3 o 4");
                                                break;
                                                case 3:
                                                case 4:
                                                case 6: printf("\nCantidad de parametros incorrecta, deben ser 2");
                                                break;
                                                case 5: printf("\nCantidad de parametros incorrecta, deben ser 3");
                                                break;
                                                case 7: printf("\nCantidad de parametros incorrecta, debe ser 1");
                                                break;
                                            }
    break;
    case PALABRAEQUIVOCADA: switch (comando) {
                                case 1: printf("\nDebe ingresar 'true' o 'false' como segunda palabra");
                                break;
                                case 2: printf("\nEn la tercer posicion puede unicamente ir 'AND' u 'OR");
                                break;
                            }
    break;
    case PALABRADEBESERNATURAL: switch (comando) {
                                    case 2: if (PerteneceIter("NOT", L)) {
                                                printf("\nLa tercer palabra debe ser un natural");
                                            }
                                            else {
                                                    printf("\nLa segunda palabra debe ser un natural");
                                                    }
                                    break;
                                    case 3:
                                    case 4:
                                    case 5: printf("\nLa segunda palabra debe ser un natural");
                                    break;
                                }
    break;
    case CUARTAPALABRADEBESERNATURAL: switch (comando) {
                                            case 2: printf("\nLa cuarta palabra debe ser un natural");
                                            break;
                                        }
    break;

    case NOEXISTEENLISTAEXPRESIONES: switch (comando) {
                                        case 2:
                                        case 3:
                                        case 4:
                                        case 5: printf("\nNo existe la expresion correspondiente en Lista Expresiones");
                                        break;
                                    }

    break;
    case NOEXISTEENLISTAEXPRESIONESPRIMERO: switch (comando) {
                                            case 2: printf("\nNumero uno no pertenece a Lista de Expresiones");
                                            break;
                                            }
    break;
    case NOEXISTEENLISTAEXPRESIONESSEGUNDO: switch (comando) {
                                            case 2: printf("\nNumero dos no pertenece a Lista de Expresiones");
                                            break;
                                            }
    break;

    case PALABRANOALFABETICA: switch(comando) {
                                case 5:
                                case 6: printf("\nEl nombre del archivo debe ser alfabetico, sin signos ni numeros");
                                break;
                            }
    break;
    case ARCHIVONODAT: switch (comando) {
                            case 5:
                            case 6: printf("\nDebe terminar en .dat el nombre del archivo");
                            break;
                        }
    break;
    case NOEXISTEARCHIVO: switch (comando) {
                                case 6: printf("\Archivo no existe, no es posible cargarlo");
                                break;
                            }
    break;

}

}
