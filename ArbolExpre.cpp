#include "ArbolExpre.h"
// A cambiar

void Crear (ABB &a) {

a = NULL;

}

boolean Vacio (ABB a) {
boolean es;

if (a == NULL) {
    es = TRUE;
}
else {
    es = FALSE;
}
return es;
}

paciente darRaiz (ABB a) {
return a->info;

}

ABB HijoIzq (ABB a) {

return a->hizq;

}


ABB HijoDer (ABB a) {

return a->hder;
}

void Insert (ABB &a, paciente valor) {

if (a == NULL) {
    a = new nodo;
    a->info = valor;
    a->hizq = NULL;
    a->hder = NULL;
    }
    else {
        if (seleccionarCedulaPaciente(valor)< seleccionarCedulaPaciente(a->info)) {
            Insert (a->hizq, valor);
        }
        else {
            Insert (a->hder, valor);
        }
    }

}



boolean existe (ABB a, long int cedula) {
if (a == NULL) {
    return FALSE;
}
else {
    if (cedula == seleccionarCedulaPaciente(a->info)) {
        return TRUE;
    }
    else {
            if (cedula < seleccionarCedulaPaciente(a->info)) {
                return existe (a->hizq, cedula);
            }
            else {
                return existe (a->hder, cedula);
            }
    }
}


}

paciente Minimo (ABB a) {
    if (a -> hizq == NULL)   {
            return (a->info);
    }
    else {
         return Minimo (a -> hizq); }

    }

void Borrar_Minimo (ABB &a) {
    ABB aux;
    if (a -> hizq == NULL) {
            aux = a -> hder;
            delete a;
            a = aux;
    }
    else
    {
        Borrar_Minimo (a -> hizq);
    }
}

void eliminarConCedula (long int cedula, ABB &a) {

    ABB aux;
    if (cedula == seleccionarCedulaPaciente(a -> info)) {
        if (a -> hder == NULL) {
            aux = a -> hizq;
            delete a;
            a = aux;
        }
        else {
                if (a -> hizq == NULL) {
                    aux = a -> hder;
                    delete a;
                    a = aux;
                }
                    else {
                        a -> info = Minimo (a -> hder);
                        Borrar_Minimo (a -> hder);
                    }
        }
    }
    else {
            if (cedula < seleccionarCedulaPaciente(a -> info))   {
                eliminarConCedula (cedula, a -> hizq);
            }
            else  {
                eliminarConCedula (cedula, a -> hder);
            }
    }

}

void listarPacientes (ABB a) {
 if (a != NULL) {
    listarPacientes (a->hizq);
    desplegarPaciente (a->info);
    listarPacientes (a->hder);
 }


}

void listarPacientesSinConsultas (ABB a) {

if (a !=NULL) {
    if (seleccionarCantConsultas(a->info) == 0 ) {
        listarPacientesSinConsultas (a->hizq);
        desplegarPaciente (a->info);
        listarPacientesSinConsultas (a->hder);
    }
    else {
        listarPacientesSinConsultas (a->hizq);
        listarPacientesSinConsultas (a->hder);
    }

}


}

void sumarConsultaAlABB (ABB &a, long int ced)
{
if (a != NULL )
{
    {
         if (seleccionarCedulaPaciente (a->info) == ced)
             sumarConsulta (a->info);
         else
            {if (ced < seleccionarCedulaPaciente (a->info))
         sumarConsultaAlABB (a->hizq, ced);
         else sumarConsultaAlABB (a->hder, ced);
          }
    }


}
}


int obtenerPacientesConCantidadDeConsultas (ABB a, int CaConsultas) {
if (a == NULL) {
    return 0;
}
else {
    if (CaConsultas <= seleccionarCantConsultas(a->info))
        {return 1+ obtenerPacientesConCantidadDeConsultas (a->hizq, CaConsultas) + obtenerPacientesConCantidadDeConsultas(a->hder, CaConsultas);}
    else {return obtenerPacientesConCantidadDeConsultas (a->hizq, CaConsultas) + obtenerPacientesConCantidadDeConsultas(a->hder, CaConsultas);}
}

}

void liberarArbol(ABB &a)
{
    if (a != NULL)
    {
        liberarArbol(a->hizq);
        liberarArbol(a->hder);
        delete a;
    }
}
